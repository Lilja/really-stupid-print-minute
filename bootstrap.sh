#!/bin/sh

while :
do
    ./print_minute
    if [ $? -eq 1 ]; then
        ./print_minute
    fi

    echo "Sleeping for 10 seconds."
    sleep 10
done
