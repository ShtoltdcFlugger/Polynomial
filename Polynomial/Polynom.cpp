#include <stdexcept>

#include "Polynom.h"

Polynom::Polynom() {
	c.clear();
	c.push_back(0);
}
Polynom::Polynom(std::vector<double> _c) {
	c.clear();
	if (_c.size() == 0)
		throw std::invalid_argument("Polynom _c.size() == 0");
	c = _c;
	while ((c.back() == 0) && (c.size() > 1))
		c.pop_back();
}
Polynom::Polynom(double _c_0) {
	c.clear();
	c.push_back(_c_0);
}

double Polynom::operator()(double x) {
	double x_n = 1;
	double value = 0;
	for (auto& i : c) {
		value += x_n * i;
		x_n *= x;
	}
	return value;
}
const double& Polynom::operator[](int i) const {
	return c[i];
}
double& Polynom::operator[](int i) {
	return c[i];
}

Polynom& Polynom::operator+=(const Polynom& p)
{
	*this = *this + p;
	return *this;
}
Polynom& Polynom::operator-=(const Polynom& p)
{
	*this = *this - p;
	return *this;
}
Polynom& Polynom::operator*=(const Polynom& p)
{
	*this = *this * p;
	return *this;
}
Polynom& Polynom::operator*=(const double& d)
{
	*this = *this * d;
	return *this;
}

int Polynom::size() const {
	return c.size();
}
void Polynom::remove_tail() {
	while ((c.back() == 0) && (c.size() > 1))
		c.pop_back();
}
void Polynom::shift(int shift)
{
	std::vector<double> tmp(shift);
	for (double& i : c) {
		tmp.push_back(i);
	}
	c = tmp;
}

Polynom operator-(const Polynom& p) {
	Polynom p_out = p;
	for (int i = 0; i < p.size(); i++)
		p_out[i] = -p_out[i];
	return p_out;
}
Polynom operator+(const Polynom& p, const Polynom& q) {
	Polynom p_out;
	if (p.size() > q.size()) {
		p_out = p;
		for (int i = 0; i < q.size(); i++)
			p_out[i] += q[i];
	}
	else {
		p_out = q;
		for (int i = 0; i < p.size(); i++)
			p_out[i] += p[i];
	}
	return p_out;
}
Polynom operator-(const Polynom& p, const Polynom& q) {
	return p + (-q);
}
Polynom operator*(const Polynom& p, const double& d)
{
	Polynom p_out = p;
	for (int i = 0; i < p.size(); i++)
		p_out[i] = p[i] * d;
	return p_out;
}
Polynom operator*(const double& d, const Polynom& p)
{
	return p * d;
}
Polynom operator*(const Polynom& p, const Polynom& q)
{
	Polynom p_out;
	for (int i = 0; i < p.size(); i++)
		p_out += shift(p, i) * q[i];
	return p_out;
}

Polynom shift(const Polynom& p, int shift)
{
	std::vector<double> tmp(shift);
	for (int i = 0; i < p.size(); i++)
		tmp.push_back(p[i]);
	return Polynom(tmp);
}

std::ostream& operator<<(std::ostream& out, const Polynom& p) {
	for (size_t i = 0; i < p.size(); ++i) {
		out << p[i] << '\t';
	}
	return out;
}
