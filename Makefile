

build:
	gcc printMinute.c -o printMinute.o

clean:
	rm printMinute.o

run: build
	./bootstrap.sh
