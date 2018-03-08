# 'make'        build executable file 'matser'
# 'make clean'  removes all .o and executable files
#

# define the C compiler to use
CC = gcc

# define any compile-time flags
CFLAGS = -Wall -g

# define any directories containing header files other than /usr/include
#
INCLUDES = -I/home/newhall/include  -I../include

# define library paths in addition to /usr/lib
LFLAGS = -L/home/newhall/lib  -L../lib

# define any libraries to link into executable:
LIBS = -lm

# define the C source files
SRCS = main.c

OBJS = $(SRCS:.c=.o)

# define the executable file 
MAIN = Execute

.PHONY: depend clean

all:	$(MAIN)
	@echo 
	@echo  SLOPE-PMC-LIKWID Compilation Successfull 
	@echo  Use [ make clean ]  to clear compilation
	@echo 
$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^



