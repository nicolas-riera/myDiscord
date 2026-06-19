#ifndef USER_H
#define USER_H

struct User {
    int id;
    char username[26];
    int friendsIds[1000];
    int friendsIdsCount = 0;
    int serversIds[100];
    int serverIdsCount = 0;
};

enum UserField {
    USERNAME,
    EMAIL,
    HASHEDPASSWOR
};

int createUser(char *username, char *email, char *hashedPassword);

User readUser(int id);

int updateUser(UserField field, char *value);

int deleteUser(int id);

#endif