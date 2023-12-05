#include "vector.h"
#include <iostream>
#include "stack.h"
using namespace std;
void task(Stack* stack)
{
    int acc = 0;
    int temp1;
    int temp2;
    bool sign = false; //Обозначает, что предыдущий символ был знаком +,-,*,/ (cм. 66 строчку кода)
    char c=0;
    while ( c!='\n')
    {
     
        cin.get(c);
        
        if (c == '*') //Обработка умножения 
        {
            temp1 = stack_get(stack);
            stack_pop(stack);
            temp2 = stack_get(stack) * temp1;
            stack_pop(stack);
            stack_push(stack, temp2);
            sign = true;


        }
        else if (c == '+')    //Обработка сложения
        {
            temp1 = stack_get(stack);
            stack_pop(stack);
            temp2 = stack_get(stack) + temp1;
            stack_pop(stack);
            stack_push(stack, temp2);
            sign = true;
        }
        else if (c == '-')  //Обработка вычитания
        {
            temp1 = stack_get(stack);
            stack_pop(stack);
            temp2 = stack_get(stack) - temp1;
            stack_pop(stack);
            stack_push(stack, temp2);
            sign = true;
        }
        else if (c == '/')  //Обработка деления
        { 
            temp1 = stack_get(stack);
            stack_pop(stack);
            temp2 = stack_get(stack) / temp1;
            stack_pop(stack);
            stack_push(stack, temp2);
            sign = true;
        }
        else  if (c == '\n')   
        {
            if (sign == true)
            {
                sign = false;
                break;
            }
            stack_push(stack, acc);
            break;

        }
        else   if (c == ' ')    //Проверяем разделитель строки (пробел)
        {
            if (sign == true)   //Если предыдущий символ был знаком, то проходим на следующую итерацию считывания 
            {
                sign = false;
                continue;
            }
            stack_push(stack, acc); //Иначе записываем в стек число для операции 
            acc = 0;
            continue;
        }
        else
        {
            acc = acc * 10 + c - '0';  //Преобразование строчного представления числа в целочисленное 

        }
    }

}




int main()
{
    Stack* stack = stack_create();

    task(stack);
    while (!stack_empty(stack))
    {
        cout << stack_get(stack) << endl;
        stack_pop(stack);


    }
    stack_delete(stack);

}