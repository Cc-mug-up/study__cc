#ifndef SMARTVECTOR_TCC
#define SMARTVECTOR_TCC
//#include"smartvector.h"
//#include<bits/stdc++.h>
template<typename T>
smartvector<T>::smartvector(size_t s){
    size=s;
    data=new T(s);
}
template<typename T>
smartvector<T>::~smartvector(){
    delete[]data;
}
template<typename T>
int smartvector<T>::find(const T& val){
    for(size_t i=0;i<size;i++){
        if(data[i]==val) return i;
    }
    std::cout<<"ц╩спур╣╫"<<std::endl;
    return -1;
}
template<typename T>
T& smartvector<T>::operator[](const size_t index){
    return data[index];
}
template<typename T>
T& smartvector<T>::getindex(const size_t index){
    return data[index];
}
template<typename T>
void smartvector<T>::sort(){
    std::sort(data,data+size);
}

template<typename T>
void smartvector<T>::show(){
    for(size_t i=0;i<size;i++){
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl;
}

template<typename T>
void smartvector<T>::push_back(const T val){
    T* newdata=new T(size+1);
    for(size_t i=0;i<size;i++){
        newdata[i]=data[i];
    } 
    newdata[size]=val;
    delete[]data;
    data=newdata;
    size++;
    std::cout<<val<<std::endl;
}

template<typename T>
void smartvector<T>::pop(){
    size--;
}

#endif