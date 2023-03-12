#pragma once
#include "IApplication.h"

namespace Renderer
{
	class LineDemo : public IApplication
	{
	public:
		int Start() override;
		string virtual GetTitle() { return "Line Demo"; }
	};
}