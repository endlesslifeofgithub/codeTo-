#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class printfun{
public:
    void operator()(const T& t){
        cout<<t<<" ";
    }
};
int & returnR(){
    int a=10;
    return a;
}
#define avAll(av) av.begin(),av.end()
class od2int{
public:
    bool operator()(int i){
        return i%2==0?true:false;
    }
};
template<typename T,typename Pred>
void partitionMy(  T start,T end,Pred pre){
    if(start>=end) return ;
    while(start<end){
        while((--end)>start){
            if(pre(*end)) break;
        }
        while(start<end){
            if(!pre(*start)) break;
            start++;
        }
        iter_swap(start,end);
        ++start;
    }
}
class less7{
public:
    bool operator()(int i){
        return i<=7;
    }
};
template <typename T>
bool binaysear(T t1,T t2,typename iterator_traits<T>::value_type value){
    if(t1>=t2) return false;
    auto len=t2-t1;
    auto half=len>>1;
    while(t1<=t2){
        if(*(t1+half)==value) return true;
        if(*(t1+half)<value) t1=t1+half+1;
        else t2=t1+half-1;
        half=(t2-t1+1)>>1;
    }
    return false;

}
template <typename T>
void creatRandomV(size_t len,vector<T>&answer){
    answer.resize(len);
    static default_random_engine e(time(0));
    static uniform_int_distribution<T> u(0,100);
    for(int i=0;i<len;i++){
        answer[i]=u(e);
    }
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
template <typename T>
void randomshuffMy(T t1,T t2){
    int lenRandom=1;
    auto tempT1=t1;
    srand(time(0));
    while((++t1)!=t2){
        size_t index=rand()%lenRandom;
        iter_swap(t1,tempT1+index);
        lenRandom++;
    }
}
template<typename It>
vector<typename It::value_type >randomPick(It t1,It t2,size_t num){
    vector<typename It::value_type >answer;
    int len=t2-t1;
    if(len<num) return answer;
    int count=0,numTemp=num;
    //srand((unsigned int)time(0));
    for(;t1!=t2;t1++){
        if(rand()%len<num){
            count++;
            answer.push_back(*t1);
            len--;
            num--;
            if(count==numTemp){
                return answer;
            }
        }else{
            len--;
        }
    }
}

vector<int> ReservoirSampling(vector<int> v, int n, int k)
{
    assert(v.size() == n && k <= n);

    // init: fill the first k elems into reservoir
    vector<int> reservoirArray(v.begin(), v.begin() + k);

    int i = 0;
    int j = 0;
    // start from the (k+1)th element to replace
    srand((unsigned int)time(0));
    for (i = k; i < n; ++i)
    {
        j = rand() % (i + 1); // inclusive range [0, i]
        if (j < k)
        {
            reservoirArray[j] = v[i];
        }
    }

    return reservoirArray;
}

int main() {
    int a;
    cout<<"uninital a:"<<a<<endl;
    int *pa=&a;
    new(pa) int(12);
    cout<<"complte a:"<<a<<endl;
    std::cout << "Hello, World!" << std::endl;
    stack<int,vector<int>>sv;
    sv.push(1);
    sv.push(2);
    while(!sv.empty()){
        cout<<sv.top();
        sv.pop();
    }
    cout<<endl;
    vector<int>avTest={8,36,45,74,12,45,23,42,4,5};
    priority_queue<int>avPriority(avTest.begin(),avTest.end());
    while(!avPriority.empty()){
        cout<<avPriority.top()<<"**";
        avPriority.pop();
    }
    cout<<endl;
    for_each(avAll(avTest),printfun<int>());
    cout<<endl;
    make_heap(avAll(avTest));
    for_each(avAll(avTest),printfun<int>());
    push_heap(avAll(avTest));
    cout<<endl;
    for_each(avAll(avTest),printfun<int>());
    cout<<endl;
    sort_heap(avAll(avTest));
    for_each(avAll(avTest),printfun<int>());
    cout<<endl;


    set<int>msi={1,2,45,4,4,4};
    cout<<*msi.find(4)<<endl;
    cout<<distance(msi.lower_bound(4),msi.upper_bound(4))<<endl<<msi.count(4)<<endl;
    for_each(avAll(msi),printfun<int>());

    vector<int> testod={1,12,3,4,5,6,7,8,9,10};
    cout<<endl;
    for_each(avAll(testod),printfun<int>());
    partitionMy(testod.begin(),testod.end(),less7());
    cout<<endl;
    for_each(avAll(testod),printfun<int>());

    default_random_engine e(time(0));
    cout<<e()<<" "<<e()<<endl;
    sort(avAll(testod));
    cout<<boolalpha<<binaysear(testod.begin(),testod.end(),10);
    vector<int>randv;
    creatRandomV(100,randv);
    for_each(avAll(randv),printfun<int>());
    cout<<endl;
    for(int i=0;i<=100;i++){
        vector<int>randv;
        creatRandomV(100,randv);
        sort(avAll(randv));
        srand(time(0));
        auto index=rand()%100;
        if(binary_search(avAll(randv),index)!=binaysear(avAll(randv),index)){
            cout<<boolalpha<<binaysear(avAll(randv),index)<<" "
                <<binary_search(avAll(randv),index)<<ends;
            cout<<"测试错误"<<endl;}
    }
    vector<int>testRandom={1,2,3,4,5 ,6,7,8,9,10};
    int sum1=0;
    for(int i=0;i<=1000000;i++){
        randomshuffMy(avAll(testRandom));
        sum1+=testRandom[0];
    }
    cout<<sum1<<endl;
    cout<<double(sum1)/1000<<endl;
    //cout<<returnR();
    vector<int>testvvv={6,5,4,3};
    next_preMy(avAll(testvvv));
    int xxx=1;
    {
        vector<int>testRandom={1,2,3,4,5 ,6,7,8,9,10};
        printf("CCCCCCCCCCCCCCCCCCCCCC\n");
        //auto ans=randomPick(avAll(testRandom),3);
        int sum1=0;
        for(int i=0;i<=10000;i++){
            auto ans=ReservoirSampling(testRandom,10,3);
            //auto ans=randomPick(avAll(testRandom),3);
            //randomshuffMy(avAll(ans));
            sum1=accumulate(avAll(ans),sum1);
        }
        cout<<sum1/3<<endl;
        cout<<"random_pick"<<double(sum1)/1000<<endl;
        //for_each(avAll(ans),printfun<int>());
    }

    return 0;

}