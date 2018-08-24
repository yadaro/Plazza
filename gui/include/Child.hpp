//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#ifndef _CHILD_
# define _CHILD_

#include <vector>
#include "Thread.hpp"
#include "SafeQueue.hpp"

class Child {
public:
	Child();
	~Child();
	void set(SafeQueue &queue, const int &nbrThreadMax);
private:
	std::vector<Thread *> _threads;
};

#endif /* _CHILD_ */