//#include<bits/stdc++.h>
#include"stack.h"
template<typename T>
void Stack<T>::pop()
{
    elems.pop_back();
}

template<typename T>
void Stack<T>::push(T elem)
{
    elems.push_back(elem);
}

template<typename T>
bool Stack<T>::empty()
{
    return elems.empty();
}
template<typename T>
T Stack<T>::gettop()
{
    return elems.back();
}