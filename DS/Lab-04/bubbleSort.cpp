#include <iostream>
using namespace std;

void bubbleSort(int arr[])
{
    bool flag = false;
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (arr[i] > arr[j])
            {
                flag = true;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            if(!flag) break;
        }
    }
}

void display(int arr[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << " " << arr[i];
    }
}

int main()
{
    int arr[5] = {4, 2, 7, 1, 3};
    bubbleSort(arr);
    display(arr);
}
