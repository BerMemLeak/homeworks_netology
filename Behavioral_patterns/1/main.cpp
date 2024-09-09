#include <iostream>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class LogConsole: public LogCommand{
public:
    void print(const std::string& message)override{
        std::cout << message << std::endl;
    }
};

class LogFile: public LogCommand{
public:
    LogFile(const std::string& path):path(path){}
    void print(const std::string& message)override{
        std::ofstream file(path, std::ios_base::app);  
        if (file.is_open()) {
            file << message << std::endl;
        } else {
            std::cerr << "Ошибка открытия файла: " << path << std::endl;
        }
    }
protected:
    std::string path{};
};

void print(LogCommand& command, std::string message){
    command.print(message);
};

int main() {
    LogConsole consoleCommand;
    LogFile fileCommand("/Users/user/Desktop/programming/c++/homeworks_netology/Behavioral_patterns/1/log321.txt");

    print(consoleCommand, "Сообщение для консоли");
    print(fileCommand, "Сообщение для файла");
    return EXIT_SUCCESS;
}
