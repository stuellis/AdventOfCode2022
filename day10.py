f = open("input_10.txt", 'r')
lines = f.read().splitlines()

# Changed from the puzzle '#' and '.' for easier reading
fillChar = '0'
emptyChar = ' '

cycle = 0
X = 1
totalSignalStrength = 0
CRT = []
sprite = [0, 1, 2]

def doCycle():
    global cycle
    global totalSignalStrength
    cycle += 1
    if (((cycle - 1) % 40) in sprite):
        CRT.append(fillChar)
    else:
        CRT.append(emptyChar)
    
    cycleString = " > c: " + f'{cycle:3}' + " == x: " + f'{X:2}'
    if ((cycle - 20) % 40 == 0):
        signalStrength = cycle * X
        totalSignalStrength += signalStrength
        cycleString += " >> Signal strength: " + str(signalStrength)
    # print(cycleString)

def printCRT():
    for row in range(6):
        rowString = ""
        for i in range(40):
            rowString += CRT[row * 40 + i]
        print(rowString)

for line in lines:
    # print(line)
    doCycle()
    if (line[:4] == "addx"):
        doCycle()
        X += int(line.split()[1])
        sprite = [X - 1, X, X + 1]

print()
print("Part 1 TOTAL: " + f'{totalSignalStrength:,}')

print("\nPart 2:")
printCRT()
print()
