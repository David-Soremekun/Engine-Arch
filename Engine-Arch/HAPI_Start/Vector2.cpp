#include "Vector2.h"


float Vector2::Length() const
{
    return sqrt(x * x + y * y);
}

float Vector2::CrossProduct(const Vector2& other)
{
    return x * other.y - y * other.x;
}

float Vector2::DotProduct(const Vector2& other)
{
    return x * other.x + y * other.y;
}

void Vector2::NormaliseInPlace()
{
    float len = Length();
    if (len==0) {
        return;
    }
    x /= len;
    y /= len;
}

Vector2::~Vector2()
{
}



Vector2 Vector2::operator+(const Vector2& rhs) const
{
    return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator-(const Vector2& rhs) const
{
    return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator*(float rhs) const
{

    return Vector2(x*rhs,y*rhs);// // O: insert return statement here
}

bool Vector2::operator==(const Vector2& l)
{
    if (x == l.x && y == l.y)
    {
        return true;
    }
    else 
    {
        return false;
    }
    
}



