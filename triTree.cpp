#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    class TreNode{
    public:
        TreNode*left;
        TreNode*right;
        TreNode():left(nullptr),right(nullptr){};
    };
    void insertNode(TreNode* root,int value){
        if(root==nullptr) return;
        for(int i=0;i<32;i++){
            int bit=((value>>(31-i))&1);
            if(bit==0){
                if(root->left==nullptr) root->left=new TreNode();
                root=root->left;
            }else{
                if(root->right==nullptr) root->right=new TreNode();
                root=root->right;
            }

        }
    }
    int findMax(TreNode* root,int value){
        auto tempRoot=root;
        int answer=0;
        for(int i=0;i<32;i++){
            if(tempRoot==nullptr) return answer;
            int flag=((value>>(31-i))&1);
            if(flag==1){
                if(root->left!=nullptr){
                    answer|=(1<<(31-i));
                    tempRoot=tempRoot->left;
                }else tempRoot=tempRoot->right;
            }else{
                if(tempRoot->right!=nullptr){
                    answer|=(1<<(31-i));
                    tempRoot=tempRoot->right;
                }else tempRoot=tempRoot->left;
            }

        }
        return answer;
    }


public:
    int findMaximumXOR(vector<int>& nums) {
        TreNode* root=new TreNode();
        for(auto num:nums){
            insertNode(root,num);
        }
        int answer=0;
        for(auto num:nums) {
            int count = findMax(root, num);
            answer = max(answer, count);
        }
        return answer;
    }
};
#include<bits/stdc++.h>
using namespace std;
vector<int> getRaw(vector<int>& last,int n){
    int count=0;
    int tempN=n;
    while(last[n]!=0){
        count++;
        last[n]--;
        if(n-1<0) n=last.size()-1;
        else n=n-1;
    }
    last[n]=count;
    return last;
}
int main(){
    int count,index;
    cin>>count;
    cin>>index;
    vector<int>last;
    while(count>0){
        int temp;
        cin>> temp;
        last.push_back(temp);
        count--;
    }
    auto answer=getRaw(last,index-1);
    for_each(answer.begin(),answer.end()-1,[](int i){cout<<i<<ends;});
    cout<<*(answer.end()-1);
}
/*int main() {
    Solution d1;
    vector<int>av={3,10,5,25,2,8};
    cout<<d1.findMaximumXOR(av)<<"  "<<(5^25)<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}*/