#include <fstream>
#include <utility>
#include <iostream>


class Formatter{
public:
    virtual ~Formatter() = default;// для таблицы виртуальных деструкторов
    [[nodiscard]] virtual std::string format(const std::string& data) const = 0;
};

class JSONFormatter : public Formatter {
public:
    [[nodiscard]] std::string format(const std::string& data) const override {
        return R"({ "data": ")" + data + "\"}";
    }
};

class HTMLFormatter : public Formatter {
public:
    [[nodiscard]] std::string format(const std::string& data) const override {
        return "<html>" + data + "<html/>";
    }
};

class TextFormatter : public Formatter {
public:
    [[nodiscard]] std::string format(const std::string& data) const override {
        return data;
    }
};

class DataGetter{
public:
    DataGetter(const Formatter& format, std::string  data):format(format), data(std::move(data)){};
    [[nodiscard]] std::string getData() const {
        return format.format(data);
    }
protected:
    const Formatter& format;
    std::string data;
};



class DataSaver {
public:
    virtual ~DataSaver() = default; // для таблицы виртуальных деструкторов
    void saveTo(std::ofstream& file, const DataGetter& dataGetter) {
        file << dataGetter.getData();
    }
};

class AllFormatsDataSaver {
public:
    AllFormatsDataSaver(std::ofstream& file, const std::string& data) {
        HTMLFormatter htmlFormatter;
        JSONFormatter jsonFormatter;
        TextFormatter textFormatter;

        DataGetter htmlData(htmlFormatter, data);
        DataSaver saver;
        saver.saveTo(file, htmlData);

        DataGetter jsonData(jsonFormatter, data);
        saver.saveTo(file, jsonData);

        DataGetter textData(textFormatter, data);
        saver.saveTo(file, textData);
    }
};

int main() {
    std::ofstream file("output.txt");

    if (file.is_open()) {
        std::string data = "example data";
        AllFormatsDataSaver allSaver(file, data);
        std::cout << "Data saved successfully!" << std::endl;
    } else {
        std::cerr << "Failed to open file." << std::endl;
    }

    return 0;
}


