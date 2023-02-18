#pragma once
#include "../vendor/tga/tgaimage.h"
#include "../math/point.h"

namespace Renderer 
{
	void drawLine(Point point1, Point point2, TGAImage& image, TGAColor color);
}
