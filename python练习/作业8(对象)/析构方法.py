class Test:
    def __init__(self):
        print("initalized")
    def __del__(self):
        print("deleted")
if __name__ == "__main__":
    x=Test()
    y=x
    z=y
    del x 
    del y
    print(111)
    del z