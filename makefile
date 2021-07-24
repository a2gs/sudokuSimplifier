# Andre Augusto Giannotti Scota (https://sites.google.com/view/a2gs/)
# C flags:
CFLAGS_OPTIMIZATION = -g
#CFLAGS_OPTIMIZATION = -O3
CFLAGS_VERSION = -std=c11
CFLAGS_WARNINGS = -Wall -Wextra -Wno-unused-parameter -Wno-unused-but-set-parameter
CFLAGS_DEFINES = -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L -D_POSIX_SOURCE=1 -D_DEFAULT_SOURCE=1 -D_GNU_SOURCE=1
CFLAGS = $(CFLAGS_OPTIMIZATION) $(CFLAGS_VERSION) $(CFLAGS_WARNINGS) $(CFLAGS_DEFINES)

# System shell utilities
CC = gcc
RM = rm -fr
CP = cp
AR = ar
RANLIB = ranlib
CPPCHECK = cppcheck

INCLUDEPATH = -I./
LIBS = 
LIBPATH = -L./

all: clean exectag

exectag:
	@echo
	@echo "=== Compiling =============="
	$(CC) -o sudokuSimplifier sudokuSimplifier.c $(CFLAGS) $(INCLUDEPATH) $(LIBPATH) $(LIBS)

test: cleantest
	$(CC) -o test test.c $(CFLAGS) $(INCLUDEPATH) $(LIBPATH) $(LIBS)

cleantest:
	-rm test.exe


clean: cleantest
	@echo
	@echo "=== clean_data =============="
	-$(RM) sudokuSimplifier core
