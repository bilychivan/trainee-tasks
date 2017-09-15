#include "memory_manager_library.h"

#include <iostream>
#include <cstring>
#include <thread>
#include <atomic>
#include <vector>

void threadFunction(const std::atomic<bool>& flag)
{
    const char* strToCopy = "Turtle";
    const size_t charNum = strlen(strToCopy) + 1;
    const char* strToCopy2 = "Albatrossen";
    const size_t charNum2 = strlen(strToCopy2) + 1;
    char* p;

    for (; !flag; )
    {
        std::this_thread::yield();
    }

    p = (char *) requestMemorySafe(charNum);

    if (p == NULL)
    {
        std::cout << "NULL\n";
        return;
    }
    std::cout << "adress = " << (void*)p << std::endl;

    strcpy(p, strToCopy);

    std::cout << "copied string = " << p << std::endl;

    p = (char *) changeMemorySizeSafe(p, charNum2);

    if (p == NULL)
    {
        std::cout << "NULL\n";
        return;
    }
    std::cout << "adress2 = " << (void *)p << std::endl;

    strcpy(p, strToCopy2);

    std::cout << "copied string = " << p << std::endl;

    freeMemorySafe(p);
}

void test()
{
    std::vector<std::thread> threadArray;
    const size_t threadNum = 1000;
    std::atomic<bool> startFlag{false};

    init(1024);

    for (size_t i = 0; i < threadNum; ++i)
    {
        threadArray.push_back(std::thread(threadFunction, std::ref(startFlag)));
    }

    startFlag = true;

    for (auto& t : threadArray)
    {
        t.join();
    }

    freeAllMemory();
}

int main()
{
    test();

    return 0;
}