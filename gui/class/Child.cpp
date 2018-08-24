//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <unistd.h>
#include "ParserFile.hpp"
#include "Mutex.hpp"
#include "Child.hpp"
#include "Socket.hpp"

# define PATH "test1"
# define PATHZ "test2"

Child::Child()
{}

Child::~Child()
{}

void *manageParseFile(void *var)
{
	SafeQueue *queue = (SafeQueue *)var;
	Mutex mutex;
	ParserFile parserFile;
	std::pair<std::string, int> tmp;

	while (true) {
		if (mutex.trylock() == true) {
			for (int i = 0; 2 > i; ++i) {				
				if (queue->tryPop(tmp) == true) {
					parserFile.run(tmp, *(queue));
				} else
					break ;
			}
			break ;
		} else
			continue ;
	}
	mutex.unlock();
	return NULL;
}

void Child::set(SafeQueue &queue, const int &nbrThreadMax)
{
	usleep(1000);
	Socket	soc(PATHZ, PATH);

	soc.sbind();
	soc.sconnect();

	queue.initFileScraped();

	for (int i = 0; nbrThreadMax > i; ++i)
		_threads.push_back(new Thread);
	for (auto it : _threads) {
		it->start(manageParseFile, &queue);
		usleep(1000);
	}
	for (auto it : _threads)
		it->wait();
	while (!queue.getScrap().empty()) {
		soc.ssend(queue.getScrap().front() + "\n", 0);
		queue.getScrap().pop();
	}
	soc.ssend(std::string("\0") + "\n", 0);

	// send nbr of command did
	soc.ssend(std::to_string(queue.getFileScraped()) + "\n", 0);
	soc.ssend(std::string("\0") + "\n", 0);
}