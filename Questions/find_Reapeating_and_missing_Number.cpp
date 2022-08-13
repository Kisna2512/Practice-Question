#include <iostream>
#include <vector>
#include <map>
#include<unordered_map>

using namespace std;

/* Problem statement:- 

Find Missing And Repeating 

Given an unsorted array Arr of size N of 
positive integers. One number 'A'
from set {1, 2, …N} 
is missing and one number 'B' occurs twice in array. 
Find these two numbers.
Example 1:
Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.


Brute force:- Maintain a count Array
TC:-O(2N)
SC:-O(N)

Optimal Approach:- Using Hashing/Using XOR/Using Maths
TC:-O(N)
SC:-O(1)

I'm using here maths

*/
// for this solution (Mathematical) for long input take long long data type

// Mathematical
vector<int> findmissingandrepating(int arr[], int n)
{
    int S = (n * (n + 1)) / 2;               // Here Take summation 1+2+3+--+n
    int P = (n * (n + 1) * (2 * n + 1)) / 6; // Here taken sqaure 1^2+2^2+3^2+---n^2

    // Taken two missing and repeating Number
    int missing = 0;
    int repeating = 0;

    /* Here find sum of all elements of array and their sqaures 
using formula Total sum-array element sum
means we find s` and p` which is sum of all elements of array
and sum of all squares of elements of an array  */
    for (int i = 0; i < n; i++)
    {
        S = S - arr[i];
        P = P - arr[i] * arr[i];
    }
    /*
After that we know tha X-Y=S`
X^2-Y^2=P`
BY MATHS, (X-Y)*(X+Y)=P`
S`*(X+Y)=P`,
X+Y=P`/S`,
X+Y+X-Y=P`/S` + S`
2X=P`/S` + S`;
X= (P`/S` + S)/2
Y=X-S`
*/

    missing = (P / S + S) / 2;
    repeating = missing - S;

    vector<int> v;
    v.push_back(repeating);
    v.push_back(missing);

    return v;
}
// Using Map

vector<int> repeating_missing(int arr[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[i]++;
    }
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    vector<int> v;

    for (auto it : mp)
    {
        if (it.second > 2)
        {
            v.push_back(it.first);
        }
        if(it.second ==1) 
        {
            v.push_back(it.first);
        }
        
    }
    return v;
}

int main(int argc, char const *argv[])
{

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans;
    // ans = findmissingandrepating(arr, n);
    ans=repeating_missing(arr,n);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}
