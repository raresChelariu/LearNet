#include "server.h"
#include <iostream>

int cd;
int main()
{
    Server server;
    server.LoadItems();
    server.Init();
    while (1)
    {
        server.AcceptClient();
    }   
    return 0;
}