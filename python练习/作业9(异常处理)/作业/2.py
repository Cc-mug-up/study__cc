userdict={"xiaoyun":1003,"xiaohuang":1011,"xiaoteng"
          :1045,"xiaoyi":1047,"xiaoyang":1051}
while True:
    curname=str(input("please input your name: "))
    curid=userdict.get(curname)
    if curid!=None:
        print("your id: {0}".format(curid))
        break
    print("not found! try again!")
   