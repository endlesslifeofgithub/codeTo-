#include <iostream>
#include <memory>
#include <functional>
#include <bits/stdc++.h>
#include <vector>
#include <random>
#include "templateTest.h"
using namespace std;
void testLis();
void func1(){std::cout<<"func1\n";};
void func2(){std::cout<<"func2\n";};
//下面三个等价
//typedef void(*ptrFunNull)();
typedef function<decltype(func1)> ptrFunNull;
//typedef decltype(&func1) ptrFunNull;
ptrFunNull setNew(ptrFunNull f){
    return f;
}
enum aa{
    lukai=250,
    shabi,
    weinaing=260
};
union myun{
    int a;
    char b;
};
int FirstNotRepeatingChar(string str) {
    vector<int>mapIndex(256,10000);
    for(size_t i=0;i<str.size();i++){
        if(mapIndex[str[i]]==10000){
            mapIndex[str[i]]=i;
        }else if(mapIndex[str[i]]>=0) mapIndex[str[i]]=-1;
    }
    int minIndex=10000;
    for(size_t i=0;i<mapIndex.size();i++){
        if(mapIndex[i]>=0&&minIndex>mapIndex[i]) minIndex=mapIndex[i];
    }
    return minIndex;

}
int GetUglyNumber_Solution(int index) {
    vector<int>uglyNum={1};
    if(index==1) return uglyNum[index-1];
    int count=1;
    int it2=0,it3=0,it5=0;
    int val2,val3,val5,minVal;
    while(count<index){
        val2=uglyNum[it2]*2;
        val3=uglyNum[it3]*3;
        val5=uglyNum[it5]*5;
        minVal=min(min(val2,val3),val5);
        if(minVal>*(uglyNum.end()-1)){
            uglyNum.push_back(minVal);
            count++;
        }
        if(minVal==val2) it2++;
        else if(minVal==val3) it3++;
        else it5++;
    }
    return(uglyNum[count-1]);

}
template<typename Iterator>
Iterator upperBoundMy(Iterator it1,Iterator it2,typename Iterator::value_type val){
    if(it1>=it2) return it2;
    int len=distance(it1,it2)/2;
    auto mid=next(it1,len);
    while(it1<it2){
        if(*mid>val) it2=mid;
        else it1=mid+1;
        len=distance(it1,it2)/2;
        mid=next(it1,len);
    }
    return it1;
}
template<typename Iterator>
Iterator lowBoundMy(Iterator it1,Iterator it2,typename Iterator::value_type val){
    if(it1>=it2) return it2;
    int len=distance(it1,it2)/2;
    auto mid=next(it1,len);
    while(it1<it2){
        if(*mid>=val) it2=mid;
        else it1=mid+1;
        len=distance(it1,it2)/2;
        mid=next(it1,len);
    }
    return it2;
}
bool matchHelp(char* str,int strIndex,char* pattern,int patternIndex){
    if(pattern[patternIndex]=='\0'&&str[strIndex]=='\0') return true;
    if(pattern[patternIndex]!='\0'&&str[strIndex]=='\0'){
        if(pattern[patternIndex+1]!='*') return false;
        return matchHelp(str,strIndex,pattern,patternIndex+2);
    }
    if(pattern[patternIndex]=='\0'&&str[strIndex]!='\0') return false;
    if(pattern[patternIndex]=='.'){
        if(pattern[patternIndex+1]!='*')
            return matchHelp(str,strIndex+1,pattern,patternIndex+1);
        else{
            bool answer=false;
            answer = matchHelp(str, strIndex, pattern, patternIndex + 2);
            if (answer) return true;
            for(int i=0;str[strIndex+i]!='\0';i++){
                answer=matchHelp(str,strIndex+i+1,pattern,patternIndex+2);
                if(answer) return true;
            }
            return false;
        }
    }
    if(pattern[patternIndex+1]=='*'){
        if(pattern[patternIndex]!=str[strIndex])
            return matchHelp(str,strIndex,pattern,patternIndex+2);
        bool answer=false;
        answer = matchHelp(str, strIndex, pattern, patternIndex + 2);
        if (answer) return true;
        for(int i=0;str[strIndex+i]==pattern[patternIndex];i++) {
            answer = matchHelp(str, strIndex + i+1, pattern, patternIndex + 2);
            if (answer) return true;
        }
        return false;
    }
    if(pattern[patternIndex]!=str[strIndex]) return false;
    else return matchHelp(str,strIndex+1,pattern,patternIndex+1);
}
bool match(char* str, char* pattern)
{
    return matchHelp(str,0,pattern,0);

}
class testConst{
public:
    static int num;
    int num1;
    testConst():num1(0){};
};
int testConst::num=12;

int main() {
    char *str="a";
    char *pattern=".*";
    cout<<boolalpha<<match(str,pattern);
    typedef  int myInt;
    myInt *p=(int *)malloc(1000*sizeof(int));
    auto temp=p;
    cout<<*p<<endl;
    for (int i = 0; i <1000 ; ++i) {
        new(p+i) int(i);
    }
    for (int i = 0; i <1000 ; ++i) {
        cout<<*(temp+i)<<endl;
    }
    free(temp);
    auto a=setNew(&func2);
    a();
    int *p2=(int*)(malloc(sizeof(int)));
    new(p2) double(2.3);//undefined behavior
    new(p2) int(2.3);//truncted
    myun nn;
    nn.a=10;
    cout<<*p2<<endl<<sizeof(myun)<<" nn.a  "<<nn.a<<endl;
    aa zz=lukai;
    cout<<zz<<"  "<<shabi<<"   "<<weinaing<<"  "<< sizeof(aa)<<endl;

    std::cout << "Hello, World!" << std::endl;
    typename testTrains<vector<int>::iterator>::value_type aaa=444;
    testTrains<int*>::value_type xxx=555;
    cout<<aaa<<endl;
    cout<<xxx<<endl;
    testLis();
    void testStack();
    testStack();
    void testHep();
    testHep();
    std::random_device rd;
    cout<<rd()<<"  "<<rd()<<endl;
    GetUglyNumber_Solution(3);
    FirstNotRepeatingChar("google");
    vector<int>avTest={1,2,3,4,4,4,5,5};
    auto aa=upperBoundMy(avTest.begin(),avTest.end(),5);
    auto bb= upper_bound(avTest.begin(),avTest.end(),5);
    auto cc=lower_bound(avTest.begin(),avTest.end(),4);
    auto dd=lowBoundMy(avTest.begin(),avTest.end(),4);
    if(aa==bb&&cc==dd) printf("正确");
    cout<<boolalpha<<(INT_MIN<-2147483648)<< INT_MIN;
    char ss[10];
    ss[2]='w';
    cout<<endl<<ss<<endl;
    testConst ts1;
    testConst const tsc;
    cout<<ts1.num<<" "<<tsc.num<<endl;
    tsc.num=13;
    cout<<ts1.num<<" "<<tsc.num<<endl;
    return 0;
}