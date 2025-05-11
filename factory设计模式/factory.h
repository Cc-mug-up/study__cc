#ifndef FACTART_H
#define FACTART_H
#include <bits/stdc++.h>
using namespace std;
// 图形基类
class Shape
{
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

// 具体图形实现
class Circle : public Shape
{
public:
    void draw() const override
    {
        std::cout << "Drawing Circle" << std::endl;
    }
};

class Rectangle : public Shape
{
public:
    void draw() const override
    {
        std::cout << "Drawing Rectangle" << std::endl;
    }
};
// 通用工厂模板（非特化版本，不实现具体创建）
template <typename T>
class ShapeFactory
{
public:
    static Shape *create()
    {
        static_assert(sizeof(T) == 0, "Unspecialized template usage");
        return nullptr;
    }
};

// 圆形特化版本
template <>
class ShapeFactory<Circle>
{
public:
    static Shape *create()
    {
        return new Circle();
    }
};

// 矩形特化版本
template <>
class ShapeFactory<Rectangle>
{
public:
    static Shape *create()
    {
        return new Rectangle();
    }
};

#endif