package new_package;

import java.util.Scanner;
import java.util.concurrent.ExecutionException;

public class Main {
	public static void main(String[] args) throws InterruptedException, ExecutionException {
		Scanner in = new Scanner(System.in);
		System.out.print("������� ������ �������: ");
		double lowwer = in.nextDouble();
		System.out.print("������� ������� �������: ");
		double upper = in.nextDouble();
		Function f = new Function();
		Integral_Computation computation = new Integral_Computation(lowwer, upper, 0.000001, f);
		long start = System.currentTimeMillis();
		computation.computation();
		long end = System.currentTimeMillis();
		System.out.println("����� ����������:" + (end - start)/1000. + "������");
		System.out.println("���������� ���������:" + computation.get_value());
		in.close();
	}
}
