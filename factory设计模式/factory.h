#ifndef FACTART_H
#define FACTART_H
#include <bits/stdc++.h>
using namespace std;
// ͼ�λ���
class Shape
{
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

// ����ͼ��ʵ��
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
// ͨ�ù���ģ�壨���ػ��汾����ʵ�־��崴����
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

// Բ���ػ��汾
template <>
class ShapeFactory<Circle>
{
public:
    static Shape *create()
    {
        return new Circle();
    }
};

// �����ػ��汾
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