
build:
	gcc print_minute.c -Wall -Wpedantic -o print_minute

clean:
	rm print_minute

run: build
	./print_minute
