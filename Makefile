# CC=gcc
# # CFLAGS=-DDEBUG

# all: bfi

# stack.o: stack.c
# 	$(CC) $(CFLAGS) -c stack.c
# mem.o: mem.c
# 	$(CC) $(CFLAGS) -c mem.c

# bfi: stack.h stack.o mem.h mem.o
# 	$(CC) $(CFLAGS) bfi.c mem.o stack.o -o bfi.exe	

# clean:
# 	rm -fr main stack.o

# stack_test: stack.h stack.o
# 	$(CC) $(CFLAGS) main.c stack.o -o main	

CC=gcc
CFLAGS=-I./Inc -m32

NASM=nasm
ASMFLAGS=-felf

OUT_DIR=Out

# all: $(OUT_DIR)/bfi

$(OUT_DIR)/stack.o: Src/stack.c Inc/stack.h
	@$(CC) $(CFLAGS) -c Src/stack.c -o $(OUT_DIR)/stack.o

$(OUT_DIR)/mem.o: Src/mem.c Inc/mem.h
	@$(CC) $(CFLAGS) -c Src/mem.c -o $(OUT_DIR)/mem.o

$(OUT_DIR)/bfi: $(OUT_DIR)/stack.o $(OUT_DIR)/mem.o
	@$(CC) $(CFLAGS) Src/bfi.c $(OUT_DIR)/mem.o $(OUT_DIR)/stack.o -o $(OUT_DIR)/bfi

clean:
	@rm -fr $(OUT_DIR)/*

compiler: $(OUT_DIR)/bfi

run: compiler
	@Out/./bfi ">++++++++[<+++++++++>-]<.>++++[<+++++++>-]<+.+++++++..+++.>>++++++[<+++++++>-]<++.------------.>++++++[<+++++++++>-]<+.<.+++.------.--------.>>>++++[<++++++++>-]<+." >> Out/hello.asm
	@$(CC) $(CFLAGS) -c Src/mem.c -o $(OUT_DIR)/mem.o
	@$(NASM) Out/hello.asm -felf
	@$(CC) $(CFLAGS) $(OUT_DIR)/mem.o $(OUT_DIR)/hello.o -o $(OUT_DIR)/hello


make a:
	$(OUT_DIR)/./hello