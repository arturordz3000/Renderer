#pragma once
#include "IApplication.h"

namespace Renderer
{
	class ZBuffer3dDemo : public IApplication
	{
	public:
		int Start() override;
		string virtual GetTitle() { return "ZBuffer3d Demo"; }
	};
}