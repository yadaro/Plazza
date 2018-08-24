//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _PARSERFILE_
# define _PARSERFILE_
# define REGEX(line, match, expr) (std::regex_search(line, match, std::regex(expr)))

#include <unordered_map>
#include <functional>
#include <fstream>
#include <string>
#include <regex>
#include <queue>
#include "Plazza.hpp"
#include "SafeQueue.hpp"

class ParserFile {
public:
	ParserFile();
	~ParserFile();
	void run(const std::pair<std::string, int> &cmd,
		SafeQueue &queue);
private:
	bool _checkFile(const std::string &file);
	void _parse(const std::string &, const std::string &,
		SafeQueue &);
	void _close();
	std::unordered_map<int,
		std::string> _expression;
	std::ifstream _ifs;
};

#endif /* _PARSERFILE_ */