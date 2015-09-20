
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 * @throws IOException
	 */
	public static int n, k;

	public static BigInteger[][] dp;

	public static BigInteger rec(int digit, int isPrevZero) {
		if (digit == n)
			return new BigInteger("1");
		if (!dp[digit][isPrevZero].equals(new BigInteger("-1")))
			return dp[digit][isPrevZero];
		BigInteger count = new BigInteger("0");
		for (int i = 0; i < k; i++) {
			if (i != 0 || isPrevZero == 0) {
				if (i == 0)
					count = count.add(rec(digit + 1, 1));
				else
					count = count.add(rec(digit + 1, 0));
				

			}

		}

		return dp[digit][isPrevZero] = count;
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		k = sc.nextInt();
		sc.close();
		dp = new BigInteger[1800][2];
		for (int i = 0; i < 1800; i++)
			for (int j = 0; j < 2; j++)
				dp[i][j] = new BigInteger("-1");
		if (n == 1)
			System.out.printf("%d\n", k);
		else
			System.out.printf("%s\n", rec(0, 1).toString());

	}
}
