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
#include "Thread.hpp"
#include "SafeQueue.hpp"
#include "Child.hpp"
#include "Parser.hpp"
#include "Socket.hpp"
#include "Error.hpp"

# define PATH "test1"

void receptionChield(const Socket &soc, SafeQueue &queue);

static Socket *launchSocket()
{
	Socket	*soc = new Socket(PATH);

	soc->sbind();
	soc->slisten();
	soc->sconnect();
	return soc;
}

static void forker(SafeQueue &queue, const int &nbrThreadMax)
{
	Child child;
	Socket	*soc;
	float nbrProsMax;

	if (queue.size() == 0)
		return ;
	nbrProsMax = ceil((float)queue.size() / (float)(nbrThreadMax * 2));
	for (int i = 0; nbrProsMax > i; ++i) {
		nbrProsMax = ceil(queue.size() / (nbrThreadMax * 2));
		if (fork() == 0) {
			child.set(queue, nbrThreadMax);
		} else {
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

	while (std::getline(std::cin, line)) {
		 parseur.set(line, queue);
	}
	return NULL;
}

static void start(const int &nbrThreadMax)
{
	SafeQueue queue;
	Thread	thread;

	thread.start(manageParseur, &queue);
	usleep(10000);
	forker(queue, nbrThreadMax);
	thread.wait();
}

int main(int ac, char **av)
{
	int threadMax = 0;

	if (ac == 2) {
		threadMax = atoi(av[1]);
		try {
			start(threadMax);
		} catch (std::exception e) {
			std::cout << e.what() << std::endl;
		}
	} else
		std::cout << "Bad arguments soory\n";
	return 0;
}
