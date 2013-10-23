/*
 * 实现String类
 * 2012-07-30
 */
#include <iostream>
#include <stdexcept>
#include <cstring>
using namespace std;

#if (_MSC_VER == 1200)  //VC6
#define for if (0); else for
#endif

class String
{
public:
    String();
    String(const char *s);
    String(const char *s, size_t n);
    String(size_t n, char c);
    String(const String& str);
    String(const String& str, size_t pos, size_t n = npos);
    ~String();

    String& append(const String& str);
    String& append(const String& str, size_t pos, size_t n);
    String& append(const char *s, size_t n);
    String& append(const char *s);
    String& append(size_t n, char c);

    String& assign(const String& that);
    String& assign(const String& str, size_t pos, size_t n);
    String& assign(const char *s, size_t n);
    String& assign(const char *s);
    String& assign(size_t n, char c);

    char& at(size_t pos);
    const char& at(size_t pos) const;
    size_t capacity() const;
    void clear();

    int compare(const String& str) const;
    int compare(const char *s) const;
    int compare(size_t pos1, size_t n1, const String& str) const;
    int compare(size_t pos1, size_t n1, const char *s) const;
    int compare(size_t pos1, size_t n1, const String& str, size_t pos2, size_t n2) const;
    int compare(size_t pos1, size_t n1, const char *s, size_t n2) const;

    size_t copy(char *s, size_t n, size_t pos = 0) const;
    const char *c_str() const;
    const char *data() const;
    bool empty() const;
    String& erase(size_t pos = 0, size_t n = npos);

    size_t find(const String& str, size_t pos = 0) const;
    size_t find(const char *s, size_t pos, size_t n) const;
    size_t find(const char *s, size_t pos = 0) const;
    size_t find(char c, size_t pos = 0) const;

    size_t find_first_not_of(const String& str, size_t pos = 0) const;
    size_t find_first_not_of(const char *s, size_t pos, size_t n) const;
    size_t find_first_not_of(const char *s, size_t pos = 0) const;
    size_t find_first_not_of(char c, size_t pos = 0) const;

    size_t find_first_of(const String& str, size_t pos = 0) const;
    size_t find_first_of(const char *s, size_t pos, size_t n) const;
    size_t find_first_of(const char *s, size_t pos = 0) const;
    size_t find_first_of(char c, size_t pos = 0) const;

    size_t find_last_not_of(const String& str, size_t pos = npos) const;
    size_t find_last_not_of(const char *s, size_t pos, size_t n) const;
    size_t find_last_not_of(const char *s, size_t pos = npos) const;
    size_t find_last_not_of(char c, size_t pos = npos) const;

    size_t find_last_of(const String& str, size_t pos = npos) const;
    size_t find_last_of(const char *s, size_t pos, size_t n) const;
    size_t find_last_of(const char *s, size_t pos = npos) const;
    size_t find_last_of(char c, size_t pos = npos) const;

    String& insert(size_t pos1, const String& str);
    String& insert(size_t pos1, const String& str, size_t pos2, size_t n);
    String& insert(size_t pos1, const char *s, size_t n);
    String& insert(size_t pos1, const char *s);
    String& insert(size_t pos1, size_t n, char c);

    size_t length() const;
    size_t max_size() const;
    void push_back(char c);

    String& replace(size_t pos1, size_t n1, const String& str);
    String& replace(size_t pos1, size_t n1, const String& str, size_t pos2, size_t n2);
    String& replace(size_t pos1, size_t n1, const char *s, size_t n2);
    String& replace(size_t pos1, size_t n1, const char *s);
    String& replace(size_t pos1, size_t n1, size_t n2, char c);

    void reserve(size_t res_arg = 0);
    void resize(size_t n, char c);
    void resize(size_t n);

    size_t rfind(const String& str, size_t pos = npos) const;
    size_t rfind(const char *s, size_t pos, size_t n) const;
    size_t rfind(const char *s, size_t pos = npos) const;
    size_t rfind(char c, size_t pos = npos) const;

    size_t size() const;
    String substr(size_t pos = 0, size_t = npos) const;
    void swap(String& str);

    String& operator+= (char c);
    String& operator+= (const char *s);
    String& operator+= (const String& str);
    String& operator= (char c);
    String& operator= (const char *s);
    String& operator= (const String& that);
    char& operator[](size_t pos);
    const char& operator[](size_t pos) const;
    /*
    friend String operator+ (const String& lhs, const String& rhs);
    friend String operator+ (const char* lhs, const String& rhs);
    friend String operator+ (char lhs, const String& rhs);
    friend String operator+ (const String& lhs, const char* rhs);
    friend String operator+ (const String& lhs, char rhs);

    friend bool operator== (const String& lhs, const String& rhs);
    friend bool operator== (const char *lhs, const String& rhs);
    friend bool operator== (const String& lhs, const char *rhs);

    friend bool operator!= (const String& lhs, const String& rhs);
    friend bool operator!= (const char *lhs, const String& rhs);
    friend bool operator!= (const String& lhs, const char *rhs);

    friend bool operator< (const String& lhs, const String& rhs);
    friend bool operator< (const char *lhs, const String& rhs);
    friend bool operator< (const String& lhs, const char *rhs);

    friend bool operator> (const String& lhs, const String& rhs);
    friend bool operator> (const char *lhs, const String& rhs);
    friend bool operator> (const String& lhs, const char *rhs);

    friend bool operator<= (const String& lhs, const String& rhs);
    friend bool operator<= (const char *lhs, const String& rhs);
    friend bool operator<= (const String& lhs, const char *rhs);

    friend bool operator>= (const String& lhs, const String& rhs);
    friend bool operator>= (const char *lhs, const String& rhs);
    friend bool operator>= (const String& lhs, const char *rhs);

    friend istream& operator>> (istream& is, String& s);
    friend ostream& operator<< (ostream& os, const String& s);
    */
private:
    void expand(size_t size);
public:
    static const size_t npos;
private:
    size_t m_size;
    size_t m_capacity;
    char *m_data;
    static const size_t m_maxsize;
};

const size_t String::npos = -1;
const size_t String::m_maxsize = static_cast<size_t>(-1) / sizeof(char) / 2;

String::String():
    m_size(0),
    m_capacity(0),
    m_data(NULL) {}

String::String(const char *s):
    m_size(strlen(s)),
    m_capacity(m_size * 2),
    m_data(strcpy(new char[m_capacity], s)) {}

String::String(const char *s, size_t n):
    m_size(n),
    m_capacity(m_size * 2),
    m_data(new char[m_capacity])
{
    memcpy(m_data, s, m_size);
}

String::String(size_t n, char c):
    m_size(n),
    m_capacity(m_size * 2),
    m_data(new char[m_capacity])
{
    memset(m_data, c, n);
}

String::String(const String& str):
    m_size(str.m_size),
    m_capacity(str.m_capacity),
    m_data(new char[m_capacity])
{
    memcpy(m_data, str.m_data, m_size);
}

String::String(const String& str, size_t pos, size_t n)
{
    if (pos > str.m_size)
    {
        throw out_of_range("String::String(const String& str, size_t pos, size_t n)");
    }

    if (n > str.m_size)
    {
        n = str.m_size;
    }

    if (pos + n < str.m_size)
    {
        m_size = n;
    }
    else
    {
        m_size = str.m_size - pos;
    }

    m_capacity = m_size * 2;
    m_data = new char[m_capacity];
    for (size_t i = 0; i < m_size; ++i)
    {
        m_data[i] = str.m_data[pos++];
    }
}

String::~String()
{
    if (m_data != NULL)
    {
        delete[] m_data;
        m_data = NULL;
    }
}

String& String::append(const String& str)
{
    return this->append(str.m_data, str.m_size);
}

String& String::append(const String& str, size_t pos, size_t n)
{
    if (pos > str.m_size)
    {
        throw out_of_range("String::append(const String& str, size_t pos, size_t n)");
    }
    return this->append(str.substr(pos, n));
}

String& String::append(const char *s, size_t n)
{
    size_t pos = m_size;
    size_t size = m_size + n;

    if (size >= m_capacity)
    {
        expand(size);
    }

    m_size = size;
    for (size_t i = 0; i < n; ++i)
    {
        m_data[pos++] = s[i];
    }
    return *this;
}

String& String::append(const char *s)
{
    return this->append(s, strlen(s));
}

String& String::append(size_t n, char c)
{
    size_t pos = m_size;
    size_t size = m_size + n;

    if (size >= m_capacity)
    {
        expand(size);
    }

    m_size = size;
    for (size_t i = 0; i < n; ++i)
    {
        m_data[pos++] = c;
    }
    return *this;
}

String& String::assign(const String& that)
{
    if (&that != this)
    {
        char *data = new char[that.m_capacity];
        delete[] m_data;
        m_data = data;
        m_size = that.m_size;
        m_capacity = that.m_capacity;
        memcpy(m_data, that.m_data, m_size);
    }
    return *this;
}

String& String::assign(const String& str, size_t pos, size_t n)
{
    if (pos > str.m_size)
    {
        throw out_of_range("String::assign(const String& str, size_t pos, size_t n)");
    }
    return this->assign(str.substr(pos, n));
}

String& String::assign(const char *s, size_t n)
{
    char *data = new char[n * 2];
    delete[] m_data;
    m_data = data;
    m_size = n;
    m_capacity = m_size * 2;
    memcpy(m_data, s, m_size);
    return *this;
}

String& String::assign(const char *s)
{
    return this->assign(s, strlen(s));
}

String& String::assign(size_t n, char c)
{
    char *data = new char[n * 2];
    delete[] m_data;
    m_data = data;
    m_size = n;
    m_capacity = m_size * 2;
    memset(m_data, c, n);
    return *this;
}

char& String::at(size_t pos)
{
    if (pos > m_size)
    {
        throw out_of_range("String::at");
    }
    return m_data[pos];
}

const char& String::at(size_t pos) const
{
    if (pos > m_size)
    {
        throw out_of_range("String::at");
    }
    return m_data[pos];
}

size_t String::capacity() const
{
    return m_capacity;
}

void String::clear()
{
    m_size = 0;
}

int String::compare(const String& str) const
{
    if (&str == this)
    {
        return 0;
    }

    size_t i = 0;
    while (i < m_size && i < str.m_size)
    {
        if (m_data[i] > str.m_data[i])
        {
            return 1;
        }
        else if (m_data[i] < str.m_data[i])
        {
            return -1;
        }
        ++i;
    }

    if (m_size != str.m_size)
    {
        return i == m_size ? -1 : 1;
    }
    return 0;
}

int String::compare(const char *s) const
{
    size_t i = 0;
    size_t length = strlen(s);
    while (i < m_size && i < length)
    {
        if (m_data[i] > s[i])
        {
            return 1;
        }
        else if (m_data[i] < s[i])
        {
            return -1;
        }
        ++i;
    }

    if (m_size != length)
    {
        return i == m_size ? -1 : 1;
    }
    return 0;
}

int String::compare(size_t pos1, size_t n1, const String& str) const
{
    if (pos1 > m_size)
    {
        throw out_of_range("String::compare(size_t pos1, size_t n1, const String& str)");
    }

    String tmp(*this, pos1, n1);
    return tmp.compare(str);
}

int String::compare(size_t pos1, size_t n1, const char *s) const
{
    if (pos1 > m_size)
    {
        throw out_of_range("String::compare(size_t pos1, size_t n1, const char *s)");
    }

    String tmp(*this, pos1, n1);
    return tmp.compare(s);
}

int String::compare(size_t pos1, size_t n1, const String& str, size_t pos2, size_t n2) const
{
    if (pos1 > m_size || pos2 > str.m_size)
    {
        throw out_of_range("String::compare(size_t pos1, size_t n1, const String& str, size_t pos2, size_t n2)");
    }

    String tmp(*this, pos1, n1);
    return tmp.compare(str.substr(pos2, n2));
}

int String::compare(size_t pos1, size_t n1, const char *s, size_t n2) const
{
    if (pos1 > m_size)
    {
        throw out_of_range("String::compare(size_t pos1, size_t n1, const char *s, size_t n2)");
    }

    String tmp(s, n2);
    return this->substr(pos1, n1).compare(tmp);
}

size_t String::copy(char *s, size_t n, size_t pos) const
{
    if (pos > m_size)
    {
        throw out_of_range("String::copy");
    }

    size_t length;
    if (pos + n < m_size)
    {
        length = n;
    }
    else
    {
        length = m_size - pos;
    }

    for (size_t i = 0; i < length; ++i)
    {
        s[i] = m_data[pos++];
    }
    return length;
}

const char *String::c_str() const
{
    m_data[m_size] = '\0';
    return m_data;
}

const char *String::data() const
{
    return m_data;
}

bool String::empty() const
{
    return m_size == 0;
}

String& String::erase(size_t pos, size_t n)
{
    if (pos > m_size)
    {
        throw out_of_range("String::erase");
    }

    if (n > m_size)
    {
        n = m_size;
    }

    if (pos + n < m_size)
    {
        for (size_t i = pos + n; i < m_size; ++i)
        {
            m_data[i - n] = m_data[i];
        }
        m_size -= n;
    }
    else
    {
        m_size = pos;
    }
    return *this;
}

void String::expand(size_t size)
{
    if (size * 2 > m_maxsize)
    {
        throw length_error("String::expand");
    }

    m_capacity = size * 2;
    char *data = new char[m_capacity];
    memcpy(data, m_data, m_size);
    delete[] m_data;
    m_data = data;
}

size_t String::find(const String& str, size_t pos) const
{
    return this->find(str.m_data, pos, str.m_size);
}

size_t String::find(const char *s, size_t pos, size_t n) const
{
    if (pos < m_size)
    {
        for (size_t i = pos; i + n <= m_size; ++i)
        {
            if (memcmp(m_data + i, s, n) == 0)
            {
                return i;
            }
        }
    }
    return npos;
}

size_t String::find(const char *s, size_t pos) const
{
    return this->find(s, pos, strlen(s));
}

size_t String::find(char c, size_t pos) const
{
    if (pos < m_size)
    {
        for (size_t i = pos; i < m_size; ++i)
        {
            if (m_data[i] == c)
            {
                return i;
            }
        }
    }
    return npos;
}

size_t String::find_first_not_of(const String& str, size_t pos) const
{
    return this->find_first_not_of(str.m_data, pos, str.m_size);
}

size_t String::find_first_not_of(const char *s, size_t pos, size_t n) const
{
    if (pos < m_size)
    {
        bool flag;
        for (size_t i = pos; i < m_size; ++i)
        {
            flag = true;
            for (size_t j = 0; j < n; ++j)
            {
                if (m_data[i] == s[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return i;
            }
        }
    }
    return npos;
}

size_t String::find_first_not_of(const char *s, size_t pos) const
{
    return this->find_first_not_of(s, pos, strlen(s));
}

size_t String::find_first_not_of(char c, size_t pos) const
{
    if (pos < m_size)
    {
        for (size_t i = pos; i < m_size; ++i)
        {
            if (m_data[i] != c)
            {
                return i;
            }
        }
    }
    return npos;
}

size_t String::find_first_of(const String& str, size_t pos) const
{
    return this->find_first_of(str.m_data, pos, str.m_size);
}

size_t String::find_first_of(const char *s, size_t pos, size_t n) const
{
    if (pos < m_size)
    {
        for (size_t i = pos; i < m_size; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                if (m_data[i] == s[j])
                {
                    return i;
                }
            }
        }
    }
    return npos;
}

size_t String::find_first_of(const char *s, size_t pos) const
{
    return this->find_first_of(s, pos, strlen(s));
}

size_t String::find_first_of(char c, size_t pos) const
{
    return this->find(c, pos);
}

size_t String::find_last_not_of(const String& str, size_t pos) const
{
    return this->find_last_not_of(str.m_data, pos, str.m_size);
}

size_t String::find_last_not_of(const char *s, size_t pos, size_t n) const
{
    if (m_size > 0)
    {
        if (pos >= m_size)
        {
            pos = m_size - 1;
        }

        bool flag;
        for (size_t i = pos + 1; i > 0; --i)
        {
            flag = true;
            for (size_t j = 0; j < n; ++j)
            {
                if (m_data[i - 1] == s[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return i - 1;
            }
        }
    }
    return npos;
}

size_t String::find_last_not_of(const char *s, size_t pos) const
{
    return this->find_last_not_of(s, pos, strlen(s));
}

size_t String::find_last_not_of(char c, size_t pos) const
{
    if (m_size > 0)
    {
        if (pos >= m_size)
        {
            pos = m_size - 1;
        }

        for (size_t i = pos + 1; i > 0; --i)
        {
            if (m_data[i - 1] != c)
            {
                return i - 1;
            }
        }
    }
    return npos;
}

size_t String::find_last_of(const String& str, size_t pos) const
{
    return this->find_last_of(str.m_data, pos, str.m_size);
}

size_t String::find_last_of(const char *s, size_t pos, size_t n) const
{
    if (m_size > 0)
    {
        if (pos >= m_size)
        {
            pos = m_size - 1;
        }

        for (size_t i = pos + 1; i > 0; --i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                if (m_data[i - 1] == s[j])
                {
                    return i - 1;
                }
            }
        }
    }
    return npos;
}

size_t String::find_last_of(const char *s, size_t pos) const
{
    return this->find_last_of(s, pos, strlen(s));
}

size_t String::find_last_of(char c, size_t pos) const
{
    return this->rfind(c, pos);
}

String& String::insert(size_t pos1, const String& str)
{
    if (pos1 > m_size)
    {
        throw out_of_range("String::insert(size_t pos1, const String& str)");
    }

    if (&str == this)
    {
        return this->insert(pos1, String(*this));
    }
    return this->insert(pos1, str.m_data, str.m_size);
}

String& String::insert(size_t pos1, const String& str, size_t pos2, size_t n)
{
    if (pos1 > m_size || pos2 > str.m_size)
    {
        throw out_of_range("String::insert(size_t pos1, const String& str, size_t pos2, size_t n)");
    }
    return this->insert(pos1, str.substr(pos2, n));
}

String& String::insert(size_t pos1, const char *s, size_t n)
{
    if (pos1 > m_size)
    {
        throw out_of_range("String::insert(size_t pos1, const char *s, size_t n)");
    }

    size_t size = m_size + n;
    if (size >= m_capacity)
    {
        expand(size);
    }

    size_t mlen = m_size - pos1;
    size_t pos2 = size - 1;
    for (size_t i = mlen; i > 0; --i)
    {
        m_data[pos2--] = m_data[pos1 + i - 1];
    }
    for (size_t i = 0; i < n; ++i)
    {
        m_data[pos1++] = s[i];
    }
    m_size = size;
    return *this;
}

String& String::insert(size_t pos1, const char *s)
{
    if (pos1 > m_size)
    {
        throw out_of_range("String::insert(size_t pos1, const char *s)");
    }
    return this->insert(pos1, s, strlen(s));
}

String& String::insert(size_t pos1, size_t n, char c)
{
    if (pos1 > m_size)
    {
        throw out_of_range("String::insert(size_t pos1, size_t n, char c)");
    }

    size_t size = m_size + n;
    if (size >= m_capacity)
    {
        expand(size);
    }

    size_t mlen = m_size - pos1;
    size_t pos2 = size - 1;
    for (size_t i = mlen; i > 0; --i)
    {
        m_data[pos2--] = m_data[pos1 + i - 1];
    }
    for (size_t i = 0; i < n; ++i)
    {
        m_data[pos1++] = c;
    }
    m_size = size;
    return *this;
}

size_t String::length() const
{
    return m_size;
}

size_t String::max_size() const
{
    return m_maxsize;
}

void String::push_back(char c)
{
    this->append(1, c);
}

String& String::replace(size_t pos1, size_t n1, const String& str)
{
    if (pos1 > m_size)
    {
        throw out_of_range("String::replace(size_t pos1, size_t n1, const String& str)");
    }
    if (&str == this)
    {
        return this->erase(pos1, n1).insert(pos1, String(*this));
    }
    return this->erase(pos1, n1).insert(pos1, str);
}

String& String::replace(size_t pos1, size_t n1, const String& str, size_t pos2, size_t n2)
{
    if (pos1 > m_size || pos2 > str.m_size)
    {
        throw out_of_range("String::replace(size_t pos1, size_t n1, const String& str, size_t pos2, size_t n2)");
    }
    return this->erase(pos1, n1).insert(pos1, str, pos2, n2);
}

String& String::replace(size_t pos1, size_t n1, const char *s, size_t n2)
{
    if (pos1 > m_size)
    {
        throw out_of_range("String::replace(size_t pos1, size_t n1, const char *s, size_t n2)");
    }
    return this->erase(pos1, n1).insert(pos1, s, n2);
}

String& String::replace(size_t pos1, size_t n1, const char *s)
{
    if (pos1 > m_size)
    {
        throw out_of_range("String::replace(size_t pos1, size_t n1, const char *s)");
    }
    return this->erase(pos1, n1).insert(pos1, s);
}

String& String::replace(size_t pos1, size_t n1, size_t n2, char c)
{
    if (pos1 > m_size)
    {
        throw out_of_range("String::replace(size_t pos1, size_t n1, size_t n2, char c)");
    }
    return this->erase(pos1, n1).insert(pos1, n2, c);
}

void String::reserve(size_t res_arg)
{
    if (res_arg < m_size || res_arg == m_capacity)
    {
        return;
    }

    if (res_arg > m_maxsize)
    {
        throw length_error("String::reserve");
    }

    char *data = new char[res_arg];
    memcpy(data, m_data, m_size);
    delete[] m_data;
    m_data = data;
    m_capacity = res_arg;
}

void String::resize(size_t n, char c)
{
    if (n == m_size)
    {
        return;
    }

    if (n < m_size)
    {
        m_size = n;
    }
    else
    {
        if (n >= m_capacity)
        {
            if (n > m_maxsize)
            {
                throw length_error("String::resize(size_t n, char c)");
            }
            expand(n);
        }

        for (size_t i = m_size; i < n; ++i)
        {
            m_data[i] = c;
        }
        m_size = n;
    }
}

void String::resize(size_t n)
{
    if (n > m_maxsize)
    {
        throw length_error("String::resize(size_t n)");
    }
    resize(n, char());
}

size_t String::rfind(const String& str, size_t pos) const
{
    return this->rfind(str.m_data, pos, str.m_size);
}

size_t String::rfind(const char *s, size_t pos, size_t n) const
{
    if (m_size > 0)
    {
        if (pos >= m_size)
        {
            pos = m_size - 1;
        }

        if (n <= m_size)
        {
            while (pos + n > m_size)
            {
                --pos;
            }
            for (size_t i = pos + 1; i > 0; --i)
            {
                if (memcmp(m_data + (i - 1), s, n) == 0)
                {
                    return i - 1;
                }
            }
        }
    }
    return npos;
}

size_t String::rfind(const char *s, size_t pos) const
{
    return this->rfind(s, pos, strlen(s));
}

size_t String::rfind(char c, size_t pos) const
{
    if (m_size > 0)
    {
        if (pos >= m_size)
        {
            pos = m_size - 1;
        }

        for (size_t i = pos + 1; i > 0; --i)
        {
            if (m_data[i - 1] == c)
            {
                return i - 1;
            }
        }
    }
    return npos;
}

size_t String::size() const
{
    return m_size;
}

String String::substr(size_t pos, size_t n) const
{
    if (pos > m_size)
    {
        throw out_of_range("String::substr");
    }
    return String(*this, pos, n);
}

void String::swap(String& str)
{
    String tmp(str);
    str = *this;
    *this = tmp;
}

String& String::operator+= (char c)
{
    return this->append(1, c);
}

String& String::operator+= (const char *s)
{
    return this->append(s);
}

String& String::operator+= (const String& str)
{
    return this->append(str);
}

String& String::operator= (char c)
{
    return this->assign(1, c);
}

String& String::operator= (const char *s)
{
    return this->assign(s);
}

String& String::operator= (const String& that)
{
    return this->assign(that);
}

char& String::operator[](size_t pos)
{
    return m_data[pos];
}

const char& String::operator[](size_t pos) const
{
    return m_data[pos];
}

String operator+ (const String& lhs, const String& rhs)
{
    return String(lhs).append(rhs);
}

String operator+ (const char *lhs, const String& rhs)
{
    return String(lhs).append(rhs);
}

String operator+ (char lhs, const String& rhs)
{
    return String(1, lhs).append(rhs);
}

String operator+ (const String& lhs, const char *rhs)
{
    return String(lhs).append(rhs);
}

String operator+ (const String& lhs, char rhs)
{
    return String(lhs).append(1, rhs);
}

bool operator== (const String& lhs, const String& rhs)
{
    return lhs.compare(rhs) == 0;
}

bool operator== (const char *lhs, const String& rhs)
{
    return rhs.compare(lhs) == 0;
}

bool operator== (const String& lhs, const char *rhs)
{
    return lhs.compare(rhs) == 0;
}

bool operator!= (const String& lhs, const String& rhs)
{
    return lhs.compare(rhs) != 0;
}

bool operator!= (const char *lhs, const String& rhs)
{
    return rhs.compare(lhs) != 0;
}

bool operator!= (const String& lhs, const char *rhs)
{
    return lhs.compare(rhs) != 0;
}

bool operator< (const String& lhs, const String& rhs)
{
    return lhs.compare(rhs) < 0;
}

bool operator< (const char *lhs, const String& rhs)
{
    return rhs.compare(lhs) > 0;
}

bool operator< (const String& lhs, const char *rhs)
{
    return lhs.compare(rhs) < 0;
}

bool operator> (const String& lhs, const String& rhs)
{
    return lhs.compare(rhs) > 0;
}

bool operator> (const char *lhs, const String& rhs)
{
    return rhs.compare(lhs) < 0;
}

bool operator> (const String& lhs, const char *rhs)
{
    return lhs.compare(rhs) > 0;
}

bool operator<= (const String& lhs, const String& rhs)
{
    return !(lhs > rhs);
}

bool operator<= (const char *lhs, const String& rhs)
{
    return !(lhs > rhs);
}

bool operator<= (const String& lhs, const char *rhs)
{
    return !(lhs > rhs);
}

bool operator>= (const String& lhs, const String& rhs)
{
    return !(lhs < rhs);
}

bool operator>= (const char *lhs, const String& rhs)
{
    return !(lhs < rhs);
}

bool operator>= (const String& lhs, const char *rhs)
{
    return !(lhs < rhs);
}

istream& operator>> (istream& is, String& s)
{
    char tmp[1024];
    is >> tmp;
    s = tmp;
    return is;
}

ostream& operator<< (ostream& os, const String& s)
{
    for (size_t i = 0; i < s.size(); ++i)
    {
        os << s[i];
    }
    return os;
}

int main()
{
    String s;

    s.assign("Hello ");
    s.append("World");
    cout << s.size() << endl;
    cout << s.capacity() << endl;
    cout << s << endl;
    return 0;
}
