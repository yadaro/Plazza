/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** Parser
*/

#include <iterator>
#include <sstream>
#include <fstream>
#include "Parser.hpp"
#include "Error.hpp"
#include "Plazza.hpp"

Parser::Parser(void)
{}

Parser::~Parser(void)
{}

void Parser::set(const std::string &line, SafeQueue *queue)
{
	_line = line;
	_queue = queue;
	begin();
}

void Parser::begin(void)
{
	std::string tmp;

	if (_line.size() == 0)
		return ;
	if (*_line.begin() == ' ')
		_line.erase(_line.begin());
	while (_line.size() != 0) {
		tmp += *(_line.begin());
		if (*(_line.begin()) == ';') {
			_line.erase(_line.begin());
			tmp.pop_back();
			_new = tmp;
			checkCommand();
			return ;
		}
		_line.erase(_line.begin());
	}
	std::cerr << "ParserCommande: ';' expected "
		  << std::endl;
}

void Parser::checkCommand(void)
{
	std::istringstream iss(_new);
	std::string tmp;

	while (std::getline(iss, tmp , ' ')) {
		_file.push_back(tmp);
	}
	_file.pop_back();
	for (std::vector<std::string>::iterator it = _enumName.begin()
		; it != _enumName.end(); it++) {
		if (*it == tmp) {
			checkFile(it);
			return ;
		}
	}
	std::cerr << "ParserCommande: the information is not a valide type"
		  << std::endl;
}

void Parser::lookFile(void)
{
	for (auto it : _file) {
		std::cout << it << std::endl;
	}
}

void Parser::checkFile(std::vector<std::string>::iterator tmp)
{
	Information info;
	int nb = tmp - _enumName.begin();
	info = static_cast<Information>(nb);
	int i = 0;
	for (auto &it : _file) {
		std::fstream fs;
		fs.open(it.c_str());
		if (fs.is_open() == false) {
			std::cerr << "ParseCommande: File doesn't existe : "
				  << it
				  << std::endl;
			_file.erase(_file.begin() + i);
		}
		fs.close();
		i++;
	}
 	for (auto it : _file){
		 std::pair<std::string, int> go(it, info);
		 _queue->push(go);
	}
	_file.clear();
	begin();
}