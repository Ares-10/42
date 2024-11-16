#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
private:
	unsigned int _n;
	T *_array;

public:
	Array() : _n(0), _array(NULL)
	{
	}

	Array(unsigned int n) : _n(n)
	{
		_array = new T[n]();
	}

	Array(Array const &obj) : _n(0), _array(NULL)
	{
		*this = obj;
	}

	~Array()
	{
		delete[] _array;
	}

	Array &operator=(Array const &obj)
	{
		if (this != &obj)
		{
			delete[] _array;
			_n = obj._n;
			_array = new T[_n];
			for (unsigned int i = 0; i < _n; i++)
				_array[i] = obj._array[i];
		}
		return (*this);
	}

	unsigned int size() const
	{
		return _n;
	}

	T &operator[](unsigned int i)
	{
		if (i >= _n)
			throw std::out_of_range("Index out of bounds");
		return (_array[i]);
	}
};

#endif //ARRAY_HPP
