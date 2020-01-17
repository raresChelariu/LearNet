#include "threadDesign.h"
#define NO_THREADS 100
#define NO_ACCEPTS_QUEUE 20
#define PORT 5000

class Server
{
public:
    pthread_t threads[NO_THREADS];
    pthread_mutex_t lock;
    int threadCount{0};

    TUPLE_LIST allQuizes, allLessons;

    int sd;
    sockaddr_in sock;

public:
    Server();
    void Init();
    void LoadItems();
    void AcceptClient();
};
Server::Server()
{
    memset(threads, 0, NO_THREADS * sizeof(pthread_t));
    memset(&sock, 0, sizeof(sockaddr_in));
    memset(&lock, 0, sizeof(pthread_mutex_t));
    
    sock.sin_family = AF_INET;
    sock.sin_port = htons(PORT);
    sock.sin_addr.s_addr = htonl(INADDR_ANY);
}
void Server::Init()
{
    if (-1 == (sd = socket(AF_INET, SOCK_STREAM, 0)))
    {
        printf("Failed to create a new socket!\n");
        return;
    }
    int reuseAdress = 1;
    setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &reuseAdress, 4);
    if (-1 == bind(sd, (sockaddr*)&sock, sizeof(sockaddr)))
    {
        printf("Error on binding!\n");
        return;
    }
    if (-1 == listen(sd, NO_ACCEPTS_QUEUE))
    {
        printf("Failed to listen for new connecting requests!\n");
        return;
    }
    printf("Listening now ...\n");
    fflush(stdout);
}
void Server::AcceptClient()
{
    int cd;
    sockaddr_in clientSock;
    memset(&clientSock, 0, sizeof(sockaddr_in));
    socklen_t sizeSock = sizeof(clientSock);

    cd = accept(sd, (sockaddr*)&clientSock, &sizeSock);
    if (-1 == cd)
    {
        printf("Error on accepting client!\n");
        fflush(stdout);
        return;
    }
    ThreadDesign* th = new ThreadDesign(&threads[threadCount++], &lock,
                                         cd, 
                                        &allLessons, &allQuizes);
}
void Server::LoadItems()
{
    MyTuple* currTuple;
    
    char  buffer[4096];
    memset(buffer, 0, 4096);
    json_object* parsed_json, *currItem, *firstJSON, *secondJSON, *thirdJSON;

    FILE * fp = fopen("lessons.json", "r");
    fread(buffer, 1, 4096, fp);
    fclose(fp);

    parsed_json = json_tokener_parse(buffer);
    int countArr = json_object_array_length(parsed_json);
    for (int i = 0; i < countArr; i++)
    {
        currItem = json_object_array_get_idx(parsed_json, i);
        json_object_object_get_ex(currItem, "title", &firstJSON);
        json_object_object_get_ex(currItem, "description", &secondJSON);
        json_object_object_get_ex(currItem, "content", &thirdJSON);
        fflush(stdout);
        currTuple = new MyTuple();
        currTuple->first = std::string(json_object_get_string(firstJSON));
        currTuple->second = std::string(json_object_get_string(secondJSON));
        currTuple->third = std::string(json_object_get_string(thirdJSON));
        
        allLessons.push_back(*currTuple);
        
        delete currTuple;
    }

    fp = fopen("quizes.json", "r");
    fread(buffer, 1, 4096, fp);
    fclose(fp);

    parsed_json = json_tokener_parse(buffer);    
    countArr = json_object_array_length(parsed_json);
    printf("Heyyy\n"); fflush(stdout);
    for (int i = 0; i < countArr; i++)
    {
        currItem = json_object_array_get_idx(parsed_json, i);
        json_object_object_get_ex(currItem, "title", &firstJSON);
        json_object_object_get_ex(currItem, "question", &secondJSON);
        json_object_object_get_ex(currItem, "answer", &thirdJSON);

        currTuple = new MyTuple();
        currTuple->first = std::string(json_object_get_string(firstJSON));
        currTuple->second = std::string(json_object_get_string(secondJSON));
        currTuple->third = std::string(json_object_get_string(thirdJSON));
        allQuizes.push_back(*currTuple);
        delete currTuple;
    }
}