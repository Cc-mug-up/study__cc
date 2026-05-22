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
if __name__ == "__main__":
    is_prime,primes=oulashai(100000)
    m=int(input("input a number: "))
    n=int(input("input a number: "))
    fp=open(r'D:\86189\vscode\python练习\作业7\课后习题\out.txt','a+', encoding='utf-8')
    for i in range(m,n+1):
        if is_prime[i]==True:
            fp.write(str(i)+' ')

