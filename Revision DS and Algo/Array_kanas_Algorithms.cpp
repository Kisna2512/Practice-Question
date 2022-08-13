#include <bits/stdc++.h>
using namespace std;

// time complexity:- o(n)
// Maximum subarray sum

int kadane(int arr[], int n)
{
    int mx = 0;
    int curr = 0;

    for (int i = 0; i < n; i++)
    {
        curr += arr[i];
        if (curr > mx)
        {
            mx = curr;
        }
        if (curr < 0)
        {
            curr = 0;
        }
    }

    return mx;
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

    cout << "Maximum subarray sum of given array is:- " << kadane(arr, n);

    return 0;
}