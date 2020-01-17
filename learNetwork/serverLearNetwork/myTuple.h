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
    MyTuple(const char* cstr);
    std::string ToString();
};
MyTuple::MyTuple()
{
    first = second = third = "";
}
MyTuple::MyTuple(std::string first, std::string second, std::string third)
{
    this->first = first;
    this->second = second;
    this->third = third;
}
MyTuple::MyTuple(const char* first, const char* second, const char* third)
{
    this->first = std::string(first);
    this->second = std::string(second);
    this->third = std::string(third);
}
std::string MyTuple::ToString()
{
    return first.append("$").append(second).append("$").append(third);
}
