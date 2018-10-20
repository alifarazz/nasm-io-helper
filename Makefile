TARGET=$(wildcard *.asm)
# compiler
ASM=nasm
LD=gcc -m32 -c

# compiler, assembler, linker flags
ASMFLAGS= -f elf32

# Library dirs
SUBDIRS= $(wildcard lib/*/)

# Static libs
STATIC_LIBS = $(wildcard lib/*.a)
STATIC_LIB_FLAGS = $(addprefix -l:, $(STATIC_LIBS))


.PHONY: default all clean

all: default

default: $(TARGET)

$(SUBDIRS):
	$(MAKE) --directory=$@

$(TARGET): $(SUBDIRS)
	$(ASM) $(ASMFLAGS) $@ -o $@.o
	$(LD) $(STATIC_LIB_FLAGS) $@.o -o $(subst .asm, , $@)
	# $(RM)  $@.o

.PRECIOUS: $(TARGET)

clean:
	$(RM) $(subst .asm, , $(TARGET)) *.o
