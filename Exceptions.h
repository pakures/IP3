#pragma once

#include <exception>

class NotImplementedException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Method is not implemented";
    }
};

class StrategyNotSetException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Strategy is not set";
    }
};
