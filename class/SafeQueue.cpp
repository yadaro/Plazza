//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "SafeQueue.hpp"

SafeQueue::SafeQueue()
	: _fileScraped(0)
{}

SafeQueue::~SafeQueue()
{}

int SafeQueue::size()
{
	return _queue.size();
}

void SafeQueue::push(std::pair<std::string, int> &value)
{
	_queue.push(value);
}

bool SafeQueue::tryPop(std::pair<std::string, int> &value)
{
	if (_queue.empty() == true)
		return false;
	else {
		value = _queue.front();
		_queue.pop();
	}
	return true;
}

std::queue<std::string> &SafeQueue::getScrap()
{
	return _queueScrap;
}

unsigned int SafeQueue::getFileScraped() const
{
	return _fileScraped;
}

void SafeQueue::incFileScraped()
{
	++_fileScraped;
}

void SafeQueue::initFileScraped()
{
	_fileScraped = 0;
}