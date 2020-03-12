#pragma once
template <typename Adaptee>
class Adapter {
protected:
	Adaptee adaptee;

public:
	Adapter(
		Adaptee adaptee
	) : 
		adaptee(adaptee)
	{	}
};
