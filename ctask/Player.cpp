/*
 * Player.cpp
 *
 *  Created on: Feb 8, 2022
 *      Author: VJITTA
 */
#include <iostream>
#include "Player.h"
#include <string.h>
#include <stdio.h>

#include <string>
using namespace std;
/* */

Player::Player(void)
{
  // TODO Auto-generated constructor stub

}

/* */
Player::Player(Channel *send, Channel *recv):m_send(send), m_recv(recv)
{

}

/* */
Player::~Player(void)
{
  // TODO Auto-generated destructor stub
}

/* */
Player &Player::operator=(const Player  &other)
{
  // TODO Auto-generated method stub
  return *this;
}

Player::Player(Player && other)
{

}

/* */
Player &Player::operator=(Player && other)
{
  // TODO Auto-generated method stub
  return *this;
}

/* */
Player::Player(const Player  &other)
{

}

/* */
ostream &operator<<(ostream &out,
                    Player  &player)
{

  return out;
}

/* */
int Player::send(string  message)
{
  cout << m_name << " send : " << message << endl;
	m_send->send(message);
	return 0;
}

/* */
string Player::recv()
{
	return m_recv->recv();
}

void Player::operator ()(int limit) {

	        while (true)
	        {
	            string receivedMessage = recv();
	            send(receivedMessage);
	        }
}
void Player::run(){

int i =0 ;
	        while ( i++ < m_msgCount)
	        {
	            string receivedMessage = recv();
              cout << m_name << " recv : " << receivedMessage << endl;
	            send(receivedMessage+std::to_string(i));
	        }
}
