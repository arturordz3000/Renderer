#pragma once
#include "IApplication.h"

namespace Renderer
{
	class WireframeDemo : public IApplication
	{
	public:
		int Start() override;
		string virtual GetTitle() { return "Wireframe Demo"; }
	};
}