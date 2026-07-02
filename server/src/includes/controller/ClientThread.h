#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <stdio.h>
#include "../model/DataBase.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <unistd.h>
#endif

struct per_session_data {
    int number;
    PGconn* conn;
};

#ifdef _WIN32
DWORD WINAPI ClientThread(LPVOID lpParam);
#else
void* ClientThread(void *vargp);
#endif

#endif