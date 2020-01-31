# Inter-thread Communication (线程间通信)
## 1. Thread-safe
```cpp
#include <iostream>
#include <mutex>
#include <thread>
#include <atomic>
using namespace std;

//atomic<int> num = 0; //atomic variable
int num = 0;
const int N = 100000000;
mutex x_mutex;

void add()
{
    for (int i = 0; i < N; i++)
    {
        //lock_guard<mutex> lock(x_mutex); //Mutex
        num++;
    }
}

int main()
{
    clock_t begin = clock();
    thread t1(add);
    //t1.join(); //join()
    thread t2(add);
    t1.join();
    t2.join();
    clock_t end = clock();
    cout << "num = " << num << "\nTime: " << end - begin << "ms" << endl;
    return 0;
}
```
* `Mutex`: lock_guard<mutex> lock(x_mutex);
* `Atomic Variable`: atomic<int> num = 0;
* `join()`: join() before t2