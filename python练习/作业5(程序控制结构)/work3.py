flag=True
for n in range(100,1000):
    if n%37==0:
        i=n%10
        j=n//10%10
        k=n//100
        if (10*i+100*j+k)%37!=0:
            flag=False
            break
        if (100*i+j+10*k)%37!=0:
            flag=False
            break    
if(flag):
    print('这是一个真命题')
else:
    print('这是一个假命题')