reading_string = input("enter a string of text")
length = len(reading_string)
words = 0
sentences = 0
for i in reading_string:
    if i==" ":
        words+=1
    if i == "." or i=="?" or i=="!":
        sentences+=1
S = sentences/words *100
L = length/words *100

readinglevel = 0.0588 * L - 0.296 * S - 15.8
if readinglevel<1:
    print("Before grade 1")
elif readinglevel <16:
    print(int(readinglevel))

else:
    print("16+")
