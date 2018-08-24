//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _THREAD_
# define _THREAD_

#include <pthread.h>

class Thread {

enum Status {
        STARTED,
        RUNNING,
        DEAD
};

public:
        Thread();
        ~Thread();
        bool start(void *(*func)(void *), void *var);
        bool wait();
	Status getStatus();
private:
        Status _status;
        pthread_t _thread;
};

#endif /* _THREAD_ */