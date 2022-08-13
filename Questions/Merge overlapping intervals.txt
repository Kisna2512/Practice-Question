#include <iostream>
#include <algorithm>
#include <vector>

/*

------Merge two overlapping intervals------

problem statement:
Given a collection of Intervals, the task is
 to merge all of the overlapping Intervals.
Example 1:
Input:
Intervals = {{1,3},{2,4},{6,8},{9,10}}
Output: {{1, 4}, {6, 8}, {9, 10}}
Explanation: Given intervals: [1,3],[2,4]
[6,8],[9,10], we have only two overlapping
intervals here,[1,3] and [2,4]. Therefore
we will merge these two and return [1,4],
[6,8], [9,10].

Brute force:Using another Data structure and using sorting
TC:-O(NLOGN)+O(N^2)
SC:-O(N)

Optimal:-using sorting 
TC:-O(Nlogn) +O(N)
sc:-O(N)


*/

using namespace std;

vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
{

    vector<vector<int>> v;

    if (intervals.size() == 0)
    {
        return v;
    }

    sort(intervals.begin(), intervals.end());
    vector<int> temp = intervals[0];

    for (auto it : intervals)
    {
        if (it[0] <= temp[1])
        {
            temp[1] = max(it[1], temp[1]);
        }
        else
        {
            v.push_back(temp);
            temp = it;
        }
    }
    v.push_back(temp);
    return v;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<int>> intervals(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        intervals[i].push_back(x);
        intervals[i].push_back(y);
    }

    vector<vector<int>> ans = overlappedInterval(intervals);
    for (auto it : ans)
    {
        cout << "{";
        for (auto i : it)
        {
            cout << i << ",";
        }
        cout << "}";
    }

    return 0;
}
