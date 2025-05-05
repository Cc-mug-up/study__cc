#include <iostream>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

template <typename T>
class Deque
{
private:
    T *elements;
    size_t size;
    size_t capacity;
    size_t frontIndex;
    size_t backIndex;

public:
    Deque() : elements(nullptr), capacity(0), size(0), frontIndex(0), backIndex(0) {}
    ~Deque()
    {
        clear();
        delete[] elements;
    }
    void push_front(const T &val)
    {
        if (size == capacity)
        {
            resize();
        }
        frontIndex = (frontIndex - 1 + capacity) % capacity;
        elements[frontIndex] = val;
        ++size;
    }
    void push_back(const T &val)
    {
        if (size == capacity)
        {
            resize();
        }
        elements[backIndex] = val;
        backIndex = (backIndex + 1 + capacity) % capacity;
        ++size;
    }
    void pop_front()
    {
        if (size == 0)
        {
            throw std::out_of_range("Deque is empty");
        }
        frontIndex = (frontIndex + 1 + capacity) % capacity;
        --size;
    }
    void pop_back()
    {
        if (size == 0)
        {
            throw std::out_of_range("Deque is empty");
        }
        backIndex = (backIndex - 1 + capacity) % capacity;
        --size;
    }
    T &operator[](size_t index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return elements[(frontIndex + index + capacity) % capacity];
    }
    T &getOfIndex(size_t index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return elements[(frontIndex + index + capacity) % capacity];
    }
    size_t getSize()
    {
        return size;
    }
    void clear()
    {
        while (size > 0)
        {
            pop_front();
        }
    }
    void printElements()
    {
        size_t index = frontIndex;
        for (size_t i = 0; i < size; i++)
        {
            std::cout << elements[index] << " ";
            index = (index + 1 + capacity) % capacity;
        }
        std::cout << std::endl;
    }

private:
    void resize()
    {
        size_t newcapacity = (capacity == 0 ? 1 : 2 * capacity);
        T *newelements = new T[newcapacity];
        size_t index = frontIndex;
        for (size_t i = 0; i < size; i++)
        {
            newelements[i] = elements[index];
            index = (index + 1) % capacity;
        }
        delete[] elements;
        elements = newelements;
        capacity = newcapacity;
        frontIndex = 0;
        backIndex = size;
    }
};

int main()
{
    Deque<int> que;
    que.push_back(5);
    que.push_back(7);
    que.push_back(8);
    que.push_front(100);
    que.push_front(1000);
    que.printElements();
    que.pop_front();
    que.pop_back();
    que.printElements();
    std::cout << que[0] << std::endl;
    return 0;
}