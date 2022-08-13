#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

    int n;
    cout << "Enter the size of an class:- " << endl;
    cin >> n;

    // user will input total marks you want to find percentage of that student
    float arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] = (arr[i] / 500) * 100;
    }

    cout << "The Array is:- " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "%, ";
    }

    return 0;
}
