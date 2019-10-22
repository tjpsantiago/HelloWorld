#include <string>
#include <Logger.hpp>

int main()
{
    int idx = 1;
    int siz = 5;
    LOG_ERROR("Tried to access index %d on vector of size %d.\n", idx, siz);
    return 1;
}