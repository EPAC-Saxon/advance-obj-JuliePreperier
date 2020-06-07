#pragma once

#include <functional>
#include <optional>
#include <map>
#include <string>
#include "Error.h"
#include "Texture.h"


namespace sgl {

	class Material
	{
	public:
		Material(std::shared_ptr<Texture> ambient, 
				 std::shared_ptr<Texture> color,
				 std::shared_ptr<Texture> normal,
				 std::shared_ptr<Texture> roughness,
				 std::shared_ptr<Texture> metallic);
		
		std::shared_ptr<Texture> GetAmbient();
		std::shared_ptr<Texture> GetColor();
		std::shared_ptr<Texture> GetNormal();
		std::shared_ptr<Texture> GetRoughness();
		std::shared_ptr<Texture> GetMetallic();


		void SetAmbient(std::shared_ptr<Texture> ambient);
		void SetColor(std::shared_ptr<Texture> color);
		void SetNormal(std::shared_ptr<Texture> normal);
		void SetRoughness(std::shared_ptr<Texture> roughness);
		void SetMetallic(std::shared_ptr<Texture> metallic);


	protected:
		
		std::shared_ptr<Texture> ambient_;
		std::shared_ptr<Texture> color_;
		std::shared_ptr<Texture> normal_;
		std::shared_ptr<Texture> roughness_;
		std::shared_ptr<Texture> metallic_;
		// Error setup.
		const Error& error_ = Error::GetInstance();

	};

	std::map<std::string, std::shared_ptr<Material>> LoadMatFromMtl(std::string file);
	// avoir texture dans map sharedptr texture 5x
	// couleur, normal, roughness, ambiantOcclusion, metallic
	// constructor avec els 5 text
	// getter des textures
	// fonction externe qui retourne la map loadMatfrom
	// -> prend la string qui représente le mat mtl et qui cherche les infos dedans et qui les load dans la map.

	// appeler le mat au moment du loadOBJ
	// prendre la première ligne mtllib Scene.mtl 

	// Modifier le parse de mesh -> il parse 1 mesh. Mais il faut loader une scene avec plusieurs mesh.
	// scene.obj a plusieurs mesh (de O à O) 
	// auto obj_file = LoadFromObj(file); -> charge un objFile 
	// autre programme depuis exterieur qui va couper le texte

}