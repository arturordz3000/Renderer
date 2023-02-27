#include "WireframeDemo.h"
#include "../model/ObjModelLoader.h"

namespace Renderer
{
	int Renderer::WireframeDemo::Start()
	{
		TGAImage image(500, 500, TGAImage::RGB);

		ObjModelLoader modelLoader;
		Model model = modelLoader.Load("assets/african_head.obj");
		model.Draw(image, WHITE);

		image.flip_vertically(); // Origin from left bottom corner
		image.write_tga_file("output.tga");

		return 0;
	}
}
