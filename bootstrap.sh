#!/bin/sh

while :
do
    ./a.out
    [ $? -eq 1 ] && ./a.out

    echo "Sleeping for 10 seconds."
    sleep 10
done
