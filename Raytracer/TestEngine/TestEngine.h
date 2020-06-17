#pragma once
#include <iostream>

#include "../Tuple.h"

#define T "True"
#define F "False"

using namespace std;

class TestEngine
{
public:

    // Test if a tuple is a point
    static void IsTuplePoint(Tuple tuple)
    {
        tuple.w == 1 ? cout << T << endl : cout << F << endl;
    }

    // Test if a tuple is a vector
    static void IsTupleVector(Tuple tuple)
    {
        tuple.w == 0 ? cout << T << endl : cout << F << endl;
    }

    // Test two float values are equal
    static void AssertEqual(float f1, float f2)
    {
        abs(f1 - f2) < EPSILON ? cout << T << endl : cout << F << endl;
    }

    // Test if two tuples are equal
    static void AssertEqual(Tuple t1, Tuple t2)
    {
        t1 == t2 ? cout << T << endl : cout << F << endl;
    }
};