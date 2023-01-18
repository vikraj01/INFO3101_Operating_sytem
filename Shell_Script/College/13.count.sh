read s
v=`echo $s | tr -cd [`A-Za-z`] | tr [`A-Z`] [`a-z`] | tr -cd [aeiou] | wc -c`
echo $v