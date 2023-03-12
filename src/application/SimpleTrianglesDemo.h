#pragma once
#include "IApplication.h"

namespace Renderer
{
	class SimpleTrianglesDemo : public IApplication
	{
	public:
		int Start() override;
		string virtual GetTitle() { return "Simple Triangles Menu"; }
	};
}