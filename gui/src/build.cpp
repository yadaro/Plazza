//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include <math.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <utility>
#include "../include/Thread.hpp"
#include "../include/SafeQueue.hpp"
#include "../include/Child.hpp"
#include "../include/Parser.hpp"
#include "../include/Socket.hpp"
#include "../include/Error.hpp"

#define PATH "test1"

void receptionChield(const Socket &soc, SafeQueue &queue);

static Socket *launchSocket()
{
	Socket *soc = new Socket(PATH);

	soc->sbind();
	soc->slisten();
	soc->sconnect();
	return soc;
}

static void forker(SafeQueue &queue, const int &nbrThreadMax)
{
	Child child;
	Socket *soc;
	float nbrProsMax;

	if (queue.size() == 0)
		return;
	nbrProsMax = ceil((float)queue.size() / (float)(nbrThreadMax * 2));
	for (int i = 0; nbrProsMax > i; ++i)
	{
		nbrProsMax = ceil(queue.size() / (nbrThreadMax * 2));
		if (fork() == 0)
		{
			child.set(queue, nbrThreadMax);
		}
		else
		{
			soc = launchSocket();
			receptionChield(*soc, queue);
			// wait(NULL); //mettre en com a la fin
		}
	}
}

void *manageParseur(void *var)
{
	std::string line;
	Parser parseur;
	SafeQueue *queue = (SafeQueue *)var;

	parseur.set("testU/index.html IP_ADDRESS;", queue);
	while (std::getline(std::cin, line))
	{
		parseur.set(line, queue);
	}
	return NULL;
}

void start(const int &nbrThreadMax, std::pair<std::string, int> cmd)
{
	SafeQueue queue;
	// Thread thread;

	// thread.start(manageParseur, &queue);
	queue.push(cmd);
	usleep(10000);
	forker(queue, nbrThreadMax);
	// thread.wait();
}