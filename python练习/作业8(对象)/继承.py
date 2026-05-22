class Dog(object):
    "define Dog class"
    counter=0
    def greet(self):
        print('Hi,i am {0},my number is {1}'.format(self.name,Dog.counter))
    def __init__(self,name):
        Dog.counter+=1
        self.name=name
class BarkingDog(Dog):
    "define subclass BarkingDog"
    def greet(self):
        "inital subclass"
        print("Woof! I am {0},my number is {1}".format(self.name,Dog.counter))
    def bark(self):
        print("barking")
if __name__ == "__main__":
    dog=BarkingDog("Zoe")
    dog.greet()
    dog.bark()