#include <iostream>
#include <fstream>
#include "vector"
#include <memory>

class Observer {
public:
    virtual  ~Observer()  = default;

    virtual void onWarning(const std::string& message) {};
    virtual void onError(const std::string& message) {};
    virtual void onFatalError(const std::string& message) {};
};

class Subject{
public:
    ~Subject() {
        observers.clear();
    }
    void addObserver(std::shared_ptr<Observer> obs) {
        observers.push_back(obs);
    }

     void warning(const std::string& message) {
        for(auto& obs: observers){
            obs->onWarning(message);
        }
    };
     void error(const std::string& message) {
         for(auto& obs: observers){
             obs->onError(message);
         }    };
     void fatalError(const std::string& message) {
         for(auto& obs: observers){
             obs->onFatalError(message);
         }
     };
private:
    std::vector<std::shared_ptr<Observer>> observers;
};





class WarningObserver: public Observer{
public:
    void onWarning(const std::string& message) override {
        std::cout << "Warning " << message << std::endl;
    }
};

class ErrorObserver: public Observer{
public:
    explicit ErrorObserver(const std::string& path): path(path){};
    void onWarning(const std::string& message) override {
        std::ofstream file(path, std::ios_base::app);
        if (file.is_open()) {
            file << "Error" << message << std::endl;
        } else {
            std::cerr << "Ошибка открытия файла: " << path << std::endl;
        }
    }
protected:
    std::string path{};
};

class FatalErrorObserver: public Observer{
public:
    explicit FatalErrorObserver(const std::string& path): path(path){};
    void onFatalError(const std::string& message) override {
        std::cout << "Fatal Error " << message << std::endl;
        std::ofstream file(path, std::ios_base::app);
        if (file.is_open()) {
            file << "Fatal Error " << message << std::endl;
        } else {
            std::cerr << "Ошибка открытия файла: " << path << std::endl;
        }
    }
protected:
    std::string path{};
};



int main() {
    Subject subject;

    // Create observers
    auto warningObserver = std::make_shared<WarningObserver>();
    auto errorObserver = std::make_shared<ErrorObserver>("errors.log");
    auto fatalErrorObserver = std::make_shared<FatalErrorObserver>("fatal_errors.log");

    // Add observers to the subject
    subject.addObserver(warningObserver);
    subject.addObserver(errorObserver);
    subject.addObserver(fatalErrorObserver);

    // Generate events
    subject.warning("This is a warning message.");
    subject.error("This is an error message.");
    subject.fatalError("This is a fatal error message.");
}
