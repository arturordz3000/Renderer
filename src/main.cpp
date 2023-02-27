#include <iostream>
#include <memory>
#include "application/IApplication.h"
#include "application/LineDemo.h"
#include "application/WireframeDemo.h"

using namespace std;
using namespace Renderer;

int main()
{
	unique_ptr<IApplication> application = make_unique<WireframeDemo>();
	return application->Start();
}