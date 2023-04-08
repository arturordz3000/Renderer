#pragma once
#include "IApplication.h"

namespace Renderer
{
	class RandomFlatShadedModelDemo : public IApplication
	{
	public:
		int Start() override;
		string virtual GetTitle() { return "RandomFlatShadedModelDemo Demo"; }
	};
}