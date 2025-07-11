#pragma once

#include "imgui.h"

template<typename T>
class Vector2
{
public:
	Vector2(const T in_x, const T in_y)
		: x(in_x), y(in_y)
	{
	}

	template<typename U>
	Vector2(const Vector2<U> &in)
		: x(static_cast<T>(in.x)), y(static_cast<T>(in.y))
	{
	}

    T x, y;

	////////////////////////////////////////////////////////////
	/// \relates Vector2
	/// \brief Overload of binary operator -
	///
	/// \param right Right operand (a vector)
	///
	/// \return Vector with components of this added to by components of right
	///
	////////////////////////////////////////////////////////////
	inline Vector2<T> operator +(const Vector2<T>& right) const
	{
		return Vector2<T>(this->x + right->x, this->y + right->y);
	}

	////////////////////////////////////////////////////////////
	/// \relates Vector2
	/// \brief Overload of binary operator -
	///
	/// \param right Right operand (a vector)
	///
	/// \return Vector with components of this subtracted by components of right
	///
	////////////////////////////////////////////////////////////
	inline Vector2<T> operator -(const Vector2<T>& right) const
	{
		return Vector2<T>(this->x - right->x, this->y - right->y);
	}

	////////////////////////////////////////////////////////////
	/// \relates Vector2
	/// \brief Overload of binary operator +=
	///
	/// \param right Right operand (a vector)
	///
	/// \return Reference to this vector after adding each component to each other
	///
	////////////////////////////////////////////////////////////
	inline Vector2<T>& operator +=(const Vector2<T>& right)
	{
		this->x += right->x;
		this->y += right->y;
		return *this;
	}

	////////////////////////////////////////////////////////////
	/// \relates Vector2
	/// \brief Overload of binary operator -=
	///
	/// \param right Right operand (a vector)
	///
	/// \return Reference to this vector after subtracting each component from each other
	///
	////////////////////////////////////////////////////////////
	inline Vector2<T>& operator -=(const Vector2<T>& right)
	{
		this->x -= right->x;
		this->y -= right->y;
		return *this;
	}

	////////////////////////////////////////////////////////////
	/// \relates Vector2
	/// \brief Overload of binary operator ==
	///
	/// \param right Right operand (a vector)
	///
	/// \return Vectors are equal each other
	///
	////////////////////////////////////////////////////////////
	inline bool operator ==(const Vector2<T>& right) const
	{
		return this->x == right->x && this->y == right->y;
	}

	////////////////////////////////////////////////////////////
	/// \relates Vector2
	/// \brief Overload of binary operator !=
	///
	/// \param right Right operand (a vector)
	///
	/// \return Vectors are not equal each other
	///
	////////////////////////////////////////////////////////////
	inline bool operator !=(const Vector2<T>& right) const
	{
		return this->x != right->x || this->y != right->y;
	}

	////////////////////////////////////////////////////////////
	/// \relates Vector2
	/// \brief Overload of binary operator *
	///
	/// \param right Right operand (a vector)
	///
	/// \return Hadamard product of the two vectors
	///
	////////////////////////////////////////////////////////////
	inline Vector2<T> operator *(const Vector2<T>& right) const
	{
		return Vector2<T>(this->x * right.x, this->y * right.y);
	}

	////////////////////////////////////////////////////////////
	/// \relates Vector2
	/// \brief Overload of binary operator *
	///
	/// \param right Right operand (a vector)
	///
	/// \return Hadamard division of the two vectors
	///
	////////////////////////////////////////////////////////////
	inline Vector2<T> operator /(const Vector2<T>& right) const
	{
		return Vector2<T>(this->x / right.x, this->y / right.y);
	}

	inline Vector2<double> operator *(const double& right) const
	{
		return Vector2<double>(this->x * right, this->y * right);
	}


	inline Vector2<T> Clamp(Vector2<T> in, T min, T max) const
	{
		if(in.x < min)
			in.x = min;

		if(in.x > max)
			in.x = max;

		if(in.y < min)
			in.y = min;

		if(in.y > max)
			in.y = max;

		return in;
	}

#if 0
	inline operator ImVec2() const
	{
		return ImVec2(float(x), float(y));
	}
#endif
};

using Vector2f = Vector2<float>;
using Vector2i = Vector2<int>;

inline bool operator ==(const ImVec4& left, const ImVec4& right)
{
	return left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w;
}

inline bool operator !=(const ImVec4& left, const ImVec4& right)
{
	return !(left == right);
}


inline float Clamp(float in, float min = 0.0, float max = 1.0)
{
	if(in < min)
		return min;

	if(in > max)
		return max;

	return in;
}

template <typename T>
inline Vector2<T> Clamp(Vector2<T> in, Vector2<T> min, Vector2<T> max)
{
	if(in.x < min.x)
		in.x = min.x;

	if(in.x > max.x)
		in.x = max.x;

	if(in.y < min.y)
		in.y = min.y;

	if(in.y > max.y)
		in.y = max.y;

	return in;
}

template <typename T>
inline Vector2<T> Max(const Vector2<T>& a, const Vector2<T>& b)
{
	return { Max(a.x, b.x), Max(a.y, b.y) };
}

inline float Abs(float in)
{
	if(in < 0)
		return in * -1.f;

	return in;
}

template <typename T>
inline Vector2<T> Abs(Vector2<T> in)
{
	return { in.x > 0 ? in.x : -in.x, in.y > 0 ? in.y : -in.y };
}

template<typename T>
inline float Max(T a, T b)
{
	if(a > b)
		return a;

	return b;
}

template<typename T>
inline float Min(T a, T b)
{
	if(a < b)
		return a;

	return b;
}
