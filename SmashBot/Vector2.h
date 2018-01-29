#ifndef FAX_VECTOR2_H
#define FAX_VECTOR2_H

namespace FAX {
	class Vector2 {
	public:
		float x;
		float y;

		Vector2();
		Vector2(float i_x, float i_y);

		Vector2& operator=(const Vector2& value);
		Vector2& operator*=(const float factor);
	};

	Vector2 operator+(const Vector2& left, const Vector2& right);
	Vector2 operator-(const Vector2& left, const Vector2& right);
	Vector2 operator*(const float left, const Vector2& right);
	Vector2 operator*(const Vector2& left, const float right);
}

#endif