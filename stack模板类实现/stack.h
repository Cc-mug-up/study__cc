#ifndef STACK_H
#define STACK_H
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Stack
{
private:
    vector<T> elems;

public:
    void pop();
    void push(T);
    T gettop();
    bool empty();
};
#endif 