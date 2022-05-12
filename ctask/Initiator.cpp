/*
 * Initiator.cpp
 *
 *  Created on: Feb 24, 2022
 *      Author: VJITTA
 */

#include "Initiator.h"

Initiator::Initiator() {
	// TODO Auto-generated constructor stub

}

Initiator::~Initiator() {
	// TODO Auto-generated destructor stub
}

Initiator::Initiator(const Initiator &other) {
	// TODO Auto-generated constructor stub

}

Initiator::Initiator(Initiator &&other) {
	// TODO Auto-generated constructor stub

}

Initiator& Initiator::operator=(const Initiator &other) {
	// TODO Auto-generated method stub

	return *this;
}

Initiator& Initiator::operator=(Initiator &&other) {
	// TODO Auto-generated method stub
return *this;
}

Initiator::Initiator(Channel *send, Channel *recv): Player(send, recv) {
}

void Initiator::operator ()(int limit) {
	send("Init Message");
    while (true)
        {
            string receivedMessage = recv();
            send(receivedMessage);
        }
}

void Initiator::run(){
	send("Init Message");
  Player::run();
}
