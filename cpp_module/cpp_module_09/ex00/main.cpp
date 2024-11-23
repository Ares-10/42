#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange bitcoin_exchange = BitcoinExchange("_data.csv");
		(void) bitcoin_exchange;
	} catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	(void) argv;
}
