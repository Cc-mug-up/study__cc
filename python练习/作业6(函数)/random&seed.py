import random
print(random.choice(['C++','Java','Python']))
print(random.randint(1,100))
print(random.randrange(0,10,2))
print(random.random())
print(random.uniform(5,10))

random.seed(100)
print(random.random())
print(random.random())

random.seed(101)
print(random.random())
print(random.random())