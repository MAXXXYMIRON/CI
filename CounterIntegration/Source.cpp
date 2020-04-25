#include <iostream>
#include <cmath>

using namespace std;

float fa(float x)
{
	return 1 / sqrt((3 * x * x) + 1);
}

float fb(float x)
{
	return log2((x * x) + 2) / (x + 1);
}


int main()
{
	setlocale(0, "");

	//Метод трапеций
	float a = 0.8,
		b = 1.8,
		h = 0.001,
		n = 7,
		W = 0;
	for (int i = 1; i <= n; i++)
	{
		W += (fa(a + ((i - 1) * h)) + 
			fa(a + (i * h)));
	}
	W *= h / 2;

	cout << W << endl;

	//Метод Симпсона
	float m = 8 / 2;
	a = 0.4; 
	b = 1.2;
	float S = 0;

	for (int i = 1; i <= m; i++)
	{
		S += fb(a + (((2 * i) - 2) * h)) + 
			(4 * fb(a + (((2 * i) - 1) * h))) + 
			fb(a + (2 * i * h));
	}
	S *= h / 3;

	cout << S << endl;

	system("pause");
	return 0;
}
