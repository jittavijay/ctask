/*
 * Channel.h
 *
 *  Created on: Feb 25, 2022
 *      Author: VJITTA
 */

#ifndef CHANNEL_H_
#define CHANNEL_H_

#include <string>
using namespace std;

class Channel {
public:
	Channel();
	virtual ~Channel();
	Channel(const Channel &other);
	Channel(Channel &&other);
	Channel& operator=(const Channel &other);
	Channel& operator=(Channel &&other);
	virtual int send(string msg) = 0;
	virtual string  recv() = 0;
};

#endif /* CHANNEL_H_ */
