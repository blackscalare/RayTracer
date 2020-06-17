#include "Tuple.h"
Tuple::Tuple()
{
}
Tuple::Tuple(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Tuple::~Tuple()
{
}

Tuple Tuple::point(float x, float y, float z)
{
	return Tuple(x, y, z, 1);
}

Tuple Tuple::vector(float x, float y, float z)
{
	return Tuple(x, y, z, 0);
}

Tuple Tuple::add(Tuple t1, Tuple t2)
{
	float x = t1.x + t2.x;
	float y = t1.y + t2.y;
	float z = t1.z + t2.z;
	float w = t1.w + t2.w;
	if (w > 1)
		w = 1;
	return Tuple(x, y, z ,w);
}

Tuple Tuple::sub(Tuple t1, Tuple t2)
{
	float x = t1.x - t2.x;
	float y = t1.y - t2.y;
	float z = t1.z - t2.z;
	float w = t1.w - t2.w;
	return Tuple(x, y, z, w);
}

float Tuple::dot(Tuple t1, Tuple t2)
{
	float dot = -1;

	if (t1.isVector() && t2.isVector())
		dot = (t1.x * t2.x) + (t1.y * t2.y) + (t1.z * t2.z);
	else
		throw "Dot product requires two vectors.";

	return dot;
}

Tuple Tuple::cross(Tuple a, Tuple b)
{
	return vector(a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z, 
		a.x * b.y - a.y * b.x);
}

float Tuple::magnitude()
{
	
	float v = -1;
	/*if(w == 0 || w == 1)
		v = sqrt(pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0) + w);
	else
		v = sqrt(pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0) + pow(w, 2.0));*/
	if (isVector())
		v = sqrt(pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0) + w);
	else
		throw "Trying to get magnitude of something else than a vector.";
	
	return v;
}

Tuple Tuple::normalize()
{
	float magnitude = -1;
	if (!isVector())
		throw "Trying to normalize something else than a vector.";
	else {
		magnitude = this->magnitude();
		x = x / magnitude;
		y = y / magnitude;
		z = z / magnitude;
	}
}
