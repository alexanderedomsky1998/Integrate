// Pthread.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "vld.h"
#include "Integral_Computation.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	double lowwer;
	double upper;
	cout << "Enter lowwer boarder:" << endl;
	cin >> lowwer;
	cout << "Enter upper boarder:" << endl;
	cin >> upper;
	Integral_Computation integral(lowwer, upper, 0.000001);
	unsigned int start_time = clock();
	integral.compute();
	unsigned int end_time = clock();
	cout << "Pthread integral computation result:" << integral.get_value() << " " << "Computation time:" << end_time - start_time << endl;
	start_time = clock();
	cout << "OpenMP integral computation result:" << calculation_openMP(lowwer, upper, 0.000001) << endl;
	end_time = clock();
	cout << "Computation time:" << end_time - start_time << endl;
	//omp_set_num_threads(4);
	/*
	#pragma omp parallel
	{
	cout << "Hello" << endl;
	}
	*/
	_getch();
}
