#!/bin/bash
# Write a shell script to make a password based menu-driven program, which will give three
# chances to enter the password in case of wrong password. If the given password is correct then
# the program will show the
# a) Number of users currently logged in.
# b) Calendar of current month.
# c) Date in the format: dd / mm / yyyy.
# d) Exit

# Prompt for password
read -s -p "Enter password: " password

# Loop for 3 chances
for i in {1..3}
do
    # Check if password is correct
    if [ "$password" == "correctpassword" ]; then
        # Show menu options
        echo "1) Number of users currently logged in"
        echo "2) Calendar of current month"
        echo "3) Date in the format: dd / mm / yyyy"
        echo "4) Exit"

        # Prompt for menu option
        read -p "Enter option: " option

        # Perform action based on menu option
        case $option in
            1) who | wc -l;;
            2) cal;;
            3) date "+%d/%m/%Y";;
            4) exit;;
            *) echo "Invalid option";;
        esac
        break
    else
        # Prompt for password again
        read -s -p "Incorrect password. Enter password: " password
    fi
done

# If password is incorrect after 3 attempts
if [ "$i" == "3" ]; then
    echo "Access denied. Exiting program."
    exit
fi
