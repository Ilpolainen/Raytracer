#pragma once
#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec3
{
private:
	float e[3];
public:
	vec3();
	~vec3();
	vec3(const int i, const int j, const int k);
	vec3(const float x, const float y, const float z);
	vec3(const double x, const double y, const double z);

	inline float x() const { return e[0]; }
	inline float y() const { return e[1]; }
	inline float z() const { return e[2]; }

	// Unary operators

	inline const vec3& operator+() const { return *this; }
	inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

	// One args operators

	inline float operator[](int i) const { return e[i]; }
	inline float& operator[](int i) { return e[i]; }

	inline vec3 operator+(const vec3 &other) const { return vec3(e[0] + other.x(), e[1] + other.y(), e[2] + other.z()); }
	inline vec3 operator-(const vec3 &other) const { return vec3(e[0] - other.x(), e[1] - other.y(), e[2] - other.z()); }
	inline float operator*(const vec3 &other) const { return dot(other); }
	inline vec3 operator/(const vec3 &other) const { return vec3(e[0] / other.x(), e[1] / other.y(), e[2] / other.z()); }

	inline vec3 operator*(float a) const { return vec3(a * e[0], a * e[1], a * e[2]); }
	inline vec3 operator/(float a) const { float c = 1 / a; return vec3(e[0] * c, e[1] * c, e[2] * c); }
	inline vec3 operator*(int a) const { return operator*(float(a)); }
	inline vec3 operator/(int a) const { return operator/(float(a)); }

	inline vec3 operator+(float a) const { return vec3(e[0] + a, e[1] + a, e[2] + a); }
	inline vec3 operator+(int n) const { float a = float(n); return vec3(e[0] + n, e[1] + n, e[2] + n); }
	inline vec3 operator-(float a) const { return vec3(e[0] - a, e[1] - a, e[2] - a); }
	inline vec3 operator-(int n) const { float a = float(n); return vec3(e[0] - n, e[1] - n, e[2] - n); }

	inline vec3& operator+=(const vec3 &other) { e[0] += other.x(); e[1] += other.y(); e[2] += other.z(); return *this; }
	inline vec3& operator-=(const vec3 & other) { e[0] -= other.x(); e[1] -= other.y(); e[2] -= other.z(); return *this; }
	inline vec3& operator*=(const vec3 &other) { e[0] *= other.x(); e[1] *= other.y(); e[2] *= other.z(); return *this; }
	inline vec3& operator/=(const vec3 &other) { e[0] /= other.x(); e[1] /= other.y(); e[2] /= other.z(); return *this; }

	inline vec3& operator*=(float a) { e[0] *= a; e[1] *= a; e[2] *= a; return *this; }
	inline vec3& operator/=(float a) { float c = 1 / a;	e[0] *= c; e[1] *= c; e[2] *= c; return *this; }
	inline vec3& operator*=(int a) { return operator*=(float(a)); }
	inline vec3& operator/=(int a) { return operator/=(float(a)); }

	
	// Friend operators

	inline friend vec3 operator*(float t, const vec3 &v) { return v * t; }

	// Other inline operations

	inline float sqlength() const { return dot(*this); }
	inline float length() const { return sqrt(dot(*this)); }

	inline void normalize() { const float c = 1 / length(); e[0] *= c; e[1] *= c; e[2] *= c; }
	inline vec3 normalized() const { float c = 1 / length(); return vec3(e[0] * c, e[1] * c, e[2] * c); }

	inline float dot(const vec3& other) const { return x() * other.x() + y() * other.y() + z() * other.z(); }
	inline vec3 had(const vec3 &other) const { return vec3(x() * other.x(), y() * other.y(), z() * other.z()); }
	inline vec3 cross(const vec3 &other) const { 
		return vec3(
			y() * other.z() - other.y() * z(), 
			z() * other.x() - other.z() * x(), 
			x() * other.y() - other.x() * y()
		); 
	}

	inline friend std::ostream& operator<<(std::ostream &os, const vec3 &t) {
		os << "(" << t.e[0] << ", " << t.e[1] << ", " << t.e[2] << ")";
		return os;
	}
};

