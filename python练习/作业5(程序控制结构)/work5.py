n=int(input("len:"))
max=0
l=[1,3,4,2,6,7,6,8,9,2,4,2]
for i in range(n-1,len(l)):
    t=1
    for j in range(n):
        t*=l[i-j]
    if(max<t):
        max=t
print(max)



