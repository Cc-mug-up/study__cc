fp=open(r'D:\86189\vscode\python练习\作业7\testseek.dat','wb+')
print(fp.write(b'Hello World!'))# 共12个字节
print(fp.seek(0))# 当前位置 0
s=fp.read(5)# 前5个字节 'Hello'
print(s)
print(fp.seek(-5,2))# 从末尾向前移动5个字节 7
s=fp.read()
print(s)#读从7往后的内容 'orld'
print(fp.seek(3,0))#从开头向后移动3个字节 3
print(fp.read(3))# 读出3个字节 'lo '
print(fp.seek(2,1))# 从当前位置向后移动2个字节
print(fp.read(3))# 读出3个字节 'rld'
