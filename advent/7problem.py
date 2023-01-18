total = 0
temp = 0
MAX = 100000
with open("file.txt") as file_in:
    for line in file_in:
        size = [int(i) for i in line.split() if i.isdigit()]
        if len(size) == 1:
            temp += size[0]

        isNew = line.split(' ')[1].strip('\n')
        if isNew == "ls":
            if temp < MAX:
                print(temp)
                total += temp
            temp = 0
print(total)
