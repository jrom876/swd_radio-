	.arch armv8-a
	.file	"sw_def_radio.cpp"
// GNU C++14 (Ubuntu/Linaro 7.5.0-3ubuntu1~18.04) version 7.5.0 (aarch64-linux-gnu)
//	compiled by GNU C version 7.5.0, GMP version 6.1.2, MPFR version 4.0.1, MPC version 1.1.0, isl version isl-0.19-GMP

// GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
// options passed:  -I /usr/include/gtk-2.0
// -I /usr/lib/aarch64-linux-gnu/gtk-2.0/include
// -I /usr/include/gio-unix-2.0/ -I /usr/include/cairo
// -I /usr/include/pango-1.0 -I /usr/include/atk-1.0 -I /usr/include/cairo
// -I /usr/include/pixman-1 -I /usr/include/gdk-pixbuf-2.0
// -I /usr/include/libpng16 -I /usr/include/pango-1.0
// -I /usr/include/harfbuzz -I /usr/include/pango-1.0
// -I /usr/include/glib-2.0 -I /usr/lib/aarch64-linux-gnu/glib-2.0/include
// -I /usr/include/freetype2 -I /usr/include/libpng16
// -I /usr/include/freetype2 -I /usr/include/libpng16
// -imultiarch aarch64-linux-gnu -D_GNU_SOURCE -D_REENTRANT
// sw_def_radio.cpp -mlittle-endian -mabi=lp64
// -auxbase-strip sw_def_radio.s -fverbose-asm -fstack-protector-strong
// -Wformat -Wformat-security
// options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
// -fauto-inc-dec -fchkp-check-incomplete-type -fchkp-check-read
// -fchkp-check-write -fchkp-instrument-calls -fchkp-narrow-bounds
// -fchkp-optimize -fchkp-store-bounds -fchkp-use-static-bounds
// -fchkp-use-static-const-bounds -fchkp-use-wrappers -fcommon
// -fdelete-null-pointer-checks -fdwarf2-cfi-asm -fearly-inlining
// -feliminate-unused-debug-types -fexceptions -ffp-int-builtin-inexact
// -ffunction-cse -fgcse-lm -fgnu-runtime -fgnu-unique -fident
// -finline-atomics -fira-hoist-pressure -fira-share-save-slots
// -fira-share-spill-slots -fivopts -fkeep-static-consts
// -fleading-underscore -flifetime-dse -flto-odr-type-merging -fmath-errno
// -fmerge-debug-strings -fomit-frame-pointer -fpeephole -fplt
// -fprefetch-loop-arrays -freg-struct-return
// -fsched-critical-path-heuristic -fsched-dep-count-heuristic
// -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
// -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
// -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
// -fshow-column -fshrink-wrap-separate -fsigned-zeros
// -fsplit-ivs-in-unroller -fssa-backprop -fstack-protector-strong
// -fstdarg-opt -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math
// -ftree-cselim -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im
// -ftree-loop-ivcanon -ftree-loop-optimize -ftree-parallelize-loops=
// -ftree-phiprop -ftree-reassoc -ftree-scev-cprop -funit-at-a-time
// -fverbose-asm -fzero-initialized-in-bss -mfix-cortex-a53-835769
// -mfix-cortex-a53-843419 -mglibc -mlittle-endian
// -momit-leaf-frame-pointer -mpc-relative-literal-loads

	.text
	.section	.text._ZSt3cosf,"axG",@progbits,_ZSt3cosf,comdat
	.align	2
	.weak	_ZSt3cosf
	.type	_ZSt3cosf, %function
_ZSt3cosf:
.LFB40:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!	//,,,
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
	str	s0, [x29, 28]	// __x, __x
// /usr/include/c++/7/cmath:185:   { return __builtin_cosf(__x); }
	ldr	s0, [x29, 28]	//, __x
	bl	cosf	//
	ldp	x29, x30, [sp], 32	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE40:
	.size	_ZSt3cosf, .-_ZSt3cosf
	.section	.text._ZSt3logf,"axG",@progbits,_ZSt3logf,comdat
	.align	2
	.weak	_ZSt3logf
	.type	_ZSt3logf, %function
_ZSt3logf:
.LFB64:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!	//,,,
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
	str	s0, [x29, 28]	// __x, __x
// /usr/include/c++/7/cmath:339:   { return __builtin_logf(__x); }
	ldr	s0, [x29, 28]	//, __x
	bl	logf	//
	ldp	x29, x30, [sp], 32	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE64:
	.size	_ZSt3logf, .-_ZSt3logf
	.section	.text._ZSt5log10f,"axG",@progbits,_ZSt5log10f,comdat
	.align	2
	.weak	_ZSt5log10f
	.type	_ZSt5log10f, %function
_ZSt5log10f:
.LFB67:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!	//,,,
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
	str	s0, [x29, 28]	// __x, __x
// /usr/include/c++/7/cmath:358:   { return __builtin_log10f(__x); }
	ldr	s0, [x29, 28]	//, __x
	bl	log10f	//
	ldp	x29, x30, [sp], 32	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE67:
	.size	_ZSt5log10f, .-_ZSt5log10f
	.section	.text._ZSt4sqrtf,"axG",@progbits,_ZSt4sqrtf,comdat
	.align	2
	.weak	_ZSt4sqrtf
	.type	_ZSt4sqrtf, %function
_ZSt4sqrtf:
.LFB81:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!	//,,,
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
	str	s0, [x29, 28]	// __x, __x
// /usr/include/c++/7/cmath:464:   { return __builtin_sqrtf(__x); }
	ldr	s0, [x29, 28]	//, __x
	bl	sqrtf	//
	ldp	x29, x30, [sp], 32	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE81:
	.size	_ZSt4sqrtf, .-_ZSt4sqrtf
	.global	freqGHz
	.bss
	.align	2
	.type	freqGHz, %object
	.size	freqGHz, 4
freqGHz:
	.zero	4
	.global	txpwrW
	.align	2
	.type	txpwrW, %object
	.size	txpwrW, 4
txpwrW:
	.zero	4
	.global	distTargetKM
	.align	2
	.type	distTargetKM, %object
	.size	distTargetKM, 4
distTargetKM:
	.zero	4
	.global	radarXSect
	.align	2
	.type	radarXSect, %object
	.size	radarXSect, 4
radarXSect:
	.zero	4
	.global	antGain
	.align	2
	.type	antGain, %object
	.size	antGain, 4
antGain:
	.zero	4
	.global	tempf
	.align	2
	.type	tempf, %object
	.size	tempf, 4
tempf:
	.zero	4
	.section	.rodata
	.align	3
.LC1:
	.string	"Path Loss (dB): \t%.5f\n"
	.text
	.align	2
	.global	_Z16twoWayPathLossDBfff
	.type	_Z16twoWayPathLossDBfff, %function
_Z16twoWayPathLossDBfff:
.LFB240:
	.cfi_startproc
	stp	x29, x30, [sp, -64]!	//,,,
	.cfi_def_cfa_offset 64
	.cfi_offset 29, -64
	.cfi_offset 30, -56
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
	str	d8, [sp, 16]	//,
	.cfi_offset 72, -48
	str	s0, [x29, 44]	// freq, freq
	str	s1, [x29, 40]	// dist, dist
	str	s2, [x29, 36]	// rxs, rxs
// sw_def_radio.cpp:168:   float result = ((20*log(freq))+(40*log(dist))+163.43-(10*log(rxs)))*(-1);
	ldr	s0, [x29, 44]	//, freq
	bl	_ZSt3logf	//
	fmov	s1, s0	// _1,
	fmov	s0, 2.0e+1	// tmp88,
	fmul	s8, s1, s0	// _2, _1, tmp88
	ldr	s0, [x29, 40]	//, dist
	bl	_ZSt3logf	//
	fmov	s1, s0	// _3,
	mov	w0, 1109393408	// tmp99,
	fmov	s0, w0	// tmp89, tmp99
	fmul	s0, s1, s0	// _4, _3, tmp89
	fadd	s0, s8, s0	// _5, _2, _4
	fcvt	d1, s0	// _6, _5
	adrp	x0, .LC0	// tmp92,
	add	x0, x0, :lo12:.LC0	// tmp91, tmp92,
	ldr	d0, [x0]	// tmp90,
	fadd	d8, d1, d0	// _7, _6, tmp90
	ldr	s0, [x29, 36]	//, rxs
	bl	_ZSt3logf	//
	fmov	s1, s0	// _8,
	fmov	s0, 1.0e+1	// tmp93,
	fmul	s0, s1, s0	// _9, _8, tmp93
	fcvt	d0, s0	// _10, _9
	fsub	d0, d8, d0	// _11, _7, _10
	fneg	d0, d0	// _12, _11
	fcvt	s0, d0	// tmp94, _12
	str	s0, [x29, 60]	// tmp94, result
// sw_def_radio.cpp:169:   printf("Path Loss (dB): \t%.5f\n",result); // DBPRINT
	ldr	s0, [x29, 60]	// tmp95, result
	fcvt	d0, s0	// _13, tmp95
	adrp	x0, .LC1	// tmp97,
	add	x0, x0, :lo12:.LC1	// tmp96, tmp97,
	bl	printf	//
// sw_def_radio.cpp:170:   return result;
	ldr	s0, [x29, 60]	// _23, result
// sw_def_radio.cpp:171: }
	ldr	d8, [sp, 16]	//,
	ldp	x29, x30, [sp], 64	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_restore 72
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE240:
	.size	_Z16twoWayPathLossDBfff, .-_Z16twoWayPathLossDBfff
	.section	.rodata
	.align	3
.LC0:
	.word	2405181686
	.word	1080323522
	.text
	.section	.text._ZSt3powIiiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_,"axG",@progbits,_ZSt3powIiiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_,comdat
	.align	2
	.weak	_ZSt3powIiiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_
	.type	_ZSt3powIiiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_, %function
_ZSt3powIiiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_:
.LFB242:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!	//,,,
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
	str	w0, [x29, 28]	// __x, __x
	str	w1, [x29, 24]	// __y, __y
// /usr/include/c++/7/cmath:418:       return pow(__type(__x), __type(__y));
	ldr	w0, [x29, 28]	// tmp77, __x
	scvtf	d0, w0	// _1, tmp77
	ldr	w0, [x29, 24]	// tmp78, __y
	scvtf	d1, w0	// _2, tmp78
	bl	pow	//
// /usr/include/c++/7/cmath:419:     }
	ldp	x29, x30, [sp], 32	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE242:
	.size	_ZSt3powIiiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_, .-_ZSt3powIiiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_
	.section	.text._ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_,"axG",@progbits,_ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_,comdat
	.align	2
	.weak	_ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_
	.type	_ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_, %function
_ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_:
.LFB243:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!	//,,,
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
	str	d0, [x29, 24]	// __x, __x
	str	w0, [x29, 20]	// __y, __y
// /usr/include/c++/7/cmath:418:       return pow(__type(__x), __type(__y));
	ldr	w0, [x29, 20]	// tmp76, __y
	scvtf	d0, w0	// _1, tmp76
	fmov	d1, d0	//, _1
	ldr	d0, [x29, 24]	//, __x
	bl	pow	//
// /usr/include/c++/7/cmath:419:     }
	ldp	x29, x30, [sp], 32	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE243:
	.size	_ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_, .-_ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_
	.section	.rodata
	.align	3
.LC3:
	.string	"RX Power at antenna: \t%.8f pico-watts\n"
	.text
	.align	2
	.global	_Z10rxPwrWattsfffff
	.type	_Z10rxPwrWattsfffff, %function
_Z10rxPwrWattsfffff:
.LFB241:
	.cfi_startproc
	stp	x29, x30, [sp, -80]!	//,,,
	.cfi_def_cfa_offset 80
	.cfi_offset 29, -80
	.cfi_offset 30, -72
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
	str	d8, [sp, 16]	//,
	.cfi_offset 72, -64
	str	s0, [x29, 60]	// Pt, Pt
	str	s1, [x29, 56]	// GtdB, GtdB
	str	s2, [x29, 52]	// GrdB, GrdB
	str	s3, [x29, 48]	// R, R
	str	s4, [x29, 44]	// freq, freq
// sw_def_radio.cpp:193: 	float result = Pt*pow(10,log10(GtdB))*pow(10,log10(GrdB))
	ldr	s0, [x29, 60]	// tmp94, Pt
	fcvt	d8, s0	// _1, tmp94
	ldr	s0, [x29, 56]	//, GtdB
	bl	_ZSt5log10f	//
	mov	w0, 10	//,
	bl	_ZSt3powIifEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_	//
	fmul	d8, d8, d0	// _4, _1, _3
	ldr	s0, [x29, 52]	//, GrdB
	bl	_ZSt5log10f	//
	mov	w0, 10	//,
	bl	_ZSt3powIifEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_	//
	fmul	d8, d8, d0	// _7, _4, _6
// sw_def_radio.cpp:194: 		*(pow(LIGHT_SPEED,2))/(pow((4*PI*(R*KILO)*(freq*GIGA)),2));
	mov	w1, 2	//,
	mov	w0, 30794	//,
	movk	w0, 0x11de, lsl 16	//,,
	bl	_ZSt3powIiiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_	//
	fmul	d8, d8, d0	// _9, _7, _8
	ldr	s0, [x29, 48]	// tmp95, R
	mov	w0, 1148846080	// tmp108,
	fmov	s1, w0	// tmp96, tmp108
	fmul	s0, s0, s1	// _10, tmp95, tmp96
	fcvt	d1, s0	// _11, _10
	adrp	x0, .LC2	// tmp99,
	add	x0, x0, :lo12:.LC2	// tmp98, tmp99,
	ldr	d0, [x0]	// tmp97,
	fmul	d1, d1, d0	// _12, _11, tmp97
	ldr	s0, [x29, 44]	// tmp100, freq
	mov	w0, 27432	// tmp109,
	movk	w0, 0x4e6e, lsl 16	// tmp109,,
	fmov	s2, w0	// tmp101, tmp109
	fmul	s0, s0, s2	// _13, tmp100, tmp101
	fcvt	d0, s0	// _14, _13
	fmul	d0, d1, d0	// _15, _12, _14
	mov	w0, 2	//,
	bl	_ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_	//
	fdiv	d0, d8, d0	// _17, _9, _16
	fcvt	s0, d0	// tmp102, _17
	str	s0, [x29, 76]	// tmp102, result
// sw_def_radio.cpp:195: 	printf("RX Power at antenna: \t%.8f pico-watts\n",result*TERA); // DBPRINT
	ldr	s0, [x29, 76]	// tmp103, result
	mov	w0, 54437	// tmp110,
	movk	w0, 0x5368, lsl 16	// tmp110,,
	fmov	s1, w0	// tmp104, tmp110
	fmul	s0, s0, s1	// _18, tmp103, tmp104
	fcvt	d0, s0	// _19, _18
	adrp	x0, .LC3	// tmp106,
	add	x0, x0, :lo12:.LC3	// tmp105, tmp106,
	bl	printf	//
// sw_def_radio.cpp:196: 	return result;
	ldr	s0, [x29, 76]	// _34, result
// sw_def_radio.cpp:197: }
	ldr	d8, [sp, 16]	//,
	ldp	x29, x30, [sp], 80	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_restore 72
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE241:
	.size	_Z10rxPwrWattsfffff, .-_Z10rxPwrWattsfffff
	.section	.rodata
	.align	3
.LC2:
	.word	1413754136
	.word	1076437499
	.text
	.section	.text._ZSt3powIifEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_,"axG",@progbits,_ZSt3powIifEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_,comdat
	.align	2
	.weak	_ZSt3powIifEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_
	.type	_ZSt3powIifEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_, %function
_ZSt3powIifEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_:
.LFB245:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!	//,,,
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
	str	w0, [x29, 28]	// __x, __x
	str	s0, [x29, 24]	// __y, __y
// /usr/include/c++/7/cmath:418:       return pow(__type(__x), __type(__y));
	ldr	w0, [x29, 28]	// tmp77, __x
	scvtf	d2, w0	// _1, tmp77
	ldr	s0, [x29, 24]	// tmp78, __y
	fcvt	d0, s0	// _2, tmp78
	fmov	d1, d0	//, _2
	fmov	d0, d2	//, _1
	bl	pow	//
// /usr/include/c++/7/cmath:419:     }
	ldp	x29, x30, [sp], 32	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE245:
	.size	_ZSt3powIifEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_, .-_ZSt3powIifEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_
	.section	.rodata
	.align	3
.LC5:
	.string	"RX Power: \t%.8f dBW\n"
	.align	3
.LC6:
	.string	"RX Power: \t%.8f dBm\n"
	.align	3
.LC7:
	.string	"RX Power: \t%.8f dBp\n"
	.text
	.align	2
	.global	_Z8rxPwrDBMfffff
	.type	_Z8rxPwrDBMfffff, %function
_Z8rxPwrDBMfffff:
.LFB244:
	.cfi_startproc
	stp	x29, x30, [sp, -80]!	//,,,
	.cfi_def_cfa_offset 80
	.cfi_offset 29, -80
	.cfi_offset 30, -72
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
	str	d8, [sp, 16]	//,
	.cfi_offset 72, -64
	str	s0, [x29, 60]	// PtxdBm, PtxdBm
	str	s1, [x29, 56]	// GtxdB, GtxdB
	str	s2, [x29, 52]	// GrxdB, GrxdB
	str	s3, [x29, 48]	// dist, dist
	str	s4, [x29, 44]	// freq, freq
// sw_def_radio.cpp:210: 	float rpwr = pow(10,((PtxdBm-30)/10))*pow(10,log10(GtxdB))
	ldr	s1, [x29, 60]	// tmp107, PtxdBm
	fmov	s0, 3.0e+1	// tmp108,
	fsub	s1, s1, s0	// _1, tmp107, tmp108
	fmov	s0, 1.0e+1	// tmp109,
	fdiv	s0, s1, s0	// _2, _1, tmp109
	mov	w0, 10	//,
	bl	_ZSt3powIifEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_	//
	fmov	d8, d0	// _3,
	ldr	s0, [x29, 56]	//, GtxdB
	bl	_ZSt5log10f	//
	mov	w0, 10	//,
	bl	_ZSt3powIifEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_	//
	fmul	d8, d8, d0	// _6, _3, _5
// sw_def_radio.cpp:211: 		*pow(10,log10(GrxdB))*(pow(LIGHT_SPEED,2))/(pow((4*PI*(dist*KILO)*(freq*GIGA)),2));
	ldr	s0, [x29, 52]	//, GrxdB
	bl	_ZSt5log10f	//
	mov	w0, 10	//,
	bl	_ZSt3powIifEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_	//
	fmul	d8, d8, d0	// _9, _6, _8
	mov	w1, 2	//,
	mov	w0, 30794	//,
	movk	w0, 0x11de, lsl 16	//,,
	bl	_ZSt3powIiiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_	//
	fmul	d8, d8, d0	// _11, _9, _10
	ldr	s0, [x29, 48]	// tmp110, dist
	mov	w0, 1148846080	// tmp133,
	fmov	s1, w0	// tmp111, tmp133
	fmul	s0, s0, s1	// _12, tmp110, tmp111
	fcvt	d1, s0	// _13, _12
	adrp	x0, .LC4	// tmp114,
	add	x0, x0, :lo12:.LC4	// tmp113, tmp114,
	ldr	d0, [x0]	// tmp112,
	fmul	d1, d1, d0	// _14, _13, tmp112
	ldr	s0, [x29, 44]	// tmp115, freq
	mov	w0, 27432	// tmp134,
	movk	w0, 0x4e6e, lsl 16	// tmp134,,
	fmov	s2, w0	// tmp116, tmp134
	fmul	s0, s0, s2	// _15, tmp115, tmp116
	fcvt	d0, s0	// _16, _15
	fmul	d0, d1, d0	// _17, _14, _16
	mov	w0, 2	//,
	bl	_ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_	//
	fdiv	d0, d8, d0	// _19, _11, _18
	fcvt	s0, d0	// tmp117, _19
	str	s0, [x29, 72]	// tmp117, rpwr
// sw_def_radio.cpp:212: 	printf("RX Power: \t%.8f dBW\n",(10*log10(rpwr))); // DBPRINT
	ldr	s0, [x29, 72]	//, rpwr
	bl	_ZSt5log10f	//
	fmov	s1, s0	// _20,
	fmov	s0, 1.0e+1	// tmp118,
	fmul	s0, s1, s0	// _21, _20, tmp118
	fcvt	d0, s0	// _22, _21
	adrp	x0, .LC5	// tmp120,
	add	x0, x0, :lo12:.LC5	// tmp119, tmp120,
	bl	printf	//
// sw_def_radio.cpp:213: 	printf("RX Power: \t%.8f dBm\n",(10*log10(rpwr))+30); // DBPRINT
	ldr	s0, [x29, 72]	//, rpwr
	bl	_ZSt5log10f	//
	fmov	s1, s0	// _23,
	fmov	s0, 1.0e+1	// tmp121,
	fmul	s1, s1, s0	// _24, _23, tmp121
	fmov	s0, 3.0e+1	// tmp122,
	fadd	s0, s1, s0	// _25, _24, tmp122
	fcvt	d0, s0	// _26, _25
	adrp	x0, .LC6	// tmp124,
	add	x0, x0, :lo12:.LC6	// tmp123, tmp124,
	bl	printf	//
// sw_def_radio.cpp:214: 	printf("RX Power: \t%.8f dBp\n",(10*log10(rpwr))+120); // DBPRINT
	ldr	s0, [x29, 72]	//, rpwr
	bl	_ZSt5log10f	//
	fmov	s1, s0	// _27,
	fmov	s0, 1.0e+1	// tmp125,
	fmul	s0, s1, s0	// _28, _27, tmp125
	mov	w0, 1123024896	// tmp135,
	fmov	s1, w0	// tmp126, tmp135
	fadd	s0, s0, s1	// _29, _28, tmp126
	fcvt	d0, s0	// _30, _29
	adrp	x0, .LC7	// tmp128,
	add	x0, x0, :lo12:.LC7	// tmp127, tmp128,
	bl	printf	//
// sw_def_radio.cpp:216: 	result = (10*log10(rpwr))+30;
	ldr	s0, [x29, 72]	//, rpwr
	bl	_ZSt5log10f	//
	fmov	s1, s0	// _31,
	fmov	s0, 1.0e+1	// tmp129,
	fmul	s1, s1, s0	// _32, _31, tmp129
	fmov	s0, 3.0e+1	// tmp131,
	fadd	s0, s1, s0	// tmp130, _32, tmp131
	str	s0, [x29, 76]	// tmp130, result
// sw_def_radio.cpp:218: 	return result;
	ldr	s0, [x29, 76]	// _55, result
// sw_def_radio.cpp:219: }
	ldr	d8, [sp, 16]	//,
	ldp	x29, x30, [sp], 80	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_restore 72
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE244:
	.size	_Z8rxPwrDBMfffff, .-_Z8rxPwrDBMfffff
	.section	.rodata
	.align	3
.LC4:
	.word	1413754136
	.word	1076437499
	.text
	.section	.rodata
	.align	3
.LC8:
	.string	"\n%.4f\tPtdBm\n"
	.align	3
.LC9:
	.string	"%.4f\tGtdb\n"
	.align	3
.LC10:
	.string	"%.4f\tGrdb\n"
	.align	3
.LC11:
	.string	"%.4f\tDistance km\n"
	.align	3
.LC12:
	.string	"%.4f\tfreq GHz\n"
	.text
	.align	2
	.global	_Z10printRxDBMfffff
	.type	_Z10printRxDBMfffff, %function
_Z10printRxDBMfffff:
.LFB246:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!	//,,,
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
	str	s0, [x29, 44]	// PtxdBm, PtxdBm
	str	s1, [x29, 40]	// GtxdB, GtxdB
	str	s2, [x29, 36]	// GrxdB, GrxdB
	str	s3, [x29, 32]	// dist, dist
	str	s4, [x29, 28]	// freq, freq
// sw_def_radio.cpp:222: 	printf("\n%.4f\tPtdBm\n",PtxdBm);
	ldr	s0, [x29, 44]	// tmp78, PtxdBm
	fcvt	d0, s0	// _1, tmp78
	adrp	x0, .LC8	// tmp80,
	add	x0, x0, :lo12:.LC8	// tmp79, tmp80,
	bl	printf	//
// sw_def_radio.cpp:223: 	printf("%.4f\tGtdb\n",GtxdB);
	ldr	s0, [x29, 40]	// tmp81, GtxdB
	fcvt	d0, s0	// _2, tmp81
	adrp	x0, .LC9	// tmp83,
	add	x0, x0, :lo12:.LC9	// tmp82, tmp83,
	bl	printf	//
// sw_def_radio.cpp:224: 	printf("%.4f\tGrdb\n",GrxdB);
	ldr	s0, [x29, 36]	// tmp84, GrxdB
	fcvt	d0, s0	// _3, tmp84
	adrp	x0, .LC10	// tmp86,
	add	x0, x0, :lo12:.LC10	// tmp85, tmp86,
	bl	printf	//
// sw_def_radio.cpp:225: 	printf("%.4f\tDistance km\n",dist);
	ldr	s0, [x29, 32]	// tmp87, dist
	fcvt	d0, s0	// _4, tmp87
	adrp	x0, .LC11	// tmp89,
	add	x0, x0, :lo12:.LC11	// tmp88, tmp89,
	bl	printf	//
// sw_def_radio.cpp:226: 	printf("%.4f\tfreq GHz\n",freq);
	ldr	s0, [x29, 28]	// tmp90, freq
	fcvt	d0, s0	// _5, tmp90
	adrp	x0, .LC12	// tmp92,
	add	x0, x0, :lo12:.LC12	// tmp91, tmp92,
	bl	printf	//
// sw_def_radio.cpp:227: 	getFresnelRadius(freq,dist);
	ldr	s1, [x29, 32]	//, dist
	ldr	s0, [x29, 28]	//, freq
	bl	_Z16getFresnelRadiusff	//
// sw_def_radio.cpp:228: }
	nop
	ldp	x29, x30, [sp], 48	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE246:
	.size	_Z10printRxDBMfffff, .-_Z10printRxDBMfffff
	.section	.rodata
	.align	3
.LC14:
	.string	"\nFresnel Radius = %.4f meters\n"
	.text
	.align	2
	.global	_Z16getFresnelRadiusff
	.type	_Z16getFresnelRadiusff, %function
_Z16getFresnelRadiusff:
.LFB247:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!	//,,,
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
	str	s0, [x29, 28]	// freqGHz, freqGHz
	str	s1, [x29, 24]	// distKM, distKM
// sw_def_radio.cpp:232: 	float result = (8.656*sqrt(distKM/(4*freqGHz)));
	ldr	s1, [x29, 28]	// tmp81, freqGHz
	fmov	s0, 4.0e+0	// tmp82,
	fmul	s0, s1, s0	// _1, tmp81, tmp82
	ldr	s1, [x29, 24]	// tmp83, distKM
	fdiv	s0, s1, s0	// _2, tmp83, _1
	bl	_ZSt4sqrtf	//
	fcvt	d1, s0	// _4, _3
	adrp	x0, .LC13	// tmp86,
	add	x0, x0, :lo12:.LC13	// tmp85, tmp86,
	ldr	d0, [x0]	// tmp84,
	fmul	d0, d1, d0	// _5, _4, tmp84
	fcvt	s0, d0	// tmp87, _5
	str	s0, [x29, 44]	// tmp87, result
// sw_def_radio.cpp:233: 	printf("\nFresnel Radius = %.4f meters\n", result); // DBPRINT
	ldr	s0, [x29, 44]	// tmp88, result
	fcvt	d0, s0	// _6, tmp88
	adrp	x0, .LC14	// tmp90,
	add	x0, x0, :lo12:.LC14	// tmp89, tmp90,
	bl	printf	//
// sw_def_radio.cpp:234: 	return result;
	ldr	s0, [x29, 44]	// _13, result
// sw_def_radio.cpp:235: }
	ldp	x29, x30, [sp], 48	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE247:
	.size	_Z16getFresnelRadiusff, .-_Z16getFresnelRadiusff
	.section	.rodata
	.align	3
.LC13:
	.word	996432413
	.word	1075924959
	.text
	.section	.text._ZSt3powIfiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_,"axG",@progbits,_ZSt3powIfiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_,comdat
	.align	2
	.weak	_ZSt3powIfiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_
	.type	_ZSt3powIfiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_, %function
_ZSt3powIfiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_:
.LFB249:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!	//,,,
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
	str	s0, [x29, 28]	// __x, __x
	str	w0, [x29, 24]	// __y, __y
// /usr/include/c++/7/cmath:418:       return pow(__type(__x), __type(__y));
	ldr	s0, [x29, 28]	// tmp77, __x
	fcvt	d0, s0	// _1, tmp77
	ldr	w0, [x29, 24]	// tmp78, __y
	scvtf	d1, w0	// _2, tmp78
	bl	pow	//
// /usr/include/c++/7/cmath:419:     }
	ldp	x29, x30, [sp], 32	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE249:
	.size	_ZSt3powIfiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_, .-_ZSt3powIfiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_
	.section	.rodata
	.align	3
.LC16:
	.string	"\nPolarization Loss Factor = %.4f\n\n"
	.text
	.align	2
	.global	_Z6getPLFf
	.type	_Z6getPLFf, %function
_Z6getPLFf:
.LFB248:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!	//,,,
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
	str	s0, [x29, 28]	// phi, phi
// sw_def_radio.cpp:239: 	phi = phi*(PI/180);
	ldr	s0, [x29, 28]	// tmp80, phi
	fcvt	d1, s0	// _1, tmp80
	adrp	x0, .LC15	// tmp83,
	add	x0, x0, :lo12:.LC15	// tmp82, tmp83,
	ldr	d0, [x0]	// tmp81,
	fmul	d0, d1, d0	// _2, _1, tmp81
	fcvt	s0, d0	// tmp84, _2
	str	s0, [x29, 28]	// tmp84, phi
// sw_def_radio.cpp:240: 	float plf = pow(cos(phi),2);
	ldr	s0, [x29, 28]	//, phi
	bl	_ZSt3cosf	//
	mov	w0, 2	//,
	bl	_ZSt3powIfiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_	//
	fcvt	s0, d0	// tmp85, _4
	str	s0, [x29, 44]	// tmp85, plf
// sw_def_radio.cpp:241: 	printf("\nPolarization Loss Factor = %.4f\n\n", plf); // DBPRINT
	ldr	s0, [x29, 44]	// tmp86, plf
	fcvt	d0, s0	// _5, tmp86
	adrp	x0, .LC16	// tmp88,
	add	x0, x0, :lo12:.LC16	// tmp87, tmp88,
	bl	printf	//
// sw_def_radio.cpp:242: 	return plf;
	ldr	s0, [x29, 44]	// _13, plf
// sw_def_radio.cpp:243: }
	ldp	x29, x30, [sp], 48	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE248:
	.size	_Z6getPLFf, .-_Z6getPLFf
	.section	.rodata
	.align	3
.LC15:
	.word	2723323193
	.word	1066524486
	.text
	.section	.rodata
	.align	3
.LC18:
	.string	"Antenna Gain = %f\n\n"
	.text
	.align	2
	.global	_Z15antGainFromFreqfff
	.type	_Z15antGainFromFreqfff, %function
_Z15antGainFromFreqfff:
.LFB250:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!	//,,,
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
	str	s0, [x29, 28]	// efficiency, efficiency
	str	s1, [x29, 24]	// aperature_area, aperature_area
	str	s2, [x29, 20]	// freq, freq
// sw_def_radio.cpp:247:   float lam = LIGHT_SPEED/freq;
	ldr	s0, [x29, 20]	// tmp87, freq
	mov	w0, 62402	// tmp103,
	movk	w0, 0x4d8e, lsl 16	// tmp103,,
	fmov	s1, w0	// tmp88, tmp103
	fdiv	s0, s1, s0	// tmp86, tmp88, tmp87
	str	s0, [x29, 40]	// tmp86, lam
// sw_def_radio.cpp:249:   float antgain = ((10*log10((efficiency*4*PI*aperature_area)/(lam*lam))));
	ldr	s1, [x29, 28]	// tmp89, efficiency
	fmov	s0, 4.0e+0	// tmp90,
	fmul	s0, s1, s0	// _1, tmp89, tmp90
	fcvt	d1, s0	// _2, _1
	adrp	x0, .LC17	// tmp93,
	add	x0, x0, :lo12:.LC17	// tmp92, tmp93,
	ldr	d0, [x0]	// tmp91,
	fmul	d1, d1, d0	// _3, _2, tmp91
	ldr	s0, [x29, 24]	// tmp94, aperature_area
	fcvt	d0, s0	// _4, tmp94
	fmul	d1, d1, d0	// _5, _3, _4
	ldr	s2, [x29, 40]	// tmp95, lam
	ldr	s0, [x29, 40]	// tmp96, lam
	fmul	s0, s2, s0	// _6, tmp95, tmp96
	fcvt	d0, s0	// _7, _6
	fdiv	d0, d1, d0	// _8, _5, _7
	bl	log10	//
	fmov	d1, d0	// _9,
	fmov	d0, 1.0e+1	// tmp97,
	fmul	d0, d1, d0	// _10, _9, tmp97
	fcvt	s0, d0	// tmp98, _10
	str	s0, [x29, 44]	// tmp98, antgain
// sw_def_radio.cpp:250:   printf("Antenna Gain = %f\n\n",antgain); // DBPRINT
	ldr	s0, [x29, 44]	// tmp99, antgain
	fcvt	d0, s0	// _11, tmp99
	adrp	x0, .LC18	// tmp101,
	add	x0, x0, :lo12:.LC18	// tmp100, tmp101,
	bl	printf	//
// sw_def_radio.cpp:251:   return antgain;
	ldr	s0, [x29, 44]	// _20, antgain
// sw_def_radio.cpp:252: }
	ldp	x29, x30, [sp], 48	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE250:
	.size	_Z15antGainFromFreqfff, .-_Z15antGainFromFreqfff
	.section	.rodata
	.align	3
.LC17:
	.word	1413754136
	.word	1074340347
	.text
	.align	2
	.global	_Z9getLambdaf
	.type	_Z9getLambdaf, %function
_Z9getLambdaf:
.LFB251:
	.cfi_startproc
	sub	sp, sp, #32	//,,
	.cfi_def_cfa_offset 32
	str	s0, [sp, 12]	// freq, freq
// sw_def_radio.cpp:255:   float clambda = (LIGHT_SPEED/freq);
	ldr	s0, [sp, 12]	// tmp76, freq
	mov	w0, 62402	// tmp79,
	movk	w0, 0x4d8e, lsl 16	// tmp79,,
	fmov	s1, w0	// tmp77, tmp79
	fdiv	s0, s1, s0	// tmp75, tmp77, tmp76
	str	s0, [sp, 28]	// tmp75, clambda
// sw_def_radio.cpp:257:   return clambda;
	ldr	s0, [sp, 28]	// _3, clambda
// sw_def_radio.cpp:258: }
	add	sp, sp, 32	//,,
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE251:
	.size	_Z9getLambdaf, .-_Z9getLambdaf
	.align	2
	.global	_Z7getFreqf
	.type	_Z7getFreqf, %function
_Z7getFreqf:
.LFB252:
	.cfi_startproc
	sub	sp, sp, #32	//,,
	.cfi_def_cfa_offset 32
	str	s0, [sp, 12]	// lam, lam
// sw_def_radio.cpp:261:   float freq = (LIGHT_SPEED/lam);
	ldr	s0, [sp, 12]	// tmp76, lam
	mov	w0, 62402	// tmp79,
	movk	w0, 0x4d8e, lsl 16	// tmp79,,
	fmov	s1, w0	// tmp77, tmp79
	fdiv	s0, s1, s0	// tmp75, tmp77, tmp76
	str	s0, [sp, 28]	// tmp75, freq
// sw_def_radio.cpp:263:   return freq;
	ldr	s0, [sp, 28]	// _3, freq
// sw_def_radio.cpp:264: }
	add	sp, sp, 32	//,,
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE252:
	.size	_Z7getFreqf, .-_Z7getFreqf
	.align	2
	.global	sqrt
	.type	sqrt, %function
sqrt:
.LFB253:
	.cfi_startproc
	sub	sp, sp, #48	//,,
	.cfi_def_cfa_offset 48
	str	d0, [sp, 8]	// num, num
// sw_def_radio.cpp:271: 	x0 = num;		// an initial guess for x0
	ldr	d0, [sp, 8]	// tmp79, num
	str	d0, [sp, 40]	// tmp79, x0
// sw_def_radio.cpp:272: 	x1 = x0;		// Set x1 to x0
	ldr	d0, [sp, 40]	// tmp80, x0
	str	d0, [sp, 24]	// tmp80, x1
// sw_def_radio.cpp:273: 	for (i=1; i<=MAX_NUM; i++) {
	mov	w0, 1	// tmp81,
	str	w0, [sp, 20]	// tmp81, i
.L38:
// sw_def_radio.cpp:273: 	for (i=1; i<=MAX_NUM; i++) {
	ldr	w0, [sp, 20]	// tmp82, i
	cmp	w0, 100	// tmp82,
	bgt	.L35	//,
// sw_def_radio.cpp:274: 		x2 = (x1 + num/x1)/2.0;
	ldr	d0, [sp, 24]	// tmp83, x1
	ldr	d1, [sp, 8]	// tmp84, num
	fdiv	d1, d1, d0	// _1, tmp84, tmp83
	ldr	d0, [sp, 24]	// tmp85, x1
	fadd	d1, d1, d0	// _2, _1, tmp85
	fmov	d0, 2.0e+0	// tmp87,
	fdiv	d0, d1, d0	// tmp86, _2, tmp87
	str	d0, [sp, 32]	// tmp86, x2
// sw_def_radio.cpp:275: 		if (fabs(x2-x1) < FLT_EPSILON)
	ldr	d1, [sp, 32]	// tmp88, x2
	ldr	d0, [sp, 24]	// tmp89, x1
	fsub	d0, d1, d0	// _3, tmp88, tmp89
	fabs	d0, d0	// _4, _3
	mov	x0, 4503599627370496000	// tmp96,
	fmov	d1, x0	// tmp90, tmp96
	fcmpe	d0, d1	// _4, tmp90
	bmi	.L41	//,
// sw_def_radio.cpp:277: 		x1 = x2;	// update x1 for next iteration
	ldr	d0, [sp, 32]	// tmp91, x2
	str	d0, [sp, 24]	// tmp91, x1
// sw_def_radio.cpp:273: 	for (i=1; i<=MAX_NUM; i++) {
	ldr	w0, [sp, 20]	// tmp93, i
	add	w0, w0, 1	// tmp92, tmp93,
	str	w0, [sp, 20]	// tmp92, i
	b	.L38	//
.L41:
// sw_def_radio.cpp:276: 			break;
	nop
.L35:
// sw_def_radio.cpp:280: 	if (i<MAX_NUM)	// Number of iterations < N
	ldr	w0, [sp, 20]	// tmp94, i
	cmp	w0, 99	// tmp94,
	bgt	.L39	//,
// sw_def_radio.cpp:283: 		return x2;
	ldr	d0, [sp, 32]	// _9, x2
	b	.L40	//
.L39:
// sw_def_radio.cpp:287: 		return -1;
	fmov	d0, -1.0e+0	// _9,
.L40:
// sw_def_radio.cpp:289: }
	add	sp, sp, 48	//,,
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE253:
	.size	sqrt, .-sqrt
	.align	2
	.global	_Z15floatToStringLBf
	.type	_Z15floatToStringLBf, %function
_Z15floatToStringLBf:
.LFB254:
	.cfi_startproc
	sub	sp, sp, #1040	//,,
	.cfi_def_cfa_offset 1040
	stp	x29, x30, [sp]	//,,
	.cfi_offset 29, -1040
	.cfi_offset 30, -1032
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
	str	s0, [x29, 28]	// f, f
// sw_def_radio.cpp:292: char * floatToStringLB(float f){
	adrp	x0, :got:__stack_chk_guard	// tmp77,
	ldr	x0, [x0, #:got_lo12:__stack_chk_guard]	// tmp76, tmp77,
	ldr	x1, [x0]	// tmp84, __stack_chk_guard
	str	x1, [x29, 1032]	// tmp84, D.10685
	mov	x1,0	// tmp84
// sw_def_radio.cpp:294:     return gcvt(f,DATA_SIZE,buffer);
	ldr	s0, [x29, 28]	// tmp78, f
	fcvt	d0, s0	// _1, tmp78
	add	x0, x29, 32	// tmp79,,
	mov	x1, x0	//, tmp79
	mov	w0, 1000	//,
	bl	gcvt	//
// sw_def_radio.cpp:295: }
	adrp	x1, :got:__stack_chk_guard	// tmp82,
	ldr	x1, [x1, #:got_lo12:__stack_chk_guard]	// tmp81, tmp82,
	ldr	x2, [x29, 1032]	// tmp85, D.10685
	ldr	x1, [x1]	// tmp83, __stack_chk_guard
	eor	x1, x2, x1	// tmp83, tmp85
	cmp	x1, 0	// tmp83,
	beq	.L44	//,
	bl	__stack_chk_fail	//
.L44:
	ldp	x29, x30, [sp]	//,,
	add	sp, sp, 1040	//,,
	.cfi_restore 29
	.cfi_restore 30
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE254:
	.size	_Z15floatToStringLBf, .-_Z15floatToStringLBf
	.section	.rodata
	.align	3
.LC19:
	.string	"a"
	.align	3
.LC20:
	.string	"linkBudgetData.txt"
	.text
	.align	2
	.global	_Z17storeDataInFileLBf
	.type	_Z17storeDataInFileLBf, %function
_Z17storeDataInFileLBf:
.LFB255:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!	//,,,
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
	str	s0, [x29, 28]	// input, input
// sw_def_radio.cpp:298: 	FILE * fPtr = fopen(TXT_FILE_LB, "a");
	adrp	x0, .LC19	// tmp75,
	add	x1, x0, :lo12:.LC19	// tmp74, tmp75,
	adrp	x0, .LC20	// tmp77,
	add	x0, x0, :lo12:.LC20	// tmp76, tmp77,
	bl	fopen	//
	str	x0, [x29, 32]	// _3, fPtr
// sw_def_radio.cpp:299: 	char * data = floatToStringLB(input);
	ldr	s0, [x29, 28]	//, input
	bl	_Z15floatToStringLBf	//
	str	x0, [x29, 40]	//, data
// sw_def_radio.cpp:301: 	fputs(data, fPtr);
	ldr	x1, [x29, 32]	//, fPtr
	ldr	x0, [x29, 40]	//, data
	bl	fputs	//
// sw_def_radio.cpp:302: 	fputs("\n", fPtr);
	ldr	x1, [x29, 32]	//, fPtr
	mov	w0, 10	//,
	bl	fputc	//
// sw_def_radio.cpp:303:   	fclose(fPtr);
	ldr	x0, [x29, 32]	//, fPtr
	bl	fclose	//
// sw_def_radio.cpp:304: }
	nop
	ldp	x29, x30, [sp], 48	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE255:
	.size	_Z17storeDataInFileLBf, .-_Z17storeDataInFileLBf
	.section	.rodata
	.align	3
.LC21:
	.string	"w"
	.text
	.align	2
	.global	_Z19clearDataFromFileLBv
	.type	_Z19clearDataFromFileLBv, %function
_Z19clearDataFromFileLBv:
.LFB256:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!	//,,,
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
// sw_def_radio.cpp:307:   	FILE * fPtr = fopen(TXT_FILE_LB, "w");
	adrp	x0, .LC21	// tmp75,
	add	x1, x0, :lo12:.LC21	// tmp74, tmp75,
	adrp	x0, .LC20	// tmp77,
	add	x0, x0, :lo12:.LC20	// tmp76, tmp77,
	bl	fopen	//
	str	x0, [x29, 24]	// _3, fPtr
// sw_def_radio.cpp:308:   	fclose(fPtr);
	ldr	x0, [x29, 24]	//, fPtr
	bl	fclose	//
// sw_def_radio.cpp:309: }
	nop
	ldp	x29, x30, [sp], 32	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE256:
	.size	_Z19clearDataFromFileLBv, .-_Z19clearDataFromFileLBv
	.section	.rodata
	.align	3
.LC22:
	.string	"Please choose from the following: "
	.align	3
.LC23:
	.string	"1 to calculate twoWayPathLossDB "
	.align	3
.LC24:
	.string	"2 to calculate rxPwrWatts "
	.align	3
.LC25:
	.string	"3 to calculate rxPwrDBM "
	.align	3
.LC26:
	.string	"6 to clear all data from linkBudgetData.txt"
	.align	3
.LC27:
	.string	"7 for store to file"
	.align	3
.LC28:
	.string	"8 for quit"
	.align	3
.LC29:
	.string	" %i"
	.align	3
.LC30:
	.string	"Please enter freq in Ghz: "
	.align	3
.LC31:
	.string	" %f"
	.align	3
.LC32:
	.string	"Please enter distance in km: "
	.align	3
.LC33:
	.string	"Please enter radar cross section area in m^2: "
	.align	3
.LC34:
	.string	"Please enter TX power in Watts: "
	.align	3
.LC35:
	.string	"Please enter TX Antenna Gain in dB: "
	.align	3
.LC36:
	.string	"Please enter RX Antenna Gain in dB: "
	.align	3
.LC37:
	.string	"Please enter TX power in dBm: "
	.align	3
.LC38:
	.string	"linkBudgetData.txt is now cleared of all data"
	.align	3
.LC39:
	.string	"Writing data to file"
	.align	3
.LC40:
	.string	"Quitting"
	.align	3
.LC41:
	.string	"Wrong choice. Now exiting."
	.text
	.align	2
	.global	_Z14getUserInputLBv
	.type	_Z14getUserInputLBv, %function
_Z14getUserInputLBv:
.LFB257:
	.cfi_startproc
	stp	x29, x30, [sp, -64]!	//,,,
	.cfi_def_cfa_offset 64
	.cfi_offset 29, -64
	.cfi_offset 30, -56
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
// sw_def_radio.cpp:311: int getUserInputLB(){
	adrp	x0, :got:__stack_chk_guard	// tmp91,
	ldr	x0, [x0, #:got_lo12:__stack_chk_guard]	// tmp90, tmp91,
	ldr	x1, [x0]	// tmp190, __stack_chk_guard
	str	x1, [x29, 56]	// tmp190, D.10691
	mov	x1,0	// tmp190
// sw_def_radio.cpp:313:   	int exitFlag = 0;
	str	wzr, [x29, 52]	//, exitFlag
// sw_def_radio.cpp:315: 	printf("Please choose from the following: \n");
	adrp	x0, .LC22	// tmp93,
	add	x0, x0, :lo12:.LC22	// tmp92, tmp93,
	bl	puts	//
// sw_def_radio.cpp:316: 	printf("1 to calculate twoWayPathLossDB \n");
	adrp	x0, .LC23	// tmp95,
	add	x0, x0, :lo12:.LC23	// tmp94, tmp95,
	bl	puts	//
// sw_def_radio.cpp:317: 	printf("2 to calculate rxPwrWatts \n");
	adrp	x0, .LC24	// tmp97,
	add	x0, x0, :lo12:.LC24	// tmp96, tmp97,
	bl	puts	//
// sw_def_radio.cpp:318: 	printf("3 to calculate rxPwrDBM \n");
	adrp	x0, .LC25	// tmp99,
	add	x0, x0, :lo12:.LC25	// tmp98, tmp99,
	bl	puts	//
// sw_def_radio.cpp:319:   	printf("6 to clear all data from linkBudgetData.txt\n");
	adrp	x0, .LC26	// tmp101,
	add	x0, x0, :lo12:.LC26	// tmp100, tmp101,
	bl	puts	//
// sw_def_radio.cpp:320: 	printf("7 for store to file\n");
	adrp	x0, .LC27	// tmp103,
	add	x0, x0, :lo12:.LC27	// tmp102, tmp103,
	bl	puts	//
// sw_def_radio.cpp:321: 	printf("8 for quit\n");
	adrp	x0, .LC28	// tmp105,
	add	x0, x0, :lo12:.LC28	// tmp104, tmp105,
	bl	puts	//
// sw_def_radio.cpp:322: 	scanf(" %i", &var);
	add	x1, x29, 48	// tmp106,,
	adrp	x0, .LC29	// tmp108,
	add	x0, x0, :lo12:.LC29	// tmp107, tmp108,
	bl	scanf	//
// sw_def_radio.cpp:323: 	switch (var) {
	ldr	w0, [x29, 48]	// var.0_1, var
	cmp	w0, 3	// var.0_1,
	beq	.L49	//,
	cmp	w0, 3	// var.0_1,
	bgt	.L50	//,
	cmp	w0, 1	// var.0_1,
	beq	.L51	//,
	cmp	w0, 2	// var.0_1,
	beq	.L52	//,
	b	.L48	//
.L50:
	cmp	w0, 7	// var.0_1,
	beq	.L53	//,
	cmp	w0, 8	// var.0_1,
	beq	.L54	//,
	cmp	w0, 6	// var.0_1,
	beq	.L55	//,
	b	.L48	//
.L51:
// sw_def_radio.cpp:325: 			printf("Please enter freq in Ghz: \n");
	adrp	x0, .LC30	// tmp110,
	add	x0, x0, :lo12:.LC30	// tmp109, tmp110,
	bl	puts	//
// sw_def_radio.cpp:326: 			scanf(" %f", &f);
	add	x1, x29, 24	// tmp111,,
	adrp	x0, .LC31	// tmp113,
	add	x0, x0, :lo12:.LC31	// tmp112, tmp113,
	bl	scanf	//
// sw_def_radio.cpp:327: 			printf("Please enter distance in km: \n");
	adrp	x0, .LC32	// tmp115,
	add	x0, x0, :lo12:.LC32	// tmp114, tmp115,
	bl	puts	//
// sw_def_radio.cpp:328: 			scanf(" %f", &d);
	add	x1, x29, 28	// tmp116,,
	adrp	x0, .LC31	// tmp118,
	add	x0, x0, :lo12:.LC31	// tmp117, tmp118,
	bl	scanf	//
// sw_def_radio.cpp:329: 			printf("Please enter radar cross section area in m^2: \n");
	adrp	x0, .LC33	// tmp120,
	add	x0, x0, :lo12:.LC33	// tmp119, tmp120,
	bl	puts	//
// sw_def_radio.cpp:330: 			scanf(" %f", &xs);
	add	x1, x29, 32	// tmp121,,
	adrp	x0, .LC31	// tmp123,
	add	x0, x0, :lo12:.LC31	// tmp122, tmp123,
	bl	scanf	//
// sw_def_radio.cpp:331: 			twoWayPathLossDB(f,d,xs);
	ldr	s0, [x29, 24]	// f.1_2, f
	ldr	s1, [x29, 28]	// d.2_3, d
	ldr	s2, [x29, 32]	// xs.3_4, xs
	bl	_Z16twoWayPathLossDBfff	//
// sw_def_radio.cpp:332:       			break;
	b	.L56	//
.L52:
// sw_def_radio.cpp:334: 			printf("Please enter freq in Ghz: \n");
	adrp	x0, .LC30	// tmp125,
	add	x0, x0, :lo12:.LC30	// tmp124, tmp125,
	bl	puts	//
// sw_def_radio.cpp:335: 			scanf(" %f", &f);
	add	x1, x29, 24	// tmp126,,
	adrp	x0, .LC31	// tmp128,
	add	x0, x0, :lo12:.LC31	// tmp127, tmp128,
	bl	scanf	//
// sw_def_radio.cpp:336: 			printf("Please enter distance in km: \n");
	adrp	x0, .LC32	// tmp130,
	add	x0, x0, :lo12:.LC32	// tmp129, tmp130,
	bl	puts	//
// sw_def_radio.cpp:337: 			scanf(" %f", &d);
	add	x1, x29, 28	// tmp131,,
	adrp	x0, .LC31	// tmp133,
	add	x0, x0, :lo12:.LC31	// tmp132, tmp133,
	bl	scanf	//
// sw_def_radio.cpp:338: 			printf("Please enter TX power in Watts: \n");
	adrp	x0, .LC34	// tmp135,
	add	x0, x0, :lo12:.LC34	// tmp134, tmp135,
	bl	puts	//
// sw_def_radio.cpp:339: 			scanf(" %f", &txp);
	add	x1, x29, 36	// tmp136,,
	adrp	x0, .LC31	// tmp138,
	add	x0, x0, :lo12:.LC31	// tmp137, tmp138,
	bl	scanf	//
// sw_def_radio.cpp:340: 			printf("Please enter TX Antenna Gain in dB: \n");
	adrp	x0, .LC35	// tmp140,
	add	x0, x0, :lo12:.LC35	// tmp139, tmp140,
	bl	puts	//
// sw_def_radio.cpp:341: 			scanf(" %f", &gtdb);
	add	x1, x29, 40	// tmp141,,
	adrp	x0, .LC31	// tmp143,
	add	x0, x0, :lo12:.LC31	// tmp142, tmp143,
	bl	scanf	//
// sw_def_radio.cpp:342: 			printf("Please enter RX Antenna Gain in dB: \n");
	adrp	x0, .LC36	// tmp145,
	add	x0, x0, :lo12:.LC36	// tmp144, tmp145,
	bl	puts	//
// sw_def_radio.cpp:343: 			scanf(" %f", &grdb);
	add	x1, x29, 44	// tmp146,,
	adrp	x0, .LC31	// tmp148,
	add	x0, x0, :lo12:.LC31	// tmp147, tmp148,
	bl	scanf	//
// sw_def_radio.cpp:344: 			rxPwrWatts(txp,gtdb,grdb,d,f);
	ldr	s0, [x29, 36]	// txp.4_5, txp
	ldr	s1, [x29, 40]	// gtdb.5_6, gtdb
	ldr	s2, [x29, 44]	// grdb.6_7, grdb
	ldr	s3, [x29, 28]	// d.7_8, d
	ldr	s4, [x29, 24]	// f.8_9, f
	bl	_Z10rxPwrWattsfffff	//
// sw_def_radio.cpp:346: 			break;
	b	.L56	//
.L49:
// sw_def_radio.cpp:348: 			printf("Please enter freq in Ghz: \n");
	adrp	x0, .LC30	// tmp150,
	add	x0, x0, :lo12:.LC30	// tmp149, tmp150,
	bl	puts	//
// sw_def_radio.cpp:349: 			scanf(" %f", &f);
	add	x1, x29, 24	// tmp151,,
	adrp	x0, .LC31	// tmp153,
	add	x0, x0, :lo12:.LC31	// tmp152, tmp153,
	bl	scanf	//
// sw_def_radio.cpp:350: 			printf("Please enter distance in km: \n");
	adrp	x0, .LC32	// tmp155,
	add	x0, x0, :lo12:.LC32	// tmp154, tmp155,
	bl	puts	//
// sw_def_radio.cpp:351: 			scanf(" %f", &d);
	add	x1, x29, 28	// tmp156,,
	adrp	x0, .LC31	// tmp158,
	add	x0, x0, :lo12:.LC31	// tmp157, tmp158,
	bl	scanf	//
// sw_def_radio.cpp:352: 			printf("Please enter TX power in dBm: \n");
	adrp	x0, .LC37	// tmp160,
	add	x0, x0, :lo12:.LC37	// tmp159, tmp160,
	bl	puts	//
// sw_def_radio.cpp:353: 			scanf(" %f", &txp);
	add	x1, x29, 36	// tmp161,,
	adrp	x0, .LC31	// tmp163,
	add	x0, x0, :lo12:.LC31	// tmp162, tmp163,
	bl	scanf	//
// sw_def_radio.cpp:354: 			printf("Please enter TX Antenna Gain in dB: \n");
	adrp	x0, .LC35	// tmp165,
	add	x0, x0, :lo12:.LC35	// tmp164, tmp165,
	bl	puts	//
// sw_def_radio.cpp:355: 			scanf(" %f", &gtdb);
	add	x1, x29, 40	// tmp166,,
	adrp	x0, .LC31	// tmp168,
	add	x0, x0, :lo12:.LC31	// tmp167, tmp168,
	bl	scanf	//
// sw_def_radio.cpp:356: 			printf("Please enter RX Antenna Gain in dB: \n");
	adrp	x0, .LC36	// tmp170,
	add	x0, x0, :lo12:.LC36	// tmp169, tmp170,
	bl	puts	//
// sw_def_radio.cpp:357: 			scanf(" %f", &grdb);
	add	x1, x29, 44	// tmp171,,
	adrp	x0, .LC31	// tmp173,
	add	x0, x0, :lo12:.LC31	// tmp172, tmp173,
	bl	scanf	//
// sw_def_radio.cpp:358: 			rxPwrDBM(txp,gtdb,grdb,d,f);
	ldr	s0, [x29, 36]	// txp.9_10, txp
	ldr	s1, [x29, 40]	// gtdb.10_11, gtdb
	ldr	s2, [x29, 44]	// grdb.11_12, grdb
	ldr	s3, [x29, 28]	// d.12_13, d
	ldr	s4, [x29, 24]	// f.13_14, f
	bl	_Z8rxPwrDBMfffff	//
// sw_def_radio.cpp:359: 			break;
	b	.L56	//
.L55:
// sw_def_radio.cpp:361: 			clearDataFromFileLB();
	bl	_Z19clearDataFromFileLBv	//
// sw_def_radio.cpp:362: 			printf("linkBudgetData.txt is now cleared of all data");
	adrp	x0, .LC38	// tmp175,
	add	x0, x0, :lo12:.LC38	// tmp174, tmp175,
	bl	printf	//
// sw_def_radio.cpp:363: 			break;
	b	.L56	//
.L53:
// sw_def_radio.cpp:365: 			printf("Writing data to file\n");
	adrp	x0, .LC39	// tmp177,
	add	x0, x0, :lo12:.LC39	// tmp176, tmp177,
	bl	puts	//
// sw_def_radio.cpp:366: 			storeDataInFileLB(tempf);
	adrp	x0, tempf	// tmp179,
	add	x0, x0, :lo12:tempf	// tmp178, tmp179,
	ldr	s0, [x0]	// tempf.14_15, tempf
	bl	_Z17storeDataInFileLBf	//
// sw_def_radio.cpp:367: 			break;
	b	.L56	//
.L54:
// sw_def_radio.cpp:369: 			printf("Quitting\n");
	adrp	x0, .LC40	// tmp181,
	add	x0, x0, :lo12:.LC40	// tmp180, tmp181,
	bl	puts	//
// sw_def_radio.cpp:370: 			exitFlag = 1;
	mov	w0, 1	// tmp182,
	str	w0, [x29, 52]	// tmp182, exitFlag
// sw_def_radio.cpp:371: 			break;
	b	.L56	//
.L48:
// sw_def_radio.cpp:373: 			printf("Wrong choice. Now exiting.\n");
	adrp	x0, .LC41	// tmp184,
	add	x0, x0, :lo12:.LC41	// tmp183, tmp184,
	bl	puts	//
// sw_def_radio.cpp:374: 			exit(0);
	mov	w0, 0	//,
	bl	exit	//
.L56:
// sw_def_radio.cpp:377: 	if(0 != exitFlag) return 0;
	ldr	w0, [x29, 52]	// tmp185, exitFlag
	cmp	w0, 0	// tmp185,
	beq	.L57	//,
// sw_def_radio.cpp:377: 	if(0 != exitFlag) return 0;
	mov	w0, 0	// _17,
	b	.L59	//
.L57:
// sw_def_radio.cpp:378: 	getUserInputLB();
	bl	_Z14getUserInputLBv	//
// sw_def_radio.cpp:379: 	return 0;
	mov	w0, 0	// _17,
.L59:
// sw_def_radio.cpp:380: }
	adrp	x1, :got:__stack_chk_guard	// tmp188,
	ldr	x1, [x1, #:got_lo12:__stack_chk_guard]	// tmp187, tmp188,
	ldr	x2, [x29, 56]	// tmp191, D.10691
	ldr	x1, [x1]	// tmp189, __stack_chk_guard
	eor	x1, x2, x1	// tmp189, tmp191
	cmp	x1, 0	// tmp189,
	beq	.L60	//,
// sw_def_radio.cpp:380: }
	bl	__stack_chk_fail	//
.L60:
	ldp	x29, x30, [sp], 64	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE257:
	.size	_Z14getUserInputLBv, .-_Z14getUserInputLBv
	.align	2
	.global	main
	.type	main, %function
main:
.LFB258:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!	//,,,
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	add	x29, sp, 0	//,,
	.cfi_def_cfa_register 29
	str	w0, [x29, 28]	// argc, argc
	str	x1, [x29, 16]	// argv, argv
// sw_def_radio.cpp:384: 	twoWayPathLossDB(24, 50, 10);
	fmov	s2, 1.0e+1	//,
	mov	w0, 1112014848	// tmp76,
	fmov	s1, w0	//, tmp76
	fmov	s0, 2.4e+1	//,
	bl	_Z16twoWayPathLossDBfff	//
// sw_def_radio.cpp:385: 	getUserInputLB();
	bl	_Z14getUserInputLBv	//
// sw_def_radio.cpp:386: 	return 0;
	mov	w0, 0	// _4,
// sw_def_radio.cpp:387: }
	ldp	x29, x30, [sp], 32	//,,,
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE258:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
