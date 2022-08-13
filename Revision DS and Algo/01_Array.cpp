#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

    int n;
    cout << "Enter the size of an array:- " << endl;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The Array is:- " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
