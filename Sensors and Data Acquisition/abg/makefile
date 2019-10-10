WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

FLAGS = -DTEST_MAIN 

SRCS = main.c abg.c
OBJS = $(SRCS:%.c=%.o)

abg: $(OBJS)
	$(GCC) $(FLAGS) $(OBJS) -o abg

.c.o:
	$(GCC) $(FLAGS) -c $*.c


clean:
	rm -f abg *.o
