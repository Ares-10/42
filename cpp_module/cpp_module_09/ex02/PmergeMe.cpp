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
	_jacobsthal = src._jacobsthal;
	return *this;
}

void PmergeMe::generateJacobsthal()
{
	int next;
	size_t sum;

	sum = 4;
	_jacobsthal.push_back(2);
	_jacobsthal.push_back(2);
	while (sum < _input.size())
	{
		next = _jacobsthal.back() + 2 * _jacobsthal[_jacobsthal.size() - 2];
		_jacobsthal.push_back(next);
		sum += next;
	}
}

PmergeMe::PmergeMe(std::vector<int> input)
{
	_input = input;
	_vector = _input;
	for (size_t i = 0; i < _input.size(); i++)
		_deque.push_back(_input[i]);
	_vector_stopwatch = 0;
	_deque_stopwatch = 0;
	generateJacobsthal();
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
	{
		if (_vector[i] != _deque[i])
			exit(1);
		std::cout << _vector[i] << " ";
	}
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

/** ===================== Vector ===================== */

void PmergeMe::sortVector()
{
	fordJohnsonVectorAlgorithm(1);
}

void PmergeMe::fordJohnsonVectorAlgorithm(int node_size)
{
	if (node_size != 1)
		groupingVector(node_size);
	if (node_size * 2 <= static_cast<int>(_vector.size()))
	{
		fordJohnsonVectorAlgorithm(node_size * 2);
		binaryInsertVector(node_size);
	}
}

static void moveVector(std::vector<int> &a, std::vector<int> &b, int apos, int bpos, int size)
{
	apos = apos * size;
	bpos = bpos * size;
	for (int i = 0; i < size; i++)
		a.insert(a.begin() + apos + i, b[bpos + i]);
	b.erase(b.begin() + bpos, b.begin() + bpos + size);
}

static int binarySearchVector(const std::vector<int> &a, int n, int left, int right, int node_size)
{
	int mid;

	mid = (left + right) / 2;
	if (right <= left)
	{
		if (a[right * node_size] < n)
			return right + 1;
		return left;
	}
	if (a[mid * node_size] > n)
		return binarySearchVector(a, n, left, mid, node_size);
	if (a[mid * node_size] < n)
		return binarySearchVector(a, n, mid + 1, right, node_size);
	return mid;
}

void PmergeMe::binaryInsertVector(int node_size)
{
	std::vector<int> a((_input.size() / node_size / 2) * node_size);
	std::vector<int> b((_input.size() - a.size()) / node_size * node_size);
	size_t i;
	size_t j;
	int pos;

	for (i = 0; i < a.size() / node_size; i++)
	{
		for (int k = 0; k < node_size; k++)
			a[i * node_size + k] = _vector[i * 2 * node_size + k];
		for (int k = 0; k < node_size; k++)
			b[i * node_size + k] = _vector[(i * 2 + 1) * node_size + k];
	}
	for (i = a.size(); i < b.size(); i++)
		b[i] = _vector[a.size() + i];

	moveVector(a, b, 0, 0, node_size);
	j = 0;
	i = 0;
	while (true)
	{
		if (j == 0)
			j = std::min(static_cast<int>(b.size()) / node_size, _jacobsthal[i++]);
		pos = binarySearchVector(a, b[--j * node_size], 0, a.size() / node_size - 1, node_size);
		moveVector(a, b, pos, j, node_size);
		if (b.empty())
		{
			for (i = 0; i < a.size(); i++)
				_vector[i] = a[i];
			return;
		}
	}
}

void PmergeMe::groupingVector(int node_size)
{
	for (size_t i = 0; i + node_size < _vector.size(); i += node_size)
		if (_vector[i] < _vector[i + node_size / 2])
			for (int j = 0; j < node_size / 2; j++)
				std::swap(_vector[i + j], _vector[i + j + node_size / 2]);
}

/** ===================== Deque ===================== */

void PmergeMe::sortDeque()
{
	fordJohnsonDequeAlgorithm(1);
}

void PmergeMe::fordJohnsonDequeAlgorithm(int node_size)
{
	if (node_size != 1)
		groupingDeque(node_size);
	if (node_size * 2 <= static_cast<int>(_deque.size()))
	{
		fordJohnsonDequeAlgorithm(node_size * 2);
		binaryInsertDeque(node_size);
	}
}

static void moveDeque(std::deque<int> &a, std::deque<int> &b, int apos, int bpos, int size)
{
	apos = apos * size;
	bpos = bpos * size;
	for (int i = 0; i < size; i++)
		a.insert(a.begin() + apos + i, b[bpos + i]);
	b.erase(b.begin() + bpos, b.begin() + bpos + size);
}

static int binarySearchDeque(const std::deque<int> &a, int n, int left, int right, int node_size)
{
	int mid;

	mid = (left + right) / 2;
	if (right <= left)
	{
		if (a[right * node_size] < n)
			return right + 1;
		return left;
	}
	if (a[mid * node_size] > n)
		return binarySearchDeque(a, n, left, mid, node_size);
	if (a[mid * node_size] < n)
		return binarySearchDeque(a, n, mid + 1, right, node_size);
	return mid;
}

void PmergeMe::binaryInsertDeque(int node_size)
{
	std::deque<int> a((_input.size() / node_size / 2) * node_size);
	std::deque<int> b((_input.size() - a.size()) / node_size * node_size);
	size_t i;
	size_t j;
	int pos;

	for (i = 0; i < a.size() / node_size; i++)
	{
		for (int k = 0; k < node_size; k++)
			a[i * node_size + k] = _deque[i * 2 * node_size + k];
		for (int k = 0; k < node_size; k++)
			b[i * node_size + k] = _deque[(i * 2 + 1) * node_size + k];
	}
	for (i = a.size(); i < b.size(); i++)
		b[i] = _deque[a.size() + i];

	moveDeque(a, b, 0, 0, node_size);
	j = 0;
	i = 0;
	while (true)
	{
		if (j == 0)
			j = std::min(static_cast<int>(b.size()) / node_size, _jacobsthal[i++]);
		pos = binarySearchDeque(a, b[--j * node_size], 0, a.size() / node_size - 1, node_size);
		moveDeque(a, b, pos, j, node_size);
		if (b.empty())
		{
			for (i = 0; i < a.size(); i++)
				_deque[i] = a[i];
			return;
		}
	}
}

void PmergeMe::groupingDeque(int node_size)
{
	for (size_t i = 0; i + node_size < _deque.size(); i += node_size)
		if (_deque[i] < _deque[i + node_size / 2])
			for (int j = 0; j < node_size / 2; j++)
				std::swap(_deque[i + j], _deque[i + j + node_size / 2]);
}
