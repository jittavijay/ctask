/*
 * UDPChannel.cpp
 *
 *  Created on: Feb 25, 2022
 *      Author: VJITTA
 */
#include <string>
#include <iostream>
#include "UDPChannel.h"
using namespace std;

UDPChannel::UDPChannel() {
	// TODO Auto-generated constructor stub

}

UDPChannel::~UDPChannel() {
	// TODO Auto-generated destructor stub
}

UDPChannel::UDPChannel(const UDPChannel &other) {
	// TODO Auto-generated constructor stub

}

UDPChannel::UDPChannel(UDPChannel &&other) {
	// TODO Auto-generated constructor stub

}

UDPChannel& UDPChannel::operator=(const UDPChannel &other) {
	// TODO Auto-generated method stub
return *this;

}

UDPChannel& UDPChannel::operator=(UDPChannel &&other) {
	// TODO Auto-generated method stub

return *this;
}

int UDPChannel::send(string msg) {

	int len = 0;
	len = sendto(m_sockfd, (const char*) msg.c_str(), msg.length(),
	MSG_CONFIRM, (const struct sockaddr*) &m_addr, sizeof(m_addr));

return len;

}

UDPChannel::UDPChannel(string ip, int port, bool isBind) :
		m_ip(ip), m_port(port) {
	if ((m_sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	// clear addr
	memset(&m_addr, 0, sizeof(m_addr));
	m_addr.sin_addr.s_addr = inet_addr(m_ip.c_str());
	m_addr.sin_port = htons(m_port);
	m_addr.sin_family = AF_INET;
	// Bind the socket with the server address
	if (isBind && bind(m_sockfd, (const struct sockaddr*) &m_addr, sizeof(m_addr)) < 0) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
}

string  UDPChannel::recv() {

	char buffer[1024];
	unsigned int len = 0, n = 0;
	string msg;
	n = recvfrom(m_sockfd, (char*) buffer, sizeof(buffer), MSG_WAITALL,
			(struct sockaddr*) &m_addr, &len);
	buffer[n] = '\0';

	msg = buffer;
	return msg;

}
