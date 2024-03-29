import java.util.Arrays;

public class Radix_Sort {

	public static void main(String[] args) {
		int arr[] = { 213, 97, 718, 123, 37, 443, 982, 64, 375, 683 };
		System.out.println("Array before Sorting: " + Arrays.toString(arr));

		int max = Integer.MIN_VALUE;
		for (int i : arr)
			max = Math.max(i, max);

		int exp = 1;
		while (exp <= max) {
			radixSort(arr, exp);
			exp *= 10;
		}

		System.out.println("Array after Sorting: " + Arrays.toString(arr));
	}

	static void radixSort(int[] arr, int exp) {
		int[] farr = new int[10];

		
		for (int i = 0; i < arr.length; i++) {
			farr[arr[i] / exp % 10]++;
		}

		for (int i = 0; i < farr.length; i++) {
			if (i == 0)
				farr[i] = farr[i] - 1;
			else
				farr[i] = farr[i] + farr[i - 1];
		}

		int[] ans = new int[arr.length];
		for (int i = arr.length - 1; i >= 0; i--) {
			int index = farr[arr[i] / exp % 10];
			ans[index] = arr[i];
			farr[arr[i] / exp % 10]--;
		}

		for (int i = 0; i < arr.length; i++)
			arr[i] = ans[i];
	}
}
