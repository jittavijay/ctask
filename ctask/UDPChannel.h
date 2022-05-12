/*
 * UDPChannel.h
 *
 *  Created on: Feb 25, 2022
 *      Author: VJITTA
 */

#ifndef UDPCHANNEL_H_
#define UDPCHANNEL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#ifdef WIN32
 	 #include <winsock2.h>
#else
 	 #include <sys/socket.h>
	 #include <sys/un.h>
	 #include <sys/socket.h>
	 #include <arpa/inet.h>
	 #include <netinet/in.h>
#endif
using namespace std;
#ifndef MSG_WAITALL
#define MSG_WAITALL 0
#endif
#ifndef MSG_CONFIRM
#define MSG_CONFIRM 0
#endif
#ifndef socklen_t
#define socklen_t int
#endif
#include <string>
#include "Channel.h"
using namespace std;

class UDPChannel : public Channel{
	std::string m_ip;
	int m_port;
	struct sockaddr_in m_addr;
	int m_sockfd;

public:
	UDPChannel();
	virtual ~UDPChannel();
	UDPChannel(const UDPChannel &other);
	UDPChannel(string ip, int port, bool isBind=true);
	UDPChannel(UDPChannel &&other);
	UDPChannel& operator=(const UDPChannel &other);
	UDPChannel& operator=(UDPChannel &&other);
	virtual int send(string msg);
	virtual string  recv();
};

#endif /* UDPCHANNEL_H_ */
