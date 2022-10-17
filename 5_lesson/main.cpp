#include <iostream>

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
class dynamic_array
{
private:
    int m_size;
    int m_capacity;
    any* m_data;
public:
    dynamic_array()
    {
        m_size = 0;
        m_capacity = 0;
        m_data = nullptr;
    }
    dynamic_array(int n)
    {
        m_size = n;
        m_data = new any[n];
    }
    ~dynamic_array()
    {
        if (m_data)
            delete[] m_data;
    }

    int size()
    {
        return m_size;
    }

    any& operator[] (int i)
    {
        return m_data[i];
    }

    void resize(int newsize)
    {
        if (newsize <= m_capacity)
        {
            m_size = newsize;
            return;
        }

        int newcapacity = maxF(newsize, m_size * 2);
        any* new_data = new any[newcapacity];
        int i;
        for (i = 0; i < min(m_size, newsize); ++i)
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

};

//void dynamic_array::max(dynamic_array& a)
template <typename any>
any max(dynamic_array<any>& a)
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
void sort(dynamic_array<T>& a)
{
    for (int i = a.size(); i > 0; --i)
        for (int j = 1; j < i; ++j)
            if (a[j - 1] > a[j])
                std::swap(a[j - 1], a[j]);
}

template <typename any>
std::ostream &operator << (std::ostream& out, dynamic_array<any>& a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        out << a[i] << " ";
    }
    //out << std::endl;
    return out;
}

template <typename any>
dynamic_array<any>& operator + (dynamic_array<any>& a, dynamic_array<any>& b)
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

template <typename T>
class Stack : public dynamic_array<T>
{
public:
    void push(T val)
    {
        this->push_back(val);
    }

    T top()
    {
        return (*this)[this->size() - 1];
    }

    void pop()
    {
        this->resize(this->size() - 1);
    }

    bool empty()
    {
        return this->size() == 0;
    }

};

int main()
{
    
}