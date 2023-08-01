#include "Matrix.h"

namespace Renderer {
	template<typename T>
	std::vector<T> Matrix<T>::operator[](const int i)
	{
		assert(i >= 0 && i < this->m.size());
		return this->m[i];
	}

	template<typename T>
	Matrix<T> Matrix<T>::operator*(Matrix<T>& other)
	{
		assert(this->GetColumnsSize() == other.GetRowsSize());
		Matrix<T> m(this->GetRowsSize(), other.GetColumnsSize());

		for (int i = 0; i < m.GetRowsSize(); i++)
		{
			for (int j = 0; j < m.GetColumnsSize(); j++) 
			{
				// TODO: I think I need another loop here.
			}
		}

		return m;
	}

	template<typename T>
	Matrix<T> Matrix<T>::FromVector3(Vector3<T>& vector) 
	{
		Matrix<T> m(3, 1);
		m[0][0] = vector.x;
		m[1][0] = vector.y;
		m[2][0] = vector.z;
	}

	template<typename T>
	Matrix<T> Matrix<T>::Identity(int r, int c)
	{
		Matrix<T> m(r, c);

		for (int i = 0, j = 0; i < r && j < c; i++, j++) {
			m[i][j] = 1;
		}

		return m;
	}
}