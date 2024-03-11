#include <iostream>

using namespace std;

void cycleSort(int arr[], int n)
{
	int writes = 0;

	for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++)
	{
		int item = arr[cycle_start];

		int pos = cycle_start;
		for (int i = cycle_start + 1; i < n; i++)
			if (arr[i] < item)
				pos++;

		if (pos == cycle_start)
			continue;

		while (item == arr[pos])
			pos += 1;
		if (pos != cycle_start)
		{
			swap(item, arr[pos]);
			writes++;
		}

		while (pos != cycle_start)
		{
			pos = cycle_start;

			for (int i = cycle_start + 1; i < n; i++)
				if (arr[i] < item)
					pos += 1;

			while (item == arr[pos])
				pos += 1;

			if (item != arr[pos])
			{
				swap(item, arr[pos]);
				writes++;
			}
		}
	}

}

// Driver program to test above function
int main()
{
	int arr[] = {1, 8, -8, 54, 41, 78, -34, 3, 9, -12, 654, 50, 2, 84, 20, -36, 41, 6, 10, 10, 2, 4};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Before sort : " << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout<< "\n\n";
	cycleSort(arr, n);
	cout << "After sort : " << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout<< "\n\n";
	return 0;
}
