#include <u.h>
#include <libc.h>
#include <auth.h>

void	usage(void);
void	catch(void*, char*);

char *keyspec = "";
char *spec = "";
int flag = MREPL;
int qflag = 0;
int noauth = 0;
int asnone = 0;

int
amount0(int fd, char *mntpt, int flags, char *aname, char *keyspec)
{
	int rv, afd;
	AuthInfo *ai;

	afd = fauth(fd, aname);
	if(afd >= 0){
		ai = auth_proxy(afd, amount_getkey, "proto=p9any role=client %s", keyspec);
		if(ai != nil)
			auth_freeAI(ai);
		else
			fprint(2, "%s: auth_proxy: %r\n", argv0);
	}
	rv = mount(fd, afd, mntpt, flags, aname);
	if(afd >= 0)
		close(afd);
	return rv;
}

void
main(int argc, char *argv[])
{
	int fd, rv;

	ARGBEGIN{
	case 'a':
		flag |= MAFTER;
		break;
	case 'b':
		flag |= MBEFORE;
		break;
	case 'c':
		flag |= MCREATE;
		break;
	case 'C':
		flag |= MCACHE;
		break;
	case 'k':
		keyspec = EARGF(usage());
		break;
	case 'N':
		asnone = 1;
		/* no break */
	case 'n':
		noauth = 1;
		break;
	case 'q':
		qflag = 1;
		break;
	default:
		usage();
	}ARGEND

	if(argc == 3)
		spec = argv[2];
	else if(argc != 2)
		usage();

	if((flag&MAFTER)&&(flag&MBEFORE))
		usage();

	fd = open(argv[0], ORDWR);
	if(fd < 0){
		if(qflag)
			exits(0);
		fprint(2, "%s: can't open %s: %r\n", argv0, argv[0]);
		exits("open");
	}

	if(asnone){
		rv = open("#c/user", OWRITE);
		if(rv < 0 || write(rv, "none", 4) != 4){
			if(qflag)
				exits(0);
			fprint(2, "%s: can't become none: %r\n", argv0);
			exits("becomenone");
		}
	}

	notify(catch);
	if(noauth)
		rv = mount(fd, -1, argv[1], flag, spec);
	else
		rv = amount0(fd, argv[1], flag, spec, keyspec);
	if(rv < 0){
		if(qflag)
			exits(0);
		fprint(2, "%s: mount %s: %r\n", argv0, argv[1]);
		exits("mount");
	}
	exits(0);
}

void
catch(void *, char *m)
{
	fprint(2, "%s: %s\n", argv0, m);
	exits(m);
}

void
usage(void)
{
	fprint(2, "usage: mount [-a|-b] [-cCnNq] [-k keypattern] /srv/service dir [spec]\n");
	exits("usage");
}
