#pragma once
#include "IApplication.h"

namespace Renderer
{
	class ZBuffer2dDemo : public IApplication
	{
	public:
		int Start() override;
		string virtual GetTitle() { return "Z-buffer 2D demo"; }
	};
}