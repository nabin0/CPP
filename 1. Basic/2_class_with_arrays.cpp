#include <iostream>
using namespace std;

class Test
{
public:
    int *age;
    string *names;

    Test(int *a, string b[])
    {
        this->age = a;
        this->names = b;
    }

    void display_data()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "The name is : " << names[i] << " and The age is " << age[i] << endl;
        }
    }
};

int main()
{
    int age[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    string name[] = {"Ned", "john", "Harry", "adam", "christine", "ada", "natasha"};
    Test obj(age, name);
    obj.display_data();
    return 0;
}