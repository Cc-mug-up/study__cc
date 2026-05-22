fp=open(r'D:\86189\vscode\python练习\作业7\firstpro.txt','a+', encoding='utf-8')
fp.write("3 4 5\n")  # 将数字转换为文本
fp.write("文本内容示例\n")
fp.seek(0)
s=fp.readlines()
print(s)
fp.close()
