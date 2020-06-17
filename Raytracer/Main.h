#pragma once
#include "Tuple.h"
#include "Projectile.h"
#include "Environment.h"
class Main
{
public:
	Projectile tick(Environment e, Projectile p);
};

