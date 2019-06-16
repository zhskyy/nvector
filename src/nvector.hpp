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

    nvector& operator=(const nvector& op) const // checking the branch
    {
        if(this == &op) return *this;

        if(op.size <= __size)
        {
            for(int index = 0; index < op.__size; index++ )
            {
                __data[index] = op.__data[index];
            }
            return *this;
        }

        else
        {
            Type* p = new Type[op.__size];

            for(int index = 0; index < op.__size; index++)
            {
                p.__data[index] = op.__data[index];
            }

            delete[] __data;
            __size = p.__size;
            __data = *p.__data;
        }
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
            return &(__data[i]);
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
        Type* p = new Type[__size + 4];
        for(int index = 0; index < p.__size; index++)
        {
            p.__data[index] = __data[index];
        }
        p.[__size + 1] = element;
        delete [] __data;
        __data = p.__data;
        __size = p.size;
    }

private:
    Type* __data;
    int __size;
};
