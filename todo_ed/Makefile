c:
	gcc -o main main.c

p:
	gcc -E -o proc main.c; vim -c :g/^#/d proc

clean:
	rm *.o main
