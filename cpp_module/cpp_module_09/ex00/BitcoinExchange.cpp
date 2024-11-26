#include "BitcoinExchange.hpp"

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
		throw std::out_of_range("invalid date value => " + str);

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		daysInMonth[1] = 29;
	}

	if (!(day >= 1 && day <= daysInMonth[month - 1]))
		throw std::out_of_range("invalid date value => " + str);;
}

static void checkValidDateFormat(const std::string &str)
{
	if (str.size() != 10)
		throw std::invalid_argument("invalid date format => " + str);
	if (!(std::isdigit(str[0]) && std::isdigit(str[1])
		&& std::isdigit(str[2]) && std::isdigit(str[3])
		&& str[4] == '-'
		&& std::isdigit(str[5]) && std::isdigit(str[6])
		&& str[7] == '-'
		&& std::isdigit(str[8]) && std::isdigit(str[9])))
		throw std::invalid_argument("invalid date format => " + str);
}

static std::string getDate(const std::string &str)
{
	checkValidDateFormat(str);
	checkValidDate(str);
	return str;
}

static float convertStringToFloat(const std::string& input) {
	if (input.empty())
		throw std::runtime_error("bad input => " + input);

	if (input[0] == '-')
		throw std::runtime_error("not a positive number.");

	size_t dotPos = input.find('.');
	std::string integerPart = (dotPos == std::string::npos) ? input : input.substr(0, dotPos);
	std::string decimalPart = (dotPos == std::string::npos) ? "" : input.substr(dotPos + 1);

	if (dotPos != std::string::npos) {
		if (decimalPart.empty())
			throw std::runtime_error("bad input => " + input);
		if (decimalPart.length() > 2)
			throw std::runtime_error("bad input => " + input);
	}

	for (size_t i = 0; i < integerPart.length(); ++i)
		if (!isdigit(integerPart[i]))
			throw std::runtime_error("bad input => " + input);

	for (size_t i = 0; i < decimalPart.length(); ++i)
		if (!isdigit(decimalPart[i]))
			throw std::runtime_error("bad input => " + input);

	std::istringstream iss(input);
	float value;
	iss >> value;

	if (iss.fail())
		throw std::runtime_error("bad input => " + input);
	return value;
}

static float getValue(const std::string &str)
{
	if (str.size() < 12 || str[10] != ',')
		throw std::invalid_argument("invalid value format => " + str);
	return convertStringToFloat(str.substr(11));
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
		throw std::runtime_error("invalid header in file.");

	while (std::getline(file, line))
	{
		date = getDate(line.substr(0, 10));
		value = getValue(line);
		_map.insert(std::make_pair(date, value));
	}
	file.close();
}

static void checkValidInputFormat(const std::string &line)
{
	if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		throw std::invalid_argument("bad input => " + line);
}

float BitcoinExchange::findPriceByDate(const std::string &date)
{
	if (_map.begin()->first > date)
		throw std::runtime_error("data not exist.");
	for (std::map<std::string, float>::const_reverse_iterator it = _map.rbegin(); it != _map.rend(); ++it)
		if (it->first <= date)
			return it->second;
	throw std::runtime_error("data not exist.");
}

void BitcoinExchange::calculateAndPrint(const std::string &line)
{
	float value;
	float price;
	std::string date;

	try
	{
		checkValidDate(line.substr(0, 10));
		checkValidInputFormat(line);
		date = line.substr(0, 10);
		value = convertStringToFloat(line.substr(13));
		if (value > 1000.0f)
			throw std::runtime_error("too large a number.");
		price = findPriceByDate(date);
		std::cout << date << " => " << value << " = " << price * value << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void BitcoinExchange::calculateFile(const std::string &filename)
{
	std::fstream file;
	std::string line;

	file.open(filename);
	if (!file.is_open())
		throw std::runtime_error("can not open file");

	std::getline(file, line);
	if (line != "date | value")
		throw std::runtime_error("invalid header in file.");

	while (std::getline(file, line))
		calculateAndPrint(line);
}
