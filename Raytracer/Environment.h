#include "Tuple.h"
#pragma once
class Environment
{
public:
	Tuple gravity, wind;
	Environment(Tuple gravity, Tuple wind)
	{
		this->gravity = gravity;
		this->wind = wind;
	}	
};

