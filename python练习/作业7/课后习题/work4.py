fp=open(r'D:\86189\vscode\python练习\作业7\课后习题\Blowing in the word.txt','r+',encoding='utf-8')
startlines=['Bob Dylan\n','Blowing in the wind\n']
endline='1962 by Warner Bros. Inc.\n'
lines=fp.read()
fp.seek(0)
fp.writelines(startlines)
fp.write(lines)
fp.write(endline)
fp.seek(0)
shows=fp.readlines()
for show in shows:
    print(show)
fp.close()