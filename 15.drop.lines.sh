# Write a shell script to drop the lines which are matched with a given word.

if [ $# -eq 1 ]
then 
    #sed -i "/$1/d" 15.txt
    grep -v $1 file.txt > temp && mv temp 15.txt 
else 
    echo "WRONG INPUT"
fi