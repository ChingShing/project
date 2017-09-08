#include "your_vector.h"
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::sort;
//请在这里完成你的代码
vector::vector(int size){
    //TODO
}
vector::vector(vector &v){
    //TODO
}
vector::vector(){
    //TODO
}
vector::~vector(){
    //TODO   
}


//不要修改以下内容！
void vector::insert(int value){
    if(number==size){
        expand();
    }
    data[number]=value;
    number++;
}
void vector::expand(){
    int *temp=new int[size];
    for (int i = 0; i < size; ++i) {
        temp[i]=data[i];
    }
    delete[] data;
    data=new int[2*size];
    for(int i=0;i<size;i++){
        data[i]=temp[i];
    }
    size=size*2;
    delete [] temp;
}
void vector::show(){
    for (int i = 0; i <number ; ++i) {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
void vector::sort_array(){
    sort(data,data+number);
}