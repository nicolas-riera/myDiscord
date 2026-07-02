#include "../includes/controller/WebSocket.h"

int lws_callback(struct lws *wsi, enum lws_callback_reasons reason,
                            void *user, void *in, size_t len) {
    struct per_session_data *pss = (struct per_session_data *)user;

    switch (reason) {
        case LWS_CALLBACK_ESTABLISHED:
            printf("Established connection with client\n");
            fflush(stdout);
        #ifdef _WIN32
            CreateThread(NULL, 0, ClientThread, pss, 0, NULL);
        #else
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, ClientThread, pss);
            pthread_detach(thread_id);
        #endif
            break;

        case LWS_CALLBACK_RECEIVE:
            printf("Data received: %.*s\n", (int)len, (char *)in);
            fflush(stdout);
            lws_callback_on_writable(wsi);
            break;

        case LWS_CALLBACK_SERVER_WRITEABLE:
            break;

        case LWS_CALLBACK_CLOSED:
            printf("Connection closed\n");
            if (pss->conn != NULL) {
                db_disconnect(pss->conn);
            }   
            fflush(stdout);
            break;

        default:
            break;
    }

    return 0;
}