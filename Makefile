
build:
	gcc print_minute.c -Wall -o print_minute

clean:
	rm print_minute

run: build
	./bootstrap.sh
