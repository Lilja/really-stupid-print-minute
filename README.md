# Really stupid print minute
Did you ever just want to find out what the current minute is for every 10 seconds? Look no further.

`printMinute.c` is a program that will print the current minute. The program will detect if the current minute
has changed since the hard-coded minute. 

If not, it will:
* Read itself line by line
    * Stop at line 6 and inject the new minute
* Open a new file called `temp`
* Write all contets and the newly injected file to `temp`
* Rename(move) `temp` to `printMinute.c`
* Compile itself with make(make -s build)
* exit with return code 1 to tell bootstraper that program has changed

Then after that, the bootstraper script will re-run the program and the current minute will be displayed again.
