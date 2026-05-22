dinfp=dict(Mayue=3000,Lilin=4500,Wuyun=8000)
print(dinfp['Mayue'])
dinfp['Mayue']=6000
print(dinfp['Mayue'])
print()
dinfp['Liuxi']=10000
print(dinfp['Liuxi'])
print('Liuxi' in dinfp)
del dinfp['Liuxi']
print('Liuxi' in dinfp)
print(dinfp)
print(len(dinfp))
print(dinfp.items())
print(dinfp.get('Mayue'))
dinfp['Liuxi']=10000
dinfp.pop('Liuxi')
dinfp.clear()
print(dinfp)
