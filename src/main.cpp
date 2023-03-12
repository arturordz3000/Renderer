#include <iostream>
#include <memory>
#include "application/IApplication.h"
#include "application/ApplicationsMenu.h"

using namespace std;
using namespace Renderer;

int main()
{
	unique_ptr<IApplication> application = make_unique<ApplicationsMenu>();
	return application->Start();
}