
#include "Material.h"
#include <iterator>
#include <fstream>
#include <sstream>

namespace sgl {
	Material::Material(std::shared_ptr<Texture> ambient, std::shared_ptr<Texture> color, std::shared_ptr<Texture> normal, std::shared_ptr<Texture> roughness, std::shared_ptr<Texture> metallic)
	{

	}

	std::map<std::string, std::shared_ptr<Material>> LoadMatFromMtl(std::string file)
	{
		std::map<std::string, std::shared_ptr<Material>> mats;

		std::ifstream ifs;
		ifs.open(file, std::ifstream::in);
		if (!ifs.is_open())
		{
			throw std::runtime_error("Couldn't open file: " + file);
		}
		std::shared_ptr<Material> material;
		std::string name;

		while (!ifs.eof())
		{
			std::string line = "";
			if (!std::getline(ifs, line)) break;
			if (line.empty()) continue;
			std::istringstream iss(line);
			std::string dump;
			if (!(iss >> dump))
			{
				throw std::runtime_error(
					"Error parsing file: " + file + " no token found.");
			}
			if (dump == "newmtl") // EX: newmtl AppleMaterial
			{
				if (material != nullptr)
				{
					mats[name] = material;
				}
				if (!(iss >> name))
				{
					throw std::runtime_error(
						"Error parsing file : " +
						file +
						" no name found in newmtl.");
				}
				material = std::make_shared<Material>(name);
			}
			else if (dump == "map_Ka") // EX: map_Ka ../Apple/Color.jpg
			{
				std::string texture_path;
				if (!(iss >> texture_path))
				{
					throw std::runtime_error(
						"Error parsing file : " +
						file +
						" no path found in map_Ka.");
				}
				material->SetAmbient(std::make_shared<Texture>(texture_path));
			}
			else if (dump == "map_Kd") // EX: map_Kd ../Apple/Color.jpg
			{
				std::string texture_path;
				if (!(iss >> texture_path))
				{
					throw std::runtime_error(
						"Error parsing file : " +
						file +
						" no path found in map_Kd.");
				}
				material->SetColor(std::make_shared<Texture>(texture_path));
			}
			else if (dump == "map_norm") // EX: map_norm ../Apple/Normal.jpg
			{
				std::string texture_path;
				if (!(iss >> texture_path))
				{
					throw std::runtime_error(
						"Error parsing file : " +
						file +
						" no path found in map_norm.");
				}
				material->SetNormal(std::make_shared<Texture>(texture_path));
			}
			else if (dump == "map_Pm") // EX: map_Pm ../Apple/Metalness.jpg
			{
				std::string texture_path;
				if (!(iss >> texture_path))
				{
					throw std::runtime_error(
						"Error parsing file : " +
						file +
						" no path found in map_Pm.");
				}
				material->SetMetallic(std::make_shared<Texture>(texture_path));
			}
			else if (dump == "map_Pr") // EX: map_Pr ../Apple/Roughness.jpg
			{
				std::string texture_path;
				if (!(iss >> texture_path))
				{
					throw std::runtime_error(
						"Error parsing file : " +
						file +
						" no path found in map_Pr.");
				}
				material->SetRoughness(std::make_shared<Texture>(texture_path));
			}
			else if (dump == "d")
			{

			}
			else if (dump == "illum")
			{

			}
			else if (dump == "Ka") // Ka = Ambiant
			{
				
			}
			else if (dump == "Kd") // Kd = Color
			{
				
			}
			else if (dump == "norm") // norm = normal
			{
				
			}
			else if (dump == "Pm") // Pm = metallic
			{
				
			}
			else if (dump == "Pr") // Pr = roughness
			{
				
			}

		}

		mats[name] = material;
		return mats;

	}
	
	/* GETTERS & SETTERS*/
	std::shared_ptr<Texture> Material::GetAmbient()
	{
		return ambient_;
	}
	std::shared_ptr<Texture> Material::GetColor()
	{
		return color_;
	}
	std::shared_ptr<Texture> Material::GetNormal()
	{
		return normal_;
	}
	std::shared_ptr<Texture> Material::GetRoughness()
	{
		return roughness_;
	}
	std::shared_ptr<Texture> Material::GetMetallic()
	{
		return metallic_;
	}
	void Material::SetAmbient(std::shared_ptr<Texture> ambient)
	{
		ambient_ = ambient;
	}
	void Material::SetColor(std::shared_ptr<Texture> color)
	{
		color_ = color;
	}
	void Material::SetNormal(std::shared_ptr<Texture> normal)
	{
		normal_ = normal;
	}
	void Material::SetRoughness(std::shared_ptr<Texture> roughness)
	{
		roughness_ = roughness;
	}
	void Material::SetMetallic(std::shared_ptr<Texture> metallic)
	{
		metallic_ = metallic;
	}

}