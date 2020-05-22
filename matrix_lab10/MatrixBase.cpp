#include "MatrixBase.h"
#include <string>
#include <cassert>

using namespace std;

void MatrixBase::operator*=(int iMult)
{
    for (int x = 0; x < m_size; ++x)
    {
        for (int y = 0; y < m_size; ++y)
        {
            element(x, y) *= iMult;
        }
    }
}

void MatrixBase::operator+=(MatrixBase &iAdd)
{
    assert(iAdd.size() == m_size);
    for (int x = 0; x < iAdd.m_size; ++x)
    {
        for (int y = 0; y < iAdd.m_size; ++y)
        {
            element(x, y) += iAdd.element(x, y);
        }
    }
}

ostream &operator<<(ostream &out, const MatrixBase &iMatrix)
{
    string temp;
    for (int x = 0; x < iMatrix.m_size; ++x)
    {
        for (int y = 0; y < iMatrix.m_size; ++y)
        {
            temp += to_string(iMatrix.element(x, y)) + " | ";
        }
        temp += "\n";
        for (int y = 0; y < iMatrix.m_size; ++y)
            temp += "----";
        temp += "\n";
    }
    out << temp;
    return out;
}
