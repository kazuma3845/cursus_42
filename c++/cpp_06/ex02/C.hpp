#pragma once

# include "Base.hpp"

class C : public Base
{
	public:
		Base * generate(void);
		void identify(Base* p);
		void identify(Base& p);
};
