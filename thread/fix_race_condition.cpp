#include <string>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include "../../thread/pparallelism.h"

//easy sharing of data between thread can cause problems-- race condition
//two parallel operations access the same memory
//this kind of bugs is hard to find and reproduce

//5 threads to increment money until reach 5000
const static int TARGET_MONEY=6000;
const static int MONEY_CHANNEL=6;

class Wallet
{
 public:
    Wallet():money(0) {}
    ~Wallet() {}
    int getMoney() const {return money;}
    void addMoney(int mon)
    {
        for(int i=0; i<mon; ++i)
            ++money;
        //internal mechanism of race condition happens
        /** 1. load 'money' variable value in register
              2. do increment
              3. update 'money' with register's value
              when this three steps has been disorder, register could get a overwritten
              value
        to solve the problem, lock mechanism need to be introduced
         */


    }
 private:
    int money;
};

class Wallet_mutex
{
public:
     Wallet_mutex():money_(0) {}
    ~Wallet_mutex() {}
     int getMoney() const {return money_;}
     void addMoney(int mon)
     {
         //mutex lock prevent the disorder lead by race condition
         mutex_.lock();
         for(int i=0; i<mon; ++i)
            ++money_;
         mutex_.unlock();
     }
     void addMoney_2(int mon)
     {
         //in 'locker' 's constructor it locks the mutex
         std::lock_guard<std::mutex> locker(mutex_);
         for(int i=0; i<mon; ++i)
            ++money_; //collect the exceptions and call the stack unwinding
         //once function exits, the destructor of 'locker' will
         //be called and unlocks the mutex
     }
private:
    int money_;
    std::mutex  mutex_;
};

int MultithreadWallet()
{
    Wallet m_wallet;
    std::vector<std::thread> threads;
    for(unsigned int i=0 ; i<MONEY_CHANNEL; ++i)
    {
        threads.push_back(std::thread(&Wallet::addMoney, &m_wallet,
                                      TARGET_MONEY/MONEY_CHANNEL));

    }

    for(unsigned int i=0 ; i<threads.size(); ++i)
    {
        threads.at(i).join();
    }

    return m_wallet.getMoney();
}

int MultithreadWallet_reliable()
{
    Wallet_mutex m_wallet_r;
    std::vector<std::thread> threads_r;
    for(unsigned int i=0 ; i<MONEY_CHANNEL; ++i)
    {
       // threads_r.push_back(std::thread(&Wallet_mutex::addMoney, &m_wallet_r,
       //                               TARGET_MONEY/MONEY_CHANNEL));
       //using the template class lock_guard which implements RAII for mutex
          threads_r.push_back(std::thread(&Wallet_mutex::addMoney_2, &m_wallet_r,
                                      TARGET_MONEY/MONEY_CHANNEL));
    }

    for(unsigned int i=0 ; i<threads_r.size(); ++i)
    {
        threads_r.at(i).join();
    }

    return m_wallet_r.getMoney();
}

int main()
{
  int val = 0;
  //executed in parallel, hence the money will be less than the target
  //this is a race condition, as two or more threads are trying to modify the same memory location
  //  and lead to unexpected conditions
  for(int k = 0; k < TARGET_MONEY/MONEY_CHANNEL; k++)
  {
     if((val = MultithreadWallet()) != TARGET_MONEY)
     {
       std::cout << "Error at count = "<<k<<" Money in Wallet = "<<val << std::endl;
     }
  }

  //using mutex to prevent race condition
 std::cout <<"After lock guarantees\n";
 int val_r=0;
 for(int kr = 0; kr < TARGET_MONEY/MONEY_CHANNEL; kr++)
  {
     if((val_r = MultithreadWallet_reliable()) != TARGET_MONEY)
     {
       std::cout << "Error at count = "<<kr<<" Money in Wallet = "<<val_r << std::endl;
     }
  }
  return 0;
}

