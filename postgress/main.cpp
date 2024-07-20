#include <iostream>
#include <string>
#include <vector>
#include <pqxx/pqxx>

//
//Метод, создающий структуру БД (таблицы).
//Метод, позволяющий добавить нового клиента.
//Метод, позволяющий добавить телефон для существующего клиента.
//Метод, позволяющий изменить данные о клиенте.

//Метод, позволяющий удалить телефон у существующего клиента.
//Метод, позволяющий удалить существующего клиента.
//Метод, позволяющий найти клиента по его данным — имени, фамилии, email или телефону.

class clientsData {
private:
    pqxx::connection c;

public:
    explicit clientsData()
            : c("host=localhost port=5432 dbname=my_database user=my_database password=my_password_123") {
        try {
            pqxx::work tx{ c };
            tx.exec("CREATE TABLE IF NOT EXISTS client ("
                    "client_id SERIAL PRIMARY KEY, "
                    "client_name VARCHAR(40) NOT NULL, "
                    "client_surname VARCHAR(40) NOT NULL, "
                    "client_email VARCHAR(40) NOT NULL UNIQUE"
                    ");");
            tx.exec("CREATE TABLE IF NOT EXISTS numbers ("
                    "phone_id SERIAL PRIMARY KEY, "
                    "client_id INT REFERENCES client (client_id), "
                    "client_numbers VARCHAR(40) NOT NULL UNIQUE"
                    ");");

            tx.commit();

        } catch (const pqxx::sql_error& e) {
            std::cerr << "SQL error: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    void add_client(const std::string& name, const std::string& surname, const std::string& email, const std::string& numbers) {
        try {
            pqxx::work tx{ c };

            // Преобразуем вектор строк в формат массива PostgreSQL
            std::string numbers_str = numbers;

            std::string insertClient = "INSERT INTO client (client_name, client_surname, client_email) VALUES ($1, $2, $3)";
            std::string insertNumber = "INSERT INTO numbers(client_id, client_numbers) VALUES ((select c.client_id from client c where c.client_name = $1 AND c.client_surname = $2 AND c.client_email = $3), $4)";

            // Выполняем SQL запрос с параметрами
            tx.exec_params(insertClient, name, surname, email);
            tx.exec_params(insertNumber, name, surname, email, numbers_str);

            tx.commit();
        } catch (const pqxx::sql_error& e) {
            std::cerr << "SQL error: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    //можно доделать, чтобы при отсутсвии селекта номер не вствлялся
    void add_num(const std::string& name, const std::string& surname, const std::string& email, const std::string& new_number) {
        try {
            pqxx::work tx{ c };
            std::string insert = "INSERT INTO numbers (client_id, client_numbers) "
                                 "VALUES ((SELECT client_id FROM client WHERE client_name = $1 AND client_surname = $2 AND client_email = $3),$4)";

            tx.exec_params(insert, name, surname, email, new_number);

            tx.commit();
        } catch (const pqxx::sql_error& e) {
            std::cerr << "SQL error: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void update_client_data(const std::string& name, const std::string& surname, const std::string& email, std::string new_name = "",  std::string new_surname = "",  std::string new_email = "") {
        try {
            pqxx::work tx{ c };
            std::string final_name = new_name.empty() ? name : new_name;
            std::string final_surname = new_surname.empty() ? surname : new_surname;
            std::string final_email = new_email.empty() ? email : new_email;


//ошибка тут, не менеяется в запросе просто
            std::string update = "UPDATE client SET client_name = $1, client_surname = $2, client_email = $3 WHERE client_name = $4 AND client_surname = $5 AND client_email = $6";

            tx.exec_params(update, final_name, final_surname, final_email, name, surname, email);

            tx.commit();
        } catch (const pqxx::sql_error& e) {
            std::cerr << "SQL error: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

};

int main() {
    clientsData db;

    std::string name = "Иван";
    std::string surname = "Иванов";
    std::string email = "ivan@example.com";
    std::string numbers = "09193";

    db.add_client(name, surname, email, numbers); // добавление клиента
    std::string num = "1898";

    db.add_num(name, surname, email, num); // добавление клиента
    db.update_client_data(name, surname,email, "кирилл", "павлюченко", "ivan@example2343.com");

//    std::string number =  "123-4654654" ;
//    db.add_num("Иван", "Иванов", "ivan@example.com", number);
    return 0;
}
