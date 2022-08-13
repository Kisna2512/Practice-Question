#include <iostream>
#include <climits>

using namespace std;

int largest_row_sum(int arr[][3], int i, int j)
{

    int maxi = INT_MIN;
    int idx = -1;
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
        if (sum > maxi)
        {
            maxi = sum;
            idx = i;
        }
    }

    cout << "The maximum sum is:- " << maxi<<endl;

    return idx;
}

int main(int argc, char const *argv[])
{

    int arr[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "At index:- " << largest_row_sum(arr, 3, 3) << endl;
    return 0;
}
