#prog5-1.py
sd1 = 3
sd2 = 3
if sd1 == sd2:
    print("the area of square is:",sd1*sd2)
from random import randint
flag=False
while flag==False:
    x=randint(0,1)
    num=int(input('Please enter a num between 0~1:'))
    if x==num:
        print('Bingo!')
        flag=True
    else:
        print('Wrong!')