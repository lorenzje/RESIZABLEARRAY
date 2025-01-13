
# CResizableArray

## Overview

`CResizableArray` is a C++ class that provides a dynamically resizable array implementation. This class includes constructors, destructors, and a variety of methods to manipulate and analyze the array.

---

## Class Details

### Header File: `CResizableArray.h`
The header file contains the class definition, including:
- Properties (private)
- Methods (public and protected)

### Source File: `CResizableArray.cpp`
The source file implements the methods declared in the header file.

---

## Key Features

- Dynamic resizing of the array.
- Methods for initialization, cleanup, and deep copying.
- Support for adding, removing, and accessing elements by index.
- Operator overloads for array-like behavior and concatenation.
- Input validation to prevent runtime errors.

---

## Constructors and Destructor

- **CResizableArray():** Default constructor.
- **CResizableArray(long lngInitialSize):** Initializes the array with a specified size.
- **CResizableArray(long lngInitialSize, long lngDefaultValue):** Initializes the array with a specified size and default value.
- **CResizableArray(const CResizableArray& source):** Copy constructor.
- **~CResizableArray():** Destructor, cleans up resources.

---

## Key Methods

### Initialization and Cleanup
- **Initialize(long lngInitialSize, long lngDefaultValue):** Initializes the array.
- **CleanUp():** Cleans up the array and resets its size.

### Array Manipulation
- **SetSize(long lngNewSize):** Resizes the array.
- **SetValueAt(long lngValue, long lngIndex):** Sets a value at a specific index.
- **GetValueAt(long lngIndex) const:** Gets a value at a specific index.
- **AddValueToFront(long lngValue):** Adds a value to the beginning of the array.
- **AddValueToEnd(long lngValue):** Adds a value to the end of the array.
- **InsertValueAt(long lngValue, long lngIndex):** Inserts a value at a specific index.
- **RemoveAt(long lngIndex):** Removes the value at a specific index.

### Display and Analysis
- **Display(const char* caption) const:** Displays the array contents with a caption.
- **GetSize() const:** Returns the current size of the array.

### Operator Overloading
- **operator[](long lngIndex):** Provides array-like access to elements (non-const).
- **operator[](long lngIndex) const:** Provides array-like access to elements (const).
- **operator+=(const CResizableArray& clsOriginalToAppend):** Appends another array to this one.
- **operator+(const CResizableArray& clsRight) const:** Returns a new array combining two arrays.

---

## Sample Usage

```cpp
#include "CResizableArray.h"

int main() {
    CResizableArray arr(5, 0); // Initialize with size 5, default value 0

    arr.SetValueAt(10, 2); // Set value at index 2
    arr.AddValueToEnd(20); // Add value to the end
    arr.AddValueToFront(5); // Add value to the front

    arr.Display("Current Array");

    return 0;
}
```

---

## License

This class implementation is for educational purposes and is not intended for production use.
