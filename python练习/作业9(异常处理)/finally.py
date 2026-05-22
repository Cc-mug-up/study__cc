def finallyTest():
    try:
        x=int(input("Enter the first number: "))
        y=int(input("Enter the second number: "))
        print(x/y)
        return 1
    except Exception as err:
        print(err)
        return 0
    finally:
        print("it is a finally clause.")
result=finallyTest()
print(result)