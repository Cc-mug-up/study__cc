f1=open(r'D:\86189\vscode\python练习\作业7\companies.txt')
lines=f1.readlines()
f1.close()
for i in range(len(lines)):
    lines[i]=str(i+1)+' '+lines[i]
f2=open(r'D:\86189\vscode\python练习\作业7\scompanies.txt','w')
f2.writelines(lines)
f2.close()