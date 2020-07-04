#pragma once
class testingClass
{
public:
	testingClass();
	testingClass(float val) { value = val; }
	~testingClass();
	float value;

	inline testingClass operator+(float val) { return testingClass(value + val); }
};

