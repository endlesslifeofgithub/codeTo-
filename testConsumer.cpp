#include <thread>
#include <mutex>
#include <deque>
#include <vector>
#include<iostream>
#include <unistd.h>
#include <condition_variable>
using namespace std;
static void test(){
    std::cout<<"test"<<std::endl;
}
class CThreadDemo
{
private:
    std::deque<int> m_data;
    std::mutex m_mtx; // 全局互斥锁.
    std::condition_variable m_cv; // 全局条件变量.
    std::condition_variable full_cv; // 全局条件变量.
    int       m_nGen;

private:
    void ProductThread(){
        while (true){
            std::unique_lock <std::mutex> lck(m_mtx);
            m_nGen = ++m_nGen % 1000;
            std::cout<<std::hex<<std::this_thread::get_id();
            printf("  product %d\n", m_nGen);
            m_data.push_back(m_nGen);
            lck.unlock();
            m_cv.notify_all();

            /* 等待1S */
            std::chrono::milliseconds dura(1000);
            std::this_thread::sleep_for(dura);
        }
    }

    void ConsumeThread(){
        while (true){
            std::unique_lock <std::mutex> lck(m_mtx);
            while (m_data.empty()){
                m_cv.wait(lck);
            }
            int nData = m_data.front();
            m_data.pop_front();
            std::cout<<std::hex<< std::this_thread::get_id();
            printf("  consume %d\n", nData);
            std::cout<<"deque: "<<m_data.size()<<std::endl;
            lck.unlock();

            /* 等待2S */
            std::chrono::milliseconds dura(1000);
            std::this_thread::sleep_for(dura);

        }
    }
public:
    CThreadDemo(){
        m_data.clear();
        m_nGen = 0;
    }

    void Start(){
        std::vector<std::thread> threads;
        threads.clear();
        for (int i = 0; i < 5; i++){/* 生产者线程 */
            threads.push_back(std::thread(&CThreadDemo::ProductThread, this));
        }
        for (int i = 5; i < 10; i++){/* 消费者线程 */
            threads.push_back(std::thread(&CThreadDemo::ConsumeThread,this));
        }
        for (auto& t : threads){/* 等待所有线程的退出 */
            t.join();
        }
    }
};
mutex mu;
int flag=0;
condition_variable cv;
void printA(int k) {
    for (int i = 0; i < k; i++) {
        //mu.lock();
        unique_lock<mutex> lk(mu);
        cv.wait(lk,[](){return flag%2==0;});
        cout << "A" << endl;
        flag++;
        cv.notify_all();
    }
}
void printB(int k) {
    for (int i = 0; i < k; i++) {
        //mu.lock();
        unique_lock<mutex> lk(mu);
        cv.wait(lk,[](){return flag%2==1;});
        cout << "B" << endl;
        flag++;
        cv.notify_all();
    }
}
function<void(int)> funtonal;
void fc(int i){cout<<"普通函数 "<<i<<endl;}
class testf{
public:  void operator()(int i){cout<<"仿函数 "<<i<<endl;}
};
int main()
{
    /*CThreadDemo test;
    test.Start();*/
    auto t1=thread(&printA,10);
    auto t2=thread(&printB,10);
    t1.join();
    t2.join();
    funtonal=fc;
    funtonal(12);
    funtonal=testf();
    funtonal(13);
    return 0;
}