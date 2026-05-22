if __name__ == "__main__":
    while True:
        try:
            num=int(input("please input the number of bread: "))
            price=float(input("please input the price of single bread: "))
            sum=num*price
            print("your sum price:{0}".format(sum))
            break
        except ValueError:
            print("Please input digit! try again!")
    