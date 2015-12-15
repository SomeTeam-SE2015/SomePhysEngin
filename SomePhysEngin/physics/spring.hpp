#ifndef _462_SPRING_HPP_
#define _462_SPRING_HPP_

#include "physics/body.hpp"

namespace _462 {

class Spring
{
public:
    Spring();
    virtual ~Spring() {};
    virtual void apply();
	inline Vector3 display(){
		Vector3 x1 = body1->position + body1->orientation * body1_offset;
		Vector3 x2 = body2->position + body2->orientation * body2_offset;
		return x2 - x1;
	}

    real_t constant;
    real_t equilibrium;
    real_t damping;
    Body* body1;
    Body* body2;
    Vector3 body1_offset;
    Vector3 body2_offset;
};

}

#endif
