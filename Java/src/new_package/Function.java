package new_package;

public class Function {
	private double x;

	Function() {
		this.x = 0;
	}

	double get_function_value(double x) {
		return Math.sin(x) * Math.exp(x + 3);
	}
}
