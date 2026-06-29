#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include "ClientThread.h"
#include <stdlib.h>
#include <libwebsockets.h>

int lws_callback(struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len);

static struct lws_protocols protocols[] = {
    { "http", lws_callback_http_dummy, 0, 0 },
    {
        "myDiscord_websocket",
        lws_callback,
        sizeof(struct per_session_data),
        1024,
    },
    { NULL, NULL, 0, 0 }
};

#endif