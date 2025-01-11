// ------------------------------------------------------------------------------------------
// Name: Jack Lorenz
// Class: C Programming
// Abstract: Homework 7
// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------
// Includes
// ------------------------------------------------------------------------------------------
#include <iostream>
#include "CResizableArray.h"

// ------------------------------------------------------------------------------------------
// Constants
// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------





int main() 
{
    CResizableArray array1;
    CResizableArray array2(5);
    CResizableArray array3(5, 2);

    array1.Display("Initialized array1");
    array2.Display("Initialized array2");
    array3.Display("Initialized array3");

    array1.SetSize(4);
    std::cout << "Array1 after SetSize(4): ";
    array1.Display("Array1");

    array1[0] = 2;
    array1[1] = 4;
    array1[2] = 6;
    array1[3] = 8;
    array1.Display("Array1 after setting values");

    array1.AddValueToFront(10);
    array1.Display("Array1 after AddValueToFront(10)");

    array1.AddValueToEnd(12);
    array1.Display("Array1 after AddValueToEnd(12)");

    array1.InsertValueAt(5, 2);
    array1.Display("Array1 after InsertValueAt(5, 2)");

    array1.RemoveAt(2);
    array1.Display("Array1 after RemoveAt(2)");

    array1.SetSize(6);
    array1.Display("Array1 after SetSize(6)");

    // Testing invalid operations
    try
    {
        array1.SetValueAt(15, -1); 
        array1.Display("Array1 after SetValueAt(15, -1)");
    }

        catch (std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
         }

    try
    {
        array1.RemoveAt(10); 
        array1.Display("Array1 after RemoveAt(10)");
    }
        catch (std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

    // Test += operator
    array1 += array2;
    array1.Display("Array1 after += array2");

    // Test + operator
    CResizableArray array4 = array1 + array3;
    array4.Display("Array4 after array1 + array3");

    system("pause");
}