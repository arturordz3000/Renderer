#include "LightShadedModelDemo.h"
#include "../model/ObjModelLoader.h"

namespace Renderer
{
	int Renderer::LightShadedModelDemo::Start()
	{
		TGAImage image(500, 500, TGAImage::RGB);

		ObjModelLoader modelLoader;
		Model model = modelLoader.Load("assets/african_head.obj");
		model.SetLightDirection({ 0, 0, -1 });
		model.Draw(image, WHITE, RenderMode::FlatLight);

		image.flip_vertically(); // Origin from left bottom corner
		image.write_tga_file("output.tga");

		return 0;
	}
}
