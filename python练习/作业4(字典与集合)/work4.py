footballSet=set(['xiao1','xiao2','xiao3','xiao4'])
basketballSet=set(['xiao1','xiao3','xiao5','xiao6'])
bothSet=footballSet&basketballSet
onlySet=footballSet^basketballSet
print(len(bothSet))
print(bothSet)
print(len(onlySet))
print(onlySet)