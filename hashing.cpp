// C++ program to find the largest product number
#include <bits/stdc++.h>
using namespace std;

// Function to find greatest number
int findGreatest(int arr[], int n)
{
	// Store occurrences of all elements in hash
	// array
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
		m[arr[i]]++;

	// Sort the array and traverse all elements from
	// end.
	sort(arr, arr + n);

	for (int i = n - 1; i > 1; i--) {
		// For every element, check if there is another
		// element which divides it.
		for (int j = 0; j < i && arr[j] <= sqrt(arr[i]);
			j++) {
			if (arr[i] % arr[j] == 0) {
				int result = arr[i] / arr[j];

				// Check if the result value exists in array
				// or not if yes the return arr[i]
				if (result != arr[j] && result!=arr[i] && m[result] > 0)
					return arr[i];

				// To handle the case like arr[i] = 4 and
				// arr[j] = 2
				else if (result == arr[j] && m[result] > 1)
					return arr[i];
			}
		}
	}
	return -1;
}

// Drivers code
int main()
{
	int arr[] = {10, 3, 5, 30, 35};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findGreatest(arr, n);
	return 0;
}
