scores=[9,9,8.5,10,7,8,8,9,8,10]
scores.sort()
scores.pop()
scores.reverse()
scores.pop()
print(scores)
scorex=9
ans=0
scores.append(scorex)
for x in scores:
    ans+=x
ans/=9
print(ans)