#ifndef MYTUPLE_H
#define MYTUPLE_H


#define TUPLE_LIST std::list<MyTuple>
#include <string>

class MyTuple
{
public:
    std::string first, second, third;
public:
    MyTuple();
    MyTuple(std::string first, std::string second, std::string third);
    MyTuple(const char* first, const char* second, const char* third);
    MyTuple(char* cstr);
    std::string ToString();
};

#endif // MYTUPLE_H
