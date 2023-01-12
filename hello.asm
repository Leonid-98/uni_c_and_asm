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
    ;;;; Instruktsioon +++
    push dword 3
    call mem_add

    ; Puhastame magasini
    add esi, 4

    ;;;; Instruktsioon +
    call mem_inc

    ;;;; Instruktsioon +
    call mem_inc

    ;;;; Instruktsioon .
    ; eax = mem_get();
    call mem_get

    ; putchar(eax);
    push eax
    call putchar

    ; Puhastame magasini
    add esp, 4

    ;;;; Programmi lõpp
    ret

