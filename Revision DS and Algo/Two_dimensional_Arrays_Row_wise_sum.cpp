#include <iostream>

using namespace std;

void sumRowwise(int arr[][3], int i, int j)
{
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
        cout << sum << endl;
    }
}

void sumcolwise(int arr[][3], int i, int j)
{
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += arr[j][i];
        }
        cout << sum << endl;
    }
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

    cout << "The Row wise sum is: " << endl;
    sumRowwise(arr, 3, 3);
    cout<<endl;
    cout<<"The column wise sum is: "<<endl;
    sumcolwise(arr,3,3);

    return 0;
}
