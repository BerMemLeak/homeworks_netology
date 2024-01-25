#ifndef MYERROR_H
#define MYERROR_H

#include <stdexcept>
#include <string>

class MyError : public std::exception {
public:
    MyError(const std::string& errorMessage) noexcept;  // Объявление конструктора с использованием noexcept
    const char* what() const noexcept override;

private:
    std::string errorMessage;
};

#endif // MYERROR_H
