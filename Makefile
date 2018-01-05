

build:
	gcc print_minute.c -Wall -o print_minute.o

clean:
	rm print_minute.o

run: build
	./bootstrap.sh
