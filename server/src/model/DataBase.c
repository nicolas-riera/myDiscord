#include "../includes/model/DataBase.h"

PGconn* db_connect() {
    const char* pass = getenv("DB_PASSWORD");

    if (pass == NULL) {
        fprintf(stderr, "Error : DB_PASSWORD environment variable undefined.\n");
        return NULL;
    }

    char conninfo[1024];

    snprintf(conninfo, sizeof(conninfo),
             "host=aws-0-eu-west-1.pooler.supabase.com "
             "port=5432 "
             "dbname=postgres "
             "user=postgres.vlgkkdghavysfgwedxin "
             "password=%s "
             "sslmode=require",
             pass);

    // Init connection
    PGconn* conn = PQconnectdb(conninfo);

    // Check connection status
    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "DataBase connection failed : %s\n", 
                PQerrorMessage(conn));
        PQfinish(conn);
        return NULL;
    }

    printf("Successfully connected to DataBase !\n");

    // --- Simple request test---
    PGresult *res = PQexec(conn, "SELECT VERSION();");
    if (PQresultStatus(res) == PGRES_TUPLES_OK) {
        printf("Server version : %s\n", PQgetvalue(res, 0, 0));
    }
    PQclear(res);
    // --------------------------------------

    return conn;
}

int db_disconnect(PGconn* conn){
    PQfinish(conn);
    return 0;
}