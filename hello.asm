global main
extern mem_add
extern mem_move
extern mem_inc
extern mem_dec
extern mem_left
extern mem_right
extern mem_get
extern mem_set
extern mem_printDebug

extern putchar

section .text
main:
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
silt_8: ; [
    call mem_get
    cmp eax, 0
    je silt_48

    call mem_right ; >
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
silt_14: ; [
    call mem_get
    cmp eax, 0
    je silt_33

    call mem_right ; >
    call mem_inc ; +
    call mem_inc ; +
    call mem_right ; >
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_right ; >
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_right ; >
    call mem_inc ; +
    call mem_left ; <
    call mem_left ; <
    call mem_left ; <
    call mem_left ; <
    call mem_dec ; -
    jmp silt_14 ; ]
silt_33:

    call mem_right ; >
    call mem_inc ; +
    call mem_right ; >
    call mem_inc ; +
    call mem_right ; >
    call mem_dec ; -
    call mem_right ; >
    call mem_right ; >
    call mem_inc ; +
silt_43: ; [
    call mem_get
    cmp eax, 0
    je silt_45

    call mem_left ; <
    jmp silt_43 ; ]
silt_45:

    call mem_left ; <
    call mem_dec ; -
    jmp silt_8 ; ]
silt_48:

    call mem_right ; >
    call mem_right ; >
    call mem_get ; .
    push eax
    call putchar
    add esp, 4

    call mem_right ; >
    call mem_dec ; -
    call mem_dec ; -
    call mem_dec ; -
    call mem_get ; .
    push eax
    call putchar
    add esp, 4

    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_get ; .
    push eax
    call putchar
    add esp, 4

    call mem_get ; .
    push eax
    call putchar
    add esp, 4

    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_get ; .
    push eax
    call putchar
    add esp, 4

    call mem_right ; >
    call mem_right ; >
    call mem_get ; .
    push eax
    call putchar
    add esp, 4

    call mem_left ; <
    call mem_dec ; -
    call mem_get ; .
    push eax
    call putchar
    add esp, 4

    call mem_left ; <
    call mem_get ; .
    push eax
    call putchar
    add esp, 4

    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_get ; .
    push eax
    call putchar
    add esp, 4

    call mem_dec ; -
    call mem_dec ; -
    call mem_dec ; -
    call mem_dec ; -
    call mem_dec ; -
    call mem_dec ; -
    call mem_get ; .
    push eax
    call putchar
    add esp, 4

    call mem_dec ; -
    call mem_dec ; -
    call mem_dec ; -
    call mem_dec ; -
    call mem_dec ; -
    call mem_dec ; -
    call mem_dec ; -
    call mem_dec ; -
    call mem_get ; .
    push eax
    call putchar
    add esp, 4

    call mem_right ; >
    call mem_right ; >
    call mem_inc ; +
    call mem_get ; .
    push eax
    call putchar
    add esp, 4

    call mem_right ; >
    call mem_inc ; +
    call mem_inc ; +
    call mem_get ; .
    push eax
    call putchar
    add esp, 4

    ret
