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
    call mem_right ; >
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
silt_9: ; [
    call mem_get
    cmp eax, 0
    je silt_22

    call mem_left ; <
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_right ; >
    call mem_dec ; -
    jmp silt_9 ; ]
silt_22:

    call mem_left ; <
    call mem_get ; .
    push eax
    call putchar
    add esp, 4

    call mem_right ; >
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
silt_30: ; [
    call mem_get
    cmp eax, 0
    je silt_41

    call mem_left ; <
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_right ; >
    call mem_dec ; -
    jmp silt_30 ; ]
silt_41:

    call mem_left ; <
    call mem_inc ; +
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
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
silt_66: ; [
    call mem_get
    cmp eax, 0
    je silt_77

    call mem_left ; <
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_right ; >
    call mem_dec ; -
    jmp silt_66 ; ]
silt_77:

    call mem_left ; <
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
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
silt_102: ; [
    call mem_get
    cmp eax, 0
    je silt_115

    call mem_left ; <
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_right ; >
    call mem_dec ; -
    jmp silt_102 ; ]
silt_115:

    call mem_left ; <
    call mem_inc ; +
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
    call mem_right ; >
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
silt_148: ; [
    call mem_get
    cmp eax, 0
    je silt_160

    call mem_left ; <
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_inc ; +
    call mem_right ; >
    call mem_dec ; -
    jmp silt_148 ; ]
silt_160:

    call mem_left ; <
    call mem_inc ; +
    call mem_get ; .
    push eax
    call putchar
    add esp, 4

    ret
