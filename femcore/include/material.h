#pragma once
#include "Common.h"

namespace MyFEM {

	enum class MaterialType {
		Planestress,
		PlaneStrain
	};

	class Material {
	public:
		Real E;
		Real nu;
		Real thickness;    //2D
		MaterialType type;

		Material(Real _E, Real _nu, Real _t = 1.0, MaterialType _type = MaterialType::Planestress)
			: E(_E), nu(_nu), thickness(_t), type(_type) {
		}

		Matrix33 getConstitutiveMatrix() const;
	};
} 