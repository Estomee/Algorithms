#include "array.h"
struct Array
{

    Data* data;
    size_t sizeArr;


};

// create array
Array* array_create(size_t size)
{
    Array* arr = new Array;  //��������� ������ ��� ���������
    arr->sizeArr = size;          //��������� ������ ��� �������� ������� �������
    arr->data = new Data[size];  // ��������� ������ ��� �������� � �������

    return arr;
}

// delete array, free memory
void array_delete(Array* arr)
{
    delete[] arr->data;   //�������� �������
    delete arr;    //�������� ���������
}

// returns specified array element
Data array_get(const Array* arr, size_t index)
{
    if (index <= arr->sizeArr)
    {
        return arr->data[index];
    }
    else return (Data)0;

}

// sets the specified array element to the value
void array_set(Array* arr, size_t index, Data value)
{
    arr->data[index] = value;  //���������� �������� � ������ �� ��������� �������


}
// returns array size
size_t array_size(const Array* arr)
{
    return arr->sizeArr;
}
