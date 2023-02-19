#pragma once

#include <string>
#include "Model.h"

using namespace std;
	
namespace Renderer
{
	class IModelLoader
	{
	public:
		virtual Model Load(const string& filePath) = 0;
	};
}