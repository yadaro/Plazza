/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Socket
*/

#include <unistd.h>
#include <errno.h>	
#include "Socket.hpp"
#include "Error.hpp"

Socket::Socket(const std::string &path)
	: _path(path)
{
	memset(&_clientAddr, 0, sizeof(struct sockaddr_un));
	memset(&_serverAddr, 0, sizeof(struct sockaddr_un));
	if ((_serverFd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)
		throw Error("SOCKET : creation failed ");
	_serverAddr.sun_family = AF_UNIX;
	strcpy(_serverAddr.sun_path, path.c_str());
	unlink(path.data());
	_mode = SERVER;
}

Socket::Socket(const std::string &cliPath, const std::string &servPath)
		:_path(servPath)
{
	memset(&_clientAddr, 0, sizeof(struct sockaddr_un));
	memset(&_serverAddr, 0, sizeof(struct sockaddr_un));
	if ((_clientFd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)
		throw Error("SOCKET : creation failed ");
	_clientAddr.sun_family = AF_UNIX;
	strcpy(_clientAddr.sun_path, cliPath.c_str());
	unlink(cliPath.data());
	_mode = CLIENT;	
}

Socket::~Socket()
{
	close(_serverFd);
	close(_clientFd);
}

void Socket::sbind(void)
{
	if (_mode == SERVER) {
		int l = sizeof(_serverAddr);

		if (bind(_serverFd, (struct sockaddr *) &_serverAddr, l) == -1) {
			close(_serverFd);
			throw Error("SOCKET : Bind failed ");
		}
	}
	else {
		int l = sizeof(_clientAddr);

		if (bind(_clientFd, (struct sockaddr *) &_clientAddr, l) == -1) {
			close(_clientFd);
			throw Error("SOCKET : Bind Client failed ");
		}
		
	}
}

void Socket::slisten(void)
{
	if (_mode == CLIENT)
		return ;
	if (listen(_serverFd, 5) == -1) {
		close(_serverFd);
		throw Error("SOCKET : Listen failed ");
	}
}


void Socket::sconnect(void)
{
	if (_mode == SERVER) {
		socklen_t l = sizeof(_serverAddr);

		if ((_clientFd = accept(_serverFd, (struct sockaddr *) &_clientAddr, &l)) == -1) {
			close(_serverFd);
			close(_clientFd);
			throw Error("SOCKET : Accept failed ");
		}
	}
	else {
		socklen_t l = sizeof(_serverAddr);

		_serverAddr.sun_family = AF_UNIX;
		strcpy(_serverAddr.sun_path, _path.c_str());
		if (connect(_clientFd, (struct sockaddr *) &_serverAddr, l) == -1) {
			close(_clientFd);
			throw Error("SOCKET : Connect failed ");
		}
	}
}

const std::string Socket::srecv(int flag)
{
	if (recv(_clientFd, _buf, sizeof(_buf), flag) == -1) {
		close(_serverFd);
		close(_clientFd);
		throw Error("SOCKET : Accept failed ");		
	}
	std::string ret = _buf;
	return ret;
}

void Socket::ssend(const std::string &msg, int flag)
{
	if (send(_clientFd, msg.c_str(), msg.size(), flag) == -1) {
		close(_serverFd);
		close(_clientFd);
		throw Error("SOCKET : Accept failed ");		
	}
}