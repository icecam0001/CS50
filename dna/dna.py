import csv
import sys

filename= sys.argv[1]
result = {}
def main():
    data = ""
    longestAGAT = 0
    longestTATC = 0
    longestAATG = 0
    keyone=""
    keytwo=""
    keythree=""

    with open(filename) as file:
        reader = csv.DictReader(file)
        for row in reader:
            name_list = []
            name = row['name']
            keyone=list(row.keys())[1]
            keytwo=list(row.keys())[2]
            keythree=list(row.keys())[3]




            name_list.append(row[keyone])
            name_list.append(row[keytwo])
            name_list.append(row[keythree])

            result[name] = name_list
    longestAGAT = longest_match(keyone)
    longestTATC = longest_match(keytwo)
    longestAATG = longest_match(keythree)
    for persons in result:
        print(longestAGAT, int(result[persons][0]) )
        print(longestTATC, int(result[persons][1]) )
        print(longestAATG, int(result[persons][2]) )

        if longestAGAT == int(result[persons][0]):
            if longestTATC == int(result[persons][1]):
                if longestAATG == int(result[persons][2]):
                    print(f"{persons} is a match")
                    return
    else:
        print("No match today")
    # TODO: Check for command-line usage

    # TODO: Read database file into a variable

    # TODO: Read DNA sequence file into a variable

    # TODO: Find longest match of each STR in DNA sequence

    # TODO: Check database for matching profiles

    return


def longest_match(subsequence):
    length= len(subsequence)
    longestAGAT=0
    with open(sys.argv[2])as file:
        data = file.read()
        for i in range(len(data)):
            counter =0



            if (data[i:i+length] == subsequence):

                while True:
                    if (data[counter*length+i:(counter+1)*length+i]==subsequence):
                        counter+=1
                    else:
                        break
                if counter>longestAGAT:
                    longestAGAT = counter
                counter = 0
        return longestAGAT

main()
