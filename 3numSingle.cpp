#include <bits/stdc++.h>
using namespace std;
extern "C"{
    void printFun(int a,char*s);
}
#include "testStaticH.h"
int singleNumber(vector<int>nums) {
    size_t lenInt=sizeof(int)*8;
    int answer=0,sum=0;

    for(size_t bitIndex=0;bitIndex<lenInt;++bitIndex){
        sum=0;
        for (auto num:nums){
            if((num>>bitIndex)&1==1){
                sum++;
                sum%=3;
            }
        }
        if(sum==1){
            answer=answer|(1<<bitIndex);
        }
    }
    return answer;

}
map<pair<int,int>,int> visited;
int uniquePaths(int m, int n) {
    if(m==1||n==1) return 1;
    pair<int,int>p2=make_pair(m,n);
    pair<int,int>p2Inverse=make_pair(n,m);
    if(visited.find(p2)!=visited.end()) return (visited[p2]);
    if(visited.find(p2Inverse)!=visited.end()) return (visited[p2Inverse]);
    int answer=0;
    if(m-1>0) answer+=uniquePaths(m-1,n);
    if(n-1>0) answer+=uniquePaths(m,n-1);
    visited[p2]=answer;
    visited[p2Inverse]=answer;
    return(answer);
}
int triangleNumber(vector<int> nums) {
    if(nums.size()<3) return 0;
    sort(nums.begin(),nums.end());
    int low=0,high=0,sum=0,count=0;
    for(size_t i=0;i<nums.size()-2;++i){
        for(size_t j=i+1;j<nums.size()-1;++j){
            high=nums[j]+nums[i]-1;
            count=upper_bound(nums.begin(),nums.end(),high)-nums.begin()-j-1;
            if(count<=0) count=0;
            // if(nums[j]<=high&&nums[j]>=low) count--;
            // if(nums[i]<=high&&nums[i]>=low) count--;
            sum+=count;
        }
    }
    return sum;
}
int main() {
    cout<<triangleNumber(vector<int>{82,15,23,82,67,0,3,92,11});
    cout<<uniquePaths(2,4)<<endl;
    cout<<(0&(1<<0))<<endl;
    cout<<singleNumber(vector<int>{1});
    int aaac=sizeof(int);
    int as=12,ad=13;
    const int &ass=as;
    as=14;
    cout<<"ass: "<<ass<<endl;
    extern string ss;
    //extern char c;
    printf("%c",c);
    void printStr(const string&);
    cout<<ss<<endl;
    printStr("hello main,");
    std::cout << "Hello, World!" << std::endl;

    int a=12;
    char*sss="123asd";
    printFun(a,sss);
    return 0;
}