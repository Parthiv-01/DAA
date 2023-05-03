#include <iostream>
using namespace std;

int search(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[low] <= arr[mid])
        {
            if (key >= arr[low] && key < arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (key > arr[mid] && key <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int n, key;
    cout << "Enter size of array : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nEnter element to search :";
    cin >> key;
    int index = search(arr, n, key);
    if (index == -1)
    {
        cout << "Key not found" << endl;
    }
    else
    {
        cout << "Key found at index " << index << endl;
    }
    return 0;
}
