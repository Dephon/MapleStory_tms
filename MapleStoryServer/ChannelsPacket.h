#ifndef CHANNELPACKET_H
#define CHANNELPACKET_H

class Channel;

class ChannelsPacket {
public:
	static void findRequest(Channel* channel, int channelid, int playerid, char* name);
	static void changeHeader(Channel* channel, char* header, Channel* channels[]);
	static void sendHeader(Channel *channel, char *header);
	static void changeChannel(Channel* channel, int playerid, short port , char channelid);
};

#endif