//Adham Salem #900222456
// Created by Lenovo.
#include <string>
#include "Heap.h"
#include <iostream>
using namespace std;

void Mheap::ADD(const string & Date, double V) {
    Heap.emplace_back(Date,V);
    HeapifyUp(Heap.size()-1);
}
void Mheap::CreateHeap() {
    for (int i = (Heap.size() / 2) - 1; i >= 0; --i)
        HeapifyDown(i);
}

void Mheap::HeapifyDown(int Index) {
    int Lchild,Rchild,Biggestchild;
    while(true){
        Lchild=(2*Index)+1;
        Rchild=(2*Index)+2;
        Biggestchild=Index;
        if(Lchild< Heap.size() and Heap[Lchild].second>Heap[Biggestchild].second){
            Biggestchild=Lchild;
        }
        if (Rchild<Heap.size() and Heap[Rchild].second>Heap[Biggestchild].second){
            Biggestchild=Rchild;
        }
        if(Biggestchild!=Index){
            swap(Heap[Index],Heap[Biggestchild]);
            Index=Biggestchild;
        }
        else
            break;
    }
}


void Mheap::HeapifyUp(int Index) {
    while( Index >0){
        int Pnode=(Index-1)/2;
        if (Heap[Index].second> Heap[Pnode].second){
            swap(Heap[Index],Heap[Pnode]);
            Index=Pnode;
        }
        else
            break;
    }
}

DataPair Mheap::getMax() {
    if(Heap.empty()){
        cout<<"Cannot get Data from an empty Heap"<<endl;
    }
    else
    {
        DataPair MaxNode= Heap.front();
        swap(Heap.front(),Heap.back());
        Heap.pop_back();
        HeapifyDown(0);
        return MaxNode;
    }
}

void MinHeap::CreateHeap() {
    for(int i=(Heap.size()/2)-1;i>=0;--i)
        HeapifyDown(i);
}

void MinHeap::HeapifyDown(int Index) {
    int Lchild,Rchild,Biggestchild;
    while(true){
        Lchild=(2*Index)+1;
        Rchild=(2*Index)+2;
        Biggestchild=Index;
        if(Lchild< Heap.size() and Heap[Lchild].second>Heap[Biggestchild].second){
            Biggestchild=Lchild;
        }
        if (Rchild<Heap.size() and Heap[Rchild].second>Heap[Biggestchild].second){
            Biggestchild=Rchild;
        }
        if(Biggestchild!=Index){
            swap(Heap[Index],Heap[Biggestchild]);
            Index=Biggestchild;
        }
        else
            break;
    }
}

void MinHeap::HeapifyUp(int Index) {
    while( Index >0){
        int Pnode=(Index-1)/2;
        if (Heap[Index].second> Heap[Pnode].second){
            swap(Heap[Index],Heap[Pnode]);
            Index=Pnode;
        }
        else
            break;
    }
}

void MinHeap::ADD(const string & Date, double V) {
    Heap.emplace_back(Date, V);
    HeapifyUp(Heap.size() - 1);
}

DataPair MinHeap::getMin(){
    if(Heap.empty()){
        cout<<"Cannot get Data from an empty Heap"<<endl;
    }
    else
    {
        DataPair MinNode= Heap.front();
        swap(Heap.front(),Heap.back());
        Heap.pop_back();
        HeapifyDown(0);
        return MinNode;
    }
}