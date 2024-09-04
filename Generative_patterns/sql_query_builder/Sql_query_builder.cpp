#include "Sql_query_builder.h"

Sql_query_builder& Sql_query_builder::AddColumn(const std::string& target) {
    if (sqlQuery.column_request_part.empty()) {
        sqlQuery.column_request_part += target;
    } else {
        sqlQuery.column_request_part += ", " + target;
    }
    return *this;
}

Sql_query_builder& Sql_query_builder::AddFrom(std::string target) {
    sqlQuery.from_request_part = std::move(target);
    return *this;
}

Sql_query_builder& Sql_query_builder::AddWhere(const std::string& where, const std::string& what) {
    if (sqlQuery.where_request_part.empty()) {
        sqlQuery.where_request_part += (where + '=' + what);
    } else {
        sqlQuery.where_request_part += (" AND " + where + '=' + what);
    }
    return *this;
}

std::string Sql_query_builder::BuildQuery() const {
    if (sqlQuery.from_request_part.empty()) {
        return "Введите обязательные поля в запрос";
    }

    std::string col;
    sqlQuery.column_request_part.empty() ? col = '*' : col = sqlQuery.column_request_part;

    std::string where;
    sqlQuery.where_request_part.empty() ? where = "" : where = " WHERE " + sqlQuery.where_request_part;

    std::string request = "SELECT " + col + " FROM " + sqlQuery.from_request_part + where + ";";
    return request;
}

Sql_query_builder& Sql_query_builder::AddWhere(const std::map<std::string, std::string>& kv) noexcept {
    std::string mes;
    for (auto& item : kv) {
        mes += " AND " + item.first + '=' + item.second;
    }
    size_t pos = mes.find(" AND ");
    if (pos != std::string::npos && sqlQuery.where_request_part.empty()) {
        mes.erase(pos, 4);
    }
    sqlQuery.where_request_part += mes;
    return *this;
}

Sql_query_builder& Sql_query_builder::AddColumns(const std::vector<std::string>& columns) noexcept {
    if (columns.empty()) {
        return *this;
    }
    std::string mes;

    sqlQuery.column_request_part.empty() ? mes = "" : mes = ", ";
    for (auto& item : columns) {
        mes += item + ", ";
    }
    mes.erase((mes.size() - 2), 2);
    sqlQuery.column_request_part += mes;
    return *this;
}

