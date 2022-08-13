#include <bits/stdc++.h>
using namespace std;

int subarrayssum(int arr[], int n, int k)
{

    // brute force
    //     int max_sum = INT_MIN;

    //     for (int i = 0; i < n - k + 1; i++) {
    //         int current_sum = 0;
    //         for (int j = 0; j < k; j++)
    //             current_sum = current_sum + arr[i + j];

    //         max_sum = max(current_sum, max_sum);
    //     }

    //     return max_sum;

    // sliding window optimal approach

    int max_sum = 0;

    for (int i = 0; i < k; i++)
    {
        max_sum += arr[i];
    }

    int sum = max_sum;

    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, sum);
    }

    return max_sum;
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

    cout << "Maximum sum is:- " << subarrayssum(arr, n, 4) << endl;

    return 0;
}