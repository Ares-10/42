#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <ctime>

class PmergeMe {
private:
	std::vector<int>	_input;
	std::vector<int>	_vector;
	std::deque<int>		_deque;

	double				_vector_stopwatch;
	double				_deque_stopwatch;

	PmergeMe();

	void	printBefore() const;
	void	printAfter() const;
	void	printStopwatch() const;

	void	initStopwatch();

	void	sortVector();
	void	sortDeque();

public:
	PmergeMe(std::vector<int> input);

	PmergeMe(PmergeMe const &src);
	~PmergeMe();
	PmergeMe &operator=(PmergeMe const &src);

	void	sort();
	void	printResult() const;
};



#endif //PMERGEME_HPP
