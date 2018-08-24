//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "Mutex.hpp"

Mutex::Mutex()
{
	_mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
}

Mutex::~Mutex()
{}

void Mutex::lock()
{
	pthread_mutex_lock(&_mutex);
}

void Mutex::unlock()
{
	pthread_mutex_unlock(&_mutex);
}

bool Mutex::trylock()
{
	if (pthread_mutex_trylock(&_mutex) == 0)
		return true;
	return false;
}