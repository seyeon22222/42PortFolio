#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>


struct Data
{
	std::string data;
};



class Serializer
{
private:
	Serializer();
public:
	~Serializer();
	Serializer(const Serializer& obj);
	Serializer &operator=(const Serializer& obj);
	// intptr_t -> 포인터의 주소를 저장하는 변수타입
	// uintptr_t -> unsigned 타입으로 포인터의 주소를 저장
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif