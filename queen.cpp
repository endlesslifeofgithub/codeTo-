#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
#include "queen.h"
using namespace std;
bool isConflict(const vector<int>&pos,int num){
    for (int i = 0; i <pos.size();++i) {
        if((abs(num-pos[i])==0)||(abs(num-pos[i])==pos.size()-i)) return true;
    }
    return false;
}
void queenHelp(const int num,vector<int> pos,vector<vector<int>>&answer){
    for (int possibleX=0;possibleX<num;++possibleX){
        if(!isConflict(pos,possibleX)){
            if(pos.size()==num-1){
                auto temp=pos;
                temp.push_back(possibleX);
                answer.push_back(temp);
            }else{
                auto temp=pos;
                temp.push_back(possibleX);
                queenHelp(num,temp,answer);
            }
        }
    }

}
vector<vector<int>> queen(int n){
    vector<vector<int>>answer;
    queenHelp(n,vector<int>(),answer);
    for(auto av:answer){
        for_each(av.begin(),av.end(),[](int i){cout<<i<<" ";});
        cout<<endl;
    }
    return answer;
}

vector<int> removeDump(vector<int>&gaGa){
    vector<int>answer;
    auto lenGa=gaGa.size();
    for (int i = 1; i <lenGa ; ++i) {
        if(gaGa[i]-gaGa[i-1]!=0) answer.push_back(gaGa[i]);
    }
    return answer;
}
vector<int>test(){return {1,2,3};};
void test( char s[]){
    cout<<sizeof(s)<<endl;
}
template<class T>
 T largestRectangleArea(vector<T> heights) {
        heights.push_back(-1);
        T max_size=0;
        int index=0;
        stack<T> s;

        while(index<heights.size())
        {
            if(s.size()==0||heights[s.top()]<=heights[index])
            {
                s.push(index);
                index++;
            }
            else
            {
                T top=s.top();
                s.pop();
                T size=0;

                if(s.size()==0)
                {
                    size=heights[top]*index;
                }
                else
                {
                    size=heights[top]*(index-s.top()-1);
                }

                if(size>max_size) max_size=size;
            }
        }

        return max_size;
    }
template <unsigned int N>
class factor{
public:
    enum{value=factor<N-1>::value*N};
};
template<>
class factor<0>{
public:
    enum{value=0};
};
int main() {
    auto aa=test();
    vector<int>cc{12,23};
    cout<<*(aa.insert(aa.end(),cc.begin(),cc.end()))<<endl;
    for_each(aa.begin(),aa.end(),[](int i){cout<<i<<endl;});
    cout<<stoi("12312as")<<endl;
    cout<<largestRectangleArea(vector<double>{1.2,1.1,1.5,1.6,1.2,1.3})<<endl;
    int d1=0.2;
    std::cout << "Hello, World!" << std::endl;
    auto an=queen(10);
    cout<<an.size();
    vector<int>av={1};
    try{
        av[2]=9;
    }catch (exception e){
        cout<<"异常捕获";
    }

    test1 t1;
    test1 t2=t1;
    t1.printte();

    cout<<"//////////////////////"<<endl;
    char s[]="sdadawqre";
    cout<< sizeof(s)<<endl;

    test(s);
    cout<<sizeof(int*)<<endl;

    cout<<"4!="<<factor<4>::value<<endl;
    return 0;
}