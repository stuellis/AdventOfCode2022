class File:
    def __init__(self, name, size, dir, level):
        self.name = name
        self.size = size
        self.dir = dir
        self.level = level

    def __str__(self):
        return self.name + " (file, size=" + str(self.size) + ")"

    def calcSize(self):
        return self.size

class Dir:
    def __init__(self, name, dir, level):
        self.name = name
        self.size = 0
        self.contents = []
        self.dir = dir
        self.level = level

    def __str__(self):
        return self.name + " (dir, size=" + str(self.size) + ")"

    def add_file(self, name, size):
        F = File(name, size, self, self.level + 1)
        self.contents.append(F)

    def add_dir(self, name):
        D = Dir(name, self, self.level + 1)
        self.contents.append(D)

    def list(self):
        for c in self.contents:
            print(" " * self.level * 2 + "- " + str(c))
            if (type(c) is Dir):
                c.list()

    def getIndex(self, name):
        i = 0
        for c in self.contents:
            if (c.name == name):
                return i
            i += 1
        return -1

    def calcSize(self):
        sum = 0
        for c in self.contents:
            sum += int(c.calcSize())
        self.size = sum
        return self.size

    def sumDirs(self, limit):
        sum = 0
        if (self.size <= limit):
            sum += self.size
        for c in self.contents:
            if (type(c) is Dir):
                sum += c.sumDirs(limit)
        return sum

    def getDirSizes(self, sizeToFind):
        dirList = []
        if (self.size >= sizeToFind):
            dirList.append(self.size)
        for c in self.contents:
            if (type(c) is Dir):
                dirList = dirList + c.getDirSizes(sizeToFind)
        return dirList


f = open("input_7.txt", 'r')
lines = f.read().splitlines()

root = Dir("root", None, 0)
root.add_dir("/")

currentDir = root

for line in lines:
    # print("> " + currentDir.name + "\t" + line)
    if(line == "$ cd .."):
        # print("Up directory level")
        currentDir = currentDir.dir
    elif(line[0:4] == "$ cd"):
        # print("Change to directory")
        changeToDir = line.split()[2]
        currentDir = currentDir.contents[currentDir.getIndex(changeToDir)]
    elif(line[0:3] == "dir"):
        # print("Directory entry")
        dirName = line.split()[1]
        currentDir.add_dir(dirName)
    elif(line == "$ ls"):
        pass
    else:
        # print("File entry")
        size = line.split()[0]
        name = line.split()[1]
        currentDir.add_file(name, size)

root.calcSize()
# root.list()

# Part 1
sum = root.sumDirs(100000)
print("Part 1  SUM: " + f'{sum:,}')

# Part 2
currentUsed = root.contents[0].size
spare = 70000000 - currentUsed
toFind = 30000000 - spare

dirSizes = root.contents[0].getDirSizes(toFind)
print("Part 2 SIZE: " + f'{min(dirSizes):,}')
