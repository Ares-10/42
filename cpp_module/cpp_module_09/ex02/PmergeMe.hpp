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

	std::vector<int>	_jacobsthal;

	PmergeMe();

	void	generateJacobsthal();

	void	printBefore() const;
	void	printAfter() const;
	void	printStopwatch() const;

	void	sortVector();
	void	sortDeque();

	void	fordJohnsonVectorAlgorithm(int node_size);
	void	fordJohnsonDequeAlgorithm(int node_size);

	void	binaryInsertVector(int node_size);
	void	binaryInsertDeque(int node_size);

	void	groupingVector(int node_size);
	void	groupingDeque(int node_size);

public:
	PmergeMe(std::vector<int> input);

	PmergeMe(PmergeMe const &src);
	~PmergeMe();
	PmergeMe &operator=(PmergeMe const &src);

	void	sort();
	void	printResult() const;
};



#endif //PMERGEME_HPP
