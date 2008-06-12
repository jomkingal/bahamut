/*
*Project Name: Bahamut
* 
*Programmers: Codestation, ZackVixACD
* 
*Project Descrption: The project bahamut is a full ad-hoc tunneling
*	software to be used by the Playstation Portable (PSP) to emulate 
*	online features.
*
*File Description:
*	TCP server
*Special Notes:
*	TODO: incomplete class
*
*Copyright Stuff:
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
* 
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
* 
*  You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SERVERSOCKET_H_
#define SERVERSOCKET_H_

#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include "Socket.h"

class ServerSocket {
private:
	int sock;
	int port;
	sockaddr_in client;

public:
	ServerSocket();
	bool bindSocket();
	bool listenSocket(int max);
	Socket *acceptSocket();
	virtual ~ServerSocket();
};

#endif /*SERVERSOCKET_H_*/
