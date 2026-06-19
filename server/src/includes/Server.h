#ifndef SERVER_H
#define SERVER_H

struct Server {
	int id;
	char name[51];
	int ownerId;
	int moderatorsIds[100];
	int moderatorsIdsCount;
	int channelsIds[500];
	int channelsIdsCount;
};

enum ServerField{
    NAME,
    OWNERID
};

int createServer(char *name, int ownerId);

Server readServer(int id);

int updateServer(ServerField field, char *value); 

int deleteServer(int id);

#endif