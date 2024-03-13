#include "Harl.hpp"

int main()
{
	Harl a;
	a.complain("ERROR");
	a.complain("WARNING");
	a.complain("INFO");
	a.complain("DEBUG");
	a.complain("JAMBON");
	return 0;
}
