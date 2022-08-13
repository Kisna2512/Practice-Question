#include <bits/stdc++.h>
using namespace std;

/* problem :- 
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.

sample input:
1
7
2 3 1 6 3 6 2

sample output:
1

logic :- a^a=0

*/

int unique(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
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

    cout<<"Unique no is:- "<<endl;
    cout<<unique(arr,n)<<endl;

    return 0;
}