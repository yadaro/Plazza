//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "Thread.hpp"

Thread::Thread()
{
	_status = STARTED;
}

Thread::~Thread()
{}

bool Thread::start(void *(*func)(void *), void *var)
{
	pthread_create(&_thread, NULL, func, var);
	_status = RUNNING;
	return true;
}

bool Thread::wait()
{
	pthread_join(_thread, NULL);
	return true;
}

Thread::Status Thread::getStatus()
{
	return _status;
}