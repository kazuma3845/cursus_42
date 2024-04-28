#include "Serializer.hpp"

int main()
{
	Data a;
	a.valInt = 42;
	uintptr_t p = Serializer::serialize(&a);
	std::cout << "Serializer : " << p << std::endl;
	Data *d = Serializer::deserialize(p);
	std::cout << "Deserializer (Int): " << d->valInt << std::endl;
	return 0;
}
