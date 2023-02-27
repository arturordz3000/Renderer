#pragma once

#include "../vendor/tga/tgaimage.h"

namespace Renderer
{
	class IApplication
	{
	public:
		int virtual Start() = 0;
	};
}