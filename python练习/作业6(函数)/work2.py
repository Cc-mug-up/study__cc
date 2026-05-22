import random
def gcd(x,y):
    if(x<y):
        x,y=y,x
    while x%y!=0:
        x,y=y,x%y
    return y

num1=random.randint(1,100)
num2=random.randint(1,100)
if gcd(num1,num2)==1:
    print('{0} and {1} are prime'.format(num1,num2))
else:
    print('{0} and {1} are not prime'.format(num1,num2))