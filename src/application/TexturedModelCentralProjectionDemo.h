#pragma once
#include "IApplication.h"

namespace Renderer
{
	class TexturedModelCentralProjectionDemo : public IApplication
	{
	public:
		int Start() override;
		string virtual GetTitle() { return "TexturedModelCentralProjection Demo"; }
	};
}