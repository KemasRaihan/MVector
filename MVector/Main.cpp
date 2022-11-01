#include "MVector.h"
#include <iostream>

using namespace std;

int main()
{
#ifdef _DEBUG
	//  _CrtSetBreakAlloc(87);
	_onexit(_CrtDumpMemoryLeaks);
#endif

	MVector* vec1 = new MVector(3);
	vec1->setElement(0, 1.0f);
	vec1->setElement(1, 2.0f);
	vec1->setElement(2, 3.0f);

	cout << "vec1: ";
	vec1->display();

	MVector* vec2 = new MVector(3);
	vec2->setElement(0, 10.0f);
	vec2->setElement(1, 20.0f);
	vec2->setElement(2, 30.0f);

	cout << "vec2: ";
	vec2->display();

	float x = 1.0f;
	const MVector* vec3 = (*vec1) - x;
	//vec3->setElement(0, 1.0f);
	//vec3->setElement(1, 2.0f);
	//vec3->setElement(2, 3.0f);

	cout << "\nvec3: ";
	vec3->display();



	const MVector* vec4 = (*vec1) - vec2;
	cout << "\nvec4: ";
	vec4->display();

	//float d = vec1->dotProduct(vec2);

	//cout << "Dot product is " << d;

	delete vec4;
	delete vec3;
	delete vec2;
	delete vec1;

	return 0;
}