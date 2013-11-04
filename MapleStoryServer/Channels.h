#ifndef CHANNELS_H
#define CHANNELS_H

#include "stdio.h"

class Channel;

short getShort(unsigned char* buf);
int getInt(unsigned char* buf);
void getString(unsigned char* buf, int len, char* out);

class Channels {
public:
	static void setChannels(int n);
	static int getChannels(){
		return channeln;
	}	
	static int getChannelStatus(int n){
		if(channels[n] == NULL)
			return 0;
		return 1;
	}	
	static void removeChannel(Channel* channel);
	static void acceptChannel(Channel* channel, unsigned char* packet);
	static void changeChannel(Channel* channel, unsigned char* packet);
	static Channel* channels[20];
private:
	static int channeln;
};

#endif