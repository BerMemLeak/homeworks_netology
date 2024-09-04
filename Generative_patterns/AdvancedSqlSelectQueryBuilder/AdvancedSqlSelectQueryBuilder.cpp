#include "AdvancedSqlSelectQueryBuilder.h"

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhereMoreLess(const std::string& where, const std::string& what, const std::string& op) {
    if (op != ">" && op != "<") {
        throw std::invalid_argument("Недопустимый символ");
    }
    if (sqlQuery.where_request_part.empty()) {
        sqlQuery.where_request_part += (where + op + what);
    } else {
        sqlQuery.where_request_part += (" AND " + where + op + what);
    }
    return *this;
}
