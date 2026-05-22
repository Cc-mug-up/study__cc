l=['l','love','Python']
for word in l:
    print(word)
l=[0]*20
l[0]=1
l[1]=1
for i in range(2,20):
    l[i]=l[i-1]+l[i-2]
for i in range(20):
    print(l[i])