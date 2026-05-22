monthdays={'Jan':31,'Feb':28,'Mar':31,'Apr':30,'May':31,'Jun':30,'Jul':31,'Aug':31,'Sep':30,'Oct':31,'Thi':40}
x={'Nov':30,'Dec':31}
print(monthdays)
monthdays.update(x)
print(monthdays)
monthdays.pop('Thi')
monthdays['Feb']=29
print(monthdays.get('Oct'))
g=monthdays.get('Xyz')
if g==None:
    print('No found')
else:
    print(g)
print(monthdays.keys())
print(monthdays.values())
print(monthdays.items())
