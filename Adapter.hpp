#pragma once
template <typename Adaptee>
class Adapter {
protected:
	Adaptee adaptee;
	Adapter(
		Adaptee adaptee
	) : 
		adaptee(adaptee)
	{	}
};
