def numsChain(num):
    chain=[]
    chain.append(num)
    cur=num
    while True:
        ls=0
        while cur!=0:
            t=cur%10
            ls+=t*t
            cur//=10
        chain.append(ls)
        if ls==89 or ls==1:
            break
        cur=ls
    i=0
    for k in chain:
        print(k,end="")
        if i!=len(chain)-1:
            print("->",end="")
        i+=1
if __name__ == "__main__":
    num=int(input("enter a number:"))
    numsChain(num)