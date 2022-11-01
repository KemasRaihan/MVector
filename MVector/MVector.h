#pragma once
struct AddValue
{
	float x;
};

class MVector
{
private:
	int size;
	float* data;

public:
	MVector(int size);
	~MVector();

	inline void setElement(int index, float item);

	void display() const;

	float calculateMagnitude();
	MVector* normalise();
	float dotProduct(MVector* rhs);

	// v1 == v2
	bool operator==(const MVector* rhs);

	// v1 != v2
	bool operator!=(const MVector* rhs) const;

	// v1 = v1 + x;
	const MVector* operator+(const float x) const;

	// v3 = v1 + v2
	const MVector* operator+(const MVector* rhs) const;

	// v2 = v1 - x;
	const MVector* operator-(const float x) const;

	// v3 = v1 - v2;
	const MVector* operator-(const MVector* rhs) const;
};

inline void MVector::setElement(int index, float item)
{
	if (index >= 0 && index < size) data[index] = item;
}

