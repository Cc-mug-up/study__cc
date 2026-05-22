try:
    num1=int(input("Enter the first number: "))
    num2=int(input("Enter the second number: "))
    print(num1/num2)
except ValueError:
    print("Please input a digit! ")

try:
    num1=int(input("Enter the first number: "))
    num2=int(input("Enter the second number: "))
    print(num1/num2)
except ZeroDivisionError:
    print("The second number cannot be zero! ")

