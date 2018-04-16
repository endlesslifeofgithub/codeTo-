#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int megreList(vector<int>& data,int start,int mid,int end){
    int ptr1=mid-1,ptr2=end,answer=0;
    vector<int>temp(end-start+1,0);
    int index=end-start;
    while(ptr1>=start&&ptr2>=mid){
        if(data[ptr1]>data[ptr2]){
            answer+=(ptr2-mid+1);
            temp[index]=data[ptr1];
            ptr1--;
            index--;
        }else {
            temp[index]=data[ptr2];
            ptr2--;
            index--;
        }
    }
    if(ptr1<start){
        for(int i=ptr2;i>=mid;i--){
            temp[index]=data[ptr2];
            ptr2--;
            index--;
        }
    }
    if(ptr2<mid){
        for(int i=ptr1;i>=start;i--){
            temp[index]=data[ptr1];
            ptr1--;
            index--;
        }
    }
    copy(temp.begin(),temp.end(),data.begin()+start);
    return answer;
}
int InversePairsHelp(vector<int>& data,int start,int end) {
    int answer = 0;
    if (start >= end) return answer;
    int len = end - start + 1;
    auto mid = start + (len >> 1);
    auto left = InversePairsHelp(data, start, mid - 1);
    auto right = InversePairsHelp(data, mid, end);
    auto megreNum = megreList(data, start, mid, end);
    return left + right + megreNum;
}
int InversePairs(vector<int>&data) {
    auto answer=InversePairsHelp(data,0,data.size()-1);
    return answer;
}
vector<vector<int>>answer;
void combinationSumHelp(const vector<int>& candidates, int target,vector<int>path,int startIndex){
    if(target<0) return;
    if(target==0){
        answer.push_back(path);
        return;
    }
    for(int i =startIndex;i<candidates.size();i++){
        auto temp=path;
        temp.push_back(candidates[i]);
        combinationSumHelp(candidates,target-candidates[i],temp,i+1);
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int>path;
    combinationSumHelp(candidates,target,path,0);
    return answer;


}

string ReverseSentence(string str) {
    int index=str.size()-1,start,end;
    string answer;
    start=index,end=index;
    while(index>=0){
        if(str[index]==' '){
            start=index;
            answer=answer+string(str.begin()+start+1,str.begin()+end+1)+' ';
            end=index;
        }
        index--;
    }
    //if(end==str.size()-1) return str;
    answer=answer+string(str.begin(),str.begin()+end);
    return answer;;
}


int main() {
    vector<int>an={2,6,3,2,7};
    auto answer=combinationSum(an,7);
    string ss="student.";
    cout<<ReverseSentence(ss);
    //cout<<InversePairs(an);
    std::cout <<endl<< "Hello, World!" << std::endl;
    return 0;
}