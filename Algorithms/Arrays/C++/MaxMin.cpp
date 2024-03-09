#include "iostream"
using namespace std;

void MaxMin() {
    int arr[10], n;
    cout << "Enter the size of the array : ";
    cin >> n;
    cout << "Enter the elements of the array : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    cout << "Largest element : " << max << endl;
    cout << "Smallest element : " << min;
}
