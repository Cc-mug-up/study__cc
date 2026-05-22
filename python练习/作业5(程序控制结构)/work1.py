import math
a=int(input("Please input the first edge:"))
b=int(input("Please input the second edge:"))
c=int(input("Please input the third edge:"))
if a+b<=c or a+c<=b or b+c<=a:
    print("error!")
else:
    p=(a+b+c)/2
    print('c = ',p*2)
    print('s = ',(p*(p-a)*(p-b)*(p-c))**(1/2))
