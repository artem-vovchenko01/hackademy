objects=$(wildcard *.c)
CC = cc
CFLAGS = -std=c99 -g

OBJS=$(patsubst %.c,%.o,$(objects))

all: $(OBJS)
	ar cr libft.a $(OBJS)

%.o: %.c
	style50 $<
	$(CC) $(CFLAGS) -c $< -o $@

clean: fclean

fclean:
	rm -rf *.o *.a *.out
