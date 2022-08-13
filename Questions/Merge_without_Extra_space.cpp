#include <iostream>

using namespace std;

/*

Problem statement:- Merge without Extra space

Given two sorted arrays arr1[] of size N and arr2[] of size M.
Each array is sorted in non-decreasing order. 
Merge the two arrays into one sorted array in 
non-decreasing order without using any extra space.

Example 1:
Input:
N = 4, M = 5
arr1[] = {1, 3, 5, 7}
arr2[] = {0, 2, 6, 8, 9}
Output: 0 1 2 3 5 6 7 8 9
Explanation: Since you can't use any 
extra space, modify the given arrays
to form 
arr1[] = {0, 1, 2, 3}
arr2[] = {5, 6, 7, 8, 9}

Brute force:- Using one extra Array
TC:-O(n*m*logn)
SC:-O(N)

Optimal Approach:- Gap Algorithm
TC:-O(n*logn)
SC:-O(1)

*/

class Solution
{
public:
    int nextgap(int gap)
    {
        if (gap <= 1)
        {
            return 0;
        }
        return gap / 2 + gap % 2;
    }
    void merge(int arr1[], int arr2[], int n, int m)
    {
        int gap = nextgap(n + m);
        int p1, p2;
        while (gap > 0)
        {
            p1 = 0;
            p2 = gap;
            while (p1 < n and p2 < n)
            {
                if (arr1[p1] > arr1[p2])
                {
                    swap(arr1[p1], arr1[p2]);
                }
                p1++;
                p2++;
            }
            while (p1 < n and p2 < m + n)
            {
                if (arr1[p1] > arr2[p2 - n])
                {
                    swap(arr1[p1], arr2[p2 - n]);
                }
                p1++;
                p2++;
            }
            while (p1 < m + n and p2 < m + n)
            {
                if (arr2[p1 - n] > arr2[p2 - n])
                {
                    swap(arr2[p1 - n], arr2[p2 - n]);
                }
                p1++;
                p2++;
            }
            gap = nextgap(gap);
        }

        int main(int argc, char const *argv[])
        {
            int n, m;
            cin >> n >> m;

            int arr1[n], arr2[m];
            for (int i = 0; i < n; i++)
            {
                cin >> arr1[i];
            }
            for (int i = 0; i < m; i++)
            {
                cin >> arr2[i];
            }

            Solution obj;
            obj.merge(arr1, arr2, n, m);
            for (int i = 0; i < n; i++)
            {
                cout << arr1[i] << " ";
            }
            cout << endl;

            for (int i = 0; i < m; i++)
            {
                cout << arr2[i] << " ";
            }

            return 0;
        }
