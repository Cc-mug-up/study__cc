class P:
    def __init__(self,name):
        self.__name=name
    def get_name(self):
        return self.__name
if __name__ == "__main__":
    x=P('John')
    print(x._P__name)
    print(x.get_name())