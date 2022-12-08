f = open("input_8.txt", 'r')
rows = f.read().splitlines()

width = len(rows[0])
height = len(rows)

grid = []

def printGrid():
    for y in range(height):
        s = " "
        for x in range(width):
            s += grid[y][x] + " "
        print(s)

def seenFromDirection(searchRange, tree):
    # print(searchRange)
    if (max(searchRange) < tree):
        return True
    return False

def countInDirection(searchRange, tree, reverse):
    count = 0
    if (reverse):
        searchRange.reverse()
    # print(searchRange)
    for t in searchRange:
        count += 1
        if (int(t) >= int(tree)):
            return count
    return count

for row in rows:
    r = []
    for c in row:
        r.append(c)
    grid.append(r)

cols = [[row[i] for row in grid] for i in range(width)]

outsideTrees = height * 2 + width * 2 - 4
totalTrees = outsideTrees

maxScenicScore = 0

for x in range(1, width - 1):
    for y in range(1, height - 1):
        tree = grid[y][x]

        # Part 1
        if (seenFromDirection(grid[y][:x], tree) or     # left
            seenFromDirection(grid[y][x+1:], tree) or   # right
            seenFromDirection(cols[x][:y], tree) or     # up
            seenFromDirection(cols[x][y+1:], tree)):    # down
            totalTrees += 1

        # Part 2
        left    = countInDirection(grid[y][:x], tree, True)
        right   = countInDirection(grid[y][x+1:], tree, False)
        up      = countInDirection(cols[x][:y], tree, True)
        down    = countInDirection(cols[x][y+1:], tree, False)
        scenicScore = left * right * up * down
        # print(tree + "\t" + str(scenicScore) + " -> " + str(left) + ", " + str(right) + ", " + str(up) + ", " + str(down))
        maxScenicScore = max(maxScenicScore, scenicScore)

# printGrid()

print("Part 1 TOTAL: " + f'{totalTrees:7,}')
print("Part 2   MAX: " + f'{maxScenicScore:7,}')
