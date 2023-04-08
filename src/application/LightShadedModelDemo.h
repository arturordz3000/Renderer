#pragma once
#include "IApplication.h"

namespace Renderer
{
	class LightShadedModelDemo : public IApplication
	{
	public:
		int Start() override;
		string virtual GetTitle() { return "LightShadedModel Demo"; }
	};
}