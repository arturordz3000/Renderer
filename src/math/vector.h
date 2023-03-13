#pragma once

namespace Renderer 
{
	template<class T> class Vector3
	{
	public:
		T x;
		T y;
		T z;

		Vector3() {}
		Vector3(T x, T y, T z) : x(x), y(y), z(z) {}

		Vector3<T> operator+(const Vector3<T>& vector);
		Vector3<T> operator-(const Vector3<T>& vector);
		Vector3<T> operator*(const int& scalar);
	};

	template<class T> class Vector2
	{
	public:
		T x;
		T y;

		Vector2() {}
		Vector2(T x, T y) : x(x), y(y) {}

		Vector2<T> operator+(const Vector2<T>& vector);
		Vector2<T> operator-(const Vector2<T>& vector);
		Vector2<T> operator*(const int& scalar);
	};
}