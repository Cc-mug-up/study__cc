class Dog:
    "define Dog class"
    counter=0
    def greet(self):
        print('Hi')
    def SetName(self,name):
        self.name=name
class Dog1:
    "define Dog class"
    counter=0
    def greet(self):
        print('Hi')
    def __init__(self,name):
        self.name=name
if __name__ == "__main__":
    dog=Dog()
    dog.greet()
    dog.SetName("gaoyiwen")
    print(Dog.counter)
    print("dog's name is {0}".format(dog.name))
    dog1=Dog1("gaoerwen")
    print("dog1's name is {0}".format(dog1.name))