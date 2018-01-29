#include "stdafx.h"
#include "Vector2.h"

namespace FAX {
	Vector2::Vector2() {
		x = 0.f;
		y = 0.f;
	}

	Vector2::Vector2(float i_x, float i_y) {
		x = i_x;
		y = i_y;
	}

	Vector2 operator+(const Vector2& left, const Vector2& right) {
		return Vector2(left.x + right.x, left.y + right.y);
	}

	Vector2 operator-(const Vector2& left, const Vector2& right) {
		return Vector2(left.x - right.x, left.y - right.y);
	}

	Vector2 operator*(const float left, const Vector2& right) {
		return Vector2(left * right.x, left * right.y);
	}

	Vector2 operator*(const Vector2& left, const float right) {
		return Vector2(left.x * right, left.y * right);
	}

	Vector2& Vector2::operator=(const Vector2& value)
	{
		if (this == &value)
			return *this;

		x = value.x;
		y = value.y;

		return *this;
	}

	Vector2& Vector2::operator*=(const float factor)
	{
		this->x *= factor;
		this->y *= factor;
		return *this;
	}
}