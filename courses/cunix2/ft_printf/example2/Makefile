CC = cc
SRCS = $(wildcard *.c)
SRCS += $(wildcard utils/*.c)
OBJS = $(SRCS:%.c=%.o)
CFLAGS = -c -g
RM = rm -f
NAME = printf.out
LNAME = libftprintf.a

all: $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	ar cr $(LNAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clear:
	$(RM) $(OBJS) $(NAME)

