#include "Matrix.h"

namespace Renderer {
	template class Matrix<float>;

	template<typename T>
	std::vector<T>& Matrix<T>::operator[](const int i)
	{
		assert(i >= 0 && i < this->m.size());
		return this->m[i];
	}

	template<typename T>
	const std::vector<T>& Matrix<T>::operator[](const int i) const
	{
		assert(i >= 0 && i < this->m.size());
		return this->m[i];
	}

	template<typename T>
	Matrix<T> Matrix<T>::operator*(Matrix<T>& other)
	{
		assert(this->GetColumnsSize() == other.GetRowsSize());
		Matrix<T> result(this->GetRowsSize(), other.GetColumnsSize());

		for (int i = 0; i < result.GetColumnsSize(); i++)
		{
			for (int j = 0; j < result.GetRowsSize(); j++)
			{
				T sum = 0;

				for (int k = 0; k < other.GetRowsSize(); k++)
				{
					sum += this->m[j][k] * other[k][i];
				}

				result[j][i] = sum;
			}
		}

		return result;
	}

	template<typename T>
	void Matrix<T>::Print()
	{
		for (int i = 0; i < this->GetRowsSize(); i++)
		{
			for (int j = 0; j < this->GetColumnsSize(); j++)
			{
				std::cout << this->m[i][j] << " ";
			}

			std::cout << std::endl;
		}
	}

	template<typename T>
	Matrix<T> Matrix<T>::FromVector3(Vector3<T>& vector) 
	{
		Matrix<T> m(4, 1);
		m[0][0] = vector.x;
		m[1][0] = vector.y;
		m[2][0] = vector.z;
		m[3][0] = 1;

		return m;
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