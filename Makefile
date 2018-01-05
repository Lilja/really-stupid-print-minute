

build:
	gcc print_minute.c -o print_minute.o

clean:
	rm print_minute.o

run: build
	./bootstrap.sh
