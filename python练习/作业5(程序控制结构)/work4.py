n=int(input("Please input an num:"))
while(n!=6174):
    l=[0]*4
    index=0
    while n!=0 and index<4:
        l[index]=n%10
        n//=10
        index+=1
    l.sort()
    n1=l[0]+10*l[1]+100*l[2]+1000*l[3]
    l.sort(reverse=True)
    n2=l[0]+10*l[1]+100*l[2]+1000*l[3]
    n=n1-n2
    print(f'{n1:04d} - {n2:04d} = {n:04d}')