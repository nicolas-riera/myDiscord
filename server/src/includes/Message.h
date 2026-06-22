#ifndef MESSAGE_H
#define MESSAGE_H

struct Message {
    int id;
    int senderId;
    int channelId;
    char content[2001];
    char timestamp[23];
};

int createMessage(int senderId, int channelId, char *content, char *timestamp);

Message readMessage(int id);

int updateMessage(char *content);

int deleteMessage(int id);

#endif