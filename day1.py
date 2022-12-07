f = open("input_1.txt", 'r')
lines = f.read().splitlines()

caloriesList = []
currentTotal = 0
for line in lines:
    # print(line)
    if line.strip() == "":
        caloriesList.append(currentTotal)
        currentTotal = 0
    else:
        currentTotal += int(line)

# Add last input
caloriesList.append(currentTotal)

sortedCalories = sorted(caloriesList, reverse=True)
# print(sortedCalories)
print("Part 1 (top 1): " + str(sortedCalories[0]))
print("Part 2 (top 3): " + str(sum(sortedCalories[0:3])))
