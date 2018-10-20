# change the name of output library
TARGET=io.a

# compiler
CC=gcc
ASM=nasm
LD=gcc -c
AR=ar

# Specific C compiler flags
OPT=-O2
WARN=-Wall -Wextra
STD=c11

# compiler, assembler, linker flags
CCFLAGS= -m32 $(WARN) -std="$(STD)" $(OPT)
ASMFLAGS= -f elf32
LINKERFLAGS= -m32 #  -m elf_i386

# source files
CCSRCS  = $(wildcard *.c)
ASMSRCS = $(wildcard *.asm)
SRCS = $(CCSRCS) $(ASMSRCS)

# object files
CCOBJS  = $(patsubst %.c, %_c.o, $(CCSRCS))
ASMOBJS = $(patsubst %.asm, %_asm.o, $(ASMSRCS))
OBJS = $(CCOBJS) $(ASMOBJS)

.PHONY: default all clean

all: default

default: $(TARGET)

%_c.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

%_asm.o: %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

$(TARGET): $(OBJS)
	$(AR) rcs ../$(TARGET) $(OBJS)


.PRECIOUS: $(TARGET) $(OBJS)

clean:
	$(RM) -f *.o ../$(TARGET)
