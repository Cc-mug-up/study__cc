class Point(object):
    def __init__(self,x,y):
        self.x=float(x)
        self.y=float(y)
    def __sub__(self, other):
        return ((self.x - other.x)**2 + (self.y - other.y)**2)**0.5
if __name__ == "__main__":
    p1=Point(3,4)
    p2=Point(6,0)
    print(p1-p2)