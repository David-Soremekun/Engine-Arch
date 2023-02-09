#include "Rectangle.h"
Rectangle::~Rectangle()
{
	
}

bool Rectangle::CompletelyContains(const Rectangle& other) const
{
	if ((right<other.left||right>other.right) 
		|| (bottom<other.top||top>other.bottom)) 
	{
		return false;
	}
	else 
	{
		return true;
	}
}
void Rectangle::ClipTo(const Rectangle& other)
{
	if (right > other.right)
		right = other.right;
	if (bottom > other.bottom)
		bottom = other.bottom;
	if (left < other.left)
		left = other.left;
	if (top < other.top)
		top = other.top;
}