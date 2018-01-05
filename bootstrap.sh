#!/bin/sh

while :
do
    ./print_minute.o
    if [ $? -eq 1 ]; then
        ./print_minute.o
    fi

    echo "Sleeping for 10 seconds."
    sleep 10
done
