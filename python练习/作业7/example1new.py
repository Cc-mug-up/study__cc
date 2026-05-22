f1=open(r'D:\86189\vscode\python练习\作业7\companies.txt','r+')
lines=f1.readlines()
for i in range(len(lines)):
    lines[i]=str(i+1)+' '+lines[i]
f1.seek(0)
f1.writelines(lines)
f1.close()