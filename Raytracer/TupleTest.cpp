#include "Tuple.h"
#include <iostream>
#include "TestEngine.h"
using namespace std;

#define T "True"
#define F "False"

void TEST_IsTuplePoint()
{
	float x = 4.3;
	float y = -4.2;
	float z = 3.1;
	float w = 1.0;
	Tuple a = Tuple(x, y, z, w);
	TestEngine::AssertEqual(a.x, x);
	TestEngine::AssertEqual(a.y, y);
	TestEngine::AssertEqual(a.z, z);
	TestEngine::AssertEqual(a.w, w);
	TestEngine::IsTuplePoint(a);
}

void TEST_IsTupleVector()
{
	float x = 4.3;
	float y = -4.2;
	float z = 3.1;
	float w = 0.0;
	Tuple a = Tuple(x, y, z, w);
	TestEngine::AssertEqual(a.x, x);
	TestEngine::AssertEqual(a.y, y);
	TestEngine::AssertEqual(a.z, z);
	TestEngine::AssertEqual(a.w, w);
	TestEngine::IsTupleVector(a);
}

void TEST_PointFunctionCreatesPoint()
{
	float x = 4;
	float y = -4;
	float z = 3;
	float w = 1;
	Tuple a = Tuple(x, y, z, w);
	Tuple b = Tuple::point(x, y, z);
	TestEngine::AssertEqual(a, b);
}

void TEST_VectorFunctionCreatesVector()
{
	float x = 4;
	float y = -4;
	float z = 3;
	float w = 0;
	Tuple a = Tuple(x, y, z, w);
	Tuple b = Tuple::vector(x, y, z);
	TestEngine::AssertEqual(a, b);
}

void TEST_AddTwoTuplesWithAdd()
{
	Tuple a1 = Tuple(3, -2, 5, 1);
	Tuple a2 = Tuple(-2, 3, 1, 0);
	Tuple check = Tuple(1, 1, 6, 1);

	Tuple result = Tuple::add(a1, a2);
	TestEngine::AssertEqual(result, check);
}

void TEST_AddTwoPointsWithAdd()
{
	Tuple p1 = Tuple::point(3, -2, 5);
	Tuple p2 = Tuple::point(-2, 3, 1);
	Tuple check = Tuple(1, 1, 6, 1);
	
	Tuple result = Tuple::add(p1, p2);
	TestEngine::AssertEqual(result, check);
}

void TEST_SubTwoPointsWithSub()
{
	Tuple p1 = Tuple::point(3, 2, 1);
	Tuple p2 = Tuple::point(5, 6, 7);
	Tuple check = Tuple::vector(-2, -4, -6);

	Tuple result = Tuple::sub(p1, p2);
	TestEngine::AssertEqual(result, check);
}

void TEST_SubVectorFromPointWithSub()
{
	Tuple p = Tuple::point(3, 2, 1);
	Tuple v = Tuple::vector(5, 6, 7);
	Tuple check = Tuple::point(-2, -4, -6);

	Tuple result = Tuple::sub(p, v);
	TestEngine::AssertEqual(result, check);
}

void TEST_SubTwoVectorsWithSub()
{
	Tuple v1 = Tuple::vector(3, 2, 1);
	Tuple v2 = Tuple::vector(5, 6, 7);
	Tuple check = Tuple::vector(-2, -4, -6);

	Tuple result = Tuple::sub(v1, v2);
	TestEngine::AssertEqual(result, check);
}

void TEST_NegateVectorWithZeroVector() {
	Tuple zero = Tuple::vector(0, 0, 0);
	Tuple v = Tuple::vector(1, -2, 3);
	Tuple check = Tuple::vector(-1, 2, -3);

	Tuple result = Tuple::sub(zero, v);
	TestEngine::AssertEqual(result, check);
}

void TEST_NegateTupleWithUnaryOperator()
{
	Tuple a = Tuple(1, -2, 3, -4);
	Tuple check = Tuple(-1, 2, -3, 4);

	Tuple result = -a;
	TestEngine::AssertEqual(result, check);
}

void TEST_NegateVectorWithUnaryOperator()
{
	Tuple v = Tuple::vector(1, -2, 3);
	Tuple check = Tuple::vector(-1, 2, -3);

	Tuple result = -v;
	TestEngine::AssertEqual(result, check);
}

void TEST_NegatePointWithUnaryOperator()
{
	Tuple p = Tuple::point(1, -2, 3);
	Tuple check = Tuple::point(-1, 2, -3);

	Tuple result = -p;
	TestEngine::AssertEqual(result, check);
}

void TEST_SubTwoPoints()
{
	Tuple p1 = Tuple::point(3, 2, 1);
	Tuple p2 = Tuple::point(5, 6, 7);
	Tuple check = Tuple::vector(-2, -4, -6);

	Tuple result = p1 - p2;
	TestEngine::AssertEqual(result, check);
}

void TEST_SubVectorFromPoint()
{
	Tuple p = Tuple::point(3, 2, 1);
	Tuple v = Tuple::vector(5, 6, 7);
	Tuple check = Tuple::point(-2, -4, -6);

	Tuple result = p - v;
	TestEngine::AssertEqual(result, check);
}

void TEST_SubTwoVectors()
{
	Tuple v1 = Tuple::vector(3, 2, 1);
	Tuple v2 = Tuple::vector(5, 6, 7);
	Tuple check = Tuple::vector(-2, -4, -6);

	Tuple result = v1 - v2;
	TestEngine::AssertEqual(result, check);
}

void TEST_AddTwoTuples()
{
	Tuple a1 = Tuple(3, -2, 5, 1);
	Tuple a2 = Tuple(-2, 3, 1, 0);
	Tuple check = Tuple(1, 1, 6, 1);

	Tuple result = a1 + a2;
	TestEngine::AssertEqual(result, check);
}

void TEST_AddTwoPoints()
{
	Tuple p1 = Tuple::point(3, -2, 5);
	Tuple p2 = Tuple::point(-2, 3, 1);
	Tuple check = Tuple(1, 1, 6, 1);

	Tuple result = p1 + p2;
	TestEngine::AssertEqual(result, check);
}

void TEST_MultiplyTupleByScalar()
{
	Tuple a = Tuple(1, -2, 3, -4);
	Tuple check = Tuple(3.5, -7, 10.5, -14);

	Tuple result = a * 3.5;
	TestEngine::AssertEqual(result, check);
}

void TEST_MultiplyTupleByFraction()
{
	Tuple a = Tuple(1, -2, 3, -4);
	Tuple check = Tuple(0.5, -1, 1.5, -2);

	Tuple result = a * 0.5;
	TestEngine::AssertEqual(result, check);
}

void TEST_DivideTupleByScalar()
{
	Tuple a = Tuple(1, -2, 3, -4);
	Tuple check = Tuple(0.5, -1, 1.5, -2);

	Tuple result = a / 2;
	TestEngine::AssertEqual(result, check);
}

void TEST_Magnitudesqrt14()
{
	Tuple vec = Tuple::vector(1, 2, 3);
	float magnitude = vec.magnitude();
	TestEngine::AssertEqual(magnitude, sqrt(14));
}

void TEST_Magnitudesqrt14wNegativeNumbers()
{
	Tuple vec = Tuple::vector(-1, -2, -3);
	float magnitude = vec.magnitude();
	TestEngine::AssertEqual(magnitude, sqrt(14));
}

void TEST_NormalizeVector()
{
	Tuple vector = Tuple::vector(4, 0, 0);
	vector.normalize();
	Tuple result = Tuple::vector(1, 0, 0);
	TestEngine::AssertEqual(vector, result);
}

void TEST_NormalizeVectorWithFloatReturnValues()
{

}

void TEST_MagnitudeOfNormalizeVector()
{
	Tuple vec = Tuple::vector(1, 2, 3);
	vec.normalize();
	float mag = vec.magnitude();
	float result = 1;
	TestEngine::AssertEqual(mag, result);
}

int main() {

	//TEST_IsTuplePoint();
	//TEST_IsTupleVector();
	//TEST_PointFunctionCreatesPoint();
	//TEST_VectorFunctionCreatesVector();
	//TEST_AddTwoTuplesWithAdd();
	//TEST_AddTwoPointsWithAdd();
	//TEST_SubTwoPointsWithSub();
	//TEST_SubVectorFromPointWithSub();
	//TEST_SubTwoVectorsWithSub();
	//TEST_NegateVectorWithZeroVector();
	//TEST_NegateTupleWithUnaryOperator();
	//TEST_NegateVectorWithUnaryOperator();
	//TEST_NegatePointWithUnaryOperator();
	//TEST_SubTwoPoints();
	//TEST_SubVectorFromPoint();
	//TEST_SubTwoVectors();
	//TEST_AddTwoTuples();
	//TEST_AddTwoPoints();
	//TEST_MultiplyTupleByScalar();
	//TEST_MultiplyTupleByFraction();
	//TEST_DivideTupleByScalar();
	//TEST_Magnitudesqrt14();
	//TEST_Magnitudesqrt14wNegativeNumbers();
	TEST_NormalizeVector();
	TEST_NormalizeVectorWithFloatReturnValues();
	TEST_MagnitudeOfNormalizeVector();
}