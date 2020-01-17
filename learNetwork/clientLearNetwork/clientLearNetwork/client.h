#ifndef CLIENT_H
#define CLIENT_H

#include "pch.h"

class Client
{
public:
    static int sd;
    static sockaddr_in sock;
    static QString username;
    static void ConnectToServer();
};

#endif // CLIENT_H
