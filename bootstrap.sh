#!/bin/sh

while :
do
    ./printMinute.o
    if [ $? -eq 1 ]; then
        ./printMinute.o
    fi

    echo "Sleeping for 10 seconds."
    sleep 10
done
