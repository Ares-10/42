#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vector_stopwatch(0), _deque_stopwatch(0)
{
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(PmergeMe const &src)
{
	if (this == &src)
		return *this;
	_vector = src._vector;
	_deque = src._deque;
	_vector_stopwatch = src._vector_stopwatch;
	_deque_stopwatch = src._deque_stopwatch;
	return *this;
}

PmergeMe::PmergeMe(std::vector<int> input)
{
	_input = std::move(input);
	_vector_stopwatch = 0;
	_deque_stopwatch = 0;
}

void PmergeMe::printBefore() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _input.size(); i++)
		std::cout << _input[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
	std::cout << "After: ";
	for (size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printStopwatch() const
{
	std::cout << "Time to process a range of " << _input.size()
			<< " elements with std::vector : " << _vector_stopwatch << " us:" << std::endl;
	std::cout << "Time to process a range of " << _input.size()
			<< " elements with std::deque : " << _deque_stopwatch << " us:" << std::endl;
}

void PmergeMe::printResult() const
{
	printBefore();
	printAfter();
	printStopwatch();
}

void PmergeMe::initStopwatch()
{
	_vector_stopwatch = 0;
	_deque_stopwatch = 0;
}

void PmergeMe::sort()
{
	clock_t start_time;
	clock_t end_time;

	start_time = clock();
	sortVector();
	end_time = clock();
	_vector_stopwatch = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1e6;
	start_time = clock();
	sortDeque();
	end_time = clock();
	_deque_stopwatch = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1e6;
}

void PmergeMe::sortVector()
{
}

void PmergeMe::sortDeque()
{
}
