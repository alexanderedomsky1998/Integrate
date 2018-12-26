#pragma once
#include <iostream>
#include "pthread.h"
#include "math.h"
#include <omp.h>
#include <stdio.h>
#include <conio.h>
#include <ctime>
using namespace std;
struct Args
{
	double lowwer;
	double upper;
	double step;
	double result;
	Args(){
		lowwer = 0;
		upper = 0;
		step = 0;
		result = 0;
	}
};
static double get_value(double x) {
	return sin(x)*exp(x + 3);
}

static void* call(void* args){
	auto arg = (Args*)(args);
	while (arg->lowwer <= arg->upper) {
		arg->result += get_value(arg->lowwer) * arg->step;
		arg->lowwer += arg->step;
	}
	return nullptr;
}

double calculation_openMP_bin(double lowwer, double upper, double step, int n_threads)
{
	double result = 0;
	for (double i = lowwer; i < upper; i += step)
	{
		result += get_value(i)*step;
	}
	return result;
}


double calculation_openMP(double lowwer, double upper, double step)
{
	double result = 0;
	unsigned int n_threads = 4;
	omp_set_num_threads(n_threads);

	long i = 0;
	double portion = (upper - lowwer) / n_threads;
#pragma omp parallel reduction(+: result)
	{
#pragma omp for
		for (i = 0; i < n_threads; i++)
		{
			result += calculation_openMP_bin(lowwer + i*portion, lowwer + (i + 1)*portion, step, n_threads);
		}
	}
	return result;
}
