#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "src/mongoose/mongoose.h"

#define HTTP_PORT "http://0.0.0.0:8080"

void *client_thread(void *arg) {
    struct mg_connection *fn_connection = (struct mg_connection *)arg;

    return NULL;
}

static void event_handler(struct mg_connection *c, int ev, void *ev_data) {
    
}

int main() {
    struct mg_mgr mgr;
    mg_mgr_init(&mgr);
    
    if (mg_http_listen(&mgr, HTTP_PORT, event_handler, NULL) == NULL) {
        printf("Error starting server...\n");
        return 1;
    }

    printf("myDiscord server started on port 8080...\n");
    for (;;) {
        mg_mgr_poll(&mgr, 1000); 
    }
    
    mg_mgr_free(&mgr);
    return 0;
}