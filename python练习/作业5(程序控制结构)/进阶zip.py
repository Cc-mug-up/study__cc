stockList=[('AXP','American Express Company','78.51'),('BA','The Boeing Company','184,76'),('CAT','Caterpiller lnc.','96.39')]
aList=[]
bList=[]
for i in range(3):
    aList.append(stockList[i][0])
    bList.append(stockList[i][2])
StockDict=dict(zip(aList,bList))
print(StockDict)