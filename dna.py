import csv
import sys
filename= sys.argv[1]
result = {}
with open(filename) as file:
    reader = csv.DictReader(file)
    for row in reader:
        name_list = []
        name = row['name']

        name_list.append(row['AGAT'])
        name_list.append(row['TATC'])
        name_list.append(row['AATG'])

        result[name] = name_list
with open(sys.argv[2])as file:


print(result)
