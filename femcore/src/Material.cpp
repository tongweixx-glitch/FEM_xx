#include "Material.h"

namespace MyFEM {

	Matrix33 Material::getConstitutiveMatrix() const {
		Matrix33 D = Matrix33::Zero();

		if (type = MaterialType::PlaneStress) {
			Real factor = E / (1.0 - nu * nu);
			D(0, 0) = 1.0; D(0, 1) = nu;
			D(1, 0) = nu;   D(1, 1) = 1.0;
			D(2, 2) = (1.0 - nu) / 2.0;
			D *= factor;
		}
		else {
			Real factor = E / ((1.0 + nu) * (1.0 - 2.0 * nu));
			D(0, 0) = 1.0 - nu; D(0, 1) = nu;
			D(1, 0) = nu;       D(1, 1) = 1.0 - nu;
			D(2, 2) = (1.0 - 2.0 * nu) / 2.0;
			D *= factor;
		}
		return D;
	}
}