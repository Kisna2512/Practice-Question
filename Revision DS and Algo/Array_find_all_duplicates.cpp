#include <bits/stdc++.h>

using namespace std;

/* problem statement: 
 
Given an integer array nums of length n where all the integers
of nums are in the range [1, n] and each integer appears once or twice, 
return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only 
constant extra space.

sample input:- 
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

*/

vector<int> findDuplicates(vector<int> &nums)
{

    vector<int> v;
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    for (auto it : mp)
    {
        if (it.second > 1)
        {
            v.push_back(it.first);
        }
    }

    return v;
}

int main(int argc, char const *argv[])
{

    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    vector<int> v{100, 0};

    v = findDuplicates(nums);

    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}
