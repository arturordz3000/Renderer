#pragma once
#include "IApplication.h"

namespace Renderer
{
	class ApplicationsMenu : public IApplication
	{
	public:
		int Start() override;
		string virtual GetTitle() { return "Applications Menu"; }
	};
}