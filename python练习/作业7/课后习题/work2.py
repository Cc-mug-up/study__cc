fp=open(r'D:\86189\vscode\python练习\作业7\课后习题\rel.txt','r+', encoding='gbk')
names=[]
lines=fp.readlines()
for line in lines:
    parts = line.strip().split(',')  
    name, id = parts
    names.append((name,id))
fp.close()
name=str(input("Please input name: "))
found=False
for mess in names:
    if mess[0]==name:
        found=True
        print(mess)
        break
if found==False:
    print('Not found!')