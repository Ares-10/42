#include <iostream>
#include <fstream>
#include <cstring>

static void puterr(std::string msg)
{
	std::cout << msg << std::endl;
	exit(EXIT_FAILURE);
}

static void replace_str(std::string &str, const std::string& s1, const std::string& s2)
{
	std::string front_str;
	std::string back_str;
	size_t pos;

	pos = str.find(s1);
	if (pos == std::string::npos)
		return;
	front_str = str.substr(0, pos);
	back_str = str.substr(pos + s1.length(), str.length());
	replace_str(back_str, s1, s2);
	str = front_str + s2 + back_str;
}

static void readfile(const std::string &filename, std::string &str)
{
	std::fstream file;
	char ch;

	file.open(filename, std::ios::in);
	if (!file.is_open())
		puterr("Error: can not open file");
	while (1)
	{
		file.get(ch);
		if (file.eof())
			break ;
		str += ch;
	}
	file.close();
}

static void writefile(const std::string &filename, const std::string &str)
{
	std::fstream file;

	file.open(filename, std::ios::out);
	if (!file.is_open())
		puterr("Error: can not open file");
	for (size_t i = 0; i < str.length(); i++)
		file.put(str.at(i));
	file.close();
}

static void check_arg(int argc, char **argv)
{
	if (argc != 4)
		puterr("usage: <filename> s1 s2");
	if (strcmp(argv[2], "") == 0)
		puterr("usage: <filename> s1 s2\ns1 can not be empty string");
}

int main(int argc, char **argv)
{
	std::string str;

	check_arg(argc, argv);
	readfile(argv[1], str);
	replace_str(str, argv[2], argv[3]);
	writefile(std::string(argv[1]) + ".replace", str);
}
