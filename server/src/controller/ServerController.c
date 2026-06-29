#include "../includes/controller/ServerController.h"

int serve(){
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
    fflush(stdout);

    while (n >= 0) {
        n = lws_service(context, 0);
    }

    lws_context_destroy(context);

    return 0;
}