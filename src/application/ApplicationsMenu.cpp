#include <iostream>
#include <memory>
#include <vector>
#include "IApplication.h"
#include "LineDemo.h"
#include "WireframeDemo.h"
#include "ApplicationsMenu.h"

namespace Renderer
{
	int ApplicationsMenu::Start()
	{
		vector<unique_ptr<IApplication>> applications;

		// Maybe it's not a good idea to make instances of all applications,
		// but they are very lightweight at the moment, so it doesn't really matter.
		applications.push_back(make_unique<LineDemo>());
		applications.push_back(make_unique<WireframeDemo>());

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