def fac(n):
    if n==1:
         return 1
    else:
         return n*fac(n-1)
def hanoi(a,b,c,n):
    if n==1:
        print(a,'->',c)
    else:
        hanoi(a,c,b,n-1)
        print(a,'->',c)
        hanoi(b,a,c,n-1)
    
if __name__ == "__main__":
    print(fac(5))
    n=int(input('input the number of plates: '))
    hanoi('a','b','c',n)