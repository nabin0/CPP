#include <iostream>
using namespace std;

int main()
{

    int num;
    cin >> num;

    int n;
    int unq_num = 0;
    for (int i = 0; i < num; i++)
    {
        cin >> n;
        unq_num = unq_num ^ n;
    }
    cout << "The unique number is : " << unq_num << endl;

    return 0;
}