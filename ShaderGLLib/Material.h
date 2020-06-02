#pragma once

#include <functional>
#include <optional>
#include <map>
#include <string>
#include "Error.h"


namespace sgl {

	class Material
	{
	public:


	private:
		std::map<std::string, std::shared_ptr<Material>> material_;
		// Error setup.
		const Error& error_ = Error::GetInstance();
	};

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

}	// End of namespace sgl.
