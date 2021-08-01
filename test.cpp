#include <iostream>
using namespace std;

int main()
{
    int arr[8] = {0};
    int n = size_t(arr) / (sizeof(int));
    cout << n << endl;
    return 0;
}