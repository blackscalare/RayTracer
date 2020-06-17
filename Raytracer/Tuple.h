#pragma once
#include <cmath>
#include <ostream>
#define EPSILON 0.00001

class Tuple
{
public:
	Tuple(float x, float y, float z, float w);
	~Tuple();

	static Tuple point(float x, float y, float z);
	static Tuple vector(float x, float y, float z);
	static Tuple add(Tuple t1, Tuple t2);
	static Tuple sub(Tuple t1, Tuple t2);
	float magnitude();
	Tuple normalize();
	float x, y, z, w;

	bool operator==(const Tuple& t) const {
		if (std::abs(x - t.x) > EPSILON|| abs(y - t.y) > EPSILON || abs(z - t.z) > EPSILON || abs(w - t.w) > EPSILON)
			return false;
		else
			return true;
	}

	Tuple operator-() const{
		if (w == 0)
			return Tuple(-x, -y, -z, 0);
		else if (w == 1)
			return Tuple(-x, -y, -z, 1);
		else
			return Tuple(-x, -y, -z, -w);
	}

	Tuple operator-(const Tuple& t) const {
		return Tuple(x - t.x, y - t.y, z - t.z, w - t.w);
	}

	Tuple operator+(const Tuple& t) const {
		float _x = x + t.x;
		float _y = y + t.y;
		float _z = z + t.z;
		float _w = w + t.w;
		if (_w > 1)
			_w = 1;
		return Tuple(_x, _y, _z, _w);
	}

	Tuple operator*(float f) const {
		if (w == 0 || w == 1)
			return Tuple(x * f, y * f, z * f, w);
		else
			return Tuple(x * f, y * f, z * f, w * f);
	}

	Tuple operator/(float f) const {
		if (w == 0 || w == 1)
			return Tuple(x / f, y / f, z / f, w);
		else
			return Tuple(x / f, y / f, z / f, w / f);
	}

	friend std::ostream& operator << (std::ostream& out, const Tuple& tuple) {
		out << "x: " << tuple.x << " y: " << tuple.y << " z: " << tuple.z << " w: " << tuple.w;
		return out;
	}
private:
	bool isVector() { return !w; };
	bool isPoint() { return w; };
};



