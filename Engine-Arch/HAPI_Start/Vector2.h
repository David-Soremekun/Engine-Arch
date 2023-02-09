#pragma once
#include <cmath>

class Vector2
{
public:
	float x{ 0 };
	float y{ 0 };	
	
	float Length() const;
	float CrossProduct(const Vector2& other);
	float DotProduct(const Vector2& other);

	void NormaliseInPlace();
	~Vector2();
	Vector2() = default;
	Vector2(float newX, float newY) : x(newX), y(newY) {}
	Vector2 operator +(const Vector2& rhs) const;
	Vector2 operator -(const Vector2& rhs) const;
	Vector2 operator*(float rhs) const;
	Vector2 operator+=(const Vector2& rhs) const;
	Vector2 operator -=(const Vector2& rhs) const;
	bool operator==(const Vector2& l);
};

