#define	NSYM	50
#define	NSNAME	8
#define NOPROF	(1<<0)
#define DUPOK	(1<<1)
#define NOSPLIT	(1<<2)

enum	as
{
	AXXX,
	AAAA,
	AAAD,
	AAAM,
	AAAS,
	AADCB,
	AADCL,
	AADCW,
	AADDB,
	AADDL,
	AADDW,
	AADJSP,
	AANDB,
	AANDL,
	AANDW,
	AARPL,
	ABOUNDL,
	ABOUNDW,
	ABSFL,
	ABSFW,
	ABSRL,
	ABSRW,
	ABTL,
	ABTW,
	ABTCL,
	ABTCW,
	ABTRL,
	ABTRW,
	ABTSL,
	ABTSW,
	ABYTE,
	ACALL,
	ACLC,
	ACLD,
	ACLI,
	ACLTS,
	ACMC,
	ACMPB,
	ACMPL,
	ACMPW,
	ACMPSB,
	ACMPSL,
	ACMPSW,
	ADAA,
	ADAS,
	ADATA,
	ADECB,
	ADECL,
	ADECW,
	ADIVB,
	ADIVL,
	ADIVW,
	AENTER,
	AGLOBL,
	AGOK,
	AHISTORY,
	AHLT,
	AIDIVB,
	AIDIVL,
	AIDIVW,
	AIMULB,
	AIMULL,
	AIMULW,
	AINB,
	AINL,
	AINW,
	AINCB,
	AINCL,
	AINCW,
	AINSB,
	AINSL,
	AINSW,
	AINT,
	AINTO,
	AIRETL,
	AIRETW,
	AJCC,
	AJCS,
	AJCXZ,
	AJEQ,
	AJGE,
	AJGT,
	AJHI,
	AJLE,
	AJLS,
	AJLT,
	AJMI,
	AJMP,
	AJNE,
	AJOC,
	AJOS,
	AJPC,
	AJPL,
	AJPS,
	ALAHF,
	ALARL,
	ALARW,
	ALEAL,
	ALEAW,
	ALEAVEL,
	ALEAVEW,
	ALOCK,
	ALODSB,
	ALODSL,
	ALODSW,
	ALONG,
	ALOOP,
	ALOOPEQ,
	ALOOPNE,
	ALSLL,
	ALSLW,
	AMOVB,
	AMOVL,
	AMOVW,
	AMOVBLSX,
	AMOVBLZX,
	AMOVBWSX,
	AMOVBWZX,
	AMOVWLSX,
	AMOVWLZX,
	AMOVSB,
	AMOVSL,
	AMOVSW,
	AMULB,
	AMULL,
	AMULW,
	ANAME,
	ANEGB,
	ANEGL,
	ANEGW,
	ANOP,
	ANOTB,
	ANOTL,
	ANOTW,
	AORB,
	AORL,
	AORW,
	AOUTB,
	AOUTL,
	AOUTW,
	AOUTSB,
	AOUTSL,
	AOUTSW,
	APOPAL,
	APOPAW,
	APOPFL,
	APOPFW,
	APOPL,
	APOPW,
	APUSHAL,
	APUSHAW,
	APUSHFL,
	APUSHFW,
	APUSHL,
	APUSHW,
	ARCLB,
	ARCLL,
	ARCLW,
	ARCRB,
	ARCRL,
	ARCRW,
	AREP,
	AREPN,
	ARET,
	AROLB,
	AROLL,
	AROLW,
	ARORB,
	ARORL,
	ARORW,
	ASAHF,
	ASALB,
	ASALL,
	ASALW,
	ASARB,
	ASARL,
	ASARW,
	ASBBB,
	ASBBL,
	ASBBW,
	ASCASB,
	ASCASL,
	ASCASW,
	ASETCC,
	ASETCS,
	ASETEQ,
	ASETGE,
	ASETGT,
	ASETHI,
	ASETLE,
	ASETLS,
	ASETLT,
	ASETMI,
	ASETNE,
	ASETOC,
	ASETOS,
	ASETPC,
	ASETPL,
	ASETPS,
	ACDQ,
	ACWD,
	ASHLB,
	ASHLL,
	ASHLW,
	ASHRB,
	ASHRL,
	ASHRW,
	ASTC,
	ASTD,
	ASTI,
	ASTOSB,
	ASTOSL,
	ASTOSW,
	ASUBB,
	ASUBL,
	ASUBW,
	ASYSCALL,
	ATESTB,
	ATESTL,
	ATESTW,
	ATEXT,
	AVERR,
	AVERW,
	AWAIT,
	AWORD,
	AXCHGB,
	AXCHGL,
	AXCHGW,
	AXLAT,
	AXORB,
	AXORL,
	AXORW,

	AFMOVB,
	AFMOVBP,
	AFMOVD,
	AFMOVDP,
	AFMOVF,
	AFMOVFP,
	AFMOVL,
	AFMOVLP,
	AFMOVV,
	AFMOVVP,
	AFMOVW,
	AFMOVWP,
	AFMOVX,
	AFMOVXP,

	AFCOMB,
	AFCOMBP,
	AFCOMD,
	AFCOMDP,
	AFCOMDPP,
	AFCOMF,
	AFCOMFP,
	AFCOML,
	AFCOMLP,
	AFCOMW,
	AFCOMWP,
	AFUCOM,
	AFUCOMP,
	AFUCOMPP,

	AFADDDP,
	AFADDW,
	AFADDL,
	AFADDF,
	AFADDD,

	AFMULDP,
	AFMULW,
	AFMULL,
	AFMULF,
	AFMULD,

	AFSUBDP,
	AFSUBW,
	AFSUBL,
	AFSUBF,
	AFSUBD,

	AFSUBRDP,
	AFSUBRW,
	AFSUBRL,
	AFSUBRF,
	AFSUBRD,

	AFDIVDP,
	AFDIVW,
	AFDIVL,
	AFDIVF,
	AFDIVD,

	AFDIVRDP,
	AFDIVRW,
	AFDIVRL,
	AFDIVRF,
	AFDIVRD,

	AFXCHD,
	AFFREE,

	AFLDCW,
	AFLDENV,
	AFRSTOR,
	AFSAVE,
	AFSTCW,
	AFSTENV,
	AFSTSW,

	AF2XM1,
	AFABS,
	AFCHS,
	AFCLEX,
	AFCOS,
	AFDECSTP,
	AFINCSTP,
	AFINIT,
	AFLD1,
	AFLDL2E,
	AFLDL2T,
	AFLDLG2,
	AFLDLN2,
	AFLDPI,
	AFLDZ,
	AFNOP,
	AFPATAN,
	AFPREM,
	AFPREM1,
	AFPTAN,
	AFRNDINT,
	AFSCALE,
	AFSIN,
	AFSINCOS,
	AFSQRT,
	AFTST,
	AFXAM,
	AFXTRACT,
	AFYL2X,
	AFYL2XP1,

	AEND,

	ADYNT,
	AINIT,

	ASIGNAME,

	AFCOMI,
	AFCOMIP,
	AFUCOMI,
	AFUCOMIP,
	ACMPXCHGB,
	ACMPXCHGL,
	ACMPXCHGW,
	ACPUID,

	/* conditional move */
	ACMOVLCC,
	ACMOVLCS,
	ACMOVLEQ,
	ACMOVLGE,
	ACMOVLGT,
	ACMOVLHI,
	ACMOVLLE,
	ACMOVLLS,
	ACMOVLLT,
	ACMOVLMI,
	ACMOVLNE,
	ACMOVLOC,
	ACMOVLOS,
	ACMOVLPC,
	ACMOVLPL,
	ACMOVLPS,
	ACMOVWCC,
	ACMOVWCS,
	ACMOVWEQ,
	ACMOVWGE,
	ACMOVWGT,
	ACMOVWHI,
	ACMOVWLE,
	ACMOVWLS,
	ACMOVWLT,
	ACMOVWMI,
	ACMOVWNE,
	ACMOVWOC,
	ACMOVWOS,
	ACMOVWPC,
	ACMOVWPL,
	ACMOVWPS,

	AFCMOVCC,
	AFCMOVCS,
	AFCMOVEQ,
	AFCMOVHI,
	AFCMOVLS,
	AFCMOVNE,
	AFCMOVNU,
	AFCMOVUN,

	/* media */
	AADDPD,
	AADDPS,
	AADDSD,
	AADDSS,
	AANDNPD,
	AANDNPS,
	AANDPD,
	AANDPS,
	ACMPPD,
	ACMPPS,
	ACMPSD,
	ACMPSS,
	ACOMISD,
	ACOMISS,
	ACVTPD2PL,
	ACVTPD2PS,
	ACVTPL2PD,
	ACVTPL2PS,
	ACVTPS2PD,
	ACVTPS2PL,
	ACVTSD2SL,
	ACVTSD2SS,
	ACVTSL2SD,
	ACVTSL2SS,
	ACVTSS2SD,
	ACVTSS2SL,
	ACVTTPD2PL,
	ACVTTPS2PL,
	ACVTTSD2SL,
	ACVTTSS2SL,
	ADIVPD,
	ADIVPS,
	ADIVSD,
	ADIVSS,
	AFXRSTOR,
	AFXSAVE,
	ALDMXCSR,
	AMASKMOVOU,
	AMASKMOVQ,
	AMAXPD,
	AMAXPS,
	AMAXSD,
	AMAXSS,
	AMINPD,
	AMINPS,
	AMINSD,
	AMINSS,
	AMOVAPD,
	AMOVAPS,
	AMOVOU,
	AMOVHLPS,
	AMOVHPD,
	AMOVHPS,
	AMOVLHPS,
	AMOVLPD,
	AMOVLPS,
	AMOVMSKPD,
	AMOVMSKPS,
	AMOVNTO,
	AMOVNTPD,
	AMOVNTPS,
	AMOVNTQ,
	AMOVO,
	AMOVQOZX,
	AMOVSD,
	AMOVSS,
	AMOVUPD,
	AMOVUPS,
	AMULPD,
	AMULPS,
	AMULSD,
	AMULSS,
	AORPD,
	AORPS,
	APACKSSLW,
	APACKSSWB,
	APACKUSWB,
	APADDB,
	APADDL,
	APADDQ,
	APADDSB,
	APADDSW,
	APADDUSB,
	APADDUSW,
	APADDW,
	APANDB,
	APANDL,
	APANDSB,
	APANDSW,
	APANDUSB,
	APANDUSW,
	APANDW,
	APAND,
	APANDN,
	APAVGB,
	APAVGW,
	APCMPEQB,
	APCMPEQL,
	APCMPEQW,
	APCMPGTB,
	APCMPGTL,
	APCMPGTW,
	APEXTRW,
	APINSRW,
	APMADDWL,
	APMAXSW,
	APMAXUB,
	APMINSW,
	APMINUB,
	APMOVMSKB,
	APMULHRW,
	APMULHUW,
	APMULHW,
	APMULLW,
	APMULULQ,
	APOR,
	APSADBW,
	APSHUFHW,
	APSHUFL,
	APSHUFLW,
	APSHUFW,
	APSLLO,
	APSLLL,
	APSLLQ,
	APSLLW,
	APSRAL,
	APSRAW,
	APSRLO,
	APSRLL,
	APSRLQ,
	APSRLW,
	APSUBB,
	APSUBL,
	APSUBQ,
	APSUBSB,
	APSUBSW,
	APSUBUSB,
	APSUBUSW,
	APSUBW,
	APSWAPL,
	APUNPCKHBW,
	APUNPCKHLQ,
	APUNPCKHQDQ,
	APUNPCKHWL,
	APUNPCKLBW,
	APUNPCKLLQ,
	APUNPCKLQDQ,
	APUNPCKLWL,
	APXOR,
	ARCPPS,
	ARCPSS,
	ARSQRTPS,
	ARSQRTSS,
	ASHUFPD,
	ASHUFPS,
	ASQRTPD,
	ASQRTPS,
	ASQRTSD,
	ASQRTSS,
	ASTMXCSR,
	ASUBPD,
	ASUBPS,
	ASUBSD,
	ASUBSS,
	AUCOMISD,
	AUCOMISS,
	AUNPCKHPD,
	AUNPCKHPS,
	AUNPCKLPD,
	AUNPCKLPS,
	AXORPD,
	AXORPS,

	APF2IW,
	APF2IL,
	API2FW,
	API2FL,

	/* add new operations here. nowhere else. here. */
	ALAST
};

enum
{
	D_AL		= 0,
	D_CL,
	D_DL,
	D_BL,

	D_AH		= 4,
	D_CH,
	D_DH,
	D_BH,

	D_AX		= 8,
	D_CX,
	D_DX,
	D_BX,
	D_SP,
	D_BP,
	D_SI,
	D_DI,

	D_F0		= 16,
	D_F7		= D_F0 + 7,

	D_CS		= 24,
	D_SS,
	D_DS,
	D_ES,
	D_FS,
	D_GS,

	D_GDTR,		/* global descriptor table register */
	D_IDTR,		/* interrupt descriptor table register */
	D_LDTR,		/* local descriptor table register */
	D_MSW,		/* machine status word */
	D_TASK,		/* task register */

	D_CR		= 35,
	D_DR		= 43,
	D_TR		= 51,

	D_NONE		= 59,

	D_BRANCH	= 60,
	D_EXTERN	= 61,
	D_STATIC	= 62,
	D_AUTO		= 63,
	D_PARAM		= 64,
	D_CONST		= 65,
	D_FCONST	= 66,
	D_SCONST	= 67,
	D_ADDR		= 68,

	D_FILE,
	D_FILE1,

	D_INDIR,	/* additive */

	D_CONST2 = D_INDIR+D_INDIR,

	D_SIZE,	/* 8l internal */

	D_M0,
	D_X0		= D_M0 + 8,
	D_XNONE		= D_X0 + 8,

	T_TYPE		= 1<<0,
	T_INDEX		= 1<<1,
	T_OFFSET	= 1<<2,
	T_FCONST	= 1<<3,
	T_SYM		= 1<<4,
	T_SCONST	= 1<<5,
	T_OFFSET2	= 1<<6,
	T_GOTYPE	= 1<<7,

	REGARG		= -1,
	REGRET		= D_AX,
	FREGRET		= D_F0,
	REGSP		= D_SP,
	REGTMP		= D_DI,
};

/*
 * this is the ranlib header
 */
#define	SYMDEF	"__.SYMDEF"

/*
 * this is the simulated IEEE floating point
 */
typedef	struct	ieee	Ieee;
struct	ieee
{
	long	l;	/* contains ls-man	0xffffffff */
	long	h;	/* contains sign	0x80000000
				    exp		0x7ff00000
				    ms-man	0x000fffff */
};
