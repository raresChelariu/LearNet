#include "pch.h"

class ThreadRuntime
{
public:
    pthread_mutex_t* lock;
    int cd;
    TUPLE_LIST* allLessons;
    TUPLE_LIST* allQuizes;
public:
    ThreadRuntime(pthread_mutex_t* lock, int cd, 
                TUPLE_LIST* allLessons, TUPLE_LIST* allQuizes);
    bool Login();
    int Command();
    bool CredentialsValid(const char* username, const char* password);
    FILE* GetConversationForItem(const char* itemName);
};
ThreadRuntime::ThreadRuntime(pthread_mutex_t* lock, int cd, 
                            TUPLE_LIST* allLessons, TUPLE_LIST* allQuizes)
{
    this->lock = lock;
    this->cd = cd;
    this->allLessons = allLessons;
    this->allQuizes = allQuizes;
}
bool ThreadRuntime::Login()
{
    char user[256], pass[256], msg[256];
    memset(user, 0, 256);
    memset(pass, 0, 256);
    memset(msg, 0, 256);

    read(cd, msg, 256);
    //printf("MSG LOGIN : %s", msg);
    fflush(stdout);
    strcpy(user, strtok(msg, ";"));
    strcpy(pass, strtok(NULL, ";"));

    int isLogged = this->CredentialsValid(user, pass);
    write(cd, isLogged ? CMD_LOGIN_YES: CMD_LOGIN_NO, 256);
    return isLogged;
}
int ThreadRuntime::Command()
{
    char msg[256];
    memset(msg, 0, 256);
    if (0 >= read(cd, msg, 256))
    {
        printf("Client has disconnected");
        return -1;
    }
    if (!strcmp(msg, CMD_GET_LESSONS))
    {
        pthread_mutex_lock(lock);
        for (auto it = allLessons->begin(); it != allLessons->end(); ++it)
            write(cd, it->ToString().c_str(), 1024);
        write(cd, CMD_FINISH, 1024);
        pthread_mutex_unlock(lock);
    }
    if (!strcmp(msg, CMD_GET_QUIZES))
    {
        pthread_mutex_lock(lock);
        for (auto it = allQuizes->begin(); it != allQuizes->end(); ++it)
            write(cd, it->ToString().c_str(), 1024);
        write(cd, CMD_FINISH, 1024);
        pthread_mutex_unlock(lock);
    }
    if (!strcmp(msg, CMD_GET_CHAT))
    {
        char line[256];
        memset(line, 0, 256);
        pthread_mutex_lock(lock);
        read(cd, msg, 256);
        FILE* fp = this->GetConversationForItem(msg);
        while (fgets(line, 256, fp))
            write(cd, line, 256);
        write(cd, CMD_FINISH, 256);
        fclose(fp);
        pthread_mutex_unlock(lock);
    }
    if (!strcmp(msg, CMD_SEND_MSG))
    {
        char title[256], sender[256];
        memset(title, 0, 256);
        memset(sender, 0, 256);
        pthread_mutex_lock(lock);
        read(cd, title, 256);
        read(cd, sender, 256);
        read(cd, msg, 256);
        FILE* fp = this->GetConversationForItem(title);
        fprintf(fp, "From %s : %s\n", sender, msg);
        fclose(fp);
        pthread_mutex_unlock(lock);
    }
    return 0;
}
bool ThreadRuntime::CredentialsValid(const char* username, const char* password)
{
    char buffer[1024];
    memset(buffer, 0, 1024);
    json_object* parsed_json;
    json_object* credentials;
    json_object* user;
    json_object* pass;

    pthread_mutex_lock(lock);
    FILE* fp = fopen("auth.json", "r");
    fread(buffer, 1, 1024, fp);
    fclose(fp);
    pthread_mutex_unlock(lock);

    parsed_json = json_tokener_parse(buffer);
    int countArr = json_object_array_length(parsed_json);
    for (int i = 0; i < countArr; i++) {
        credentials = json_object_array_get_idx(parsed_json, i);
        json_object_object_get_ex(credentials, "username", &user);
        json_object_object_get_ex(credentials, "password", &pass);
        if (!strcmp(json_object_get_string(user), username) &&
            !strcmp(json_object_get_string(pass), password))
                return 1;
    }
    return 0;
}

FILE* ThreadRuntime::GetConversationForItem(const char* itemName)
{
    char filePath[256], line[256];
    memset(filePath, 0, 256);
    sprintf(filePath, "./conversations/chat%s.txt", itemName);
    return fopen(filePath, "a+");
}