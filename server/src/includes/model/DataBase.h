#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

PGconn* db_connect();
int db_disconnect(PGconn* conn);

#endif