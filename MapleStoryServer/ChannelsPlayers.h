#ifndef CHANNELSPLAYERS_H
#define CHANNELSPLAYERS_H

#include <hash_map>

using namespace std;
using namespace stdext;

class Channel;

class ChannelsPlayers {
public:
	static void addPlayer(Channel* channel, unsigned char* packet);
	static void removePlayer(Channel* channel, unsigned char* packet);
	static void findRequest(Channel* channel, unsigned char* packet);
	static void removePlayersFromChannel(int n);
	static void changeHeader(Channel* channel, unsigned char* packet);
	static bool isPlayerConnected(int charid);
	static char header[100];
private:
	static hash_map <int, int> players;
};

#endif