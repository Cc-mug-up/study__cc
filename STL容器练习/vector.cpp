#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <stdexcept>
// using namespace std;
template <typename T>
class Vector
{
private:
    T *elements;
    size_t size;
    size_t capacity;

public:
    Vector() : elements(nullptr), size(0), capacity(0) {}
    ~Vector()
    {
        delete[] elements;
    }
    Vector(size_t s)
    {
        elements = new T[s];
        capacity = s;
        size = s;
        reserve(2 * s);
        for (size_t i = 0; i < size; i++)
        {
            elements[i] = 0;
        }
    }
    Vector(size_t s, T num)
    {
        elements = new T[s];
        capacity = s;
        size = s;
        reserve(2 * s);
        for (size_t i = 0; i < size; i++)
        {
            elements[i] = num;
        }
    }
    Vector(Vector &other)
    {
        capacity = other.capacity;
        size = other.size;
        elements = new T[capacity];
        std::copy(other.elements, other.elements + other.size, elements);
    }
    Vector &operator=(const Vector &other)
    {
        if (this != &other)
        {
            delete[] elements;
            capacity = other.capacity;
            size = other.size;
            elements = new T[capacity];
            std::copy(other.elements, other.elements + other.size, elements);
        }
        return *this;
    }
    T &operator[](size_t index)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }
    const T &operator[](size_t index) const
    {
        // 检查索引是否越界
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }
    size_t getsize()
    {
        return size;
    }
    size_t getcapacity()
    {
        return capacity;
    }
    T *begin()
    {
        return elements;
    }
    T *end()
    {
        return elements + size;
    }
    void push_back(const T &val)
    {
        if (size == capacity)
        {
            if (capacity != 0)
                reserve(2 * capacity);
            else
                reserve(1);
        }
        elements[size++] = val;
    }
    void pop_back()
    {
        if (size > 0)
            size--;
    }
    void printElements()
    {
        for (size_t i = 0; i < size; i++)
        {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }
    void clear()
    {
        size = 0;
    }
    void insert(size_t index, const T &val)
    {
        if (index > size)
        {
            throw std::out_of_range("Index out of range");
        }
        if (size == capacity)
        {
            if (capacity == 0)
                reserve(1);
            else
                reserve(2 * capacity);
        }

        for (size_t i = size; i > index; i--)
        {
            elements[i] = elements[i - 1];
        }
        elements[index] = val;
        size++;
    }

private:
    void reserve(size_t newcapacity)
    {
        if (newcapacity > capacity)
        {
            T *newelements = new T[newcapacity];
            std::copy(elements, elements + size, newelements);
            delete[] elements;
            elements = newelements;
            capacity = newcapacity;
        }
    }
};
int main()
{
    int n;
    std::cin >> n;
    Vector<int> myvector(n, 0);
    for (int i = 0; i < myvector.getsize(); i++)
    {
        std::cin >> myvector[i];
    }
    std::sort(myvector.begin(), myvector.end());
    myvector.printElements();
    Vector<int> secondvector(myvector);
    secondvector.printElements();
    Vector<std::string> strvector(n, "abcd");
    strvector.push_back("12121");
    strvector.printElements();
    return 0;
}