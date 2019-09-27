#!/bin/bash

# example line: char pinkish[] = { 0x1b, '[', '3', '8',';','5',';','2','1','2','m',0 };

for x in {000..255}; do
    full_line="char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', "
    full_line=$full_line$(echo $x | grep -o . | while read line; do
	echo "'$line',"
    done)
    #echo "{"$full_line" 'm', 0 }; std::cout << c << $x << std::endl;}"
    echo "{"$full_line" 'm', 0 };}"
done
