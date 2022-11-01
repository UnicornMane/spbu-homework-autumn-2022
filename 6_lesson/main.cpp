#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char  *argv[])
{
    try
    {
        std::fstream fs;
        fs.open("//Users//mi//Documents//txts//true.txt", std::fstream::in | std::fstream::out | std::fstream::app);
        if (!fs.is_open())
        {
            throw std::fstream::failure("Unable to run true.txt");
        }
        if()
    }
    catch(std::exception &ex)
    {
        if (typeid(ex) == typeid(std::underflow_error))
        {
            std::cout << ex.what() << std::endl;
        }
        else if (typeid(ex) == typeid(std::ifstream::failure))
        {
            std::cout << ex.what();
        }
    }
    return EXIT_SUCCESS;
}
