l=[]
i=0
while i<10:
    x=int(input("Please an num:"))
    l.append(x)
    i=i+1
l.sort()
point=int(4)
left,right=0,len(l)-1
while left<=right:
    mid=(left+right)//2
    if l[mid]>point:
        right=mid-1
    elif l[mid]<point:
        left=mid+1
    else:
        break
if left<=right : 
    print('find out!')
else:
    print('No Exist!')

