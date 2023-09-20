#include <iostream>
#include <memory>
#include <vector>
#include "IApplication.h"
#include "LineDemo.h"
#include "WireframeDemo.h"
#include "SimpleTrianglesDemo.h"
#include "ApplicationsMenu.h"
#include "RandomFlatShadedModelDemo.h"
#include "LightShadedModelDemo.h"
#include "ZBuffer2dDemo.h"
#include "ZBuffer3dDemo.h"
#include "TexturedModelDemo.h"
#include "MatrixDemo.h"

namespace Renderer
{
	int ApplicationsMenu::Start()
	{
		vector<unique_ptr<IApplication>> applications;

		// Maybe it's not a good idea to make instances of all applications,
		// but they are very lightweight at the moment, so it doesn't really matter.
		applications.push_back(make_unique<LineDemo>());
		applications.push_back(make_unique<WireframeDemo>());
		applications.push_back(make_unique<SimpleTrianglesDemo>());
		applications.push_back(make_unique<RandomFlatShadedModelDemo>());
		applications.push_back(make_unique<LightShadedModelDemo>());
		applications.push_back(make_unique<ZBuffer2dDemo>());
		applications.push_back(make_unique<ZBuffer3dDemo>());
		applications.push_back(make_unique<TexturedModelDemo>());
		applications.push_back(make_unique<MatrixDemo>());

		cout << "Choose application: " << endl;
		for (int i = 0; i < applications.size(); i++)
		{
			cout << i + 1 << ") " << applications[i]->GetTitle() << endl;
		}

		int choosenApplication;
		while (true)
		{
			cin >> choosenApplication;
			if (choosenApplication < 1 || choosenApplication > applications.size())
			{
				cout << "Invalid option, try again" << endl;
				continue;
			}

			break;
		}

		return applications[choosenApplication - 1]->Start();
	}
}