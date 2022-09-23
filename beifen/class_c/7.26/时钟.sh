#!/bin/bash
year=2022
month=7
day=26
hour=11
min=20
sec=0
for((;;))
{
((sec++))
sleep 1
while sec -eq 60
{
    sec = 0
    min++
}
while min -eq 60
    {
	min = 0
	hour++
    }
while hour -eq 24
    {
	hour = 0
	day++
    }
while day -eq 30
    {
	day = 0
	mounth++
    }
while mounth -eq 12
    {
	mouth = 0
	year++
    }
printf "%d-%02d-%02d %02d:%02d:%02d\r" $year $month $day $hour $min $sec
}
