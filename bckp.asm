; See kood on transleeritud Brainfuck programmist:
; +++.
global main
extern mem_add
extern mem_move
extern mem_inc
extern mem_dec
extern mem_left
extern mem_rigth
extern mem_get
extern mem_set
extern mem_printDebug

extern putchar

section .text

; +++[-#]
main:
    ; +++
    call mem_inc
    call mem_inc
    call mem_inc

    ; [
silt_3:
    call mem_get
    cmp eax, 0
    je silt_6

    ; -
    call mem_dec

    ; #
    call mem_printDebug

    ; ]
    jmp silt_3
silt_6


    ret
