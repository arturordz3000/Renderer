#pragma once
#include "IApplication.h"

namespace Renderer
{
	class MatrixDemo : public IApplication
	{
	public:
		int Start() override;
		string virtual GetTitle() { return "Matrix Demo"; }
	};
}