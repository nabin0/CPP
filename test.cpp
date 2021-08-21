
#include <iostream>
using namespace std;

class Test
{
    int a;
    int arr[5];

public:
    Test()
    {
        a = 23;
    }

    void display()
    {
        cout << "Displaying" << endl;
    }
};

int main()
{

    Test obj;
    obj.display();

    return 0;
}
