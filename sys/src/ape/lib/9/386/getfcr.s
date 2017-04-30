
TEXT	setfcr(SB), $0
	MOVL	p+0(FP),AX
	XORB	$0x3f,AX
	PUSHW	AX
	WAIT
	FLDCW	0(SP)
	POPW	AX
	RET

TEXT	getfcr(SB), $0
	PUSHW	AX
	WAIT
	FSTCW	0(SP)
	POPW	AX
	XORB	$0x3f,AX
	RET

TEXT	getfsr(SB), $0
	WAIT
	FSTSW	AX
	RET

TEXT	setfsr(SB), $0
	WAIT
	FCLEX
	RET
