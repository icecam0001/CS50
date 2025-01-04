number = input("Number: ")
sum=0
z=0
if len(number)!=13 and len(number)!=15 and len(number)!=16:
    print("invalid number")
else:
    for i in number:
        z+=1
        if len(number)%2== 0:
            if z%2 ==0:
                sum += int(i)
            else:
                k = int(i)*2
                sum+=k%10
                sum+= int(k/10)
        else:
            if z%2 ==0:
                k = int(i)*2
                sum+=k%10
                sum+= int(k/10)
            else:
                sum+=int(i)
if sum%10 ==0:
    print("its legit")
    if (len(number)==15 and (number[1]=='4' or number[1] == '7') and num[0] == '3'):
        print("AMEX Gold like the king")
    elif (len(number) == 16 and number[0] == '5' and int(number[1]) <=5 and int(number[1])>=1):
        print("MASTERCARD")
    elif((len(number)==13 or len(number) == 16) and number[0]=='4'):
        print("VISA")
else:
    print("invalid")


