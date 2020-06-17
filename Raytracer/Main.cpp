#include "Main.h"
#include <iostream>

int main()
{
	Main m;
	Tuple position = Tuple::point(0, 1, 0);
	Tuple velocity = Tuple::vector(1, 1, 0);
	velocity.normalize();
	Tuple gravity = Tuple::vector(0, -0.1, 0);
	Tuple wind = Tuple::vector(-0.01, 0, 0);

	Projectile p = Projectile(position, velocity);
	Environment e = Environment(gravity, wind);

	while (p.position.y >= 0) {
		p = m.tick(e, p);
		std::cout << p.position << std::endl;
	}
}

Projectile Main::tick(Environment e, Projectile p)
{
	p.position = p.position + p.velocity;
	p.velocity = p.velocity + e.gravity + e.wind;

	return p;
}
