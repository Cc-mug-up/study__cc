names=['xiaoma','xiaowang','xiaoma','xiaoliu','xiaoma','xiaoliu']
dictname={}
for name in names:
    if name in dictname:
        dictname[name]+=1
    else:
        dictname[name]=1
print(dictname)