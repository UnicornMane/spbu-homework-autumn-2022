#include <iostream>
#include <exception>
#include <limits>

template<typename any>
any min(any f, any s)
{
    if (f < s)
        return f;
    return s;
}

template<typename any>
any maxF(any f, any s)
{
    if (f > s)
        return f;
    return s;
}

template<typename any>
class selfVector
{
private:
    int m_size;
    int m_capacity;
    any* m_data;
public:
    selfVector()
    {
        m_size = 0;
        m_capacity = 0;
        m_data = nullptr;
    }
    selfVector(int n)
    {
//        if (n < 0)
//        {
//            throw std::length_error("vector size can't be less than zero!!\n");
//        }
        m_size = n;
        m_data = new any[n];
    }
    selfVector(int n, any t)
    {
//        if (n < 0)
//        {
//            throw std::length_error("vector size can't be less than zero!!\n");
//        }
        m_size = n;
        m_data = new any[n];
        for (int i = 0; i < n; ++i)
        {
            m_data[i] = t;
        }
    }
    ~selfVector()
    {
        delete[] m_data;
    }

    int capacity()
    {
        return m_capacity;
    }

    int size()
    {
        return m_size;
    }

    any& operator[] (int i)
    {
//        if (i >= m_size)
//        {
//            throw std::out_of_range("out_of_range!!\n");
//        }
        return m_data[i];
    }

    void resize(int newsize)
    {
        if (newsize <= m_capacity)
        {
            m_size = newsize;
            return;
        }

//        if ((long long)2*m_size > std::numeric_limits<int>::max())
//        {
//            throw std::bad_alloc("you can't make size of vector bigger than (2<<31 - 1)\n");
//        }
        int newcapacity = maxF(newsize, m_size * 2);
        any* new_data = new any[newcapacity];
        int i = 0;
        for (; i < min(m_size, newsize); ++i)
            new_data[i] = m_data[i];
        for (; i < newsize; ++i)
            new_data[i] = any();
        delete[] m_data;
        m_data = new_data;
        m_size = newsize;
        m_capacity = newcapacity;
    }

    void push_back(any val)
    {
        resize(m_size + 1);
        m_data[m_size - 1] = val;
    }

    void insert(int pos, any val)
    {
        resize(m_size + 1);
        for (int i = m_size - 1; i > pos; --i)
        {
            m_data[i] = m_data[i - 1];
        }
        m_data[pos] = val;
    }

    int sum()
    {
        int s = 0;
        for (int i = 0; i < m_size; ++i)
        {
//            if (s + m_data[i] > std::numeric_limits<int>::max())
//            {
//                throw std::overflow_error("the sum of elements is bigger than INT_MAX\n");
//            }
            s += m_data[i];
        }
        return s;
    }

    void invert_element(int ind)
    {
//        if (m_data[ind] == 0)
//        {
//            throw std::underflow_error("you will get +-inf element\n");
//        }
        m_data[ind] = 1 / m_data[ind];
    }
};


template <typename any>
any max(selfVector<any>& a)
{
    int tmp = a[0];
    for (int i = 1; i < a.size(); ++i)
    {
        if (a[i] > tmp)
            tmp = a[i];
    }
    return tmp;
}

template<typename T>
void sort(selfVector<T>& a)
{
    for (int i = a.size(); i > 0; --i)
        for (int j = 1; j < i; ++j)
            if (a[j - 1] > a[j])
                std::swap(a[j - 1], a[j]);
}

template <typename any>
std::ostream &operator << (std::ostream& out, selfVector<any>& a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        out << a[i] << " ";
    }
    //out << std::endl;
    return out;
}

template <typename any>
selfVector<any>& operator + (selfVector<any>& a, selfVector<any>& b)
{
    int tmp = a.size();
    a.resize(a.size() + b.size());
    int i = 0;
    while (tmp != a.size())
    {
        a[tmp] = b[i];
        i++;
        tmp++;
    }
    return a;
}
