#include <iostream>
using namespace std;

//Structure for adt array
struct ArrayAdt
{
    int total_size;
    int used_size;
    int *ptr;
};

//Creates i.e initializes adt array
void create(ArrayAdt *arr, int totalSize, int usedSize)
{
    arr->total_size = totalSize;
    arr->used_size = usedSize;
    arr->ptr = new int(totalSize * sizeof(int));
}

//Setting values of array elements
void set_val(ArrayAdt *arr)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        cout << "Enter value for index : " << i << " ";
        cin >> arr->ptr[i];
    }
}


//Traverse and display data of the array
void show_data(ArrayAdt *arr)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        cout << arr->ptr[i] << " ";
    }
    cout << endl;
}


//Insert index at the particular index
int insert(ArrayAdt *arr, int index, int value)
{
    if (arr->used_size >= arr->total_size)
    {
        return -1;
    }

    for (int i = arr->used_size; i >= index; i--)
    {
        arr->ptr[i + 1] = arr->ptr[i];
    }
    arr->ptr[index] = value;
    arr->used_size++;

    return value;
}


//
int delete_element_from_array(ArrayAdt *arr, int idx){
    if(arr->used_size <= idx){
        return -1;
    }

    for (int i = idx; i < arr->used_size; i++)
    {
        arr[i] = arr[i+1];
    }
    arr->used_size--;
    return 0;
}
int main()
{

    struct ArrayAdt myArr;
    create(&myArr, 5, 3);
    set_val(&myArr);
    insert(&myArr,1,555);
    cout << "Printing all elements of the array: " << endl;
    show_data(&myArr);
    delete_element_from_array(&myArr, 2);
    show_data(&myArr);

    return 0;
}