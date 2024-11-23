#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <fstream>

class BitcoinExchange {
private:
	std::map<std::string, float> _map;

	BitcoinExchange();

public:
	BitcoinExchange(const std::string &filename);
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange();
	BitcoinExchange &operator=(BitcoinExchange const &src);
};



#endif //BITCOINEXCHANGE_HPP
