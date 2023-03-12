#pragma once

#include "../vendor/tga/tgaimage.h"
#include <string>

using namespace std;

namespace Renderer
{
	class IApplication
	{
	public:
		int virtual Start() = 0;
		string virtual GetTitle() = 0;
	};
}