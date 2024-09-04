#include "./sql_query_builder/Sql_query_builder.h"
#include "./AdvancedSqlSelectQueryBuilder/AdvancedSqlSelectQueryBuilder.h"

int main() {
    try {
        AdvancedSqlSelectQueryBuilder query_builder;
        query_builder.AddColumn("name").AddColumn("phone");
        query_builder.AddFrom("students");
        query_builder.AddWhereMoreLess("id", "42",">").AddWhereMoreLess("name", "John","<");



        std::map<std::string, std::string> conditions = {
                {"name", "John"},
                {"age", "30"},
                {"city", "New_York"}
        };
        std::vector <std::string> field = {
                "email",
                "gender",
                "weight"
        };

        query_builder.AddWhere(conditions);
        query_builder.AddColumns(field);
//    bool isTrue = query_builder.BuildQuery() == "SELECT name, phone FROM students WHERE id=42 AND name=John;";
        std::cout << query_builder.BuildQuery() ;
   } catch (std::exception& error) {
        std::cout << error.what();
    }
    return 0;
}

