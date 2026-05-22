a=int(input('please input a int type number:'))
b=[]
while(a!=0):
    x=a%10
    a//=10
    b.append(x)
print(b[0]*1000+b[1]*100+b[2]*10+b[3])