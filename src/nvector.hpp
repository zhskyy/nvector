#include <cassert>
#include <string>
#include <stdexcept>

template <class Type>
class nvector {
    //replace all assert(0); for implementations
public:
    nvector()
    {
        __data = nullptr;
        __size = 0;
    }

    nvector(int size)
    {
        __data = new Type[size];
        __size = size;
    }

    virtual ~nvector()
    {
        delete[] __data;
    }

    nvector(const nvector& op)
    {
        if (op.__size)
        {
            __data = new Type[op.__size];
            __size = op.__size;
            memcpy(op.__data, op.__data, __size*sizeof(Type));
        }
        else
        {
            __data = nullptr;
            __size = 0;
        }
    }

    nvector(nvector&& op)
    {
        assert(0);
    }

    nvector& operator=(const nvector& op) const
    {
        assert(0);
    }

    Type operator[](const long i) const
    {
        if(i <= __size)
        {
            return __data[i];
        }
        else
        {
            return 0;
        }
    }

    Type& operator[](const long i)
    {
        if(i < __size )
        {
            return &(__data+i);
        }
        else
        {
            return nullptr;
        }
    }

    Type at(const long i) const
    {
        throw std::range_error("out of range at function at");
    }

    void push_back(const Type& element)
    {
        assert(0);
    }

private:
    Type* __data;
    int __size;
};
