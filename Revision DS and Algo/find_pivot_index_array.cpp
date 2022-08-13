#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        int pre = 0;

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            sum -= nums[i];
            if (pre == sum)
            {
                return i;
            }
            pre += nums[i];
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution obj;
    int n;
    cout << "Enter the size of an array:- " << endl;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << "The pivot index is:- " << obj.pivotIndex(nums);

    return 0;
}
