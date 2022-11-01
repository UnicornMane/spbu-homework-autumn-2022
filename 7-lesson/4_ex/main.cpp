#include <iostream>

template <typename T>
bool templated(T a)
{
    return true;
}

template<>
bool templated<int>(int a)
{
    return false;
}

int main()
{
    std::cout << templated(3.01f) << std::endl;
    std::cout << templated((int)3) << std::endl;
}
