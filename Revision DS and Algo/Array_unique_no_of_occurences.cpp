#include <bits/stdc++.h>
using namespace std;

/*  problem statement:
Given an array of integers arr, return true if the
 number of occurrences
 of each value in the 
 array is unique, or 
 false otherwise.


sample testcases:- 
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. 
No two values have the same number of occurrences.


*/

bool uniqueOccurrences(int arr[], int n)
{

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    set<int> s;

    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        s.insert(i->second);
    }

    return s.size() == mp.size() ? true : false;
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

    if (uniqueOccurrences(arr,n))
    {
        cout << "Your array satisfied given condition" << endl;
    }
    else
    {
        cout << "Your array does'nt satisfies given condition" << endl;
    }

    return 0;
}