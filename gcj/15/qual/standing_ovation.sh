#!/bin/bash

read num_cases

for i in $(seq 1 $num_cases); do
	read s_max s
	s=$(echo $s | grep -o .)
	j=0
	tot=0
	ans=0
	for c in $s; do
		let "delta = j - tot"
		let "ans = delta > ans ? delta : ans"
		let "tot += c"
		let "j++"
	done
	printf "Case #%d: %d\n" $i $ans
done
