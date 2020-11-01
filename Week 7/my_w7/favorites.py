import csv

title_count = dict() # To store number of title and their counts

with open('CS50 2019 - Lecture 7 - Favorite TV Shows (Responses) - Form Responses 1.csv', 'r') as file:
    reader = csv.DictReader(file)

    for row in reader:
        #print(row['title'])
        title = row['title'].lower()
        if title in title_count:
            title_count[title] += 1
        else:
            title_count[title] = 1

#for k, v in sorted(title_count.items()):
    #print(v, k, sep=' | ')

def f(item): # sort dict by value
    return item[1]

for k, v in sorted(title_count.items(), key=f, reverse=True):
    print(k, v, sep=' | ')