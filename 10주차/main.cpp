#include "math.h"

void main() {

	Vec3 Vector(0, 0); //������ 0,0���� ����
	Mat3 Matrix;//��� ����

	Matrix.Translate(3, 5); // 3,5�� �̵�
	Vector = Vector * Matrix; // ������ �����ε����� ���Ϳ� ��� ���
	Matrix.Rotate(30); // 30�� ȸ��
	Vector = Vector * Matrix;// ������ �����ε����� ���Ϳ� ��� ���
	Matrix.Scale(2); // ũ�⸦ 2��� Ȯ��
	Vector = Vector * Matrix;// ������ �����ε����� ���Ϳ� ��� ���

	cout << fixed;
	cout.precision(0); // �Ҽ��� ����

	cout << "������ 0,0�϶� 3,5�̵� 30��ȸ�� 2��Ȯ���������� ��ǥ����: " << endl;
	cout << Vector.Position[0] << "," << Vector.Position[1] << "�Դϴ�." << endl;
}