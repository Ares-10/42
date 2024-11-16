#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>

typedef struct Data
{
	std::string	str;
	int			n;
	bool		b;
	double		d;
}	Data;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &copy);
	~Serializer();
	Serializer &operator=(const Serializer &src);

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};


#endif //SERIALIZER_HPP
