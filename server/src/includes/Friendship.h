#ifndef FRIENDSHIP_H
#define FRIENDSHIP_H

struct Friendship
{
    int id;
    int user1Id;
    int user2Id;
    FriendStatus friendStatus;
};

enum FriendStatus {
    PENDING, 
    ACCEPTED,
    BLOCKED
};

enum FriendshipField {
    USER1ID, 
    USER2ID, 
    FRIENDSTATUS
};

int createFriendship(int user1id, int user2id, FriendStatus friendstatus);

Friendship readFriendship(int id);

int updateFriendship(FriendshipField field, char *value);

int deleteFriendship(int id);

#endif