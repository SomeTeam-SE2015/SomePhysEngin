#ifndef _462_LENTHSQUARESPRING_HPP_
#define _462_LENTHSQUARESPRING_HPP_

#include "physics/spring.hpp"

namespace _462 {

class LenthSqSpring: public Spring
{
public:
	LenthSqSpring();
	virtual ~LenthSqSpring() {};
	virtual void apply();
};

}

#endif
