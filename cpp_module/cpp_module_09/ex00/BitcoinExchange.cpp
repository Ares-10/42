#include "BitcoinExchange.hpp"

#include <iostream>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this == &src)
		return *this;
	return *this;
}

static void checkValidDate(std::string str)
{
	int year = std::atoi(str.substr(0, 4).c_str());
	int month = std::atoi(str.substr(5, 2).c_str());
	int day = std::atoi(str.substr(8, 2).c_str());

	if (year < 1 || year > 9999 || month < 1 || month > 12)
		throw std::out_of_range("Invalid date value => " + str);

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		daysInMonth[1] = 29;
	}

	if (!(day >= 1 && day <= daysInMonth[month - 1]))
		throw std::out_of_range("Invalid date value => " + str);;
}

static void checkValidDateFormat(const std::string &str)
{
	if (str.size() != 10)
		throw std::invalid_argument("Invalid date format => " + str);
	if (!(std::isdigit(str[0]) && std::isdigit(str[1])
		&& std::isdigit(str[2]) && std::isdigit(str[3])
		&& str[4] == '-'
		&& std::isdigit(str[5]) && std::isdigit(str[6])
		&& str[7] == '-'
		&& std::isdigit(str[8]) && std::isdigit(str[9])))
		throw std::invalid_argument("Invalid date format => " + str);
}

static std::string getDate(const std::string &str)
{
	checkValidDateFormat(str);
	checkValidDate(str);
	return str;
}

static void checkValidFloat(const std::string &str)
{
	bool dot = false;

	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] == '.')
		{
			if (dot)
				throw std::invalid_argument("Failed to parse value => " + str);
			dot = true;
		} else if (!std::isdigit(str[i]))
			throw std::invalid_argument("Failed to parse value => " + str);
	}
}

static float getValue(const std::string &str)
{
	std::string valueStr;

	if (str.empty() || str[0] != ',')
		throw std::invalid_argument("Invalid value format => " + str);
	valueStr = str.substr(1);
	checkValidFloat(valueStr);
	return std::atof(valueStr.c_str());
}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	std::fstream file;
	std::string date;
	float value;
	std::string line;

	file.open(filename);
	if (!file.is_open())
		throw std::runtime_error("can not open file");

	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Invalid header in file.");

	while (std::getline(file, line))
	{
		date = getDate(line.substr(0, 10));
		value = getValue(line.substr(10));
		_map.insert(std::make_pair(date, value));
	}
	file.close();
}
