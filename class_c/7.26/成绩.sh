#!/bin/bash
if [ $1 -ge 0 -a $1 -lt 60 ]
then
    echo "D"
elif [ $1 -ge 60 -a $1 -lt 80 ]
then
    echo "C"
elif [ $1 -ge 80 -a $1 -lt 90 ]
then
    echo "B"
elif [ $1 -ge 90 -a $1 -le 100 ]
then
    echo "A"
else
    echo "error"
fi
