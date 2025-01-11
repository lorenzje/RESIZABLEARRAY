// --------------------------------------------------------------------------------
// Name: CResizableArray
// Abstract: Class method definitions
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CResizableArray.h"
#include <iostream>
#include <stdexcept>

// --------------------------------------------------------------------------------
// Name: SetValue
// Abstract: Set the value
// --------------------------------------------------------------------------------
#include "CResizableArray.h"

// --------------------------------------------------------------------------------
// Name: Initialize
// Abstract: initializes
// --------------------------------------------------------------------------------
void CResizableArray::Initialize(long lngInitialSize, long lngDefaultValue)
{
    m_lngArraySize = lngInitialSize;
    m_palngValues.assign(lngInitialSize, lngDefaultValue);
}



// --------------------------------------------------------------------------------
// Name: CleanUp
// Abstract: cleans up
// --------------------------------------------------------------------------------
void CResizableArray::CleanUp()
{
    m_palngValues.clear();
    m_lngArraySize = 0;
}



// --------------------------------------------------------------------------------
// Name: DeepCopy
// Abstract: Set the value
// --------------------------------------------------------------------------------
void CResizableArray::DeepCopy(const CResizableArray& source)
{
    if (this != &source)
    {
        CleanUp();
        m_lngArraySize = source.m_lngArraySize;
        m_palngValues = source.m_palngValues;
    }
}



// --------------------------------------------------------------------------------
// Name: Initialize
// Abstract: Set the value
// --------------------------------------------------------------------------------
CResizableArray::CResizableArray()
{
    Initialize();
}



// --------------------------------------------------------------------------------
// Name: Initialize
// Abstract: Set the value
// --------------------------------------------------------------------------------
CResizableArray::CResizableArray(long lngInitialSize)
{
    Initialize(lngInitialSize);
}



// --------------------------------------------------------------------------------
// Name: Initialize
// Abstract: Set the value
// --------------------------------------------------------------------------------
CResizableArray::CResizableArray(long lngInitialSize, long lngDefaultValue)
{
    Initialize(lngInitialSize, lngDefaultValue);
}



// --------------------------------------------------------------------------------
// Name: Initialize
// Abstract: Set the value
// --------------------------------------------------------------------------------
CResizableArray::CResizableArray(const CResizableArray& source)
{
    Initialize();
    *this = source; // Utilize the assignment operator
}



// --------------------------------------------------------------------------------
// Name: CleanUp
// Abstract: Set the value
// --------------------------------------------------------------------------------
CResizableArray::~CResizableArray()
{
    CleanUp();
}



// --------------------------------------------------------------------------------
// Name: operator
// Abstract: Set the value
// --------------------------------------------------------------------------------
CResizableArray& CResizableArray::operator=(const CResizableArray& source)
{
    if (this != &source)
    {
        CleanUp();
        DeepCopy(source);
    }
    return *this;
}



// --------------------------------------------------------------------------------
// Name: SetSize
// Abstract: Set the value
// --------------------------------------------------------------------------------
void CResizableArray::SetSize(long lngNewSize)
{
    if (lngNewSize < 0)
    {
        lngNewSize = 0;
    }
    m_palngValues.resize(lngNewSize, 0);
    m_lngArraySize = lngNewSize;
}



// --------------------------------------------------------------------------------
// Name: GetSize
// Abstract: Set the value
// --------------------------------------------------------------------------------
long CResizableArray::GetSize() const
{
    return m_lngArraySize;
}



// --------------------------------------------------------------------------------
// Name: SetValueAt
// Abstract: Set the value
// --------------------------------------------------------------------------------
void CResizableArray::SetValueAt(long lngValue, long lngIndex)
{
    if (lngIndex < 0)
    {
        lngIndex = 0;
    }
    else if (lngIndex >= m_lngArraySize)
    {
        lngIndex = m_lngArraySize - 1;
    }
    m_palngValues[lngIndex] = lngValue;
}



// --------------------------------------------------------------------------------
// Name: GetValueAt
// Abstract: Get the value
// --------------------------------------------------------------------------------
long CResizableArray::GetValueAt(long lngIndex) const
{
    if (lngIndex < 0)
    {
        lngIndex = 0;
    }
    else if (lngIndex >= m_lngArraySize)
    {
        lngIndex = m_lngArraySize - 1;
    }
    return m_palngValues[lngIndex];
}



// --------------------------------------------------------------------------------
// Name: AddValueToFront
// Abstract: Set the value
// --------------------------------------------------------------------------------
void CResizableArray::AddValueToFront(long lngValue)
{
    m_palngValues.insert(m_palngValues.begin(), lngValue);
    ++m_lngArraySize;
}



// --------------------------------------------------------------------------------
// Name: AddValueToEnd
// Abstract: Set the value
// --------------------------------------------------------------------------------
void CResizableArray::AddValueToEnd(long lngValue)
{
    m_palngValues.push_back(lngValue);
    ++m_lngArraySize;
}



// --------------------------------------------------------------------------------
// Name: InsertValueAt
// Abstract: Set the value
// --------------------------------------------------------------------------------
void CResizableArray::InsertValueAt(long lngValue, long lngIndex)
{
    if (lngIndex < 0)
    {
        lngIndex = 0;
    }
    if (lngIndex > m_lngArraySize)
    {
        lngIndex = m_lngArraySize;
    }
    m_palngValues.insert(m_palngValues.begin() + lngIndex, lngValue);
    ++m_lngArraySize;
}



// --------------------------------------------------------------------------------
// Name: RemoveAt
// Abstract: Set the value
// --------------------------------------------------------------------------------
void CResizableArray::RemoveAt(long lngIndex)
{
    if (lngIndex < 0)
    {
        lngIndex = 0;
    }
    else if (lngIndex >= m_lngArraySize)
    {
        lngIndex = m_lngArraySize - 1;
    }
    m_palngValues.erase(m_palngValues.begin() + lngIndex);
    --m_lngArraySize;
}



// --------------------------------------------------------------------------------
// Name: Display
// Abstract: Set the value
// --------------------------------------------------------------------------------
void CResizableArray::Display(const char* caption) const
{
    std::cout << caption << ": ";
    for (long value : m_palngValues)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}



// --------------------------------------------------------------------------------
// Name: operator lngIndex
// Abstract: Set the value
// --------------------------------------------------------------------------------
long& CResizableArray::operator[](long lngIndex)
{
    if (lngIndex < 0)
    {
        lngIndex = 0;
    }
    else if (lngIndex >= m_lngArraySize)
    {
        lngIndex = m_lngArraySize - 1;
    }
    return m_palngValues[lngIndex];
}



// --------------------------------------------------------------------------------
// Name: operator lngIndex const
// Abstract: Set the value
// --------------------------------------------------------------------------------
const long& CResizableArray::operator[](long lngIndex) const
{
    if (lngIndex < 0)
    {
        lngIndex = 0;
    }
    else if (lngIndex >= m_lngArraySize)
    {
        lngIndex = m_lngArraySize - 1;
    }
    return m_palngValues[lngIndex];
}



// --------------------------------------------------------------------------------
// Name: operator clsOriginalToAppend
// Abstract: Set the value
// --------------------------------------------------------------------------------
CResizableArray& CResizableArray::operator+=(const CResizableArray& clsOriginalToAppend)
{
    m_palngValues.insert(m_palngValues.end(), clsOriginalToAppend.m_palngValues.begin(), clsOriginalToAppend.m_palngValues.end());
    m_lngArraySize = m_palngValues.size();
    return *this;
}



// --------------------------------------------------------------------------------
// Name: operator clsRight
// Abstract: Set the value
// --------------------------------------------------------------------------------
CResizableArray CResizableArray::operator+(const CResizableArray& clsRight) const
{
    CResizableArray result(*this);
    result += clsRight;
    return result;
}
