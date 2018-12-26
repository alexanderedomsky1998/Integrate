#pragma once
#include "Bin_computation.h"
class Integral_Computation {
private:
	double lowwer;
	double upper;
	double result = 0;
	double step;
	static const int n_threads = 4;
public:
	Integral_Computation(double lowwer1, double upper1, double step1) {
		this->lowwer = lowwer1;
		this->upper = upper1;
		this->step = step1;
	}

	double get_value() {
		return result;
	}

	double get_portion_size() {
		return (upper - lowwer) / n_threads;
	}

	void compute(){
		if (lowwer >= upper) {
			return;
		}
		else {
			double portion = get_portion_size();
			pthread_t ThreadArray[n_threads];
			Args* ThreadArgs[n_threads];
			for (int i = 0; i < n_threads; i++) {
				ThreadArgs[i] = new Args();
				ThreadArgs[i]->lowwer = lowwer + i*portion;
				ThreadArgs[i]->upper = lowwer + (i + 1)*portion;
				ThreadArgs[i]->step = step;
				pthread_create(&ThreadArray[i], nullptr, call, ThreadArgs[i]);
			}

			for (int i = 0; i < n_threads; i++){
				while (!pthread_join(ThreadArray[i], NULL))
					result += ThreadArgs[i]->result;
			}
			for (int i = 0; i < n_threads; i++){
				delete ThreadArgs[i];
			}
		}
	}

};
