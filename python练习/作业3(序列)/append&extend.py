bList=[1,2,3]
bList.append('111')
print(bList)
bList.extend('111')
print(bList)

a=[1,2,[3,4]]
print(a)
b=a.copy()
print(b[2])
b[1]=1
b[2][1]=5
print(b[1] is a[1])
print(b[2][1] is a[2][1])
import copy
a=[1,2,[3,4]]
print(a)
c=copy.deepcopy(a)
print(c[2])
c[1]=1
c[2][1]=5
print(c[1] is a[1])
print(c[2][1] is a[2][1])