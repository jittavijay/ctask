/*
 * Player.h
 *
 *  Created on: Feb 8, 2022
 *      Author: VJITTA
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Channel.h"
#include "UDPChannel.h"
using namespace std;

class Player {
private:
string m_name;
  int m_msgCount;
	Channel *m_send;
	Channel *m_recv;
public:
	Player();
	Player(Channel *send, Channel *recv);
	virtual ~Player();
	Player& operator=(const Player &other);
	Player(Player &&other);
	Player& operator=(Player &&other);
	Player(const Player &other);
	friend ostream & operator << (ostream &out, Player &player);
	virtual int send(string message);
	virtual string recv();
	virtual void operator()(int limit);
  int setMsgCount(int count) { return (m_msgCount = count); }
  int getMsgCount() { return m_msgCount; }
void setName(string name) { m_name = name; }
string getName() { return m_name; }
virtual void run();
};
#endif /* PLAYER_H_ */
