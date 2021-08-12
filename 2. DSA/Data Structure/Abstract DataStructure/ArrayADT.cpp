#include <iostream>
using namespace std;

class MyArrAdt
{
    int total_size;
    int used_size;
    int *ptr;

public:
    //Constructing adt array
    MyArrAdt(MyArrAdt *ptr_obj, int total_size, int used_size)
    {
        this->total_size = total_size;
        this->used_size = used_size;
        this->ptr = new int(total_size);
    }

    //Setting value for each elements
    int set_val(MyArrAdt *ptr_obj)
    {
        for (int i = 0; i < ptr_obj->used_size; i++)
        {
            cout << "Enter value for idx: " << i << " ";
            cin >> ptr_obj->ptr[i];
        }
        return 1;
    }

    // Get value of particular index
    int get_val(MyArrAdt *ptr_obj, int index)
    {
        return ptr_obj->ptr[index];
    }

    //Diaplay all elements of the array
    void show(MyArrAdt *ptr_obj)
    {
        for (int i = 0; i < ptr_obj->used_size; i++)
        {
            cout << ptr_obj->ptr[i] << " ";
        }
        cout << endl;
    }

    // Insert element at particular index
    int insert(MyArrAdt *obj, int index, int value)
    {
        if (obj->used_size >= obj->total_size)
        {
            return -1;
        }

        for (int i = obj->used_size; i >= index; i--)
        {
            obj->ptr[i + 1] = obj->ptr[i];
        }
        obj->ptr[index] = value;
        obj->used_size++;

        return value;
    }

    //DEleting element from the array
    int delete_from_arr(MyArrAdt *obj, int index)
    {
        if (obj->used_size <= index)
        {
            return -1;
        }
        for (int i = index; i < obj->used_size; i++)
        {
            obj->ptr[i] = obj->ptr[i + 1];
        }
        obj->used_size--;
        return 0;
    }
};

int main()
{

    MyArrAdt obj1(&obj1, 5, 3);
    obj1.set_val(&obj1);
    obj1.insert(&obj1, 1, 555);
    obj1.delete_from_arr(&obj1, 2);
    obj1.show(&obj1);
    cout << obj1.get_val(&obj1, 2);
    return 0;
}