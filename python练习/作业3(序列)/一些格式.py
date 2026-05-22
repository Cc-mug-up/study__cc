hStr='hello python!'
print(hStr.center(50))
print(hStr.count('o'))
s1='abc&ABC'
print(s1)
print(s1.find('A'))
s=s1.lower()
print(s)
print(s.count('a'))
print('love '.join(['I ','Python!']))
s2='I lkve yku'
print(s2.replace('k','o'))
cList=[x for x in range(1,10,2)]
print(cList)
pList=[('AXP','American Express Company','78.51'),
       ('BA','The Boeing Company','184.76'),
       ('CAT','Caterpillar Inc.','96.39'),
       ('CSCO','Cisco System,Inc.','33.71'),
       ('CVX','Chevron Corporation','106.09')]
print(pList[1])
print(pList[1][1])