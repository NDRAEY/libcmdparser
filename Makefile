OBJS=cmdparser.o
CFLAGS?=-O2 -Wall -Wextra
LIB=libcmdparser.a

all: $(LIB)

$(LIB): $(OBJS)
	ar rcs $(LIB) $(OBJS)

$(OBJS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	-rm $(OBJS)
	-rm $(LIB)
