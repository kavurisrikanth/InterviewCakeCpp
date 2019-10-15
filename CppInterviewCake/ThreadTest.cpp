#include "Thread.cpp"
#include <iostream>
#include <thread>

void doInsert(Thread *t)
{
    for (int i = 0; i < 10; i++)
    {
        t->insert(i);
        // std::this_thread::sleep_for(std::chrono::milliseconds(8));
        std::cout << "Insert done: " << i << std::endl;
    }

    std::cout << "Display after insert" << std::endl;
    t->display();
}

void doRemove(Thread *t)
{
    int num_clashes = 0;

    std::cout << "Display before remove" << std::endl;
    t->display();
    for (int i = 0; i < 10; i++)
    {
        try
        {
            std::cout << "Trying to remove" << std::endl;
            int x = t->remove();
            std::cout << "Remove done: " << x << std::endl;
        }
        catch (std::underflow_error e)
        {
            num_clashes++;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    std::cout << "#Clashes: " << num_clashes << std::endl;
}

int main(void)
{
    Thread* t = new Thread();
    std::thread one(doInsert, t);
    std::thread two(doRemove, t);

    one.join();
    two.join();

    delete t;
    return 0;
}