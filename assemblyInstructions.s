	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 5
	.globl	_byteInterpetation              ; -- Begin function byteInterpetation
	.p2align	2
_byteInterpetation:                     ; @byteInterpetation
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	w8, #65
	stur	w8, [x29, #-4]
	ldur	w8, [x29, #-4]
	sturb	w8, [x29, #-5]
	ldursb	w10, [x29, #-5]
	mov	x9, sp
                                        ; implicit-def: $x8
	mov	x8, x10
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	ldur	w9, [x29, #-4]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	mov	w0, #0
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_demonstrate_memory_reuse       ; -- Begin function demonstrate_memory_reuse
	.p2align	2
_demonstrate_memory_reuse:              ; @demonstrate_memory_reuse
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	x0, #4
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
	bl	_malloc
	stur	x0, [x29, #-8]
	ldur	x8, [x29, #-8]
	ldr	w9, [x8]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	ldur	x9, [x29, #-8]
	mov	w8, #100
	str	w8, [x9]
	ldur	x8, [x29, #-8]
	ldr	w9, [x8]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	ldur	x0, [x29, #-8]
	bl	_free
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	bl	_malloc
	str	x0, [sp, #16]
	ldr	x8, [sp, #16]
	ldr	w9, [x8]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	mov	w0, #0
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3, 0x0                          ; -- Begin function main
lCPI2_0:
	.quad	0x3ff4cccccccccccd              ; double 1.3
lCPI2_1:
	.quad	0x406681999999999a              ; double 180.05000000000001
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	.cfi_def_cfa_offset 64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	w8, #0
	str	w8, [sp, #20]                   ; 4-byte Folded Spill
	stur	wzr, [x29, #-4]
	adrp	x8, lCPI2_1@PAGE
	ldr	d0, [x8, lCPI2_1@PAGEOFF]
	stur	d0, [x29, #-16]
	ldur	d0, [x29, #-16]
	mov	x8, sp
	str	d0, [x8]
	adrp	x0, l_.str.5@PAGE
	add	x0, x0, l_.str.5@PAGEOFF
	bl	_printf
	adrp	x8, lCPI2_0@PAGE
	ldr	d0, [x8, lCPI2_0@PAGEOFF]
	str	d0, [sp, #24]
	ldr	d0, [sp, #24]
	mov	x8, sp
	str	d0, [x8]
	adrp	x0, l_.str.6@PAGE
	add	x0, x0, l_.str.6@PAGEOFF
	bl	_printf
	ldr	w0, [sp, #20]                   ; 4-byte Folded Reload
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"%c\n"

l_.str.1:                               ; @.str.1
	.asciz	"%d\n"

l_.str.2:                               ; @.str.2
	.asciz	"Memory before: %d\n"

l_.str.3:                               ; @.str.3
	.asciz	"Stored: %d\n"

l_.str.4:                               ; @.str.4
	.asciz	"Memory after reallocation: %d\n"

l_.str.5:                               ; @.str.5
	.asciz	"%f\n"

l_.str.6:                               ; @.str.6
	.asciz	"%f"

.subsections_via_symbols
