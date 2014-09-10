#pragma once
#include <math.h>
#define PI 3.14159265

class Vector2
{
public:

	float   x;
	float   y;

	Vector2() 
	{
		x = 0.0f;
		y = 0.0f;
	}

	Vector2(float r, float s)
	{
		x = r;
		y = s;
	}

	Vector2& Set(float r, float s)
	{
		x = r;
		y = s;
		return (*this);
	}

	float& operator [](long k)
	{
		return ((&x)[k]);
	}

	const float& operator [](long k) const
	{
		return ((&x)[k]);
	}

	Vector2& operator +=(const Vector2& v)
	{
		x += v.x;
		y += v.y;
		return (*this);
	}

	Vector2& operator -=(const Vector2& v)
	{
		x -= v.x;
		y -= v.y;
		return (*this);
	}

	Vector2& operator *=(float t)
	{
		x *= t;
		y *= t;
		return (*this);
	}

	Vector2& operator /=(float t)
	{
		float f = 1.0F / t;
		x *= f;
		y *= f;
		return (*this);
	}

	Vector2& operator &=(const Vector2& v)
	{
		x *= v.x;
		y *= v.y;
		return (*this);
	}

	Vector2 operator -(void) const
	{
		return (Vector2(-x, -y));
	}

	Vector2 operator +(const Vector2& v) const
	{
		return (Vector2(x + v.x, y + v.y));
	}

	Vector2 operator -(const Vector2& v) const
	{
		return (Vector2(x - v.x, y - v.y));
	}

	Vector2 operator *(float t) const
	{
		return (Vector2(x * t, y * t));
	}

	Vector2 operator /(float t) const
	{
		float f = 1.0F / t;
		return (Vector2(x * f, y * f));
	}

	float operator *(const Vector2& v) const
	{
		return (x * v.x + y * v.y);
	}

	Vector2 operator &(const Vector2& v) const
	{
		return (Vector2(x * v.x, y * v.y));
	}

	bool operator ==(const Vector2& v) const
	{
		return ((x == v.x) && (y == v.y));
	}

	bool operator !=(const Vector2& v) const
	{
		return ((x != v.x) || (y != v.y));
	}

	/*Vector2& Normalize(void)
	{
		return (*this /= sqrtf(x * x + y * y));
	}*/

	void Normalize()
	{
		float length = (sqrtf(this->x * this->x + this->y * this->y));

		if (length > 0.f)
		{
			this->x = this->x / length;
			this->y = this->y / length;
		}
	}

	Vector2& Rotate(float angle);
};


inline Vector2 operator *(float t, const Vector2& v)
{
	return (Vector2(t * v.x, t * v.y));
}

inline float Dot(const Vector2& v1, const Vector2& v2)
{
	return (v1 * v2);
}

inline float Magnitude(const Vector2& v)
{
	return (sqrtf(v.x * v.x + v.y * v.y));
}

inline float InverseMag(const Vector2& v)
{
	return (1.0F / sqrtf(v.x * v.x + v.y * v.y));
}

inline float SquaredMag(const Vector2& v)
{
	return (v.x * v.x + v.y * v.y);
}

inline float Angle(const Vector2& v)
{
	if (v.x >= 0.0f)
	{
		return atan(v.y / v.x) * 180 / PI;
	}
	else
	{
		return (atan(v.y / v.x) * 180 / PI) + 180;
	}

}