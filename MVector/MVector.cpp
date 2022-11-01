#include "MVector.h"
#include <iostream>
#include <crtdbg.h>

using namespace std;

MVector::MVector(int size) : size(size)
{
	data = (float*)malloc(sizeof(float) * size);
}

MVector::~MVector()
{
	free(data);
}


void MVector::display() const
{
	cout << "\n[";
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << ",";
	}
	cout << "]\n";
}


float MVector::calculateMagnitude()
{
	float sumOfSquares = 0;

	for (int i = 0; i < size; i++)
	{
		sumOfSquares += data[i] * data[i];
	}

	float magnitude = sqrt(sumOfSquares);
	//cout << "\nMagnitude is " << magnitude;

	return magnitude;
}

MVector* MVector::normalise()
{
	MVector* result = new MVector(size);
	for (int i = 0; i < size; i++)
	{
		result->data[i] = data[i] / calculateMagnitude();
	}

	return result;
}

float MVector::dotProduct(MVector* rhs)
{
	float result = 0;

	if (size == rhs->size)
	{
		for (int i = 0; i < size; i++)
		{
			result += data[i] * rhs->data[i];
		}
		return result;
	}

	return -1;
}

bool MVector::operator==(const MVector* rhs)
{
	if (size == rhs->size)
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] != rhs->data[i])
				return false;
		}
		return true;
	}
	return false;
}

//bool MVector::operator!=(const MVector* rhs) const
//{
//	return !(*this == rhs);
//}

bool MVector::operator!=(const MVector* rhs) const
{
	if (size == rhs->size)
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] != rhs->data[i])
				return true;
		}
		return false;
	}
	return true;
}

const MVector* MVector::operator+(const float x) const
{
	MVector* result = new MVector(size);
	for (int i = 0; i < size; i++)
	{
		result->data[i] = data[i] + x;
	}
	return result;
}

const MVector* MVector::operator-(const float x) const
{
	MVector* result = new MVector(size);
	for (int i = 0; i < size; i++)
	{
		result->data[i] = data[i] - x;
	}
	return result;
}

const MVector* MVector::operator-(const MVector* rhs) const
{
	MVector* result = new MVector(size);
	if (size == rhs->size)
	{
		for (int i = 0; i < size; i++)
		{
			result->data[i] = data[i] - rhs->data[i];
		}
		return result;
	}

	return nullptr;
}


