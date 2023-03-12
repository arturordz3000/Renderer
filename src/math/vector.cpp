#include "vector.h"

namespace Renderer
{
	template<class T>
	Vector3<T> Vector3<T>::operator+(const Vector3<T>& vector)
	{
		return Vector3<T>(
			this->x + vector.x,
			this->y + vector.y,
			this->z + vector.z
		);
	}

	template<class T>
	Vector3<T> Vector3<T>::operator-(const Vector3<T>& vector)
	{
		return Vector3<T>(
			this->x - vector.x,
			this->y - vector.y,
			this->z - vector.z
		);
	}

	template<class T>
	Vector3<T> Vector3<T>::operator*(const int& scalar)
	{
		return Vector3<T>(
			this->x * scalar,
			this->y * scalar,
			this->z * scalar
		);
	}
	template<class T>
	Vector2<T> Vector2<T>::operator+(const Vector2<T>& vector)
	{
		return Vector2<T>(
			this->x + vector.x,
			this->y + vector.y
		);
	}

	template<class T>
	Vector2<T> Vector2<T>::operator-(const Vector2<T>& vector)
	{
		return Vector2<T>(
			this->x - vector.x,
			this->y - vector.y
		);
	}

	template<class T>
	Vector2<T> Vector2<T>::operator*(const int& scalar)
	{
		return Vector2<T>(
			this->x * scalar,
			this->y * scalar
		);
	}
}