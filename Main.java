package Programming;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	private static long[] array;
	private static long[] store;

	private static void jully() {

		 while (scanner.hasNextLine()) {
			try {
				int n = scanner.nextInt();
				if (n < 1)
					continue;
				array = new long[n + 1];
				for (int i = 0; i < n; i++) {
					array[i] = scanner.nextInt();
				}
				if (n == 1) {
					System.out.println("Jolly");
					continue;
				}
				store = new long[n + 1];
				for (int i = 0; i < n - 1; i++) {
					store[i] = Math.abs(array[i] - array[i + 1]);
				}
				boolean test = true;
				Arrays.sort(store, 0, n - 1);
				for (int i = 0; i < n - 1; i++) {
					if (store[i] != i + 1) {
						test = false;
						break;
					}
				}
				if (test) {
					System.out.println("Jolly");
				} else {
					System.out.println("Not jolly");
				}
			} catch (Exception ex) {
				break;
			}
		}

	}

	public static void main(String[] args) {
		jully();
	}

	private static Scanner scanner = new Scanner(System.in);
	// private static Scanner scanner = fileConnectedFactory.getScanner();
}