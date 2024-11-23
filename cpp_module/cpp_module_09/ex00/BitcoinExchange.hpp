#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange {
private:
	std::map<std::string, float> _map;

	BitcoinExchange();
	float findPriceByDate(const std::string &date);
	void calculateAndPrint(const std::string &line);

public:
	BitcoinExchange(const std::string &filename);
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange();
	BitcoinExchange &operator=(BitcoinExchange const &src);

	void calculateFile(const std::string &filename);
};



#endif //BITCOINEXCHANGE_HPP
