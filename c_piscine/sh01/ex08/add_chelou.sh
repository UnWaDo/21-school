#!/bin/sh

# 0	'	m	g
# 1	\	r	t
# 2	"	d	a
# 3	?	o	i
# 4	!	c	o
# 5			" "
# 6			l
# 7			u
# 8			S
# 9			n
# 10			e
# 11			m
# 12			f

FT_NBR1="\\'?\"\\"'"
sub1="'\\\"?!"
num="01234"

echo $FT_NBR1
echo $sub1
echo $num

# FT_NBR2=rcrdmddd
# echo $FT_NBR2

# echo $'\'\\"?!' | tr $sub1 $num
# echo $FT_NBR1 | tr $sub1 $num
# echo "mrdocmd" | tr "mrdoc" "01234"

# f1=$(echo '$FT_NBR1' | tr '\'\\"?!' '01234')
# f2=$(echo '$FT_NBR2' | tr 'mrdoc' '01234')
# echo $f1
# echo $f2
