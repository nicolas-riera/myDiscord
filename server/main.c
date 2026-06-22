#include <stdio.h>
#include <stdlib.h>
#include <libwebsockets.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <unistd.h>
#endif

struct per_session_data__minimal {
    int number;
};

#ifdef _WIN32
DWORD WINAPI ClientThread(LPVOID lpParam) {
    struct per_session_data__minimal *pss = (struct per_session_data__minimal *)lpParam;
    printf("Started client Thread\n");
    return 0;
}
#else
void* ClientThread(void *vargp) {
    struct per_session_data__minimal *pss = (struct per_session_data__minimal *)vargp;
    printf("Started client Thread\n");
    return NULL;
}
#endif

static int callback_minimal(struct lws *wsi, enum lws_callback_reasons reason,
                            void *user, void *in, size_t len) {
    struct per_session_data__minimal *pss = (struct per_session_data__minimal *)user;

    switch (reason) {
        case LWS_CALLBACK_ESTABLISHED:
            printf("Established connection with client\n");
        #ifdef _WIN32
            CreateThread(NULL, 0, ClientThread, pss, 0, NULL);
        #else
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, ClientThread, pss);
            pthread_detach(thread_id);
        #endif
            break;

        case LWS_CALLBACK_RECEIVE:
            printf("Data received: %s\n", (char *)in);
            lws_callback_on_writable(wsi);
            break;

        case LWS_CALLBACK_SERVER_WRITEABLE:
            break;

        case LWS_CALLBACK_CLOSED:
            printf("Connection closed\n");
            break;

        default:
            break;
    }

    return 0;
}

static struct lws_protocols protocols[] = {
    { "http", lws_callback_http_dummy, 0, 0 },
    {
        "myDiscord_websocket",
        callback_minimal,
        sizeof(struct per_session_data__minimal),
        1024,
    },
    { NULL, NULL, 0, 0 }
};

int main(int argc, const char **argv) {
    struct lws_context_creation_info info;
    struct lws_context *context;
    int n = 0;

    memset(&info, 0, sizeof(info));
    info.port = 8080;
    info.protocols = protocols;
    info.gid = -1;
    info.uid = -1;

    context = lws_create_context(&info);
    if (!context) {
        lwsl_err("Error starting server\n");
        return 1;
    }

    printf("myDiscord Server started on port 8080.\n");

    while (n >= 0) {
        n = lws_service(context, 0);
    }

    lws_context_destroy(context);

    return 0;
}