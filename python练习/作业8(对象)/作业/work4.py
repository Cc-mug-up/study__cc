from operator import itemgetter
from datetime import date
from datetime import datetime
class Car(object):
    def __init__(self,name):
        self.carcount=0
        self.carmanagestation=name
        self.carmesslist=[]
    def insert(self,number,jointime,brand,recentchecktime):
        for x in self.carmesslist:
            if number in x:
                print("{0} already exist , try again !".format(number))
                return False
        self.carmesslist.append([number,jointime,brand,recentchecktime])
        self.carcount+=1
        print("{0} Add success !".format(number))
        return True
    def Del(self,number):
        for x in self.carmesslist:
            if number in x:
                print("{0} del success !".format(number))
                self.carmesslist.remove(x)
                self.carcount-=1
                return True
        print("{0} already not exist , try again !".format(number))
        return False
    def find(self,number):
        for x in self.carmesslist:
            if number in x:
                print(x)
                print("{0} find success !".format(number))
                return True
        print("{0} not exist , try again !".format(number))
        return False
    def carmessprintf(self):
        for x in self.carmesslist:
            print(x)
    def sortnumber(self):
        self.carmesslist=sorted(self.carmesslist,key=itemgetter(0))
        print("sort success !")
    def findunchecked(self):
        pd=date(2026,1,1)
        c=0
        for x in self.carmesslist:
            y=datetime.strptime(x[3], "%Y-%m-%d").date()
            if y<pd:
                print(x)
                c+=1
        if c>0:
            print("find success!")
            return True
        else:
            print("find defect!")
            return False
    def __add__(self,other):
        newCar = Car(f"{self.carmanagestation}_{other.carmanagestation}")
        all_cars = self.carmesslist + other.carmesslist
        seen_numbers = set()
        for x in all_cars:
            if x[0] not in seen_numbers:  # 去重
                newCar.carmesslist.append(x)
                seen_numbers.add(x[0])
        newCar.carcount = len(newCar.carmesslist)
        return newCar
    def printmess(self):
        for x in self.carmesslist:
            print(x)
    def load_from_file1(self):
        fp=open(r"D:\86189\vscode\python练习\作业8\作业\vehiclea.txt",'r+',encoding="utf-8")
        lines=fp.readlines()
        fp.close()
        for line in lines:
            parts = line.strip().split(',')
            number,jointime,brand,recentchecktime=parts
            self.insert(number,jointime,brand,recentchecktime)
        print("load success!")
    def store_to_file1(self):
        fp=open(r"D:\86189\vscode\python练习\作业8\作业\vehiclea.txt",'w',encoding="utf-8")
        for car in self.carmesslist:
            line = ','.join(car) + '\n'
            fp.write(line)
        print("store success!")
        fp.close()
    def rem_unchecked_year(self,year):
        pd=date(2026-year,1,1)
        c=0
        for x in self.carmesslist:
            y=datetime.strptime(x[3], "%Y-%m-%d").date()
            if y<pd:
                self.carmesslist.remove(x)
                c+=1
        if c>0:
            print("remove success!")
            return True
        else:
            print("no selected !")
            return False
    def load_from_file2(self):
        fp=open(r"D:\86189\vscode\python练习\作业8\作业\vehiclb.txt",'r+',encoding="utf-8")
        lines=fp.readlines()
        fp.close()
        for line in lines:
            parts = line.strip().split(',')
            number,jointime,brand,recentchecktime=parts
            self.insert(number,jointime,brand,recentchecktime)
        print("load success!")
    def store_to_file2(self):
        fp=open(r"D:\86189\vscode\python练习\作业8\作业\vehiclb.txt",'w',encoding="utf-8")
        for car in self.carmesslist:
            line = ','.join(car) + '\n'
            fp.write(line)
        print("store success!")
        fp.close()
class ProjectCar(Car):
    def insert(self,number,jointime,brand,recentchecktime,function):
        for x in self.carmesslist:
            if number in x:
                print("{0} already exist , try again !".format(number))
                return False
        self.carmesslist.append([number,jointime,brand,recentchecktime,function])
        self.carcount+=1
        print("{0} Add success !".format(number))
        return True
    def load_from_file(self):
        fp=open(r"D:\86189\vscode\python练习\作业8\作业\vehiclec.txt",'r+',encoding="utf-8")
        lines=fp.readlines()
        fp.close()
        for line in lines:
            parts = line.strip().split(',')
            number,jointime,brand,recentchecktime,function=parts
            self.insert(number,jointime,brand,recentchecktime,function)
        print("load success!")
def test1():
    station1=Car("cc1")
    station1.load_from_file1()
    num=str(input("please input car number: "))
    station1.find(num)
    station1.findunchecked()
    station1.sortnumber()
    station1.printmess()
    station1.rem_unchecked_year(3)
    station1.store_to_file1()
    station2=Car("cc2")
    station2.load_from_file2()
    station3=station1+station2
    station3.printmess()
    station4=ProjectCar("cc3")
    station4.load_from_file()
    station4.printmess()
if __name__ == "__main__":
    test1()






