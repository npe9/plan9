long tabatari[256] =	/* from jhelling@cs.ruu.nl (Jeroen Hellingman) */
{
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x3f,
0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,
0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5a,0x5b,0x5c,0x5d,0x5e,0x5f,
0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7a,0x7b,0x7c,0x7d,0x7e,0x7f,
0x00c7, 0x00fc, 0x00e9, 0x00e2, 0x00e4, 0x00e0, 0x00e5, 0x00e7, /* accented latin */
0x00ea, 0x00eb, 0x00e8, 0x00ef, 0x00ee, 0x00ec, 0x00c4, 0x00c5,
0x00c9, 0x00e6, 0x00c6, 0x00f4, 0x00f6, 0x00f2, 0x00fb, 0x00f9,
0x00ff, 0x00d6, 0x00dc, 0x00a2, 0x00a3, 0x00a5, 0x00df, 0x0192,
0x00e1, 0x00ed, 0x00f3, 0x00fa, 0x00f1, 0x00d1, 0x00aa, 0x00ba,
0x00bf, 0x2310, 0x00ac, 0x00bd, 0x00bc, 0x00a1, 0x00ab, 0x00bb,
0x00e3, 0x00f5, 0x00d8, 0x00f8, 0x0153, 0x0152, 0x00c0, 0x00c3,
0x00d5, 0x00a8, 0x00b4, 0x2020, 0x00b6, 0x00a9, 0x00ae, 0x2122,
0x0133, 0x0132, 
                0x05d0, 0x05d1, 0x05d2, 0x05d3, 0x05d4, 0x05d5, /* hebrew */
0x05d6, 0x05d7, 0x05d8, 0x05d9, 0x05db, 0x05dc, 0x05de, 0x05e0,
0x05e1, 0x05e2, 0x05e4, 0x05e6, 0x05e7, 0x05e8, 0x05e9, 0x05ea,
0x05df, 0x05da, 0x05dd, 0x05e3, 0x05e5, 
                                        0x00a7, 0x2038, 0x221e, /* math */
0x03b1, 0x03b2, 0x0393, 0x03c0, 0x03a3, 0x03c3, 0x00b5, 0x03c4, /* greek */
0x03a6, 0x03b8, 0x2126, 0x03b4, 
                                0x222e, 0x03c6, 0x2208, 0x220f, /* math */
0x2261, 0x00b1, 0x2265, 0x2264, 0x2320, 0x2321, 0x00f7, 0x2248,
0x00b0, 0x2022, 0x00b7, 0x221a, 0x207f, 0x00b2, 0x00b3, 0x00af,
};
long tabebcdic[256] =	/* from jhelling@cs.ruu.nl (Jeroen Hellingman) */
{
0x00, 0x01, 0x02, 0x03, -1,   0x09, -1,   0x7f,
-1,   -1,   -1,   0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
0x10, 0x11, 0x12, 0x13, -1,   -1,   0x08, -1,
0x18, 0x09, -1,   -1,   0x1c, 0x1d, 0x1e, 0x1f,
-1,   -1,   -1,   -1,   -1,   0x0a, 0x17, 0x1b,
-1,   -1,   -1,   -1,   -1,   0x05, 0x06, 0x07,
-1,   -1,   0x16, -1,   -1,   -1,   -1,   0x04,
-1,   -1,   -1,   -1,   0x14, 0x15, -1,   0x1a,
0x20, -1,   -1,   -1,   -1,   -1,   -1,   -1,
-1,   -1,   0x5b, 0x2e, 0x3c, 0x28, 0x2b, 0x21,
0x26, -1,   -1,   -1,   -1,   -1,   -1,   -1,
-1,   -1,   0x5d, 0x24, 0x2a, 0x29, 0x3b, 0x5e, /* not-sign 0xac -> circumflex 0x5e */
0x2d, 0x2f, -1,   -1,   -1,   -1,   -1,   -1,
-1,   -1,   0x7c, 0x2c, 0x25, 0x5f, 0x3e, 0x3f,
-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
-1,   0x60, 0x3a, 0x23, 0x40, 0x27, 0x3d, 0x22,
-1,   0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
0x68, 0x69, -1,   -1,   -1,   -1,   -1,   -1,
-1,   0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70,
0x71, 0x72, -1,   -1,   -1,   -1,   -1,   -1,
-1,   0x7e, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, /* non-spacing macron 0xaf -> tilde 0x7e */
0x79, 0x7a, -1,   -1,   -1,   -1,   -1,   -1,
-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
0x7b, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
0x48, 0x49, -1,   -1,   -1,   -1,   -1,   -1,
0x7d, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50,
0x51, 0x52, -1,   -1,   -1,   -1,   -1,   -1,
0x5c, -1,   0x53, 0x54, 0x55, 0x56, 0x57, 0x58,
0x59, 0x5a, -1,   -1,   -1,   -1,   -1,   -1,
0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
0x38, 0x39, -1,   -1,   -1,   -1,   -1,   -1,
};
long tabmacroman[256] =	/* (modified via world.std.com!choupt) from mduerst@ifi.unizh.ch (Martin J. Du"rst) */
{
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x3f,
0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,
0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5a,0x5b,0x5c,0x5d,0x5e,0x5f,
0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7a,0x7b,0x7c,0x7d,0x7e,0x7f,
0x00c4,0x00c5,0x00c7,0x00c9,0x00d1,0x00d6,0x00dc,0x00e1,
0x00e0,0x00e2,0x00e4,0x00e3,0x00e5,0x00e7,0x00e9,0x00e8,
0x00ea,0x00eb,0x00ed,0x00ec,0x00ee,0x00ef,0x00f1,0x00f3,
0x00f2,0x00f4,0x00f6,0x00f5,0x00fa,0x00f9,0x00fb,0x00fc,
0x2020,0x00b0,0x00a2,0x00a3,0x00a7,0x2022,0x00b6,0x00df,
0x00ae,0x00a9,0x2122,0x00b4,0x00a8,0x2260,0x00c6,0x00d8,
0x221e,0x00b1,0x2264,0x2265,0x00a5,0x00b5,0x2202,0x2211,
0x220f,0x03c0,0x222b,0x00aa,0x00ba,0x2126,0x00e6,0x00f8,
0x00bf,0x00a1,0x00ac,0x221a,0x0192,0x2248,0x2206,0x00ab,
0x00bb,0x2026,0x00a0,0x00c0,0x00c3,0x00d5,0x0152,0x0153,
0x2013,0x2014,0x2012,0x201d,0x2018,0x2019,0x00f7,0x25ca, /*2013 en dash suggested by Glenn A. Adams*/
0x00ff,0x0178,0x2044,0x00a4,0x2039,0x203a,0xfb01,0xfb02,
0x2021,0x00b7,0x201a,0x201e,0x2030,0x00c2,0x00ca,0x00c1,
0x00cb,0x00c8,0x00cd,0x00ce,0x00cf,0x00cc,0x00d3,0x00d4,
0xf7ff,0x00d2,0x00da,0x00db,0x00d9,0x0131,0x02c6,0x02dc,
0x00af,0x02d8,0x02d9,0x02da,0x00b8,0x02dd,0x02db,0x02c7,
};
long tabnextstep[256] = 	/* From mduerst@ifi.unizh.ch (Martin J. Du"rst) */
/* From NEXTSTEP Encoding Vector / Character Code Palette */
/* quote (0027) and quoteright (2019) should be exchanged */
/*	if visual form is considered exactly; left as is */
/*	for compatibility with other low-end systems */
{
0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
0x2007, 0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C7,
0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
0x00D0, 0x00D1, 0x00D2, 0x00D3, 0x00D4, 0x00D5, 0x00D6, 0x00D9,
0x00DA, 0x00DB, 0x00DC, 0x00DD, 0x00DE, 0x00B5, 0x00D7, 0x00F7,
0x00A9, 0x00A1, 0x00A2, 0x00A3, 0x2044, 0x00A5, 0x0192, 0x00A7,
0x00A4, 0x2019, 0x201C, 0x00AB, 0x2039, 0x2040, 0xFB01, 0xFB02,
0x00AE, 0x2013, 0x2020, 0x2021, 0x00B7, 0x254E, 0x00B6, 0x2022,
0x201A, 0x201E, 0x201D, 0x00BB, 0x2026, 0x2030, 0x00AC, 0x00BF,
0x00B9, 0x0300, 0x0301, 0x0302, 0x0303, 0x0304, 0x0306, 0x0307,
0x0308, 0x00B2, 0x030A, 0x0327, 0x00B3, 0x030B, 0x0328, 0x030C,
0x2014, 0x00B1, 0x00BC, 0x00BD, 0x00BE, 0x00E0, 0x00E1, 0x00E2,
0x00E3, 0x00E4, 0x00E5, 0x00E7, 0x00E8, 0x00E9, 0x00EA, 0x00EB,
0x00EC, 0x00C6, 0x00ED, 0x00AA, 0x00EE, 0x00EF, 0x00F0, 0x00F1,
0x0141, 0x00D8, 0x0152, 0x00BA, 0x00F2, 0x00F3, 0x00F4, 0x00F5,
0x00F6, 0x00E6, 0x00F9, 0x00FA, 0x00FB, 0x0131, 0x00FC, 0x00FD,
0x0142, 0x00F8, 0x0153, 0x00DF, 0x00FE, 0x00FF, 0xFFFF, 0xFFFF
};
long tabps2[256] =	/* from jhelling@cs.ruu.nl (Jeroen Hellingman) */
{
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x3f,
0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,
0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5a,0x5b,0x5c,0x5d,0x5e,0x5f,
0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7a,0x7b,0x7c,0x7d,0x7e,0x7f,
0x00c7, 0x00fc, 0x00e9, 0x00e2, 0x00e4, 0x00e0, 0x00e5, 0x00e7, /* latin-1 repertoire with forms */
0x00ea, 0x00eb, 0x00e8, 0x00ef, 0x00ee, 0x00ec, 0x00c4, 0x00c5,
0x00c9, 0x00e6, 0x00c6, 0x00f4, 0x00f6, 0x00f2, 0x00fb, 0x00f9,
0x00ff, 0x00d6, 0x00dc, 0x00f8, 0x00a3, 0x00d8, 0x00d7, 0x0192,
0x00e1, 0x00ed, 0x00f3, 0x00fa, 0x00f1, 0x00d1, 0x00aa, 0x00ba,
0x00bf, 0x00ae, 0x00ac, 0x00bd, 0x00bc, 0x00a1, 0x00ab, 0x00bb,
0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x00c1, 0x00c2, 0x00c0,
0x00a9, 0x2563, 0x2551, 0x2557, 0x255d, 0x00a2, 0x00a5, 0x2510,
0x2514, 0x2534, 0x252c, 0x251c, 0x2500, 0x253c, 0x00e3, 0x00c3,
0x255a, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256c, 0x00a4,
0x00f0, 0x00d0, 0x00ca, 0x00cb, 0x00c8, 0x0131, 0x00cd, 0x00ce, 
0x00cf, 0x2518, 0x250c, 0x2588, 0x2584, 0x00a6, 0x00cc, 0x2580,
0x00d3, 0x00df, 0x00d4, 0x00d2, 0x00f5, 0x00d5, 0x00b5, 0x00fe,
0x00de, 0x00da, 0x00db, 0x00d9, 0x00fd, 0x00dd, 0x00af, 0x00b4,
0x00ad, 0x00b1, 0x2017, 0x00be, 0x00b6, 0x00a7, 0x00f7, 0x00b8,
0x00b0, 0x00a8, 0x00b7, 0x00b9, 0x00b3, 0x00b2, 0x220e, 0x00a0,
};
long tabsf1[256] =	/* From Kari.Hurtta@Helsinki.FI (Kari E. Hurtta) */
{
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x3f,
0xc9,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,
0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5a,0xc4,0xd6,0xc5,0xdc,0x5f,
0xe9,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7a,0xe4,0xf6,0xe5,0xfc,0x7f,
0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,
  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
};
long tabsf2[256] =	/* from wirzeniu@cc.helsinki.fi (Lars Wirzenius) */
{
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x3f,
0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,
0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5a,0xc4,0xd6,0xc5,0x5e,0x5f,
0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7a,0xe4,0xf6,0xe5,0x7e,0x7f,
0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,
  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
};
long tabtis620[256] =	/* from jhelling@cs.ruu.nl (Jeroen Hellingman) */
{
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x3f,
0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,
0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5a,0x5b,0x5c,0x5d,0x5e,0x5f,
0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7a,0x7b,0x7c,0x7d,0x7e,0x7f,
  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  -1,   0x0e01, 0x0e02, 0x0e03, 0x0e04, 0x0e05, 0x0e06, 0x0e07,
0x0e08, 0x0e09, 0x0e0a, 0x0e0b, 0x0e0c, 0x0e0d, 0x0e0e, 0x0e0f,
0x0e10, 0x0e11, 0x0e12, 0x0e13, 0x0e14, 0x0e15, 0x0e16, 0x0e17,
0x0e18, 0x0e19, 0x0e1a, 0x0e1b, 0x0e1c, 0x0e1d, 0x0e1e, 0x0e1f,
0x0e20, 0x0e21, 0x0e22, 0x0e23, 0x0e24, 0x0e25, 0x0e26, 0x0e27,
0x0e28, 0x0e29, 0x0e2a, 0x0e2b, 0x0e2c, 0x0e2d, 0x0e2e, 0x0e2f,
0x0e30, 0x0e31, 0x0e32, 0x0e33, 0x0e34, 0x0e35, 0x0e36, 0x0e37,
0x0e38, 0x0e39, 0x0e3a, -1,     -1,     -1,     -1,     0x0e3f,
0x0e40, 0x0e41, 0x0e42, 0x0e43, 0x0e44, 0x0e45, 0x0e46, 0x0e47,
0x0e48, 0x0e49, 0x0e4a, 0x0e4b, 0x0e4c, 0x0e4d, 0x0e4e, 0x0e4f,
0x0e50, 0x0e51, 0x0e52, 0x0e53, 0x0e54, 0x0e55, 0x0e56, 0x0e57,
0x0e58, 0x0e59, 0x0e5a, 0x0e5b, -1,     -1,     -1,     -1,
};
long tabviet1[256] =	/* From jdo@sjc.mentorg.com (James Do) */
{
    -1,   0xda, 0x1ee4,     -1, 0x1eea, 0x1eec, 0x1eee,    0x7,
    -1,     -1,    0xa,     -1,     -1,    0xc,     -1,     -1,
    -1, 0x1ee8, 0x1ef0, 0x1ef2, 0x1ef6, 0x1ef8,   0xdd, 0x1ef4,
    -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x3f,
0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,
0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5a,0x5b,0x5c,0x5d,0x5e,0x5f,
0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7a,0x7b,0x7c,0x7d,0x7e,0x7f,
  0xc0, 0x1ea2,   0xc3,   0xc1, 0x1ea0, 0x1eb6, 0x1eac,   0xc8,
0x1eba, 0x1ebc,   0xc9, 0x1eb8, 0x1ec6,   0xcc, 0x1ec8, 0x0128,
  0xcd, 0x1eca,   0xd2, 0x1ece,   0xd5,   0xd3, 0x1ecc, 0x1ed8,
0x1edc, 0x1ede, 0x1ee0, 0x1eda, 0x1ee2,   0xd9, 0x1ee6, 0x0168,
  0xa0, 0x0102,   0xc2,   0xca,   0xd4, 0x01a0, 0x01af, 0x0110,
0x0103,   0xe2,   0xea,   0xf4, 0x01a1, 0x01b0, 0x0111, 0x1eb0,
0x0300, 0x0309, 0x0303, 0x0301, 0x0323,   0xe0, 0x1ea3,   0xe3,
  0xe1, 0x1ea1, 0x1eb2, 0x1eb1, 0x1eb3, 0x1eb5, 0x1eaf, 0x1eb4,
0x1eae, 0x1ea6, 0x1ea8, 0x1eaa, 0x1ea4, 0x1ec0, 0x1eb7, 0x1ea7,
0x1ea9, 0x1eab, 0x1ea5, 0x1ead,   0xe8, 0x1ec2, 0x1ebb, 0x1ebd,
  0xe9, 0x1eb9, 0x1ec1, 0x1ec3, 0x1ec5, 0x1ebf, 0x1ec7,   0xec,
0x1ec9, 0x1ec4, 0x1ebe, 0x1ed2, 0x0129,   0xed, 0x1ecb,   0xf2,
0x1ed4, 0x1ecf,   0xf5,   0xf3, 0x1ecd, 0x1ed3, 0x1ed5, 0x1ed7,
0x1ed1, 0x1ed9, 0x1edd, 0x1edf, 0x1ee1, 0x1edb, 0x1ee3,   0xf9,
0x1ed6, 0x1ee7, 0x0169,   0xfa, 0x1ee5, 0x1eeb, 0x1eed, 0x1eef,
0x1ee9, 0x1ef1, 0x1ef3, 0x1ef7, 0x1ef9,   0xfd, 0x1ef5, 0x1ed0
};
long tabviet2[256] =	/* From jdo@sjc.mentorg.com (James Do) */
{
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x3f,
0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,
0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5a,0x5b,0x5c,0x5d,0x5e,0x5f,
0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7a,0x7b,0x7c,0x7d,0x7e,0x7f,
    -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,
    -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,
    -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,
    -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,
  0xa0, 0x0102,   0xc2,   0xca,   0xd4, 0x01a0, 0x01af, 0x0110,
0x0103,   0xe2,   0xea,   0xf4, 0x01a1, 0x01b0, 0x0111, 0x1eb0,
0x0300, 0x0309, 0x0303, 0x0301, 0x0323,   0xe0, 0x1ea3,   0xe3,
  0xe1, 0x1ea1, 0x1eb2, 0x1eb1, 0x1eb3, 0x1eb5, 0x1eaf, 0x1eb4,
0x1eae, 0x1ea6, 0x1ea8, 0x1eaa, 0x1ea4, 0x1ec0, 0x1eb7, 0x1ea7,
0x1ea9, 0x1eab, 0x1ea5, 0x1ead,   0xe8, 0x1ec2, 0x1ebb, 0x1ebd,
  0xe9, 0x1eb9, 0x1ec1, 0x1ec3, 0x1ec5, 0x1ebf, 0x1ec7,   0xec,
0x1ec9, 0x1ec4, 0x1ebe, 0x1ed2, 0x0129,   0xed, 0x1ecb,   0xf2,
0x1ed4, 0x1ecf,   0xf5,   0xf3, 0x1ecd, 0x1ed3, 0x1ed5, 0x1ed7,
0x1ed1, 0x1ed9, 0x1edd, 0x1edf, 0x1ee1, 0x1edb, 0x1ee3,   0xf9,
0x1ed6, 0x1ee7, 0x0169,   0xfa, 0x1ee5, 0x1eeb, 0x1eed, 0x1eef,
0x1ee9, 0x1ef1, 0x1ef3, 0x1ef7, 0x1ef9,   0xfd, 0x1ef5, 0x1ed0
};
long tabviscii[256] =	/* From cuong@haydn.Stanford.EDU (Cuong T. Nguyen) */
{
0x0000, 0x0001, 0x1EB2, 0x0003, 0x0004, 0x1EB4, 0x1EAA, 0x0007,
0x0008, 0x0009, 0x000a, 0x000b, 0x000c, 0x000d, 0x000e, 0x000f,
0x0010, 0x0011, 0x0012, 0x0013, 0x1EF6, 0x0015, 0x0016, 0x0017,
0x0018, 0x1EF8, 0x001a, 0x001b, 0x001c, 0x001d, 0x1EF4, 0x001f,
0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027,
0x0028, 0x0029, 0x002a, 0x002b, 0x002c, 0x002d, 0x002e, 0x002f,
0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037,
0x0038, 0x0039, 0x003a, 0x003b, 0x003c, 0x003d, 0x003e, 0x003f,
0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047,
0x0048, 0x0049, 0x004a, 0x004b, 0x004c, 0x004d, 0x004e, 0x004f,
0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057,
0x0058, 0x0059, 0x005a, 0x005b, 0x005c, 0x005d, 0x005e, 0x005f,
0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067,
0x0068, 0x0069, 0x006a, 0x006b, 0x006c, 0x006d, 0x006e, 0x006f,
0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077,
0x0078, 0x0079, 0x007a, 0x007b, 0x007c, 0x007d, 0x007e, 0x007f,
0x1EA0, 0x1EAE, 0x1EB0, 0x1EB6, 0x1EA4, 0x1EA6, 0x1EA8, 0x1EAC,
0x1EBC, 0x1EB8, 0x1EBE, 0x1EC0, 0x1EC2, 0x1EC4, 0x1EC6, 0x1ED0,
0x1ED2, 0x1ED4, 0x1ED6, 0x1ED8, 0x1EE2, 0x1EDA, 0x1EDC, 0x1EDE,
0x1ECA, 0x1ECE, 0x1ECC, 0x1EC8, 0x1EE6, 0x0168, 0x1EE4, 0x1EF2,
0x00D5, 0x1EAF, 0x1EB1, 0x1EB7, 0x1EA5, 0x1EA7, 0x1EA9, 0x1EAD,
0x1EBD, 0x1EB9, 0x1EBF, 0x1EC1, 0x1EC3, 0x1EC5, 0x1EC7, 0x1ED1,
0x1ED3, 0x1ED5, 0x1ED7, 0x1EE0, 0x01A0, 0x1ED9, 0x1EDD, 0x1EDF,
0x1ECB, 0x1EF0, 0x1EE8, 0x1EEA, 0x1EEC, 0x01A1, 0x1EDB, 0x01AF,
0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x1EA2, 0x0102, 0x1EB3, 0x1EB5,
0x00C8, 0x00C9, 0x00CA, 0x1EBA, 0x00CC, 0x00CD, 0x0128, 0x1EF3,
0x0110, 0x1EE9, 0x00D2, 0x00D3, 0x00D4, 0x1EA1, 0x1EF7, 0x1EEB,
0x1EED, 0x00D9, 0x00DA, 0x1EF9, 0x1EF5, 0x00DD, 0x1EE1, 0x01B0,
0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x1EA3, 0x0103, 0x1EEF, 0x1EAB,
0x00E8, 0x00E9, 0x00EA, 0x1EBB, 0x00EC, 0x00ED, 0x0129, 0x1EC9,
0x0111, 0x1EF1, 0x00F2, 0x00F3, 0x00F4, 0x00F5, 0x1ECF, 0x1ECD,
0x1EE5, 0x00F9, 0x00FA, 0x0169, 0x1EE7, 0x00FD, 0x1EE3, 0x1EEE
};
