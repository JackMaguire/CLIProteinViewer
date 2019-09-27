#!/bin/bash

# example line: char pinkish[] = { 0x1b, '[', '3', '8',';','5',';','2','1','2','m',0 };

x=0

#for x in {000..255}; do
grep XXX RGBs.txt | while read rgb_line; do
    r=`echo $rgb_line | awk -F, '{print $1}'`
    g=`echo $rgb_line | awk -F, '{print $2}'`
    b=`echo $rgb_line | awk -F, '{print $3}'`
    full_line="char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', "
    full_line=$full_line$(echo $x | grep -o . | while read line; do
	echo "'$line',"
    done)
    #echo "{"$full_line" 'm', 0 }; std::cout << c << $x << std::endl;}"
    echo "{"
    echo $(echo "    $full_line 'm', 0 };")
    #echo "  colors256[ $x ].chars = c;"
    echo "  std::stringstream ss;"
    echo "  ss << c;"
    echo "  std::string s = ss.str();"
    echo "  colors256[ $x ].cmd = std::move( s );"
    echo "  colors256[ $x ].r = $r;"
    echo "  colors256[ $x ].g = $g;"
    echo "  colors256[ $x ].b = $b;"
    echo "}"
    x=$((x+1))
done
