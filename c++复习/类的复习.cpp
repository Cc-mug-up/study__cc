#include <bits/stdc++.h>
using namespace std;
class Shape
{
protected:
    int width;
    int length;

public:
    virtual int getarea() = 0;
    void setwidth(int width)
    {
        this->width = width;
    }
    void setlength(int length)
    {
        this->length = length;
    }
};
class Rectangle : public Shape
{
public:
    int getarea()
    {
        return width * length;
    }
};
class Triangle : public Shape
{
public:
    int getarea()
    {
        return width * length / 2;
    }
};
int main()
{
    Shape *shape = new Triangle();
    Rectangle rect;
    shape->setlength(5);
    shape->setwidth(6);
    cout << shape->getarea() << endl;
    return 0;
}
