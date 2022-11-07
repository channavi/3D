#include <iostream>
#include <cmath>

using namespace std;
class Mat3 {
public:
    float Mat[3][3]; // 2�������

    Mat3() { //  ��� ������
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Mat[i][j] = 0; // ��� ���� �ʱ�ȭ
            }
        }
    }
    void Reset() { // ��� �ʱ�ȭ �Լ�
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Mat[i][j] = 0;
            }
        }
        Mat[2][2] = 1; //2���� ��ǥ���� z���� �������� �������� 1�� �ʱ�ȭ
    }

    void Translate(float x, float y)
    {
        Reset();
        Mat[0][0] = 1;
        Mat[1][1] = 1;
        Mat[2][0] = x;
        Mat[2][1] = y;
        // �̵� ��ȯ ��� ���Ŀ� �°� ����
    }

    void Rotate(float r)
    {
        Reset();
        double Rotate = r * (3.14 / 180); // ���� ����
        Mat[0][0] = cos(Rotate);
        Mat[0][1] = (-sin(Rotate));
        Mat[1][0] = sin(Rotate);
        Mat[1][1] = cos(Rotate);
        // ȸ�� ��ȯ ��� ���Ŀ� �°� ����
    }

    void Scale(float s)
    {
        Reset();
        Mat[0][0] = s;
        Mat[1][1] = s;
        // ũ�� ��ȯ ��� ���Ŀ� �°� ����
    }

};

class Vec3 {
public:
    float Position[2]; // 2������ǥ+������ǥ

    Vec3(float x, float y) { // ������
        Position[0] = x;
        Position[1] = y;
    }

    Vec3 operator *(Mat3& p) // ������ �����ε�
    {
        float x = Position[0]; // 3*1����� x����
        float y = Position[1]; // 3*1����� y����
        float z = 1; // 3*1����� z����
        float a = (x * p.Mat[0][0]) + (y * p.Mat[1][0]) + (z * p.Mat[2][0]); // ��İ� x��ǥ ����� ����
        float b = (x * p.Mat[0][1]) + (y * p.Mat[1][1]) + (z * p.Mat[2][1]); // ��İ� y��ǥ ����� ����
        // Z��ǥ�� 2�������� �ʿ�����Ƿ� ����
        return Vec3(a, b); // ����� x,y��ǥ ����
    }
}; #pragma once
