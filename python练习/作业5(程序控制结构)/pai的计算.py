i=1
flag=1
sum=0
while i<50000000:
    if flag==1:
        sum+=1/i
    else:
        sum-=1/i
    i+=2
    flag=-flag
sum*=4
print('pai=',sum)