import csv

houses = {
    "Gryffindor": 0,
    "Huffflepuff": 0,
    "Ravenclaw": 0,
    "Slyntherin": 0
}

with open("file_name.csv", "r") as file:
    reader = csv.reader(file)
    next(reader)
    for row in reader:
        house = row[1]
        houses[house] += 1

for house in houses:
    print(f"{house}: {houses[house]}")