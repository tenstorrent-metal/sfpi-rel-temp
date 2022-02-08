SFPI_ROOT ?= ..
CC_PATH ?= $(SFPI_ROOT)/compiler

X86_INCLUDES = $(SFPI_ROOT)/include/sfpi.h $(SFPI_ROOT)/include/sfpi_fp16.h $(SFPI_ROOT)/include/sfpi_internal.h

X86_CC = g++
X86_CFLAGS = -I$(SFPI_ROOT)/include -O3 -std=c++17 -Wall -DARCH_GRAYSKULL -DCOMPILE_FOR_EMULE

SRCS = fp16c.cc

SIMS = $(addprefix x86/,$(SRCS:.cc=))

all: $(ASMS) $(EXES) $(SIMS)

x86:
	mkdir x86

x86/%.o: %.cc $(X86_INCLUDES) | x86
	$(X86_CC) $(X86_CFLAGS) -c -o $@ $<

x86/%: x86/%.o | x86
	$(X86_CC) $(X86_CFLAGS) -o $@ $<

clean:
	@rm -rf x86
	@rm -rf core.*
	@rm -f *~*

.PHONY: all clean
