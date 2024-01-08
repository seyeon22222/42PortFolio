#include "Serializer.hpp"

int main()
{
	Data	obj;
	Data*	obj_ptr;

	obj.data = "Main Test";
	obj_ptr = Serializer::deserialize(Serializer::serialize(&obj));
	std::cout << "Obj : " << obj.data << std::endl; 
	std::cout << "Obj Ptr : " << obj_ptr->data << std::endl;
}