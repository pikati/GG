#pragma once

class Vector2
{
private:

public:
	Vector2();
	Vector2(float x, float y);
	float x, y;
	void Set(float x, float y);
	const Vector2 operator+(const Vector2& vec) const;
	const Vector2 operator-(const Vector2& vec) const;
	Vector2& operator+=(const Vector2& vec);
};

class Vector3
{
private:
	
public:
	Vector3();
	Vector3(float x, float y, float z);
	float x, y, z;

	static Vector3 back;
	static Vector3 down;
	static Vector3 forward;
	static Vector3 left;
	static Vector3 one;
	static Vector3 right;
	static Vector3 up;
	static Vector3 zero;

	void Set(float x, float y, float z);

	//�֐��̃P�c��const�̓����o��ύX�ł��Ȃ���������
	const Vector3 operator+(const Vector3& vec) const;
	const Vector3 operator-(const Vector3& vec) const;
	//*��/�̓N���X�O�Ɏ������ׂ� �����œ����N���X�^�����Ȃ��ꍇ����
	/*const Vector3 operator*(const float n) const;
	const Vector3 operator/(const float n) const;*/
	Vector3& operator+=(const Vector3& vec);
};

class Vector4
{
private:

public:
	Vector4();
	Vector4(float x, float y, float z, float w);
	float x, y, z, w;

	void Set(float x, float y, float z, float w);

	const Vector4 operator+(const Vector4& vec) const;
	const Vector4 operator-(const Vector4& vec) const;
	Vector4& operator+=(const Vector4& vec);
};

class Transform
{
public:
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;
};

#pragma region struct

struct Vertex2D
{
	Vector3 position;
	Vector2 coordinate;
	Vector4 color;
};

#pragma endregion