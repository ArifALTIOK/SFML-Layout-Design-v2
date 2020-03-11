#pragma once
#include "ITransformable.hpp"

class Transformable : public ITransformable {
	Vector2f m_position;
	Vector2f m_origin;
	Vector2f m_scale;
	float m_angle;
public:
	Vector2f getPosition()const {
		return m_position;
	}

	Vector2f getOrigin()const {
		return m_origin;
	}

	Vector2f getScale()const {
		return m_scale;
	}

	float getRotation()const {
		return m_angle;
	}

	void setPosition(const Vector2f& position) {
		m_position = position;
	}

	void setOrigin(const Vector2f& origin) {
		m_origin = origin;
	}

	void setScale(const Vector2f& scale) {
		m_scale = scale;
	}

	void setRotation(float angle) {
		m_angle = angle;
	}
};