#include "Tuple.h"
#pragma once
class Projectile
{
public:
	Tuple position, velocity;
	Projectile(Tuple position, Tuple velocity)
	{
		this->position = position;
		this->velocity = velocity;
	}
};

