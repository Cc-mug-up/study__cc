class A:
    pass
class B(A):
    pass
if __name__ == "__main__":
    print(issubclass(B,A))
    x=A()
    y=B()
    print(isinstance(x,A))
    print(isinstance(x,B))
    print(isinstance(y,A))
    print(isinstance(y,B))