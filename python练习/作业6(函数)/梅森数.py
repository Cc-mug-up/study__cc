limit = 1000000
is_prime=[True] * (limit + 1)
is_prime[1]=False
is_prime[0]=False
primes=[]
for i in range(2,limit+1):
    if(is_prime[i]==True):
        primes.append(i)
    for j in primes:
        if j*i>limit:
            break
        is_prime[j*i]=False
        if i%j==0:
            break
merseNum=[]
indexNum=[]
n=6
for prime in primes:
    merseNum.append(2**prime-1)
    indexNum.append(prime)
    if len(merseNum)==6:
        break
for i in range(0,6):
    print('2^',indexNum[i],' - 1 =',merseNum[i])
