#include <iostream>
class bad_length{
public:
    std::string str = "Вы ввели слово запретной длины! До свидания";
};


int function(std::string str, int forbidden_length){
    if (forbidden_length == str.length() ) {
        throw bad_length();
    }
    return str.length();
}

int main(){
    bool isLengthRight = true;
    while (isLengthRight == true) {
        int len = 0;
        std::string word;
        std::cout <<"Введите запретную длину: ";
        std::cin >> len;
        std::cout <<"Введите слово: ";
        std::cin >> word;
        try {
            int length = function(word, len);
            std::cout << "Длина слова \"" << word << "\" равна " << length/2 << std::endl;
        } catch (bad_length) {
            bad_length b;
            std::cout << b.str << std::endl;
            break;
        }
    }
    return 0;
}