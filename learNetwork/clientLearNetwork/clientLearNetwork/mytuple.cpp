#include "mytuple.h"
#include <string.h>

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
MyTuple::MyTuple(char* cstr)
{
    char *p = strtok(cstr, "$");
    std::string s = std::string(p);
    this->first = s;
    p = strtok(NULL, "$");
    this->second = std::string(p);
    p = strtok(NULL, "$");
    this->third = std::string(p);
}
