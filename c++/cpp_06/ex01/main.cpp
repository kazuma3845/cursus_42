#include "Serializer.hpp"

int main()
{
	Data a;
	uintptr_t p = Serializer::serialize(&a);
	std::cout << "Serializer : " << p << std::endl;
	Data *d = Serializer::deserialize(p);
	std::cout << "Deserializer (Int): " << d->valInt << std::endl;
	std::cout << "Deserializer (Str): " << d->valStr << std::endl;
	return 0;
}
