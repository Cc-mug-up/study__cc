#ifndef SMARTVECTOR_H
#define SMARTVECTOR_H
#include<bits/stdc++.h>
template<typename T>
class smartvector{
    private:
    T* data;
    size_t size;
    public:
    smartvector(size_t);
    ~smartvector();
    int find(const T&);
    T& operator [](size_t);
    void sort();
    void show();
    T& getindex(const size_t);
    void push_back(const T);
    void pop();
};
#include"smartvector.tcc"
#endif