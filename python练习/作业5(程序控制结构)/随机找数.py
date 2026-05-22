from random import randint
x=randint(0,300)
for count in range(5):
    digit=int(input('Please input a number between 0~300:'))
    if digit == x:
        print('Bingo!')
    elif digit > x:
        print('Too large,please try again.')
    else:
        print('Too small,please try again.')
print(x)