class Date:
    pass
if __name__ == "__main__":
    curDate = Date()
    curDate.month=6
    curDate.day=1
    print(curDate.__dict__)