#include <iostream>
#include <functional>
#include <type_traits>
using namespace std;


template <typename T, typename... Ts>
class logger
{
private:
    function<T(Ts...)> f;

public:
    logger(function<T(Ts...)> f)
    {
        this->f = f;
    }


    void operator() (Ts... args) requires (is_same_v<T, void>)
    {
        {int dummy[sizeof...(Ts)] = {(std::cout << args << "; ", 0)...};}
        cout << endl;
        f(args...);
    }

    T operator() (Ts... args)
    {
        {int dummy[sizeof...(Ts)] = {(std::cout << args << "; ", 0)...};}
        cout << endl;
        return f(args...);
    }
};


double fs(long long t, double k)
{
    return t/k;
}

void v_fs(long long t, double k)
{
    cout << t/k << endl;
}

int main()
{
    long long t = 6;
    double k = 0.1;
    logger <double, long long, double> F(fs);
    cout << F(t, k) << endl;

    logger <void, long long, double> v_F(v_fs);
    v_F(t, k);


}