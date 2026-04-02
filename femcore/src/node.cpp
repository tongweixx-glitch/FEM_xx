#include "Node.h"
#include <iomanip>

namespace MyFEM {

	void node::print()const {
		std::cout << "Node ID: " << id
			<< " | Coords: (" << std::fixed << std::setprecision(4)
			<< x << ", " << y << ", " << z << ")";

		if (!global_dof_indices.empty()) {
			std::cout << " | DOFs: [";
			for (size_t i = 0; i < global_dof_indices.size(); ++i) {
				std::cout << global_dof_indices[i] << (i == global_dof_indices.size() - 1 ? "" : ", ");
			}
			std::cout << "]";
		}
		std::cout << std::endl;
	}
}