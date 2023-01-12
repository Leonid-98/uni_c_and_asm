
CC=gcc
CFLAGS=-I./Inc -m32

NASM=nasm
ASMFLAGS=-felf

OUT_DIR=Out


$(OUT_DIR)/stack.o: Src/stack.c Inc/stack.h
	@$(CC) $(CFLAGS) -c Src/stack.c -o $(OUT_DIR)/stack.o

$(OUT_DIR)/mem.o: Src/mem.c Inc/mem.h
	@$(CC) $(CFLAGS) -c Src/mem.c -o $(OUT_DIR)/mem.o

$(OUT_DIR)/bfi: $(OUT_DIR)/stack.o $(OUT_DIR)/mem.o
	@$(CC) $(CFLAGS) Src/bfi.c $(OUT_DIR)/mem.o $(OUT_DIR)/stack.o -o $(OUT_DIR)/bfi

clean:
	@rm -fr $(OUT_DIR)/*

compiler: clean $(OUT_DIR)/bfi

translator: compiler
	@Out/./bfi ">++++++++[<+++++++++>-]<.>++++[<+++++++>-]<+.+++++++..+++.>>++++++[<+++++++>-]<++.------------.>++++++[<+++++++++>-]<+.<.+++.------.--------.>>>++++[<++++++++>-]<+." >> $(OUT_DIR)/hello.asm
	@$(CC) $(CFLAGS) -c Src/mem.c -o $(OUT_DIR)/mem.o
	@$(NASM) Out/hello.asm -felf
	@$(CC) $(CFLAGS) $(OUT_DIR)/mem.o $(OUT_DIR)/hello.o -o $(OUT_DIR)/hello

run: translator
	@$(OUT_DIR)/./hello || /bin/true

    
	
