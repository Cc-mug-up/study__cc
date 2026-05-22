class Dog(object):
    "define Dog class"
    counter=0
    def greet(self):
        Dog.counter+=1
        print('Hi,i am {0},my number is {1}'.format(self.name,Dog.counter))
    def __init__(self,name):
        self.name=name
if __name__ == "__main__":
    dog1=Dog("Zara")
    dog1.greet()
    dog2=Dog("Paul")
    dog2.greet()
