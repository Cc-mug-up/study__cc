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

lst=['B01','B02','B03','B05','B08','B10']
s='B01,B02,B03,B05,B08,B10'
num1=len(lst)
print(s)
print(num1)
num2=s.count(',')+1
num3=len(s.split(','))
print(num2,num3)