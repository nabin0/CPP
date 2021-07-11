#include <iostream>
#include <climits>
using namespace std;

int main()
{
    // Take user input for size of number items
    cout << "How many numbers you want to enter: " << endl;
    int n;
    cin >> n;

    // Declaring the min and max var and initializing them with min and max int limit value
    int min_so_far = INT_MAX;
    int max_so_far = INT_MIN;

    // Algo to find min and max number
    int user_input_no;

    for (int i = 0; i < n; i++)
    {
        cin >> user_input_no;
        if (user_input_no < min_so_far)
        {
            min_so_far = user_input_no;
        }
        if (user_input_no > max_so_far)
        {
            max_so_far = user_input_no;
        }
    }
    cout << "The max number is : " << max_so_far << endl;
    cout << "The min number is : " << min_so_far << endl;
    return 0;
}