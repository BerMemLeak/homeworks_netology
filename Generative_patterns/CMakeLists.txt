cmake_minimum_required(VERSION 3.27)
project(Generative_patterns)


set(CMAKE_CXX_STANDARD 23)

add_executable(Generative_patterns main.cpp
        sql_query_builder/Sql_query_builder.cpp
        AdvancedSqlSelectQueryBuilder/AdvancedSqlSelectQueryBuilder.cpp)




