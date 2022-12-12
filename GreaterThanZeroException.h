#ifndef GREATERTHANZEROEXCEPTION_H_INCLUDED
#define GREATERTHANZEROEXCEPTION_H_INCLUDED

#include<exception>

class GreaterThanZeroException : public std::exception
{
public:
    GreaterThanZeroException() = default;

    const char* what() const noexcept override  {
        return "Value must be greater than zero!";
    }
};

#endif // GREATERTHANZEROEXCEPTION_H_INCLUDED
