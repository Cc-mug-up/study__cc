#埃氏筛
n=100
is_prime=[True]*(n+1)
is_prime[0]=False
is_prime[1]=False
prime=[]
for i in range(2,n+1):
    if is_prime[i]==True:
        prime.append(i)
        for j in range(i*i,n+1,i):
            is_prime[j]=False
for p in prime:
    print(p) 