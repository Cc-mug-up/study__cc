sum=0
i=1
while i<=100:
    sum+=i
    i=i+1
print(sum)

x=eval(input('Enter the first number:'))
y=eval(input('Enter the second number:'))
z=x*y
if x<y:
    x,y=y,x
while x%y!=0:
    x,y=y,x%y
print('最大公约数:',y)
print('最小公倍数:',z//y)