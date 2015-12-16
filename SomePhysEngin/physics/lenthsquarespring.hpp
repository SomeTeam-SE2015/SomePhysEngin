#ifndef _SomeEngin_LENTHSQUARESPRING_HPP_
#define _SomeEngin_LENTHSQUARESPRING_HPP_

#include "physics/spring.hpp"

namespace _SomeEngin {

class LenthSqSpring: public Spring
{
public:
	LenthSqSpring();
    virtual ~LenthSqSpring() {}
	virtual void apply();
};

}

#endif
