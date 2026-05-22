n=int(input('Please input an num between 1~9:'))
count=0
for i in range(1,101):
    if i%n==0 or (i>10 and (i%10==n or i//10==n)):
        continue
    count+=1
    print(i,sep=',',end=' ')
    if count%10==0:
        print()
