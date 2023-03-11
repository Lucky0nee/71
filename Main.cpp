/*
Змініть наступну програму, замінивши звичайний вказівник на розумний вказівник std::unique_ptr
На додаткову оцінку допишіть метод для скорочення раціональних дробів
*/
#include <iostream>
#include <memory>

class Fraction {
public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator(numerator), m_denominator(denominator)
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1) {
		out << f1.m_numerator << "/" << f1.m_denominator;
		return out;
	}
private:
	int m_numerator = 0;
	int m_denominator = 1;
};

void printFraction(std::unique_ptr<Fraction> ptr) { // const Fraction* const ptr
	if (ptr)
		std::cout << *ptr;
}

int main() {
	std::unique_ptr<Fraction> ptr = std::make_unique<Fraction>(49, 11711);

	printFraction(std::move(ptr));
	return 0;
}
