#ifndef CHANNEL_H
#define CHANNEL_H

struct Channel {
    int id;
    char name[51];
    bool access;
};

enum ChannelField {
    NAME,
    ACCESS
};

int createChannel(char *name);

Channel readChannel(int id);

int updateChannel(ChannelField field, char *value);

int deleteChannel(int id);

#endif