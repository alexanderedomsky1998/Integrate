package new_package;

import java.util.concurrent.Callable;

public class Bin_computation implements Callable {
	private Function f;
	private double lowwer;
	private double upper;
	private double step;

	Bin_computation(double lowwer, double upper, double step, Function f) {
		this.f = f;
		this.lowwer = lowwer;
		this.upper = upper;
		this.step = step;
	}

	double get_value(double x) {
		return f.get_function_value(x);
	}

	@Override
	public Double call() throws Exception {
		// TODO Auto-generated method stub
		double result = 0;
		while (this.lowwer <= this.upper) {
			result += get_value(this.lowwer) * this.step;
			this.lowwer += this.step;
		}
		return result;
	}

}
