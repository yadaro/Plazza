//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#ifndef _SAFEQUEUE_
# define _SAFEQUEUE_

#include <queue>
#include <string>
#include "Plazza.hpp"


class SafeQueue {
public:
        SafeQueue();
        ~SafeQueue();
	void push(std::pair<std::string, int> &value);
	bool tryPop(std::pair<std::string, int> &value);
	int size();
	std::queue<std::string> &getScrap();
	void incFileScraped();
	void initFileScraped();
	unsigned int getFileScraped() const;
private:
	std::queue<std::pair<std::string, int>> _queue;
	std::queue<std::string> _queueScrap;
	unsigned int _fileScraped;
};

#endif /* _SAFEQUEUE_ */
