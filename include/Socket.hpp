//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#ifndef SOCKET_HPP_
#define SOCKET_HPP_

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <iostream>

class Socket {
public:
	#ifndef SOCKET_MODE
	# define SOCKET_MODE
		enum socketMode {
			SERVER,
			CLIENT
		};	
	#endif /* SOCKET_MODE */
	
/*
** PROTOTYPE : CONSTRUCTOR WITH ONE PATH IS THE SERVER
*/
	Socket(const std::string &path);
/*
** PROTOTYPE : CONSTRUCTOR WITH TWO PATHS IS THE CLIENT THE FIRST PATH 
**	       IS THE CLIENT PATH AND THE SECOND THE SERVER PATH
*/
	Socket(const std::string &pathc, const std::string &paths);
	~Socket();
/*
** PROTOTYPE : FUNCTIONS FOR THE SOCKETS
*/
	void sbind(void);
	void slisten(void);
	void sconnect(void);
	const std::string srecv(int flags);
	void ssend(const std::string &msg, int flags);
/*
** VARIABLES : VARIABLES IN PUBLIC WITH POSSIBLY TO CREATE TWO SOCKETS
** 	       ONE FOR THE SERVER THE SECOND FOR THE CLIENT GETTER/SETTER ?
*/
	struct sockaddr_un	_clientAddr;
	struct sockaddr_un	_serverAddr;
	int			_serverFd;
	int			_clientFd;

private:
	socketMode		_mode;
	char			_buf[500];
	std::string		_path;
};

#endif /* !SOCKET_HPP_ */
