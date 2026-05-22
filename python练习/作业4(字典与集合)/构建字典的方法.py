infp=[('Mayue',3000),('Lilin',4500),('Wuyun',8000)]
binfp=dict(infp)
print(binfp)
cinfp=dict([['Mayue',3000],['Lilin',4500],['Wuyun',8000]])
print(cinfp)
dinfp=dict(Mayue=3000,Lilin=4500,Wuyun=8000)
print(dinfp)
#键值对相等 用fromkeys()方法
ginfo={}.fromkeys(('Mayue','Lilin','Wuyun'),3000)
print(ginfo)