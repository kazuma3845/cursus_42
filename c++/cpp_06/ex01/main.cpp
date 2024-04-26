#include "Serializer.hpp"

int main()
{
	Data a;
	a.valInt = 42;
	a.valStr = "Test";
	uintptr_t p = Serializer::serialize(&a);
	std::cout << "Serializer : " << p << std::endl;
	Data *d = Serializer::deserialize(p);
	std::cout << "Deserializer (Int): " << d->valInt << std::endl;
	std::cout << "Deserializer (Str): " << d->valStr << std::endl;
	return 0;
}
