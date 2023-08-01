#pragma once
#include <cmath>

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

		Vector3<T> operator-();

		Vector3<T> operator^(const Vector3<T>& vector);

		template<typename U>
		Vector3<T> operator*(const U& scalar);

		template<typename U>
		T operator*(const Vector3<U>& otherVector);

		static Vector3<T> CrossProduct(const Vector3<T>& vector1, const Vector3<T>& vector2);

		void Normalize()
		{
			T magnitude = std::sqrt(x * x + y * y + z * z);

			this->x = this->x / magnitude;
			this->y = this->y / magnitude;
			this->z = this->z / magnitude;

		}
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

		template<typename U>
		Vector2<T> operator*(const U& scalar);
	};

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
	Vector3<T> Vector3<T>::operator-()
	{
		return Vector3<T>(
			-this->x,
			-this->y,
			-this->z
			);
	}

	template<class T>
	Vector3<T> Vector3<T>::CrossProduct(const Vector3<T>& vector1, const Vector3<T>& vector2)
	{
		T scalar1 = vector1.y * vector2.z - vector1.z * vector2.y;
		T scalar2 = vector1.z * vector2.x - vector1.x * vector2.z;
		T scalar3 = vector1.x * vector2.y - vector1.y * vector2.x;

		return Vector3<T>(scalar1, scalar2, scalar3);
	}

	template<class T>
	template<typename U>
	Vector3<T> Vector3<T>::operator*(const U& scalar)
	{
		return Vector3<T>(
			this->x * scalar,
			this->y * scalar,
			this->z * scalar
			);
	}

	template<class T>
	template<typename U>
	T Vector3<T>::operator*(const Vector3<U>& otherVector)
	{
		return this->x * otherVector.x + this->y * otherVector.y + this->z * otherVector.z;
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
	template<typename U>
	Vector2<T> Vector2<T>::operator*(const U& scalar)
	{
		return Vector2<T>(
			this->x * scalar,
			this->y * scalar
			);
	}

	template<class T>
	Vector3<T> Vector3<T>::operator^(const Vector3<T>& vector)
	{
		return Vector3<T>::CrossProduct(*this, vector);
	}
}