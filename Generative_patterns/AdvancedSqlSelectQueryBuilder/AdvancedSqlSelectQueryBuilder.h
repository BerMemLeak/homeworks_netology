#pragma once

#include "../sql_query_builder/Sql_query_builder.h"
#include <stdexcept>
#include <string>

class AdvancedSqlSelectQueryBuilder : public Sql_query_builder {
public:
    AdvancedSqlSelectQueryBuilder& AddWhereMoreLess(const std::string& where, const std::string& what, const std::string& op);
};

