## 'make' build executable file ##
## 'make clean' remove all .o and exe files ##

PAPIINC = ..
PAPILIB = libpapi.a

CC = gcc 

##Define compile time flags ##
CFLAGS += -I$(PAPIINC)

OS = $(shell uname)

TARGETS_NTHD = main

ifeq ($(OS), SunOS)
   LDFLAGS =  $(PAPILIB) -lcpc -lirc
   TARGETS = $(TARGETS_NTHD) 
else 
 ifeq ($(OS), AIX)
   CC = xlc
   LDFLAGS =  $(PAPILIB) -lpmapi -lirc
   TARGETS = $(TARGETS_NTHD) 
 else
    ifeq ($(OS), OSF1)
        LDFLAGS =  $(PAPILIB) -lrt -lirc
        TARGETS = $(TARGETS_NTHD)  
    else
        ifeq ($(OS), Linux)
             TARGETS = $(TARGETS_NTHD)
        else
             TARGETS = $(TARGETS_NTHD)  
        endif
        LDFLAGS =  $(PAPILIB) 
     endif
 endif
endif

all: $(TARGETS) 

$(TARGETS_NTHD):  %:%.o 
	$(CC) -o $@ $(CFLAGS) $^  $(LDFLAGS) -lirc 

clean:
	$(RM) *.o $(TARGETS) 

