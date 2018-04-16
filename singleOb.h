//
// Created by endlesslife on 17-11-27.
//

#ifndef SINGLEOBJECT_SINGLEOB_H
#define SINGLEOBJECT_SINGLEOB_H
#include <memory>
#include <bits/stdc++.h>
#include <boost/ref.hpp>
/////////////////////////终极版
class singtonFin{
public:
    int flag;
    //怎么样不用管返回的是引用还是正常的值
    static singtonFin& getInstance(){
        static singtonFin s;//c++11 保证局部静态变量在初始化的时候是线程安全的所以没有问题.
        return s;
    }
private:
    //下面三个是必须要私有或者删除的
    singtonFin(){std::cout<<"s:construct"<<std::endl;};
    singtonFin (const singtonFin&);
    singtonFin& operator=(const singtonFin&);
    //static std::shared_ptr<sington> s;
};
/////////////////////////////////////
//class singlTonP:singtonFin{
//
//public:
//    singlTonP(){};
//    singtonFin& getinstanceP(){
//        return singtonFin::getInstance();
//    }
//};
///////////////////////////////////////////////////////////////
//下面应该也可以
class sington{
public:
    typedef std::shared_ptr<sington> sType;
    int flag=1;
    static sington& getInstance(){
        //if(s== nullptr) s=std::shared_ptr<sington>(new sington());
        return *s;
    }
private:
    sington(){std::cout<<"s2:construct"<<std::endl;};
    sington(const sington&);
    sington& operator=(const sington&);
    static sType s;
    //static sington* s;
};
//sington* sington::s=new sington();
sington::sType sington::s=sington::sType(new sington());
/////////////////////////////////////////////////////////////



class singleTon2{
private:
    singleTon2(){};
public:
    static singleTon2& getInstance(){
        static singleTon2 s;
        return s;
    }
};
class CSingleton
{
private:
    static std::mutex mutex;
    CSingleton(){};
    static CSingleton * m_pInstance;
public:
    ~CSingleton(){
        delete m_pInstance;
    }
    static CSingleton* GetInstance()
    {
        if ( m_pInstance == NULL ){
            mutex.lock();
            if(m_pInstance == NULL )
                m_pInstance = new CSingleton();
            mutex.unlock();
        }

        return m_pInstance;
    }

};
std::mutex  CSingleton::mutex;
CSingleton* CSingleton::m_pInstance=new CSingleton();
//std::shared_ptr<sington> sington::s=std::make_shared<sington>();
//sington* sington::s=new sington();



#endif //SINGLEOBJECT_SINGLEOB_H
