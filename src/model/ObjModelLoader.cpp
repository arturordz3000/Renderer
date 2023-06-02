#include "ObjModelLoader.h"
#include <fstream>
#include <string>
#include <sstream>
#include "../math/vector.h"

using namespace std;

namespace Renderer
{
	Model ObjModelLoader::Load(const string& filePath)
	{
		Model model;

		ifstream file;
		file.open(filePath.c_str(), ifstream::in);

		if (file.fail())
		{
			runtime_error fileLoadFailed("An error occured loading the file. Make sure the file exists.");
			throw fileLoadFailed;
		}

		string line;

		while (!file.eof())
		{
			getline(file, line);
			istringstream lineStream(line.c_str());

			// This variable will help us to skip characters we're not interested in.
			char thrash;
			
			if (line.compare(0, 2, "v ") == 0)
			{
				// We expect a line like: v 1.0 1.0 1.0
				
				// Getting rid of the initial "v" character.
				lineStream >> thrash;

				Vector3<float> vertex;
				lineStream >> vertex.x >> vertex.y >> vertex.z;
				model.vertices.push_back(vertex);
			}
			else if (line.compare(0, 3, "vt ") == 0)
			{
				// We expect a line like: vt 1.0 1.0 0.0

				// Getting rid of the initial "vt" characters.
				lineStream >> thrash >> thrash;

				Vector2<float> uv;
				float uvThrash = 0;

				lineStream >> uv.x >> uv.y >> uvThrash;
				model.uv.push_back(uv);
			}
			else if (line.compare(0, 2, "f ") == 0)
			{
				// We expect a line like: f 6/4/1 3/5/3 7/6/5

				// Getting rid of the initial "f" character
				lineStream >> thrash;

				// Reading the rest of the line.
				// Each iteration will read a set of 3 numbers.
				// In this example, we will be reading 6/4/1, then 3/5/3 and finally 7/6/5.
				// The first number of each set is the vertex index which we have to store.
				vector<int> indices;
				vector<int> uvIndices;
				int index;
				int uvIndex;

				// We have to get rid of indices we're not interested in.
				int indexThrash;

				while (lineStream >> index >> thrash >> uvIndex >> thrash >> indexThrash)
				{
					indices.push_back(index - 1);
					uvIndices.push_back(uvIndex - 1);

				}

				model.faces.push_back(indices);
				model.facesUV.push_back(uvIndices);
			}
		}

		return model;
	}
}
