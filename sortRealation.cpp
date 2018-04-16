#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename Iterator>
void adjustHeap(Iterator it1,Iterator it2,Iterator it3){
    int len=it2-it1;
    int indexToAdjust=it3-it1;
    while(indexToAdjust*2+1<=len-1){
        auto indexToVal=*(it1+indexToAdjust);
        auto leftChildIndex=indexToAdjust*2+1;
        auto leftVal=*(it1+leftChildIndex);
        if(leftChildIndex+1<=len-1){
            int rightChildIndex=leftChildIndex+1;
            auto rightVal=*(it1+rightChildIndex);
            if(leftVal<=indexToVal&&rightVal<=indexToVal) return;
            else if(leftVal>rightVal){
                iter_swap(it1+leftChildIndex,it1+indexToAdjust);
                indexToAdjust=leftChildIndex;
            }else{
                iter_swap(it1+rightChildIndex,it1+indexToAdjust);
                indexToAdjust=rightChildIndex;
            }
        }else{
            if(leftVal>=indexToVal){
                iter_swap(it1+leftChildIndex,it1+indexToAdjust);
                indexToAdjust=leftChildIndex;
            }else break;
        }
    }

}
template<typename Iterator>
void headSortMy(Iterator it1,Iterator it2){
    int len=it2-it1;
    for(auto it=it2-1;it>it1;it--){
        iter_swap(it1,it);
        adjustHeap(it1,it,it1);
    }
}
template<typename Iterator>
void makeHeap(vector<int>&array,Iterator it1,Iterator it2){
    int len=it2-it1;
    //index:0-len-1
    int firstHasLeaf=(len>>1)-1;
    for(int i=firstHasLeaf;i>=0;i--){
        adjustHeap(it1,it2,it1+i);
    }
}
template<typename Iterator>
Iterator partition(Iterator it1,Iterator it2){
    auto pivot=*it1;
    auto first=it1;
    first++;
    auto last=it2;
    while(true){
        while(*first<pivot)first++;
        last--;
        while(*last>pivot) last--;
        if(first>=last) break;
        iter_swap(first,last);
        first++;
    }
    iter_swap(first-1,it1);
    return first-1;
}
template<typename Iterator>
void  quickSortMy(Iterator it1,Iterator it2){
    if(it1>=it2-1) return;
    auto gap=partition(it1,it2);
    quickSortMy(it1,gap);
    quickSortMy(gap+1,it2);
}
template<typename Iterator>
void bubleSort (Iterator it1,Iterator it2){
    auto len=it2-it1;
    for(auto i=0;i<len;i++){
        for(auto j=0;j<len-i-1;j++){
            if(*(it1+j)>*(it1+j+1)) iter_swap(it1+j,it1+j+1);
        }
    }
}
template<typename Iterator>
void selectSort (Iterator it1,Iterator it2){
    auto len=it2-it1;
    for(auto i=0;i<len;i++){
        int minNum=i;
        for(auto j=i;j<len;j++){
            if(*(it1+j)<*(it1+minNum)) minNum=j;
        }
        iter_swap(it1+i,it1+minNum);
    }
}





int main() {
    {vector<int>array={16, 7, 3, 20, 17,8,8,12,12,12,12,21,12,32,34,54,56,23,54,23,54,21,54,21,56,23,56,23,76};
    makeHeap(array,array.begin(),array.end());
    headSortMy(array.begin(),array.end());
    std::cout << "Hello, World!" << std::endl;}
    {vector<int>array={16, 7, 3, 20, 17,8,8,12,12,12,12,21,12,32,34,54,56,23,54,23,54,21,54,21,56,23,56,23,76};
        quickSortMy(array.begin(),array.end());
        headSortMy(array.begin(),array.end());
        std::cout << "Hello, World!" << std::endl;}
    {
        vector<int>array={16, 7, 3, 20, 17,8,8,12,12,12,12,21,12,32,34,54,56,23,54,23,54,21,54,21,56,23,56,23,76};
        bubleSort(array.begin(),array.end());

        std::cout << "Hello, World!" << std::endl;

    }
    {
        vector<int>array={16, 7, 3, 20, 17,8,8,12,12,12,12,21,12,32,34,54,56,23,54,23,54,21,54,21,56,23,56,23,76};
        selectSort(array.begin(),array.end());

        std::cout << "Hello, World!" << std::endl;

    }
    return 0;
}
