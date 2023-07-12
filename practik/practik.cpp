#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

double fun(double x)
{
	return sin(x);
}
//double pr9m(double a, double b, ...) {
//	for(i = 1; i <= n; i++)
//	Integral = Integral + h * f(a + h * (i - 0.5));
//  cout << "I1 = " << Integral << "\n";
//	return ...;
//}
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "Russian_Russia.1251 ");
	int i; // счЄтчик
	double Integral; // здесь будет интеграл
	double a = 0.0, b = 1.0; // задаЄм отрезок интегрировани€
	double h = 0.1;// задаЄм шаг интегрировани€
	double n; // задаЄм число разбиений n
	n = (b - a) / h;
	char j;

	cout<<"¬ведите 1 чтобы решить интеграл методом пр€моугольников"<<endl;
	cout<<"¬ведите 2 чтобы решить интеграл методом трапеций"<<endl;
	cout<<"¬ведите 3 чтобы решить интеграл методом —импсона"<<endl;
	cout<<"¬ведите 4 чтобы решить интеграл методом √аусса"<<endl;
	while (true)
	{
		cin>>j;

		switch(j)
		{

		case '1':
			Integral = 0.0;
			for(i = 1; i <= n; i++){
				Integral +=  h * fun(a + h * (i - 0.5));}
			cout << "I1 = " << Integral << "\n";
			break;

		case '2':
			Integral = h * (fun(a) + fun(b)) / 2.0;
			for(i = 1; i <= n-1; i++)
				Integral += h * fun(a + h * i);
			cout << "I2 = " << Integral << "\n";;
			break;

		case '3':
			Integral = h * (fun(a) + fun(b)) / 6.0;
			for(i = 1; i <= n; i++)
				Integral +=  4.0 / 6.0 * h * fun(a + h * (i - 0.5));
			for(i = 1; i <= n-1; i++)
				Integral +=  + 2.0 / 6.0 * h * fun(a + h * i);
			cout << "I3 = " << Integral << "\n";
			break;

			case '4':
			Integral=((b-a)/2)*((fun((a+b)/2)-((b-a)/2*sqrt(3)))+(fun((a+b)/2)+((b-a)/2*sqrt(3))));
			cout << "I4 = " << Integral << "\n";
			break;
			
		default:
			system("PAUSE");
			return 0;
		}
	}
}
