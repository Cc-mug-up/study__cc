def square(x,y):
    return x+y,x-y
from pStr import printStr
printStr()

def gcd(x,y):
    if x<y:
        x,y=y,x
    while x%y!=0:
        x,y=y,x%y
    return y

x=eval(input("Enter the first number:"))
y=eval(input("Enter the second number:"))
gcdxy=gcd(x,y)
print('GCD({0:d},{1:d})={2:d}'.format(x,y,gcdxy))
print(x*y/gcdxy)
