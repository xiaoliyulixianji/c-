#include <iostream>
#include <cmath>

// ����һ����ά�����ṹ
struct Vector3 {
	double x, y, z;

	// ���캯��
	Vector3(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

	// �������
	Vector3 cross(const Vector3& other) const {
		return Vector3(
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x
		);
	}

	// �������
	double dot(const Vector3& other) const {
		return x * other.x + y * other.y + z * other.z;
	}

	// �ж������Ƿ�Ϊ������
	bool isZero() const {
		return std::fabs(x) < 1e-6 && std::fabs(y) < 1e-6 && std::fabs(z) < 1e-6;
	}

	// �ж������Ƿ�Ϊ��������
	bool isScalarMultipleOf(const Vector3& other) const {
		if (isZero() || other.isZero()) return false;
		double ratioX = x / other.x;
		double ratioY = y / other.y;
		double ratioZ = z / other.z;
		return std::fabs(ratioX - ratioY) < 1e-6 && std::fabs(ratioY - ratioZ) < 1e-6;
	}
};

// �ж������������Ƿ�ƽ��
bool areParallel(const Vector3& n1, const Vector3& n2) {
	// ���Ϊ����ƽ��
	Vector3 s = n1.cross(n2);
	return s.isZero();
}

// �ж������������Ƿ��غ�
bool areCoincident(const Vector3& n1, const Vector3& n2) {
	// ���ƽ���ҷ�����ͬ�������෴������Ϊ�غ�
	return areParallel(n1, n2) && n1.isScalarMultipleOf(n2);
}

int main() {
	Vector3 n1(1, 1, 1);  // ��һ��������
	Vector3 n2(2, 2, 2);  // �ڶ���������

	// �ж��Ƿ�ƽ��
	if (areParallel(n1, n2)) {
		std::cout << "����������ƽ�С�" << std::endl;
	}
	else {
		std::cout << "������������ƽ�С�" << std::endl;
	}

	// �ж��Ƿ��غ�
	if (areCoincident(n1, n2)) {
		std::cout << "�����������غϡ�" << std::endl;
	}
	else {
		std::cout << "�������������غϡ�" << std::endl;
	}

	return 0;
}
