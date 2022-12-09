f = open("input_9.txt", 'r')
lines = f.read().splitlines()

#################
# NUMBER OF KNOTS
#################
numOfKnots = 10
#################

knotsx = []
knotsy = []
visited = []

for k in range(numOfKnots):
    knotsx.append(0)
    knotsy.append(0)

def updateKnot(knot):
    global knotsx
    global knotsy
    if (knotsy[knot] == knotsy[knot - 1]):
        if (abs(knotsx[knot - 1] - knotsx[knot]) > 1):
            # Need to move knot x
            if (knotsx[knot - 1] < knotsx[knot]):
                knotsx[knot] -= 1
            else:
                knotsx[knot] += 1
    elif (knotsx[knot] == knotsx[knot - 1]):
        if (abs(knotsy[knot - 1] - knotsy[knot]) > 1):
            # Need to move knot y
            if (knotsy[knot - 1] < knotsy[knot]):
                knotsy[knot] -= 1
            else:
                knotsy[knot] += 1
    elif (abs(knotsx[knot - 1] - knotsx[knot]) > 1 or abs(knotsy[knot - 1] - knotsy[knot]) > 1):
        #Need to move knot diagonally
        if (knotsx[knot - 1] > knotsx[knot]):
            knotsx[knot] += 1
        else:
            knotsx[knot] -= 1
        if (knotsy[knot - 1] > knotsy[knot]):
            knotsy[knot] += 1
        else:
            knotsy[knot] -= 1
    printPos()

def updateRope():
    for k in range(1, numOfKnots):
        updateKnot(k)
    tail = [knotsx[numOfKnots - 1], knotsy[numOfKnots - 1]]
    if not tail in visited:
        visited.append(tail)

def printPos():
    x = "x: "
    y = "y: "
    for k in range(numOfKnots):
        x += "(" + f'{knotsx[k]:4}' + ") "
        y += "(" + f'{knotsy[k]:4}' + ") "
    print(x)
    print(y)
    print()

for line in lines:
    print(line)
    if (line[0] == "R"):
        for i in range(int(line.split()[1])):
            knotsx[0] += 1
            updateRope()
    if (line[0] == "L"):
        for i in range(int(line.split()[1])):
            knotsx[0] -= 1
            updateRope()
    if (line[0] == "U"):
        for i in range(int(line.split()[1])):
            knotsy[0] += 1
            updateRope()
    if (line[0] == "D"):
        for i in range(int(line.split()[1])):
            knotsy[0] -= 1
            updateRope()

print("Rope with " + str(numOfKnots) + " knots - Tail VISITED: " + str(len(visited)))