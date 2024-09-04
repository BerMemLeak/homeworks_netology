#pragma once

#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <string>

struct Sql_query {
    std::string column_request_part;
    std::string from_request_part;
    std::string where_request_part;
};

class Sql_query_builder {
public:
    Sql_query_builder& AddColumn(const std::string& target);
    Sql_query_builder& AddFrom(std::string target);
    Sql_query_builder& AddWhere(const std::string& where, const std::string& what);
    [[nodiscard]] std::string BuildQuery() const;
    Sql_query_builder& AddWhere(const std::map<std::string, std::string>& kv) noexcept;
    Sql_query_builder& AddColumns(const std::vector<std::string>& columns) noexcept;

protected:
    Sql_query sqlQuery;
};

