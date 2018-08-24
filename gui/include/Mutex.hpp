//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _MUTEX_
# define _MUTEX_

#include <pthread.h>
//#include "IMutex.hpp"

class Mutex {
public:
        Mutex();
        ~Mutex();
        void lock();
        void unlock();
        bool trylock();
private:
        pthread_mutex_t _mutex;
};


#endif /* _MUTEX_ */