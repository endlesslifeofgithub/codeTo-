#include <iostream>
#include<bits/stdc++.h>
using namespace std;
template<typename Iterator>
void pushHeapMy(Iterator it1, Iterator it2) {
    if (it1 >= it2 - 1) return;
    int len = it2 - it1;
    int toUp = len - 1;
    while (toUp > 0 && *(it1 + toUp) > *(it1 + (toUp - 1) / 2)) {
        iter_swap(it1 + toUp, it1 + (toUp - 1) / 2);
        toUp = (toUp - 1) / 2;
    }
}

template<typename Iterator>
void popHeadMy(Iterator it1, Iterator it2) {
    if (it1 >= it2 - 1) return;
    int len = it2 - it1;
    int endPos = len - 1;
    iter_swap(it1, it1 + endPos);
    int downPos = 0;
    while (downPos <= len - 1) {
        int leftChild = 2 * downPos + 1;
        int rightChild = 2 * downPos + 2;
        if (leftChild < len - 1 && rightChild < len - 1
            && *(it1 + downPos) < min(*(it1 + rightChild), *(it1 + leftChild))) {
            if (*(it1 + leftChild) < *(it1 + rightChild)) {
                iter_swap(it1 + rightChild, it1 + downPos);
                downPos = rightChild;
            } else {
                iter_swap(it1 + leftChild, it1 + downPos);
                downPos = leftChild;
            }
        }
    }
}

template<typename Iterator>
void makeHeadMy(Iterator it1, Iterator it2) {
    if (it1 >= it2 - 1) return;
    for (int i = 2; i <= it2 - it1; i++) {
        pushHeapMy(it1, it1 + i);
    }
}
int factor(int n){
    if(n==0) return 1;
    int answer=1;
    while(n>0){
        answer*=n;
        n--;
    }
    return answer;
}
template<typename T>
bool next_preMy(T t1,T t2){
    if(t1>=t2) return false;
    //从后往前找到第一个降序
    auto latter=t2-1;
    auto early=latter-1;
    while(early>=t1){
        if(*early<*latter) break;
        early--,latter--;
    }
    if(early==t1-1){
        reverse(t1,t2);
        return false;
    }
    latter=t2-1;
    while(*latter<=*early){
        latter--;
    }
    iter_swap(latter,early);
    reverse(early+1,t2);
    return true;
}
template<typename Iterator>
Iterator parttion(Iterator it1,Iterator it2){
    auto start=it1;
    auto end=it2;
    auto val=*it1;
    start++;
    while(true){
        while(*start<val) ++start;
        --end;
        while(*end>val) --end;
        if(start>=end) break;
        iter_swap(start,end);
        ++start;
    }
    iter_swap(--start,it1);
    return start;
}
template<typename Iterator>
void quickSort(Iterator it1,Iterator it2){
    if(it1>=it2-1) return;
    auto index=parttion(it1,it2);
    quickSort(it1,index);
    quickSort(index+1,it2);
}
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if(k>input.size()) return vector<int>{};
    auto start=input.begin();
    auto end=input.end();
    auto it=parttion(start,end);
    while(end-start>3){
        if(it-input.begin()>k) end=it;
        else start=it+1;
        it=parttion(start,end);
    }
    sort(start,end);
    return vector<int>(input.begin(),input.begin()+k);
}
int main() {

        int count,index;
        cin>>count;
        cin>>index;
        vector<int>last;
        while(count>0){
            int temp;
            cin>>temp;
            last.push_back(temp);
            count--;
        }
        for_each(last.begin(),last.end(),[](int i){cout<<i<<ends;});
    list<int> ls={1,2,3,4,5,6,7,8};
    for_each(ls.begin(),ls.end(),[](const int &i){cout<<i<<ends;});
    auto lsb=ls.begin();
    cout<<*(prev(lsb))<<endl;
    cout<<endl;
    vector<int>avTest={1,2,3,4,5,6,7,8};
    makeHeadMy(avTest.begin(),avTest.end());
    for_each(avTest.begin(),avTest.end(),[](const int &i){cout<<i<<ends;});
    {
        cout<<endl;
        vector<int>avTest={1,2,3,4,5,6,7,8};
        make_heap(avTest.begin(),avTest.end());
        for_each(avTest.begin(),avTest.end(),[](const int &i){cout<<i<<ends;});

    }
    std::cout << "Hello, World!" << std::endl;
    vector<string> avString={"1245","sad","wqeqw","qweqw","asdsad"};
    auto sizeAvString=avString.size();
    int kinds=factor(sizeAvString);
    while((kinds--)>0){
        for_each(avString.begin(),avString.end(),[](const string &ss){cout<<ss<<"  ";});
        cout<<endl;
        next_preMy(avString.begin(),avString.end());
    }
    cout<<endl;
    for_each(avString.begin(),avString.end(),[](const string &ss){cout<<ss<<"  ";});
    vector<int> toSort1={8,54,2,4,2,9,69,4,84,754,78,47,47,2,42,5,45,41};
    vector<int> toSort2={8,54,2,4,2,9,69,4,84,754,78,47,47,2,42,5,45,41};
    quickSort(toSort2.begin(),toSort2.end());
    vector<int> ss1=GetLeastNumbers_Solution(toSort1,13);
    cout<<endl;
    for_each(ss1.begin(),ss1.end(),[](const int &ss){cout<<ss<<"  ";});
    cout<<endl;
    for_each(toSort2.begin(),toSort2.end(),[](const int &ss){cout<<ss<<"  ";});
     return 0;
}