#pragma once
#include <vector>
#include <cassert>
#include <iostream>
#include "Vector.h"

namespace Renderer
{
	template<typename T>
	class Matrix {
	private:
		std::vector<std::vector<T>> m;

	public:
		Matrix(int r, int c) 
		{
			assert(r > 0 && c > 0);
			this->m = std::vector<std::vector<T>>(r, std::vector<T>(c, 0));
		}

		std::vector<T>& operator[](const int i);
		Matrix<T> operator*(Matrix<T>& other);

		int GetRowsSize()
		{
			return this->m.size();
		}

		int GetColumnsSize()
		{
			return this->m[0].size();
		}

		void Print();

		static Matrix<T> FromVector3(Vector3<T>& vector);
		static Matrix<T> Identity(int r, int c);
	};
}