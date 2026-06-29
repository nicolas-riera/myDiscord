#ifndef REACTION_H
#define REACTION_H

struct Reaction {
    int id;
    int messageId;
    int userId;
    char femoji[5];
};

enum ReactionField {
    MESSAGEID,
    USERID, 
    EMOJI
};

int createReaction(int messageId, int userId, char *emoji);

Reaction readReaction(int id);

int deleteReaction(int id);

#endif