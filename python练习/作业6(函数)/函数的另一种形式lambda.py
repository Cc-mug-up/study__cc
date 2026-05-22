r=lambda x:x+x
print(r(5))

def search(scores):
    t=sorted(scores.items(),key=lambda d:(d[1][0]+d[1][1]+d[1][2])//3)
    return t[len(t)-1][0],t[0][0]
if __name__ == "__main__":
    dictScores={'Jerry':[87,85,91],'Mary':[76,83,88],'Tim':[97,95,89],'John':[77,83,81]}
    maxName,minName=search(dictScores)
    print('{0} got the first place,{1} got the last.'.format(maxName,minName))
    a=sorted(dictScores.items(),key=lambda d:d[0])
    print(a)
    a=sorted(dictScores.items(),key=lambda d:d[1][0])
    print(a)