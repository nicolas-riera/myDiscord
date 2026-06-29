#include "../includes/controller/ClientThread.h"

#ifdef _WIN32
DWORD WINAPI ClientThread(LPVOID lpParam) {
    struct per_session_data *pss = (struct per_session_data *)lpParam;
    printf("Started client Thread\n");
    fflush(stdout);
    return 0;
}
#else
void* ClientThread(void *vargp) {
    struct per_session_data *pss = (struct per_session_data *)vargp;
    printf("Started client Thread\n");
    fflush(stdout);
    return NULL;
}
#endif