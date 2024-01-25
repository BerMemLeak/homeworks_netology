#include "MyError.h"

MyError::MyError(const std::string& errorMessage) noexcept : errorMessage(errorMessage) {}

const char* MyError::what() const noexcept {
return errorMessage.c_str();
}
