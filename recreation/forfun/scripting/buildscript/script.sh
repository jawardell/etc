#!/bin/bash
#This script extracts the version number from the changelog.md file
#Asks the user for input about proceeding or not

echo 'Hello Human!'
head -n 1 src/changelog.md > temp
read firstline < temp
echo 1st line is: $firstline
read -a splitfirstline <<< $firstline
version=${splitfirstline[1]}
echo version is: $version
echo 'do you want to continue? (1 continue, 0 exit)'
read versioncontinue
regex='^[0-9]+'
if ! [[ $versioncontinue =~ $regex ]]
then
	echo not a number
elif [ $versioncontinue -eq 1 ]
then
	echo OK
elif [ $versioncontinue -eq 0 ]
then
	echo please come back when ur ready
else
	echo bad input
fi
