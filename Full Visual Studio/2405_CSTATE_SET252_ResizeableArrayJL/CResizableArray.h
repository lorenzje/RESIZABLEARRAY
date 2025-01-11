// --------------------------------------------------------------------------------
// Name: CResizableArray
// Abstract: This class ...
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Pre-compiler Directives
// --------------------------------------------------------------------------------
#pragma once		// Include this file only once even if referenced multiple times

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;



class CResizableArray
{
    // --------------------------------------------------------------------------------
    // Properties
    // --------------------------------------------------------------------------------
private:
    long m_lngArraySize;
    std::vector<long> m_palngValues;

protected:
    void Initialize(long lngInitialSize = 0, long lngDefaultValue = 0);
    void CleanUp();

    // --------------------------------------------------------------------------------
    // Methods
    // --------------------------------------------------------------------------------
public:
    // Constructors
    CResizableArray();
    CResizableArray(long lngInitialSize);
    CResizableArray(long lngInitialSize, long lngDefaultValue);

    // Destructor
    ~CResizableArray();

    // Methods
    void SetSize(long lngNewSize);
    long GetSize() const;
    void SetValueAt(long lngValue, long lngIndex);
    long GetValueAt(long lngIndex) const;
    void AddValueToFront(long lngValue);
    void AddValueToEnd(long lngValue);
    void InsertValueAt(long lngValue, long lngIndex);
    void RemoveAt(long lngIndex);
    void Display(const char* caption) const;
};