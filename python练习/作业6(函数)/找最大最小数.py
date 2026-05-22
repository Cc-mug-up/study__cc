def search(scores):
    maxScore=0
    minScore=100
    for k,v in scores.items():
        aveg = (scores[k][0]+scores[k][1]+scores[k][2])//3
        if aveg>=maxScore:
            maxScore=aveg
            maxName=k
        if aveg<=minScore:
            minScore=aveg
            minName=k
    return maxName,minName
if __name__ == "__main__":
    dictScores={'Jerry':[87,85,91],'Mary':[76,83,88],'Tim':[977,95,89],'John':[77,83,81]}
    maxName,minName=search(dictScores)
    print('{0} got the first place,{1} got the last.'.format(maxName,minName))