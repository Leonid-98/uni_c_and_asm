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
main:
    call mem_inc
    

    ;;;; Instruktsioon .
    ; eax = mem_get();
    call mem_get

    call mem_printDebug

    ; putchar(eax);
    push eax
    call putchar

    ; Puhastame magasini
    add esp, 4


    ;;;; Programmi lõpp
    ret
