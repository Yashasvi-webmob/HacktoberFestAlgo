#include <iostream>
using namespace std;

int BinarySearch(int n, int search, int arr[])
{
    int l = 0;
    int r = n;
    int mid =  l + (r-l)/2 ; /* suppose we take large number and by adding it will definitely overflow so to avoid it l+(r-l)/2 is prefered */
    while (l <= r)
    {
        if (arr[mid] == search)
        {
            return mid;
        }
        else if (arr[mid] < search)
        {
            l = mid + 1;
        }
        else{
            r=mid-1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int number;
    cin >> number;
    cout << BinarySearch(n, number, arr);
    cout << "this is binary serach";
    

    return 0;
}

