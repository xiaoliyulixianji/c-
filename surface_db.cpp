#include <iostream>
#include <vector>
#include <cmath>

// 结构体表示三维向量
struct Vector3D {
	double x;
	double y;
	double z;
	Vector3D(double x_ = 0, double y_ = 0, double z_ = 0) : x(x_), y(y_), z(z_) {}
};

// 计算两个三维向量的点积
double dotProduct(const Vector3D& v1, const Vector3D& v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// 计算三维向量的模
double magnitude(const Vector3D& v) {
	return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

// 判断两个向量是否平行
bool areParallel(const Vector3D& v1, const Vector3D& v2) {
	double cosTheta = dotProduct(v1, v2) / (magnitude(v1) * magnitude(v2));
	// 考虑浮点数误差，当余弦值接近 1 或 -1 时认为平行
	return std::fabs(cosTheta) > 0.9999;
}

// 判断两个向量是否重合，假设重合条件是平行且至少一个分量成比例
bool areCoincident(const Vector3D& v1, const Vector3D& v2) {
	if (!areParallel(v1, v2)) {
		return false;
	}
	// 检查是否成比例
	if (std::fabs(v1.x) > 0.0001 && std::fabs(v2.x) > 0.0001) {
		double ratio = v1.x / v2.x;
		if (std::fabs(v1.y / v2.y - ratio) < 0.0001 && std::fabs(v1.z / v2.z - ratio) < 0.0001) {
			return true;
		}
	}
	else if (std::fabs(v1.y) > 0.0001 && std::fabs(v2.y) > 0.0001) {
		double ratio = v1.y / v2.y;
		if (std::fabs(v1.x / v2.x - ratio) < 0.0001 && std::fabs(v1.z / v2.z - ratio) < 0.0001) {
			return true;
		}
	}
	else if (std::fabs(v1.z) > 0.0001 && std::fabs(v2.z) > 0.0001) {
		double ratio = v1.z / v2.z;
		if (std::fabs(v1.x / v2.x - ratio) < 0.0001 && std::fabs(v1.y / v2.y - ratio) < 0.0001) {
			return true;
		}
	}
	return false;
}

int main() {
	Vector3D normal1(1, 2, 3);
	Vector3D normal2(2, 4, 6);
	if (areCoincident(normal1, normal2)) {
		std::cout << "这两个法向量是重合的" << std::endl;
	}
	else if (areParallel(normal1, normal2)) {
		std::cout << "两个法向量平行但不重合." << std::endl;
	}
	else {
		std::cout << "这两个法向量不平行." << std::endl;
	}
	return 0;
}
