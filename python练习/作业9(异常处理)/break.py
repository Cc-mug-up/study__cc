aList=[1,2,3,4,5]
i=0
while True:
    try:
        print(aList[i])
    except IndexError:
        print("index error!")
        break
    i+=1