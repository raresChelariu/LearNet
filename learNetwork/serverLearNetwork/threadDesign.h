#include "threadRuntime.h"

class ThreadDesign
{
public:
    struct ThreadParam
    {
        int cd;
        pthread_mutex_t* lock;
        TUPLE_LIST* allLessons;
        TUPLE_LIST* allQuizes;
    };
public:
    ThreadDesign(pthread_t* thread, pthread_mutex_t* lock, int cd, 
                            TUPLE_LIST* allLessons, TUPLE_LIST* allQuizes);
    static void* ThreadStart(void* args);
};
ThreadDesign::ThreadDesign(pthread_t* thread, pthread_mutex_t* lock, int cd, 
                            TUPLE_LIST* allLessons, TUPLE_LIST* allQuizes)
{
    ThreadParam* thParam = (ThreadParam*) malloc(sizeof(ThreadParam));
    thParam->cd = cd;
    thParam->lock = lock;
    thParam->allLessons = allLessons;
    thParam->allQuizes = allQuizes;
    pthread_create(thread, NULL, ThreadStart, thParam);
}
void* ThreadDesign::ThreadStart(void* args)
{
    ThreadParam p = *((ThreadParam*)args);
    ThreadRuntime* th = new ThreadRuntime(p.lock, p.cd, p.allLessons, p.allQuizes);
    while (1)
    {
        if (th->Login())
            break;
    }
    while (1)
    {
        if (-1 == th->Command())
        {
            pthread_cancel(pthread_self());
            return NULL;
        }
    }
    return NULL;
}   