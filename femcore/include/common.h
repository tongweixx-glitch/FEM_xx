#ifndef COMMOM_H
#define COMMOM_H

#pragma once

#include <vector>
#include<iostream>
#include<cmath>

#include <Eigen/Dense>
#include <Eigen/Sparse>

namespace MyFEM {
	using Real = double

	using MatrixXX = Eigen::Matrix<Real, Eigen::Dynamic, Eigen::Dynamic>;

	using VectorX = Eigen::Matrix<Real, Eigen::Dynamic, 1>;

	using Matrix22 = Eigen::Matrix<Real, 2, 2>;
	using Matrix33 = Eigen::Matrix<Real, 3, 3>;

	using Vector2 = Eigen::Matrix<Real, 2, 1>;
	using Vector3 = Eigen::Matrix<Real, 3, 1>;

	//稀疏矩阵
	using SparseMatrix = Eigen::SparseMatrix<Real>;
	// 稀疏矩阵插入器（组装矩阵临时存取工具）
	using Triplet = Eigen::Triplet<Real>;

	const Real PI = std::acos(-1.0);

	inline void logMessage(const std::string& msg) {
		std::cout << "[FEM LOG]: " << msg << std::endl;
	}

}

#endif