def isnumber(num):
    if num>='0' and num<='9':
        return True
    return False

fp=open(r'D:\86189\vscode\python练习\作业7\课后习题\subtitles.srt','r+', encoding='utf-8')
lines=fp.readlines()
fp.close()
results=[]
for line in lines:
    if isnumber(line[0])==False:
        results.append(line)
for dia in results:
    print(dia,end="")
fp=open(r'D:\86189\vscode\python练习\作业7\课后习题\subtitlesnew.txt','w+', encoding='utf-8')
for result in results:
    fp.write(result)
fp.close()
