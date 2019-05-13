#include <cassert>
#include <string>
#include <stdexcept>

template <class Type>
class nvector {
    //replace all assert(0); for implementations
public:
    nvector()
    {
        assert(0);//replace all assert(0); for implementations
    }

    virtual ~nvector()
    {
        assert(0);
    }

    nvector(const nvector& op)
    {
        assert(0);
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
        assert(0);
    }

    Type& operator[](const long i)
    {
        assert(0);
    }

    Type at(const long i) const
    {
        throw std::range_error("out of range at function at");
    }

private:
    Type* __data;
};
