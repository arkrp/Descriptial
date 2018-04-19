#ifndef CONSTANT
#define CONSTANT
#include "..\..\nomial.hpp"
#include <string>
template<class T>
class constant : public nomial<T>
{
public:
    T value;
    constant(T param)
    {
        value=param;
    }
    virtual T eval(T)
    {
        return(value);
    }
    virtual constant * clone() const
    {
        return(new constant(value));
    }
    virtual string tostring() const
    {
        return(to_string(value));
    }
};
#endif
