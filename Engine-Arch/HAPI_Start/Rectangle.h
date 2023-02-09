#pragma once
class Rectangle
{
private:
	int left;
	int right;
	int top;
	int bottom;
public:
	~Rectangle();
	Rectangle() : left(0), right(0), top(0), bottom(0) {}
	Rectangle(int l, int r, int t, int b) : left(l), right(r), top(t), bottom(b) {}
	
	void Translate(int dirX, int dirY) 
	{
		left += dirX;
		right += dirX;
		top += dirY;
		bottom += dirY;
	}
	int Width() const 
	{ 
		return right - left; 
	
	}
	int Height() const 
	{
		return bottom - top; 
	}
	int Top() const
	{
		return top;
	}
	int Left() const
	{
		return left;
	}
	bool CompletelyContains(const Rectangle& other) const;
	bool CompletelyOutside(const Rectangle& other);
	void ClipTo(const Rectangle& other);
};

