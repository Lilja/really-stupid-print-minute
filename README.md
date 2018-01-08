# Really stupid print minute
Did you ever just want to find out what the current minute is for every 10 seconds? Look no further.

`print_minute.c` is a program that will print the current minute of the system.
The program will detect if the current minute has changed since the hard-coded minute in the program.

If current minute is different from now, it will:
* Open up itself and read, line by line
    * Stop at line 7 and inject the new minute
* Open a new file called `temp`
* Write all contents and the newly injected minute to `temp`
* Rename(move) `temp` to `print_minute.c`
* Compile itself with `make`(`make -s build`)
* Run recompiled version within the same process.

# Run
```shell
make run
```
