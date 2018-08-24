//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#ifndef _PLAZZA_
# define _PLAZZA_

#include <iostream>
#include <vector>
#include "Socket.hpp"
#include "SafeQueue.hpp"

enum	Information {
	PHONE_NUMBER,
	EMAIL_ADDRESS,
	IP_ADDRESS
};

char	*get_line(const int fd);
// void	receptionChield(const Socket &soc, SafeQueue &queue);

#endif /* _PLAZZA_ */