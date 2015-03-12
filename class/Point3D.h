#ifndef POINT3D_H
#define POINT3D_H
 
//#include <iostream>
 
class Point3D
{
private:
    int m_nX;
    int m_nY;
    int m_nZ;
 
public:
    // A default constructor
    Point3D()
        : m_nX(0), m_nY(0), m_nZ(0)
    {
    }
 
    // A specific constructor
    Point3D(int nX, int nY, int nZ)
        : m_nX(nX), m_nY(nY), m_nZ(nZ)
    {
    }
 
    // An overloaded output operator
    friend std::ostream& operator<<(std::ostream& out, const Point3D &cPoint)
    {
        out << "(" << cPoint.GetX() << ", " << cPoint.GetY() << ", " << cPoint.GetZ() << ")";
        return out;
    }
 
    // Access functions
    void SetPoint(int nX, int nY, int nZ)
    {
        m_nX = nX;
        m_nY = nY;
        m_nZ = nZ;
    }
 
    int GetX() const { return m_nX; }
    int GetY() const { return m_nY; }
    int GetZ() const { return m_nZ; }
};
 
#endif

