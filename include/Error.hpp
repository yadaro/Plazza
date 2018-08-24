/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <iostream>

class Error: public std::exception
{
public:
	Error(const std::string &msg) throw();
	Error() throw();
	~Error() throw();
	const char *what() const throw();
private:
	std::string _msg;
};

#endif /* !ERROR_HPP_ */
