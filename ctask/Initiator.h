/*
 * Initiator.h
 *
 *  Created on: Feb 24, 2022
 *      Author: VJITTA
 */

#ifndef INITIATOR_H_
#define INITIATOR_H_

#include "Player.h"
#include "Channel.h"

class Initiator : public Player{
public:
	Initiator();
	virtual ~Initiator();
	Initiator(Channel *send, Channel *recv);
	Initiator(const Initiator &other);
	Initiator(Initiator &&other);
	Initiator& operator=(const Initiator &other);
	Initiator& operator=(Initiator &&other);
	virtual void operator()(int limit);
virtual void run();
};

#endif /* INITIATOR_H_ */
