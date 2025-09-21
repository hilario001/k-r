CFLAGS=-Wall -Wextra -Werror -pedantic -ggdb -O
CFILES=td.c

main: $(CFILES)
	$(CC) $(CFLAGS) -o td $(CFILES)

clean:
	rm main *.txt *.o

deploy:
	mv td /usr/local/bin/
