# change the name of output library
TARGET=main.o

# compiler
ASM=nasm

# compiler, assembler, linker flags
ASMFLAGS= -f elf32
LD=ld -m elf_i386

# source files
SRCS = $(wildcard *.asm)

# object files
OBJS = $(patsubst %.asm, %.o, $(SRCS))

.PHONY: default all clean

all: default

default: $(TARGET)

%.o: %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

$(TARGET): $(OBJS)
	$(LD) $(OBJS) -o $(TARGET)

.PRECIOUS: $(TARGET) $(OBJS)

clean:
	$(RM) -f *.o $(TARGET)
