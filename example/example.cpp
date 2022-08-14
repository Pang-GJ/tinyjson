#include "json.hpp"

#include <iostream>
#include <fstream>

struct Base {
    int pp;
    std::string qq;

    START_FROM_JSON
        pp = from("pp", tinyjson::int_t);
        qq = from("qq", tinyjson::str_t);
    END_FROM_JSON

    START_TO_JSON
        to("pp") = pp;
        to("qq") = qq;
    END_TO_JSON
};

struct MyTest {
    int id;
    std::string name;
    Base q;

    START_TO_JSON
        to_struct("base", q);
        to("id") = id;
        to("name") = name;
    END_TO_JSON

    START_FROM_JSON
        id = from("id", int);
        name = from("name", std::string);
        from_struct("base", q);
    END_FROM_JSON
};

void test_class_serialization() {
    MyTest test{.id = 32, .name="fda"};
    auto item = tinyjson::Parser::FromJson<MyTest>(R"({"base":{"pp":0,"qq":""},"id":32,"name":"fda"} )");
    std::cout << tinyjson::Parser::ToJSON(item);
}

void test_string_parser() {
    std::ifstream fin("../../example/keybindings.json");
    std::string text((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>());
    tinyjson::Parser p;
    p.Init(text);
    auto q = p.Parse();
    std::ofstream fout("../../example/test_out.json");
    fout << q.ToString();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test_class_serialization();
    test_string_parser();
    return 0;
}
