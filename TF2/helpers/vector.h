#ifndef VECTOR_H
#define VECTOR_H
#ifdef _WIN32
#pragma once
#endif

class vector
{
public:

	float x, y, z;

	vector(void)
	{
		invalidate();
	}

	vector(float x, float y, float z)
	{
		this->x = x; this->y = y; this->z = z;
	}

	vector(float* clr)
	{
		x = clr[0]; y = clr[1]; z = clr[2];
	}

	float& operator[](int i)
	{
		return ((float*)this)[i];
	}

	float operator[](int i) const
	{
		return ((float*)this)[i];
	}

	bool operator==(const vector& src) const
	{
		return (src.x == x) && (src.y == y) && (src.z == z);
	}

	bool operator!=(const vector& src) const
	{
		return (src.x != x) || (src.y != y) || (src.z != z);
	}

	vector& operator+=(const vector& v)
	{
		x += v.x; y += v.y; z += v.z;
		return *this;
	}

	vector& operator-=(const vector& v)
	{
		x -= v.x; y -= v.y; z -= v.z;
		return *this;
	}

	vector& operator*=(float fl)
	{
		x *= fl; y *= fl; z *= fl;
		return *this;
	}

	vector& operator*=(const vector& v)
	{
		x *= v.x; y *= v.y; z *= v.z;
		return *this;
	}

	vector& operator/=(const vector& v)
	{
		x /= v.x; y /= v.y; z /= v.z;
		return *this;
	}

	vector&	operator+=(float fl)
	{
		x += fl; y += fl; z += fl;
		return *this;
	}

	vector&	operator/=(float fl)
	{
		x /= fl; y /= fl; z /= fl;
		return *this;
	}

	vector&	operator-=(float fl)
	{
		x -= fl; y -= fl; z -= fl;
		return *this;
	}

	vector operator-(void) const
	{
		return vector(-x, -y, -z);
	}

	vector operator+(const vector& v) const
	{
		return vector(x + v.x, y + v.y, z + v.z);
	}

	vector operator-(const vector& v) const
	{
		return vector(x - v.x, y - v.y, z - v.z);
	}

	vector operator*(float fl) const
	{
		return vector(x * fl, y * fl, z * fl);
	}

	vector operator*(const vector& v) const
	{
		return vector(x * v.x, y * v.y, z * v.z);
	}

	vector operator/(float fl) const
	{
		return vector(x / fl, y / fl, z / fl);
	}

	vector operator/(const vector& v) const
	{
		return vector(x / v.x, y / v.y, z / v.z);
	}

	float length(void) const
	{
		return sqrtf(x * x + y * y + z * z);
	}

	float length2d(void) const
	{
		return sqrtf(x * x + y * y);
	}

	float dot(const vector& b) const
	{
		return (x * b.x + y * b.y + z * b.z);
	}

	void invalidate()
	{
		x = y = z = std::numeric_limits<float>::infinity();
	}

	void init(float x = 0.0f, float y = 0.0f, float z = 0.0f)
	{
		this->x = x; this->y = y; this->z = z;
	}

	float length_sqr(void) const
	{
		return (x * x + y * y + z * z);
	}

};

inline void vector_subtract(const vector& a, const vector& b, vector& result)
{
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
}

inline void vector_clear(vector& a)
{
	a.x = a.y = a.z = 0.0f;
}

inline void vector_copy(const vector& src, vector& dst)
{
	dst.x = src.x;
	dst.y = src.y;
	dst.z = src.z;
}

inline void vector_add(const vector& a, const vector& b, vector& c)
{
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
}

inline void vector_angles(const vector& forward, vector& angles)
{

	float tmp, yaw, pitch;

	if (forward.y == 0 && forward.x == 0) {

		yaw = 0;

		if (forward.z > 0) {
			pitch = 270;
		} else {
			pitch = 90;
		}

	} else {

		yaw = RAD2DEG(atan2f(forward.y, forward.x));

		if (yaw < 0)
			yaw += 360;

		tmp = forward.length2d();
		pitch = RAD2DEG(atan2f(-forward.z, tmp));

		if (pitch < 0)
			pitch += 360;

	}

	angles[0] = pitch;
	angles[1] = yaw;
	angles[2] = 0;

}

class __declspec(align(16))vector_aligned : public vector
{
public:

	inline vector_aligned(void) {};

	inline vector_aligned(float x, float y, float z)
	{
		init(x, y, z);
	}

	explicit vector_aligned(const vector& v)
	{
		init(v.x, v.y, v.z);
	}

	vector_aligned& operator=(const vector& v)
	{
		init(v.x, v.y, v.z);
		return *this;
	}

	float w;

};

#endif // !VECTOR_H