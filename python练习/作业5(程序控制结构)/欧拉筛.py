#欧拉筛
n=100
is_prime=[True]*(n+1)
is_prime[0]=False
is_prime[1]=False
prime=[]
for i in range(2,n+1):
    if(is_prime[i]==True):
        prime.append(i)
    for j in prime:
        if j*i>n:
            break
        is_prime[j*i]=False
        if i%j==0:
            break
for p in prime:
    print(p)