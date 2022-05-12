//============================================================================
// Name        : Ctask.cpp
// Author      : Vijaya Kumar Jitta
// Version     :
// Copyright   : Your copyright notice
// Description : 
/*
Having a Player class - an instance of this class with that can communicate with other Player(s) (other instances of this class)

The use case for this task is as bellow:

1. create 2 players

2. one of the players should send a message to second player (let's call this player "initiator")

3. when a player receives a message should send back a new message that contains the received message concatenated with the message counter that this player sent.

4. finalise the program (gracefully) after the initiator sent 10 messages and received back 10 messages (stop condition)

5. both players should run in the same process (strong requirement)

6. document for every class the responsibilities it has.

7. opposite to 5: have every player in a separate process (different PID).

Please use pure/standard C++ libs as much as possible (no additional frameworks like boost, nothing to be installed on the test system, etc.).
Please use C++17 or older version. Solution has to be delivered for Linux system (compiled with gcc).
Please deliver one single CMake (3.XX version) project with the source code only (no binaries). Please send the CMake project as archive attached to e-mail (eventual links for download will be ignored due to security policy).
Please provide a shell script to start the program.
Everything what is not clearly specified is to be decided by developer. Everything what is specified is a hard requirement.
Please focus on design and not on technology, the technology should be the simplest possible that is achieving the target.
The focus of the exercise is to deliver the cleanest and clearest design that you can achieve (and the system has to be functional).
*/
//============================================================================
#include <iostream>
#include<thread>
#include "Player.h"
#include "Initiator.h"
#include "Channel.h"
#include "UDPChannel.h"

using namespace std;
#define SENDER 1
#define RECIEVER 2
#define BOTH 3

void run(Player *pl)
{
  pl->run();
  cout <<pl->getName() <<" Exiting thread" <<endl;
}

int main(int argc, char *argv[]) {
	int mode;
	string p1IP, port1, port2, p2IP;
	int p1Port, p2Port;
	mode = atoi(argv[1]); //cin >> mode;
	p1IP = argv[2];  //cin >> p1IP;
	p1Port = atoi(argv[3]); //cin >> p1Port;
	p2IP = argv[4]; //cin >> p2IP;
	p2Port = atoi(argv[5]); //cin >> p2Port;
	Player *p1, *p2;


/* starrt receiver first */
/* start sender next */

	if (mode == SENDER) {
	Channel *to = new UDPChannel(p1IP, p1Port);
	Channel *from = new UDPChannel(p2IP, p2Port,false );
		p1 = new Initiator(from, to);
    p1->setName("Player-1");
    p1->setMsgCount(10);
    p1->run();
	} else if (mode == RECIEVER) {
	Channel *to = new UDPChannel(p1IP, p1Port, false);
	Channel *from = new UDPChannel(p2IP, p2Port);
		p1 = new Player(to, from);
    p1->setName("Player-2");
    p1->setMsgCount(10);
     p1->run();
	} else if (mode == BOTH) {
	Channel *to = new UDPChannel(p1IP, p1Port);
	Channel *from = new UDPChannel(p2IP, p2Port);
		p1 = new Player(to, from);
		p2 = new Initiator(from, to);

    p1->setName("Player-1");
    p2->setName("Player-2");
    p1->setMsgCount(10);
    p2->setMsgCount(10);
		thread th1(run, p1);
		thread th2(run, p2);
		th1.join();
		th2.join();

	}
	return 0;
}
