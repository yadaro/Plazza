//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "ParserFile.hpp"

ParserFile::ParserFile()
{
	_expression = {
		{PHONE_NUMBER, "([0-9] *){10}"},
		{EMAIL_ADDRESS, "[a-zA-Z0-9_.-]+@[a-zA-Z0-9_.-]+\\.[a-zA-Z]+"},
		{IP_ADDRESS, "((2[0-5][0-5]|1[0-9][0-9]|0?[0-9]{1,2})\\.){3}(2[0-5][0-5]|1[0-9][0-9]|0?[0-9]{1,2})"}
	};
}

ParserFile::~ParserFile()
{}

void ParserFile::run(const std::pair<std::string, int> &cmd, SafeQueue &queue)
{
	_parse(cmd.first, _expression[cmd.second], queue);
}

bool ParserFile::_checkFile(const std::string &file)
{
	_ifs.open(file, std::ifstream::in);
	if (_ifs.is_open() == true)
		return true;
	else
		return false;
}

void ParserFile::_close()
{
	_ifs.close();
}

void ParserFile::_parse(const std::string &file, const std::string &expr,
	SafeQueue &queue)
{
	std::string line;
	std::string tmp;
	std::smatch match;
	std::queue<std::string> &scrapQueue = queue.getScrap();

	if (_checkFile(file) == true) {
		for (unsigned int i = 1; std::getline(_ifs, line) ; ++i) {
			if (REGEX(line, match, expr) == true) {
				// tmp = "file " + file + ", line " +
				// 	std::to_string(i) + ", match : " +
				// 	std::string(match[0]);
				tmp = std::string(match[0]);
				// std::cout << tmp << std::endl;
				scrapQueue.push(tmp);
			}
		}
		queue.incFileScraped();
		_close();
	} else
		std::cout << "ParserFile: sorry couldn't open file" << std::endl;
}