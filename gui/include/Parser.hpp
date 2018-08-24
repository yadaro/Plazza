/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <utility>
#include "SafeQueue.hpp"

class Parser {
public:
	Parser(void);
	~Parser(void);
	void set(std::string const &line, SafeQueue *queue);
private:
	void begin(void);
	void checkCommand(void);
	void lookFile(void);
	void checkFile(std::vector<std::string>::iterator);
	std::vector<std::string> _file;
	std::string _line;
	Information _info;
	SafeQueue *_queue;
	std::string _new;
	std::vector<std::string> _enumName {
		"PHONE_NUMBER",
		"EMAIL_ADDRESS",
		"IP_ADDRESS"
	};
};

#endif /* !PARSER_HPP_ */
