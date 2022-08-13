#include <bits/stdc++.h>
using namespace std;

/*

problem statement:- Given an array of size N containing only 0s, 1s, and 2s; 
sort the array in ascending order.

Brute force:- Using inbuilt sort
TC:-o(nlogn)
SC:-o(1)

----------------------------------------

Better approach:- Using count sort
TC:-O(2N);
SC:-O(1);

-----------------------------------------

Optimal Approach:- 
Time complexity:- o(n)
space complexity:- o(1)

using Dutch National flag Algorithm

----------------------------------------*/


void sort_012(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {

        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort_012(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}