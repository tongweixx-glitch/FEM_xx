#pragma once
#include"Common.h"

namespace MyFEM {

	class Node {
	public:
		int id;
		Real x, y, z;

		//degrees of freedom
		//全局矩阵中节点对应的编号（ux, uy)
		std::vector<int> global_dof_indices;

		Node(int _id, Real _x, Real _y, Real _z = 0.0)
			: id(_id), x(_x), y(_y), z(_z) {
		}

		void print() const;

		//自由度索引
		void setDofIndices(const std::vector<int>& indices) {
			global_dof_indices = indices
		}

		//节点坐标向量
		Vector3 getCoords() const {
			return Vector3(x, y, z);
		}
	};
}



/*
1. 创建节点
Node node1(1, 0.0, 0.0);      // 2D 节点，z=0
Node node2(2, 1.0, 0.0);

2. 全局自由度编号器会为每个节点的每个自由度分配全局编号
std::vector<int> dof_indices = { 0, 1 };  // 假设节点1的 ux->0, uy->1
node1.setDofIndices(dof_indices);

3. 组装单元刚度矩阵时，获取该节点的全局自由度索引
for (int dof : node1.global_dof_indices) {
	将单元矩阵元素累加到全局矩阵的第 dof 行/列

4. 输出调试信息
node1.print();

直接暴露成员变量 global_dof_indices 让外部代码随意修改，会破坏封装性。
通过 setDofIndices 函数，将来可以在函数内部添加检查
（例如确保 indices 非空或大小符合预期），而不影响外部调用。
*/