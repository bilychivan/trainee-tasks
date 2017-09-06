#include "test.h"
#include "entity.h"

int main()
{
    try
    {
        test();      
    }
    catch(EntityException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}