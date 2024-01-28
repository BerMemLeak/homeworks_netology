#pragma once
#include <exception>
#include <iostream>
class error: public std::exception{
public:
	error(const std::string& errorMessage) noexcept: errorMessage(errorMessage) {}; 
	const char* what() const noexcept override {
		return errorMessage.c_str();
	}
private:
	std::string errorMessage;
};