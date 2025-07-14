#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <iostream>

using namespace std;

boost::mutex mtx;
boost::condition_variable cv;
bool isRuning = true;

void func1()
{
    static int cnt1 = 0;
    while(true)
    {
        {
            boost::unique_lock<boost::mutex> lock(mtx);
            if(!isRuning) break;
        }
        
        cout << "func1:" << cnt1++ << endl;
        boost::this_thread::sleep(boost::posix_time::seconds(1));
    }
}

void func2()
{
    static int cnt2 = 0;
    while(true)
    {
        {
            boost::unique_lock<boost::mutex> lock(mtx);
            if(!isRuning) break;
        }
        
        cout << "\tfunc2:" << cnt2++ << endl;
        boost::this_thread::sleep(boost::posix_time::seconds(2));
    }
}

int main()
{
    boost::thread thread1(&func1);
    boost::thread thread2(&func2);

    cout << "Press Enter to exit..." << endl;
    cin.get();

    {
        boost::unique_lock<boost::mutex> lock(mtx);
        isRuning = false;
    }
    cv.notify_all();

    thread1.join();
    thread2.join();
    cout << "exit" << endl;
    return 0;
}