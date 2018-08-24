//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "Plazza.hpp"
#include "Socket.hpp"

void receptionChield(const Socket &soc, SafeQueue &queue)
{
	char *tmp;
	unsigned int nbrDrop = 0;
	std::pair<std::string, int> pop;

	while ((tmp = get_line(soc._clientFd)) && tmp[0] != 0)
		std::cout << tmp << std::endl;
	while ((tmp = get_line(soc._clientFd)) && tmp[0] != 0)
		nbrDrop = atoi(tmp);
	for (unsigned int i = 0; nbrDrop > i; ++i) {
		if (queue.tryPop(pop) == false)
			continue ;
	}
}