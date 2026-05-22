class PersonInfo:
    "define PersonInfo Class"
    def person(self,dep):
        self.dep=dep
        self.num=0
        self.plist=[]
    def insertp(self,name,age):
        for x in self.plist:
            if name in x:
                print("{0} already in list".format(name))
                return False
        self.num+=1
        self.plist.append([name,age])
        return True
    def delp(self,name):
        for x in self.plist:
            if name in x:
                print("Delete {0}".format(name))
                self.plist.remove(x)
                self.num-=1
                return True
        print("{0} not in list".format(name))
        return False
    def searchp(self,name):
        for x in self.plist:
            if name in x:
                print("{0} in list".format(name))
                print(x)
                return True
        print("{0} not in list".format(name))
        return False
    def printplist(self):
        for x in self.plist:
            print(x)
class PersonInfo1:
    "define PersonInfo Class"
    def __init__(self,dep):
        self.dep=dep
        self.num=0
        self.plist=[]
    def insertp(self,name,age):
        for x in self.plist:
            if name in x:
                print("{0} already in list".format(name))
                return False
        self.num+=1
        self.plist.append([name,age])
        return True
    def delp(self,name):
        for x in self.plist:
            if name in x:
                print("Delete {0}".format(name))
                self.plist.remove(x)
                self.num-=1
                return True
        print("{0} not in list".format(name))
        return False
    def searchp(self,name):
        for x in self.plist:
            if name in x:
                print("{0} in list".format(name))
                print(x)
                return True
        print("{0} not in list".format(name))
        return False
    def printplist(self):
        for x in self.plist:
            print(x)
if __name__ == "__main__":
    cs=PersonInfo1("CS")
    cs.insertp('WangTian',18)
    cs.insertp("ZhangWei",20)
    cs.insertp("LiJianGuo",40)
    print("There are {0} people in Dep.{1}".format(cs.num,cs.dep))
    cs.printplist()
    cs.searchp("ZhangWei")
    cs.delp("LiJianGuo")
    cs.printplist()
