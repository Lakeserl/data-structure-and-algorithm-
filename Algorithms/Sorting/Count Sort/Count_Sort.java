import java.util.Arrays;

public class Count_Sort {

	public static void main(String[] args) {
		int arr[] = { 9, 6, 3, 5, 3, 4, 3, 9, 6, 4, 6, 5, 8, 9, 9 };
		System.out.println("Array before Sorting: " + Arrays.toString(arr));

		int n = arr.length;
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			min = Math.min(min, arr[i]);
			max = Math.max(max, arr[i]);
		}
		int range = max - min + 1;
		System.out.println("Minimum Element = " + min + "\nMaximum Element = " + max + "\nRange = " + range);

		countSort(arr, min, max);
		System.out.println("Array after Sorting: " + Arrays.toString(arr));
	}

	static void countSort(int arr[], int min, int max) {
		int range = max - min + 2;
		int[] farr = new int[range];

		for (int i = 0; i < arr.length; i++) {
			int index = arr[i] - min;
			farr[index]++;
		}

		for (int i = 0; i < farr.length; i++) {
			if (i == 0)
				farr[i] = farr[i] - 1;
			else
				farr[i] = farr[i] + farr[i - 1];
		}

		int[] ans = new int[arr.length];
		for (int i = arr.length - 1; i >= 0; i--) {
			int val = arr[i];
			int index = farr[val - min];
			ans[index] = val;
			farr[val - min]--;
		}

		for (int i = 0; i < arr.length; i++)
			arr[i] = ans[i];
	}
}
