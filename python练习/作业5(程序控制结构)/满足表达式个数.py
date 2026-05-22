i,j,k=0,0,0
count=0
for i in range(21):
    for j in range(51):
        k=100-5*i-2*j
        if k>=0:
            count+=1
print(count)