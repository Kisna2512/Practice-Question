#include <bits/stdc++.h>
using namespace std;

void input_2D(vector<vector<int>> &arr, int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        vector<int> temp;
        for (int j = 0; j < col; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        arr.push_back(temp);
        temp.clear();
    }
}

void print_2D(vector<vector<int>> &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> arr;
    int row;
    cout << "Enter the no of row:- " << endl;
    cin >> row;
    int col;
    cout << "Enter the no of columns:- " << endl;
    cin >> col;
    input_2D(arr, row, col);
    print_2D(arr);

    return 0;
}