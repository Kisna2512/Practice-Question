#include <bits/stdc++.h>
using namespace std;

/* Problem Statement:-  

Count Inversions


Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).
Example 2:

Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already 
sorted so there is no inversion count.
Example 3:

Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array 
are same, so there is no inversion count.
Your Task:
You don't need to read input or print anything. Your task is to complete the function inversionCount() which takes the array arr[] and the size of the array as inputs and returns the inversion count of the given array.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 5*105
1 ≤ arr[i] ≤ 1018


*/

class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.

    long long merge(long long a[], long long temp[], long long left, long long mid, long long right)
    {
        long long i, j, k, cnt = 0;
        i = left;
        j = mid;
        k = left;

        while (i <= mid - 1 and j <= right)
        {
            if (a[i] <= a[j])
            {
                temp[k++] = a[i++];
            }
            else
            {
                temp[k++] = a[j++];
                cnt += (mid - i);
            }
        }
        while (i <= mid - 1)
        {
            temp[k++] = a[i++];
        }
        while (j <= right)
        {
            temp[k++] = a[j++];
        }
        for (int m = left; m <= right; m++)
        {
            a[m] = temp[m];
        }
        return cnt;
    }

    long long merge_sort(long long a[], long long temp[], long long left, long long right)
    {
        long long cnt = 0;
        if (left < right)
        {
            int mid = (left + right) / 2;

            cnt += merge_sort(a, temp, left, mid);
            cnt += merge_sort(a, temp, mid + 1, right);
            cnt += merge(a, temp, left, mid + 1, right);
        }
        return cnt;
    }

    long long int inversionCount(long long arr[], long long N)
    {

        long long temp[N];
        long long ans = merge_sort(arr, temp, 0, N - 1);
        return ans;
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    cin >> N;
    long long arr[N];
    for (long long i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
   Solution obj;
   cout<<obj.inversionCount(arr,N)<<endl;

        return 0;
}