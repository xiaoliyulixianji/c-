#include <iostream>
#include <cmath>

// 定义一个三维向量结构
struct Vector3 {
	double x, y, z;

	// 构造函数
	Vector3(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

	// 叉积运算
	Vector3 cross(const Vector3& other) const {
		return Vector3(
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x
		);
	}

	// 点积运算
	double dot(const Vector3& other) const {
		return x * other.x + y * other.y + z * other.z;
	}

	// 判断向量是否为零向量
	bool isZero() const {
		return std::fabs(x) < 1e-6 && std::fabs(y) < 1e-6 && std::fabs(z) < 1e-6;
	}

	// 判断向量是否为标量倍数
	bool isScalarMultipleOf(const Vector3& other) const {
		if (isZero() || other.isZero()) return false;
		double ratioX = x / other.x;
		double ratioY = y / other.y;
		double ratioZ = z / other.z;
		return std::fabs(ratioX - ratioY) < 1e-6 && std::fabs(ratioY - ratioZ) < 1e-6;
	}
};

// 判断两个法向量是否平行
bool areParallel(const Vector3& n1, const Vector3& n2) {
	// 叉积为零则平行
	Vector3 s = n1.cross(n2);
	return s.isZero();
}

// 判断两个法向量是否重合
bool areCoincident(const Vector3& n1, const Vector3& n2) {
	// 如果平行且方向相同（或者相反），认为重合
	return areParallel(n1, n2) && n1.isScalarMultipleOf(n2);
}

int main() {
	Vector3 n1(1, 1, 1);  // 第一个法向量
	Vector3 n2(2, 2, 2);  // 第二个法向量

	// 判断是否平行
	if (areParallel(n1, n2)) {
		std::cout << "两个法向量平行。" << std::endl;
	}
	else {
		std::cout << "两个法向量不平行。" << std::endl;
	}

	// 判断是否重合
	if (areCoincident(n1, n2)) {
		std::cout << "两个法向量重合。" << std::endl;
	}
	else {
		std::cout << "两个法向量不重合。" << std::endl;
	}

	return 0;
}
