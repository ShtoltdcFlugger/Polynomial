#pragma once

#include <iostream>
#include <vector>

struct Polynom
{
	Polynom();

	Polynom(std::vector<double> _c);

	Polynom(double _c_0);
	template<typename ...Args>
	Polynom(double _c_0, Args ...args);

	double operator()(double x);

	const double& operator[](int i) const;
	double& operator[](int i);

	Polynom& operator+=(const Polynom& p);
	Polynom& operator-=(const Polynom& p);
	Polynom& operator*=(const Polynom& p);
	Polynom& operator*=(const double& d);

	int size() const;

	void remove_tail();
	void shift(int shift);

private:
	std::vector<double> c;
};

Polynom shift(const Polynom& p, int shift);

std::ostream& operator<<(std::ostream& out, const Polynom& p);
Polynom operator-(const Polynom& p);
Polynom operator+(const Polynom& p, const Polynom& q);
Polynom operator-(const Polynom& p, const Polynom& q);
Polynom operator*(const Polynom& p, const double& d);
Polynom operator*(const double& d, const Polynom& p);
Polynom operator*(const Polynom& p, const Polynom& q);

template<typename ...Args>
inline Polynom::Polynom(double _c_0, Args ...args)
{
	c.clear();
	Polynom tmp(args...);
	c.push_back(_c_0);
	for (auto& i : tmp.c)
		c.push_back(i);
	while ((c.back() == 0) && (c.size() > 1))
		c.pop_back();
}
