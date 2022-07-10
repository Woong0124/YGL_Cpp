#include "VecF.h"

VecF::VecF(int d, float* a) : n{ d }
{
	arr = new float[d];	// d의 수만큼 float arr 배열 생성
	if (a) memcpy(arr, a, sizeof(float) * n);	// arr에 a값을 sizeof(float)*n 만큼 복사
}

VecF::VecF(const VecF& fv) : n{ fv.n }
{
	arr = new float[n];
	memcpy(arr, fv.arr, sizeof(float) * n);
}

VecF::~VecF()
{
	delete[] arr;
}

VecF VecF::add(const VecF& fv) const
{
	VecF tmp{ n };
	for (int i = 0; i < n; ++i)
	{
		tmp.arr[i] = arr[i] + fv.arr[i];
	}
	return tmp;
}

void VecF::Print() const
{
	cout << "[ ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
		cout << " ]";
	}
}
