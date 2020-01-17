#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <cstdlib>

#include <vector>
#include <string>
#include <QString>
#include "mytuple.h"

#define CMD_LOGIN_YES "LOGIN_YES"
#define CMD_LOGIN_NO "LOGIN_NO"
#define CMD_GET_QUIZES "CMD_GET_QUIZES"
#define CMD_GET_LESSONS "CMD_GET_LESSONS"
#define CMD_FINISH "CMD_FINISH"
#define CMD_GET_CHAT "CMD_GET_CHAT"
#define CMD_SEND_MSG "CMD_SEND_MSG"
