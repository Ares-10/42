#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange bitcoin_exchange = BitcoinExchange("data.csv");

		bitcoin_exchange.calculateFile(argv[1]);
		(void) bitcoin_exchange;
	} catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}

	(void) argv;
}
