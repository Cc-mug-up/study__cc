from math import sqrt
def isprime(x):
    if x==1:
        return False
    k=int(sqrt(x))
    for j in range(2,k+1):
        if x%j==0:
            return False
    return True
if __name__ == "__main__":
    for i in range(1,101):
        if isprime(i)==True:
            print(i,end=" ")