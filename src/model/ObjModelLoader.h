#pragma once

#include "IModelLoader.h"

using namespace std;

namespace Renderer
{
	class ObjModelLoader : public IModelLoader
	{
	public:
		Model Load(const string& filePath) override;
	};
}