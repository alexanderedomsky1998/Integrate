package new_package;

import java.util.ArrayList;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;
import java.util.concurrent.FutureTask;

public class Integral_Computation {
	private double lowwer;
	private double upper;
	private Function f;
	private double result = 0;
	private double step;
	private int n_threads = 50;

	Integral_Computation(double lowwer1, double upper1, double step1, Function f1) {
		this.lowwer = lowwer1;
		this.upper = upper1;
		this.f = f1;
		this.step = step1;
	}

	double get_value() {
		return result;
	}

	double get_portion_size() {
		return (upper - lowwer) / n_threads;
	}

	void computation() throws InterruptedException, ExecutionException {
		if (lowwer >= upper) {
			return;
		} else {
			double portion = get_portion_size();
			ArrayList<Future> results = new ArrayList<Future>();
			for (int i = 0; i < n_threads; i++) {
				Bin_computation item = new Bin_computation(lowwer, lowwer + portion, step, f);
				FutureTask task = new FutureTask(item);
				results.add(task);
				Thread t = new Thread(task);
				t.start();
				lowwer += portion;
			}
			for (int i = 0; i < n_threads; i++) {
				while (!results.get(i).isDone()) {

				}
			}
			for (Future res : results)
				try {
					result += (double) res.get();
				} catch (ExecutionException e) {
					e.printStackTrace();
				}
		}
	}

}
