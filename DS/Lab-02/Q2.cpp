#include <iostream>
using namespace std;

int main()
{
    int arr1[100][100];
    int arr2[100][100];
    int ans[100][100];
    int size;
    int element;

    cout << "Enter the size of first array: ";
    cin >> size;

    cout << "Input for array 1" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "Enter the element " << j + 1 << ": ";
            cin >> element;
            arr1[i][j] = element;
        }
    }

    cout << "Input for array 2" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "Enter the element " << j + 1 << ": ";
            cin >> element;
            arr2[i][j] = element;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            ans[i][j] = arr1[i][j] * arr2[i][j];
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
