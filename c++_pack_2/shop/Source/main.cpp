#include "test.h"
#include "base.h"

int main()
{
    try
    {
        test();
    }
    catch (BaseException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}