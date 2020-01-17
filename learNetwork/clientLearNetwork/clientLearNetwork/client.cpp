#include "client.h"
#define IP_HOST "127.0.0.1"
#define PORT 5000

int Client::sd;
sockaddr_in Client::sock;
QString Client::username;
void Client::ConnectToServer()
{
    memset(&sock, 0, sizeof(sockaddr_in));
    sock.sin_family = AF_INET;
    sock.sin_addr.s_addr = inet_addr(IP_HOST);
    sock.sin_port = htons(PORT);
    if (-1 == (sd = socket(AF_INET, SOCK_STREAM, 0)))
    {
        printf("Error on creating socket!\n");
        fflush(stdout);
        return;
    }
    if (-1 == ::connect(sd, (sockaddr*)&sock, sizeof(sockaddr)))
    {
        printf("Failed to connect successfully to server!\n");
        fflush(stdout);
        return;
    }
    printf("Client made the connection\n");
    fflush(stdout);
}
