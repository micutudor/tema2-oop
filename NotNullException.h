#ifndef NOTNULLEXCEPTION_H_INCLUDED
#define NOTNULLEXCEPTION_H_INCLUDED

#include<exception>

class NotNullException : public std::exception
{
public:
    NotNullException() = default;

    const char* what() const noexcept override  {
        return "Value must be not null!";
    }
};

#endif // NOTNULLEXCEPTION_H_INCLUDED
