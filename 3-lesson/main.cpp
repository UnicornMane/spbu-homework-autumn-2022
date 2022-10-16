#include <iostream>


using namespace std;


template <typename T>
class q
{
public:
    T s, x, y, z;
    q()
    {
        s = 0;
        x = 0;
        y = 0;
        z = 0;
    }
    q(T s = 0, T x = 0, T y = 0, T z = 0)
    {
        this->s = s;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    q<T> operator*(q<T> b);
    q<T> operator*(T a);
    q<T> operator/(T a);
    q<T> operator/(q<T> b);
    q<T> operator+(q<T> b);
    q<T> operator-(q<T> b);
    q<T> operator-();
    q<T>& operator+=(q<T> a);
    q<T>& operator-=(q<T> a);
    q<T>& operator*=(q<T> a);
    q<T>& operator*=(T a);
    q<T>& operator/=(q<T> a);
    q<T>& operator/=(T a);
};

template<typename T>
q<T> q<T>::operator*(q<T> b)
{
    return q<T>(this->s * b.s - this->x*b.x - this->y*b.y - this->z*b.z,
                this->s * b.x + this->x * b.s + this->y *  b.z - this->z  * b.y,
                this->s * b.y  + this->y * b.s + this->z * b.x - this->a * b.z,
                this->s * b.z + this->z * b.s + this->x * b.y - this->y *  b.x);
}

template<typename T>
q<T> q<T>::operator*(T a)
{
    return q<T>(this->s * a, this->x * a, this->y * a, this->z * a);
}

template<typename T>
q<T> q<T>::operator/(T a)
{
    return q<T>(this->s / a, this->x / a, this->y / a, this->z / a);
}

template<typename T>
q<T> q<T>::operator/(q<T> b)
{
    q<T> bRev(b.s, -b.x, -b.y, -b.z);
    T normSq = b.s * b.s + b.x * b.x + b.y * b.y + b.z * b.z;
    q<T> bInv = bRev / normSq;
    return (*this) * bInv;
}

template<typename T>
q<T> q<T>::operator+(const q<T> b)
{
    return q<T>(this->s + b.s, this->x + b.x, this->y + b.y, this->z + b.z);
}

template<typename T>
q<T> q<T>::operator-(const q<T> b)
{
    return q<T>(this->s - b.s, this->x - b.x, this->y - b.y, this->z - b.z);
}

template<typename T>
q<T> q<T>::operator-()
{
    return q<T>(-this->s, -this->x, -this->y, -this->z);
}

template<typename T>
q<T> &q<T>::operator+=(q<T> a)
{
    this->s += a.s;
    this->x += a.x;
    this->y += a.y;
    this->z += a.z;
    return *this;
}

template<typename T>
q<T> &q<T>::operator-=(q<T> a)
{
    a = -a;
    this->s += a.s;
    this->x += a.x;
    this->y += a.y;
    this->z += a.z;
    return *this;
}

template<typename T>
q<T> &q<T>::operator*=(q<T> a)
{
    (*this) =  (*this) * a;
    return (*this);
}

template<typename T>
q<T> &q<T>::operator*=(T a)
{
    (*this) = (*this) * a;
    return (*this);
}

template<typename T>
q<T> &q<T>::operator/=(q<T> a)
{
    (*this) = (*this) / a;
    return (*this);
}

template<typename T>
q<T> &q<T>::operator/=(T a)
{
    (*this) = (*this) / a;
    return (*this);
}

template<typename T>
bool operator==(const q<T> &left, const q<T> right)
{
    return (left.s == right.s) && (left.x == right.x) && (left.y == right.y) && (left.z == right.z);
}

template <typename T>
std::ostream &operator << (std::ostream& out, const q<T> &a)
{
    return out << a.s << " + (" << a.x << "*i) + (" << a.y << "*j) + (" << a.z << "*k)";
    //return out;
}



int main(int argc, char* argv[])
{
    q<int> a(1, 2, 5, 4);
    q<int> b(1, 2, 3, 4);
    cout << "a: " << a << endl << "b: " << b << endl;
    cout << "b + a: " << b + a << endl;
    cout << "b - a: " << b - a << endl;
    cout << "-a: " <<  -a << endl;
    a += b;
    cout << "a += b: " << a << endl;
    a -= b;
    a -= b;
    cout << "a -= b: " << a << endl;

    return EXIT_SUCCESS;
}
