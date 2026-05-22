def oulashai(limit):
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
    return is_prime,primes
def merse(n):
    merseNum=[]
    indexNum=[]
    for prime in primes:
        merseNum.append(2**prime-1)
        indexNum.append(prime)
        if len(merseNum)==n:
            break
    return merseNum,indexNum
is_prime,primes=oulashai(100000)
merseNum,indexNum=merse(5)
for i in range(0,5):
    print('2 ^',indexNum[i],' - 1 =',merseNum[i])