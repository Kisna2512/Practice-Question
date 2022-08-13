#include <bits/stdc++.h>
using namespace std;

int duplicates(int arr[], int n)
{
    int k;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second > 1)
        {
            k = it.first;
        }
    }
    return k;
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

    cout << "The duplicate number is:- " << duplicates(arr, n);

    return 0;
}