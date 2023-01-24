#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

std::mutex m;
std::condition_variable cv;



void printOdd(int *x,int *y)
{
    while(true && *y < 199 && *x < 200)
    {
        std::unique_lock<std::mutex> ul(m);
        cv.wait(ul,[&](){ return *y < *x;});
        *y = *y + 2;
        std::cout<<*y<<std::endl;
        cv.notify_one();
    }
    
}

void printEven(int *x,int *y)
{
    while(true && *y < 199 && *x <  200)
    {
        std::unique_lock<std::mutex> ul(m);
        cv.wait(ul,[&](){return *x < *y;});
        *x = *x + 2;
        std::cout<<*x<<std::endl;
        cv.notify_one();

    }
}



int main()
{
    std::thread t1,t2;
    int x = 0,y=1;

    //std::cout<<x<<std::endl;
    // std::cout<<y<<std::endl;
    t1 = std::thread(&printOdd,&x,&y);
    t2 = std::thread(&printEven,&x,&y);
    
    t1.join();
    t2.join();

    return 0;


}