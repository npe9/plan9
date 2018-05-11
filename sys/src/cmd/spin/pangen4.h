/***** spin: pangen4.h *****/

/*
 * This file is part of the public release of Spin. It is subject to the
 * terms in the LICENSE file that is included in this source directory.
 * Tool documentation is available at http://spinroot.com
 *
 * The DFA code below was written by Anuj Puri and Gerard J. Holzmann in
 * May 1997, and was inspired by earlier work on data compression using
 * sharing tree data structures and graph-encoded sets by J-Ch. Gregoire
 * (INRS Telecom, Quebec, Canada) and D.Zampunieris (Univ.Namur, Belgium)
 * The splay routine code included here is based on the public domain
 * version written by D. Sleator <sleator@cs.cmu.edu> in 1992.
 */

static const char *Dfa[] = {
	"#ifdef MA",
#if 0
	"/*",
	"#include <stdio.h>",
	"#define uchar	unsigned char",
	"*/",
	"#define ulong	unsigned long",
	"#define ushort	unsigned short",
	"",
#endif
	"#define TWIDTH		256",
	"#define HASH(y,n)	(n)*(((long)y))",
	"#define INRANGE(e,h)	((h>=e->From && h<=e->To)||(e->s==1 && e->S==h))",
	"",
	"extern char	*emalloc(unsigned long);	/* imported routine  */",
	"extern void	dfa_init(ushort);	/* 4 exported routines */",
	"extern int	dfa_member(ulong);",
	"extern int	dfa_store(uchar *);",
	"extern void	dfa_stats(void);",
	"",
	"typedef struct Edge {",
	"	uchar From, To;		/* max range 0..255 */",
	"	uchar s, S;		/* if s=1, S is singleton */",
	"	struct Vertex	*Dst;",
	"	struct Edge	*Nxt;",
	"} Edge;",
	"",
	"typedef struct Vertex {",
	"	ulong	key, num;	/* key for splay tree, nr incoming edges */",
	"	uchar	from[2], to[2];	/* in-node predefined edge info    */",
	"	struct	Vertex	*dst[2];/* most nodes have 2 or more edges */",
	"	struct	Edge	*Succ;	/* in case there are more edges */",
	"	struct	Vertex	*lnk, *left, *right; /* splay tree plumbing */",
	"} Vertex;",
	"",
	"static Edge	*free_edges;",
	"static Vertex	*free_vertices;",
	"static Vertex	**layers;	/* one splay tree of nodes per layer */",
	"static Vertex	**path;		/* run of word in the DFA */",
	"static Vertex	*R, *F, *NF;	/* Root, Final, Not-Final */",
	"static uchar	*word, *lastword;/* string, and last string inserted */",
	"static int	dfa_depth, iv=0, nv=0, pfrst=0, Tally;",
	"",
	"static void	insert_it(Vertex *, int);	/* splay-tree code */",
	"static void	delete_it(Vertex *, int);",
	"static Vertex	*find_it(Vertex *, Vertex *, uchar, int);",
	"",
	"static void",
	"recyc_edges(Edge *e)",
	"{",
	"	if (!e) return;",
	"	recyc_edges(e->Nxt);",
	"	e->Nxt = free_edges;",
	"	free_edges = e;",
	"}",
	"",
	"static Edge *",
	"new_edge(Vertex *dst)",
	"{	Edge *e;",
	"",
	"	if (free_edges)",
	"	{	e = free_edges;",
	"		free_edges = e->Nxt;",
	"		e->From = e->To = e->s = e->S = 0;",
	"		e->Nxt = (Edge *) 0;",
	"	} else",
	"		e = (Edge *) emalloc(sizeof(Edge));",
	"	e->Dst = dst;",
	"",
	"	return e;",
	"}",
	"",
	"static void",
	"recyc_vertex(Vertex *v)",
	"{",
	"	recyc_edges(v->Succ);",
	"	v->Succ = (Edge *) free_vertices;",
	"	free_vertices = v;",
	"	nr_states--;",
	"}",
	"",
	"static Vertex *",
	"new_vertex(void)",
	"{	Vertex *v;",
	"",
	"	if (free_vertices)",
	"	{	v = free_vertices;",
	"		free_vertices = (Vertex *) v->Succ;",
	"		v->Succ = (Edge *) 0;",
	"		v->num  = 0;",
	"	} else",
	"		v = (Vertex *) emalloc(sizeof(Vertex));",
	"",
	"	nr_states++;",
	"	return v; ",
	"}",
	"",
	"static Vertex *",
	"allDelta(Vertex *v, int n)",
	"{	Vertex *dst = new_vertex();",
	"",
	"	v->from[0] = 0;",
	"	v->to[0] = 255;",
	"	v->dst[0] = dst;",
	"	dst->num = 256;",
	"	insert_it(v, n);",
	"	return dst;",
	"}",
	"",
	"static void",
	"insert_edge(Vertex *v, Edge *e)",
	"{	/* put new edge first */",
	"	if (!v->dst[0])",
	"	{	v->dst[0] = e->Dst;",
	"		v->from[0] = e->From;",
	"		v->to[0] = e->To;",
	"		recyc_edges(e);",
	"		return;",
	"	}",
	"	if (!v->dst[1])",
	"	{	v->from[1] = v->from[0]; v->from[0] = e->From;",
	"		v->to[1]   = v->to[0];   v->to[0]   = e->To;",
	"		v->dst[1]  = v->dst[0];  v->dst[0]  = e->Dst;",
	"		recyc_edges(e);",
	"		return;",
	"	} /* shift */",
	"	{	int f      = v->from[1];",
	"		int t      = v->to[1];",
	"		Vertex *d  = v->dst[1];",
	"		v->from[1] = v->from[0]; v->from[0] = e->From;",
	"		v->to[1]   = v->to[0];   v->to[0]   = e->To;",
	"		v->dst[1]  = v->dst[0];  v->dst[0]  = e->Dst;",
	"		e->From = f;",
	"		e->To   = t;",
	"		e->Dst  = d;",
	"	}",
	"	e->Nxt = v->Succ;",
	"	v->Succ = e;",
	"}",
	"",
	"static void",
	"copyRecursive(Vertex *v, Edge *e)",
	"{	Edge *f;",
	"	if (e->Nxt) copyRecursive(v, e->Nxt);",
	"	f = new_edge(e->Dst);",
	"	f->From = e->From;",
	"	f->To   = e->To;",
	"	f->s    = e->s;",
	"	f->S    = e->S;",
	"	f->Nxt  = v->Succ;",
	"	v->Succ = f;",
	"}",
	"",
	"static void",
	"copyEdges(Vertex *to, Vertex *from)",
	"{	int i;",
	"	for (i = 0; i < 2; i++)",
	"	{	to->from[i] = from->from[i];",
	"		to->to[i]   = from->to[i];",
	"		to->dst[i]  = from->dst[i];",
	"	}",
	"	if (from->Succ) copyRecursive(to, from->Succ);",
	"}",
	"",
	"static Edge *",
	"cacheDelta(Vertex *v, int h, int first)",
	"{	static Edge *ov, tmp;  int i;",
	"",
	"	if (!first && INRANGE(ov,h))",
	"		return ov; /* intercepts about 10%% */",
	"	for (i = 0; i < 2; i++)",
	"		if (v->dst[i] && h >= v->from[i] && h <= v->to[i])",
	"		{	tmp.From = v->from[i];",
	"			tmp.To   = v->to[i];",
	"			tmp.Dst  = v->dst[i];",
	"			tmp.s    =  tmp.S = 0;",
	"			ov = &tmp;",
	"			return ov;",
	"		}",
	"	for (ov = v->Succ; ov; ov = ov->Nxt)",
	"		if (INRANGE(ov,h)) return ov;",
	"",
	"	Uerror(\"cannot get here, cacheDelta\");",
	"	return (Edge *) 0;",
	"}",
	"",
	"static Vertex *",
	"Delta(Vertex *v, int h)	/* v->delta[h] */",
	"{	Edge *e;",
	"",
	"	if (v->dst[0] && h >= v->from[0] && h <= v->to[0])",
	"		return v->dst[0];	/* oldest edge */",
	"	if (v->dst[1] && h >= v->from[1] && h <= v->to[1])",
	"		return v->dst[1];",
	"	for (e = v->Succ; e; e = e->Nxt)",
	"		if (INRANGE(e,h))",
	"			return e->Dst;",
	"	Uerror(\"cannot happen Delta\");",
	"	return (Vertex *) 0;",
	"}",
	"",
	"static void",
	"numDelta(Vertex *v, int d)",
	"{	Edge *e;",
	"	ulong cnt;",
	"	int i;",
	"",
	"	for (i = 0; i < 2; i++)",
	"	if (v->dst[i])",
	"	{	cnt = v->dst[i]->num + d*(1 + v->to[i] - v->from[i]);",
	"		if (d == 1 && cnt < v->dst[i]->num) goto bad;",
	"		v->dst[i]->num = cnt;",
	"	}",
	"	for (e = v->Succ; e; e = e->Nxt)",
	"	{	cnt = e->Dst->num + d*(1 + e->To - e->From + e->s);",
	"		if (d == 1 && cnt < e->Dst->num)",
	"bad:			Uerror(\"too many incoming edges\");",
	"		e->Dst->num = cnt;",
	"	}",
	"}",
	"",
	"static void",
	"setDelta(Vertex *v, int h, Vertex *newdst)	/* v->delta[h] = newdst; */",
	"{	Edge *e, *f = (Edge *) 0, *g;",
	"	int i;",
	"",
	"	/* remove the old entry, if there */",
	"	for (i = 0; i < 2; i++)",
	"		if (v->dst[i] && h >= v->from[i] && h <= v->to[i])",
	"		{	if (h == v->from[i])",
	"			{	if (h == v->to[i])",
	"				{	v->dst[i] = (Vertex *) 0;",
	"					v->from[i] = v->to[i] = 0;",
	"				} else",
	"					v->from[i]++;",
	"			} else if (h == v->to[i])",
	"			{	v->to[i]--;",
	"			} else",
	"			{	g = new_edge(v->dst[i]);/* same dst */",
	"				g->From    = v->from[i];",
	"				g->To      = h-1;	/* left half */",
	"				v->from[i] = h+1;	/* right half */",
	"				insert_edge(v, g);",
	"			}",
	"			goto part2;",
	"		}",
	"	for (e = v->Succ; e; f = e, e = e->Nxt)",
	"	{	if (e->s == 1 && e->S == h)",
	"		{	e->s = e->S = 0;",
	"			goto rem_tst;",
	"		}",
	"		if (h >= e->From && h <= e->To)",
	"		{	if (h == e->From)",
	"			{	if (h == e->To)",
	"				{	if (e->s)",
	"					{	e->From = e->To = e->S;",
	"						e->s = 0;",
	"						break;",
	"					} else",
	"						goto rem_do;",
	"				} else",
	"					e->From++;",
	"			} else if (h == e->To)",
	"			{	e->To--;",
	"			} else				/* split */",
	"			{	g = new_edge(e->Dst);	/* same dst */",
	"				g->From = e->From;",
	"				g->To   = h-1;		/* g=left half */",
	"				e->From = h+1;		/* e=right half */",
	"				g->Nxt  = e->Nxt;	/* insert g */",
	"				e->Nxt  = g;		/* behind e */",
	"				break;			/* done */",
	"			}",
	"",
	"rem_tst:		if (e->From > e->To)",
	"			{	if (e->s == 0) {",
	"rem_do:				if (f)",
	"						f->Nxt = e->Nxt;",
	"					else",
	"						v->Succ = e->Nxt;",
	"					e->Nxt = (Edge *) 0;",
	"					recyc_edges(e);",
	"				} else",
	"				{	e->From = e->To = e->S;",
	"					e->s = 0;",
	"			}	}",
	"			break;",
	"	}	}",
	"part2:",
	"	/* check if newdst is already there */",
	"	for (i = 0; i < 2; i++)",
	"		if (v->dst[i] == newdst)",
	"		{	if (h+1 == (int) v->from[i])",
	"			{	v->from[i] = h;",
	"				return;",
	"			}",
	"			if (h == (int) v->to[i]+1)",
	"			{	v->to[i] = h;",
	"				return;",
	"		}	}",
	"	for (e = v->Succ; e; e = e->Nxt)",
	"	{	if (e->Dst == newdst)",
	"		{	if (h+1 == (int) e->From)",
	"			{	e->From = h;",
	"				if (e->s == 1 && e->S+1 == e->From)",
	"				{	e->From = e->S;",
	"					e->s = e->S = 0;",
	"				}",
	"				return;",
	"			}",
	"			if (h == (int) e->To+1)",
	"			{	e->To = h;",
	"				if (e->s == 1 && e->S == e->To+1)",
	"				{	e->To = e->S;",
	"					e->s = e->S = 0;",
	"				}",
	"				return;",
	"			}",
	"			if (e->s == 0)",
	"			{	e->s = 1;",
	"				e->S = h;",
	"				return;",
	"	}	}	}",
	"	/* add as a new edge */",
	"	e = new_edge(newdst);",
	"	e->From = e->To = h;",
	"	insert_edge(v, e);",
	"}",
	"",
	"static ulong",
	"cheap_key(Vertex *v)",
	"{	ulong vk2 = 0;",
	"",
	"	if (v->dst[0])",
	"	{	vk2 = (ulong) v->dst[0];",
	"		if ((ulong) v->dst[1] > vk2)",
	"			vk2 = (ulong) v->dst[1];",
	"	} else if (v->dst[1])",
	"		vk2 = (ulong) v->dst[1]; ",
	"	if (v->Succ)",
	"	{	Edge *e;",
	"		for (e = v->Succ; e; e = e->Nxt)",
	"			if ((ulong) e->Dst > vk2)",
	"				vk2 = (ulong) e->Dst;",
	"	}",
	"	Tally = (vk2>>2)&(TWIDTH-1);",
	"	return v->key;",
	"}",
	"",
	"static ulong",
	"mk_key(Vertex *v)	/* not sensitive to order */",
	"{	ulong m = 0, vk2 = 0;",
	"	Edge *e;",
	"",
	"	if (v->dst[0])",
	"	{	m += HASH(v->dst[0], v->to[0] - v->from[0] + 1);",
	"		vk2 = (ulong) v->dst[0]; ",
	"	}",
	"	if (v->dst[1])",
	"	{	m += HASH(v->dst[1], v->to[1] - v->from[1] + 1);",
	"		if ((ulong) v->dst[1] > vk2) vk2 = (ulong) v->dst[1]; ",
	"	}",
	"	for (e = v->Succ; e; e = e->Nxt)",
	"	{	m += HASH(e->Dst, e->To - e->From + 1 + e->s);",
	"		if ((ulong) e->Dst > vk2) vk2 = (ulong) e->Dst; ",
	"	}",
	"	Tally = (vk2>>2)&(TWIDTH-1);",
	"	return m;",
	"}",
	"",
	"static ulong",
	"mk_special(int sigma, Vertex *n, Vertex *v)",
	"{	ulong m = 0, vk2 = 0;",
	"	Edge *f;",
	"	int i;",
	"",
	"	for (i = 0; i < 2; i++)",
	"		if (v->dst[i])",
	"		{	if (sigma >= v->from[i] && sigma <= v->to[i])",
	"			{	m += HASH(v->dst[i], v->to[i]-v->from[i]);",
	"				if ((ulong) v->dst[i] > vk2",
	"				&&   v->to[i] > v->from[i])",
	"					vk2 = (ulong) v->dst[i]; ",
	"			} else",
	"			{	m += HASH(v->dst[i], v->to[i]-v->from[i]+1);",
	"				if ((ulong) v->dst[i] > vk2)",
	"					vk2 = (ulong) v->dst[i]; ",
	"		}	}",
	"	for (f = v->Succ; f; f = f->Nxt)",
	"	{	if (sigma >= f->From && sigma <= f->To)",
	"		{	m += HASH(f->Dst, f->To - f->From + f->s);",
	"			if ((ulong) f->Dst > vk2",
	"			&&   f->To - f->From + f->s > 0)",
	"				vk2 = (ulong) f->Dst; ",
	"		} else if (f->s == 1 && sigma == f->S)",
	"		{	m += HASH(f->Dst, f->To - f->From + 1);",
	"			if ((ulong) f->Dst > vk2) vk2 = (ulong) f->Dst; ",
	"		} else",
	"		{	m += HASH(f->Dst, f->To - f->From + 1 + f->s);",
	"			if ((ulong) f->Dst > vk2) vk2 = (ulong) f->Dst; ",
	"	}	}",
	"",
	"	if ((ulong) n > vk2) vk2 = (ulong) n; ",
	"	Tally = (vk2>>2)&(TWIDTH-1);",
	"	m += HASH(n, 1);",
	"	return m;",
	"}",
	"",
	"void ",
	"dfa_init(ushort nr_layers)",
	"{	int i; Vertex *r, *t;",
	"",
	"	dfa_depth = nr_layers;	/* one byte per layer */",
	"	path   = (Vertex **) emalloc((dfa_depth+1)*sizeof(Vertex *));",
	"	layers = (Vertex **) emalloc(TWIDTH*(dfa_depth+1)*sizeof(Vertex *));",
	"	lastword = (uchar *) emalloc((dfa_depth+1)*sizeof(uchar));",
	"	lastword[dfa_depth] = lastword[0] = 255;",
	"	path[0] = R = new_vertex(); F = new_vertex();",
	"",
	"	for (i = 1, r = R; i < dfa_depth; i++, r = t)",
	"		t = allDelta(r, i-1);",
	"	NF = allDelta(r, i-1);",
	"}",
	"",
	"#if 0",
	"static void complement_dfa(void) { Vertex *tmp = F; F = NF; NF = tmp; }",
	"#endif",
	"",
	"double",
	"tree_stats(Vertex *t)",
	"{	Edge *e; double cnt=0.0;",
	"	if (!t) return 0;",
	"	if (!t->key) return 0;",
	"	t->key = 0; /* precaution */",
	"	if (t->dst[0]) cnt++;",
	"	if (t->dst[1]) cnt++;",
	"	for (e = t->Succ; e; e = e->Nxt)",
	"		cnt++;",
	"	cnt += tree_stats(t->lnk);",
	"	cnt += tree_stats(t->left);",
	"	cnt += tree_stats(t->right);",
	"	return cnt;",
	"}",
	"",
	"void",
	"dfa_stats(void)",
	"{	int i, j; double cnt = 0.0;",
	"	for (j = 0; j < TWIDTH; j++)",
	"	for (i = 0; i < dfa_depth+1; i++)",
	"		cnt += tree_stats(layers[i*TWIDTH+j]);",
	"	printf(\"Minimized Automaton:\t%%6lu nodes and %%6g edges\\n\",",
	"		nr_states, cnt);",
	"}",
	"",
	"int",
	"dfa_member(ulong n)",
	"{	Vertex **p, **q;",
	"	uchar *w = &word[n];",
	"	int i;",
	"",
	"	p = &path[n]; q = (p+1);",
	"	for (i = n; i < dfa_depth; i++)",
	"		*q++ = Delta(*p++, *w++);",
	"	return (*p == F);",
	"}",
	"",
	"int",
	"dfa_store(uchar *sv)",
	"{	Vertex **p, **q, *s, *y, *old, *new = F;",
	"	uchar *w, *u = lastword;",
	"	int i, j, k;",
	"",
	"	w = word = sv;",
	"	while (*w++ == *u++)	/* find first byte that differs */",
	"		;",
	"	pfrst = (int) (u - lastword) - 1;",
	"	memcpy(&lastword[pfrst], &sv[pfrst], dfa_depth-pfrst);",
	"	if (pfrst > iv) pfrst = iv;",
	"	if (pfrst > nv) pfrst = nv;",
	"/* phase1: */",
	"	p = &path[pfrst]; q = (p+1); w = &word[pfrst];",
	"	for (i = pfrst; i < dfa_depth; i++)",
	"		*q++ = Delta(*p++, *w++);	/* (*p)->delta[*w++]; */",
	"",
	"	if (*p == F) return 1;	/* it's already there */",
	"/* phase2: */",
	"	iv = dfa_depth;",
	"	do {	iv--;",
	"		old = new;",
	"		new = find_it(path[iv], old, word[iv], iv);",
	"	} while (new && iv > 0);",
	"",
	"/* phase3: */",
	"	nv = k = 0; s = path[0];",
	"	for (j = 1; j <= iv; ++j) ",
	"		if (path[j]->num > 1)",
	"		{	y = new_vertex();",
	"			copyEdges(y, path[j]);",
	"			insert_it(y, j);",
	"			numDelta(y, 1);",
	"			delete_it(s, j-1);",
	"			setDelta(s, word[j-1], y);",
	"			insert_it(s, j-1);",
	"			y->num = 1;	/* initial value 1 */",
	"			s = y;",
	"			path[j]->num--;	/* only 1 moved from j to y */",
	"			k = 1;",
	"		} else",
	"		{	s = path[j];",
	"			if (!k) nv = j;",
	"		}",
	"	y = Delta(s, word[iv]);",
	"	y->num--;",
	"	delete_it(s, iv); ",
	"	setDelta(s, word[iv], old);",
	"	insert_it(s, iv); ",
	"	old->num++;",
	"",
	"	for (j = iv+1; j < dfa_depth; j++)",
	"		if (path[j]->num == 0)",
	"		{	numDelta(path[j], -1);",
	"			delete_it(path[j], j);",
	"			recyc_vertex(path[j]);",
	"		} else",
	"			break;",
	"	return 0;",
	"}",
	"",
	"static Vertex *",
	"splay(ulong i, Vertex *t)",
	"{	Vertex N, *l, *r, *y;",
	"",
	"	if (!t) return t;",
	"	N.left = N.right = (Vertex *) 0;",
	"	l = r = &N;",
	"	for (;;)",
	"	{	if (i < t->key)",
	"		{	if (!t->left) break;",
	"			if (i < t->left->key)",
	"			{	y = t->left;",
	"				t->left = y->right;",
	"				y->right = t;",
	"				t = y;",
	"				if (!t->left) break;",
	"			}",
	"			r->left = t;",
	"			r = t;",
	"			t = t->left;",
	"		} else if (i > t->key)",
	"		{	if (!t->right) break;",
	"			if (i > t->right->key)",
	"			{	y = t->right;",
	"				t->right = y->left;",
	"				y->left = t;",
	"				t = y;",
	"				if (!t->right) break;",
	"			}",
	"			l->right = t;",
	"			l = t;",
	"			t = t->right;",
	"		} else",
	"			break;",
	"	}",
	"	l->right = t->left;",
	"	r->left = t->right;",
	"	t->left = N.right;",
	"	t->right = N.left;",
	"	return t;",
	"}",
	"",
	"static void",
	"insert_it(Vertex *v, int L)",
	"{	Vertex *new, *t;",
	"	ulong i; int nr;",
	"",
	"	i = mk_key(v);",
	"	nr = ((L*TWIDTH)+Tally);",
	"	t = layers[nr];",
	"",
	"	v->key = i; ",
	"	if (!t)",
	"	{	layers[nr] = v;",
	"		return;",
	"	}",
	"	t = splay(i, t);",
	"	if (i < t->key)",
	"	{	new = v;",
	"		new->left = t->left;",
	"		new->right = t;",
	"		t->left = (Vertex *) 0;",
	"	} else if (i > t->key)",
	"	{	new = v;",
	"		new->right = t->right;",
	"		new->left = t;",
	"		t->right = (Vertex *) 0;",
	"	} else	 /* it's already there */",
	"	{	v->lnk = t->lnk; /* put in linked list off v */",
	"		t->lnk = v;",
	"		new = t;",
	"	}",
	"	layers[nr] = new;",
	"}",
	"",
	"static int",
	"checkit(Vertex *h, Vertex *v, Vertex *n, uchar sigma)",
	"{	Edge *g, *f;",
	"	int i, k, j = 1;",
	"",
	"	for (k = 0; k < 2; k++)",
	"		if (h->dst[k])",
	"		{	if (sigma >= h->from[k] && sigma <= h->to[k])",
	"			{	if (h->dst[k] != n) goto no_match;",
	"			}",
	"			for (i = h->from[k]; i <= h->to[k]; i++)",
	"			{	if (i == sigma) continue;",
	"				g = cacheDelta(v, i, j); j = 0;",
	"				if (h->dst[k] != g->Dst)",
	"					goto no_match;",
	"				if (g->s == 0 || g->S != i)",
	"					i = g->To;",
	"		}	}",
	"	for (f = h->Succ; f; f = f->Nxt)",
	"	{	if (INRANGE(f,sigma))",
	"		{	if (f->Dst != n) goto no_match;",
	"		}",
	"		for (i = f->From; i <= f->To; i++)",
	"		{	if (i == sigma) continue;",
	"			g = cacheDelta(v, i, j); j = 0;",
	"			if (f->Dst != g->Dst)",
	"				goto no_match;",
	"			if (g->s == 1 && i == g->S)",
	"				continue;",
	"			i = g->To;",
	"		}",
	"		if (f->s && f->S != sigma)",
	"		{	g = cacheDelta(v, f->S, 1);",
	"			if (f->Dst != g->Dst)",
	"				goto no_match;",
	"		}",
	"	}",
	"	if (h->Succ || h->dst[0] || h->dst[1]) return 1;",
	"no_match:",
	"	return 0;",
	"}",
	"",
	"static Vertex *",
	"find_it(Vertex *v, Vertex *n, uchar sigma, int L)",
	"{	Vertex *z, *t;",
	"	ulong i; int nr;",
	"",
	"	i = mk_special(sigma,n,v);",
	"	nr = ((L*TWIDTH)+Tally);",
	"	t = layers[nr];",
	"",
	"	if (!t) return (Vertex *) 0;",
	"	layers[nr] = t = splay(i, t);",
	"	if (i == t->key)",
	"	for (z = t; z; z = z->lnk)",
	"		if (checkit(z, v, n, sigma))",
	"			return z;",
	"",
	"	return (Vertex *) 0;",
	"}",
	"",
	"static void",
	"delete_it(Vertex *v, int L)",
	"{	Vertex *x, *t;",
	"	ulong i; int nr;",
	"",
	"	i = cheap_key(v);",
	"	nr = ((L*TWIDTH)+Tally);",
	"	t = layers[nr];",
	"	if (!t) return;",
	"",
	"	t = splay(i, t);",
	"	if (i == t->key)",
	"	{	Vertex *z, *y = (Vertex *) 0;",
	"		for (z = t; z && z != v; y = z, z = z->lnk)",
	"			;",
	"		if (z != v) goto bad;",
	"		if (y)",
	"		{	y->lnk = z->lnk;",
	"			z->lnk = (Vertex *) 0;",
	"			layers[nr] = t;",
	"			return;",
	"		} else if (z->lnk)	/* z == t == v */",
	"		{	y = z->lnk;",
	"			y->left = t->left;",
	"			y->right = t->right;",
	"			t->left = t->right = t->lnk = (Vertex *) 0;",
	"			layers[nr] = y;",
	"			return;",
	"		}",
	"		/* delete the node itself */",
	"		if (!t->left)",
	"		{	x = t->right;",
	"		} else",
	"		{	x = splay(i, t->left);",
	"			x->right = t->right;",
	"		}",
	"		t->left = t->right = t->lnk = (Vertex *) 0;",
	"		layers[nr] = x;",
	"		return;",
	"	}",
	"bad:	Uerror(\"cannot happen delete\");",
	"}",
	"#endif", /* MA */
	0,
};
