#include <iostream>
#include <vector>
using namespace std;

void pairsum(int arr[], int size)
{
    vector<vector<int>> ans;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == 5)
            {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }

    for (auto pair : ans)
    {
        cout << "(" << pair[0] << ", " << pair[1] << ")" << endl;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5}; // Correct initialization
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate array size

    pairsum(arr, size);

    return 0;
}
