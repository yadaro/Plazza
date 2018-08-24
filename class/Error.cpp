/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(const std::string &msg) throw()
		 :_msg(msg)
{}

Error::Error() throw()
		 :_msg("")
{}

Error::~Error()
{}

const char *Error::what() const throw()
{
	return _msg.c_str();
}