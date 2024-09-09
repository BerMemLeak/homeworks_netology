#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

enum Type {
    fatal_error = 0,
    simpleError,
    warning,
    unknown_message
};

class LogMessage {
public:
    virtual ~LogMessage() = default;
    virtual void setNext(std::shared_ptr<LogMessage> nextHandler) = 0;
    virtual void message(const std::string& request, Type type) = 0;
protected:
    explicit LogMessage(Type type) : type(type) {}
    Type type;
};

class Error : public LogMessage {
protected:
    std::shared_ptr<LogMessage> next;

public:
    explicit Error(Type type) : LogMessage(type) {}

    void setNext(std::shared_ptr<LogMessage> nextHandler) override {
        next = std::move(nextHandler);
    }

    void message(const std::string& request, Type type) override {
        if (next) {
            next->message(request, type);
        } else {
            std::cout << "Запрос не обработан." << std::endl;
        }
    }
};

class FatalError : public Error {
public:
    FatalError() : Error(fatal_error) {}

    void message(const std::string& request, Type type) override {
        if (type == fatal_error) {
            throw ("Fatal Error: "+ request);
        } else {
            Error::message(request, type);
        }
    }
};


class SimpleError: public Error{
public:
    explicit SimpleError(std::string path) : path(path), Error(simpleError) {}
    void message(const std::string& request, Type type) override {
        if (type == simpleError) {
            std::ofstream file(path, std::ios_base::app);
            if (file.is_open()) {
                file << request << std::endl;
            } else {
                std::cerr << "Ошибка открытия файла: " << path << std::endl;
            }
        } else {
            Error::message(request, type);
        }
    }
protected:
    std::string path;
};

class Warning: public Error{
public:
    Warning() : Error(warning) {}

    void message(const std::string& request, Type type) override {
        if (type == warning) {
            std::cout << "Warning "<< request << std::endl;
        } else {
            Error::message(request, type);
        }
    }
};

class Unknown_message: public Error{
public:

public:
    Unknown_message() : Error(unknown_message) {}

    void message(const std::string& request, Type type) override {
        if (type == unknown_message) {
            throw ("Unknown message: "+ request);
        } else {
            Error::message(request, type);
        }
    }};


int main() {
    try {
        // Создаем обработчики
        auto fatalError_checker = std::make_shared<FatalError>();
        auto simpleError_checker = std::make_shared<SimpleError>("123.txt");
        auto warning_checker = std::make_shared<Warning>();
        auto unknown_message_checker = std::make_shared<Unknown_message>();


        // Формируем цепочку
        fatalError_checker->setNext(simpleError_checker);
        simpleError_checker->setNext(warning_checker);
        warning_checker->setNext(unknown_message_checker);

        // Клиент отправляет запрос
        std::string request = "Проверить правописание и логику";

        fatalError_checker->message(request,fatal_error);

        return 0;
    }catch (std::string & e){
        //кастыыыль, не знаю, какую ошибку выкидывать, поэтому просто строку викидываю
        std::cout << e;
    }
}
