#pragma once
#include <iostream>

template<typename T>
struct Vector2;

using Vector2u = Vector2<unsigned int>;
using Vector2i = Vector2<int>;
using Vector2f = Vector2<float>;


template<typename T>
struct Vector2 {
	T x, y;
	Vector2(
		T x = T(),
		T y = T()
	) :
		x(x),
		y(y)
	{	}

	Vector2<T> operator+(const Vector2<T>& rhs)const {
		return Vector2<T>(x + rhs.x, y + rhs.y);
	}
	
	Vector2<T>& operator+=(const Vector2<T>& rhs) {
		return *this = *this + rhs;
	}

	Vector2<T> operator-(const Vector2<T>& rhs)const {
		return Vector2<T>(x - rhs.x, y - rhs.y);
	}

	Vector2<T>& operator-=(const Vector2<T>& rhs) {
		return *this = *this - rhs;
	}

	Vector2<T> operator*(const Vector2<T>& rhs)const {
		return Vector2<T>(x * rhs.x, y * rhs.y);
	}

	Vector2<T>& operator*=(const Vector2<T>& rhs) {
		return *this = *this * rhs;
	}

	Vector2<T> operator/(const Vector2<T>& rhs)const {
		return Vector2<T>(x / rhs.x, y / rhs.y);
	}

	Vector2<T> operator+(const T& value) const{
		return *this +Vector2<T>(value, value);
	}

	Vector2<T> operator-(const T& value)const {
		return *this -Vector2<T>(value, value);
	}

	Vector2<T> operator*(const T& value) const{
		return *this * Vector2<T>(value, value);
	}

	Vector2<T> operator/(const T& value) const{
		return *this / Vector2<T>(value, value);
	}


	T total()const {
		return x + y;
	}

	Vector2f normalize()const {
		float l = length();
		return Vector2f(x / l, y / l);
	}
	
	float length()const {
		return sqrt(pow(x, 2) + pow(y, 2));
	}

	

	friend std::ostream& operator<<(std::ostream& out, const Vector2<T>& vec) {
		out << "[" << vec.x << " " << vec.y << "]";
		return out;
	}
};


template<typename Src, typename Dest>
struct Vector2Converter {
	static Dest convert(Src src) {
		return Dest(src.x, src.y);
	}
};