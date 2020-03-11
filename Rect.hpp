#pragma once
#include "Vector2.hpp"

template<typename T>
struct Rect {
	T left, top, width, height;
	Rect(
		const Vector2<T>& position,
		const Vector2<T>& dimension
	) :
		Rect(
			position.x,
			position.y,
			dimension.x,
			dimension.y
		)
	{	}

	Rect(
		T left = T(),
		T top = T(),
		T width = T(),
		T height = T()
	) : 
		left(left),
		top(top),
		width(width),
		height(height)
	{	}

	Vector2f position()const {
		return Vector2f(left, top);
	}

	Vector2f dimension()const {
		return Vector2f(width, height);
	}

	friend std::ostream& operator<<(std::ostream& out, const Rect<T>& rect) {
		out << Vector2f(rect.left, rect.top) << " " << Vector2f(rect.width, rect.height);
		return out;
	}
};

using FloatInt = Rect<int>;
using FloatRect = Rect<float>;