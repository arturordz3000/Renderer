#pragma once
#include "IApplication.h"

namespace Renderer
{
	class TexturedModelDemo : public IApplication
	{
	public:
		int Start() override;
		string virtual GetTitle() { return "TexturedModel Demo"; }
	};
}