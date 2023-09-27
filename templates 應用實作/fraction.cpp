#include<iostream>
#include<cmath>
using namespace std;

class Fraction {
private:
	float num;//分子
	float den;//分母
public:
	Fraction() {
		this->num = 0;
		this->den = 0;
	}
	Fraction(float num, float den) {
		this->num = num;
		this->den = den;
	}
	void set_num(float num) {
		this->num = num;
	}
	void set_den(float den) {
		this->den = den;
	}
	float get_num() {
		return this->num;
	}
	float get_den() {
		return this->den;
	}

	void operator -() {
		this->num = -this->num;
	}
	Fraction operator+(const Fraction& B) {
		Fraction temp;
		if (this->den == B.den) {
			temp.num = this->num + B.num;
			temp.den = this->den;
			return temp;
		}
		else {
			temp.num = this->num * B.den;
			temp.num = temp.num + (this->den * B.num);
			temp.den = this->den * B.den;
			return temp;
		}
	}
	void operator+=(const Fraction& B) {
		if (this->den == B.den) {
			this->num = this->num + B.num;
			this->den = this->den;
		}
		else {
			this->num = this->num * B.den;
			this->num = this->num + (this->den * B.num);
			this->den = this->den * B.den;
		}
	}
	void operator+=(const int B) {
		this->num = this->num + B * this->den;
		this->den = this->den;
	}
	Fraction operator-(const Fraction& B) {
		Fraction temp;
		if (this->den == B.den) {
			temp.num = this->num - B.num;
			temp.den = this->den;
			return temp;
		}
		else {
			temp.num = this->num * B.den;
			temp.num = temp.num - (this->den * B.num);
			temp.den = this->den * B.den;
			return temp;
		}
	}
	void operator-=(const Fraction& B) {
		if (this->den == B.den) {
			this->num = this->num - B.num;
			this->den = this->den;
		}
		else {
			this->num = this->num * B.den;
			this->num = this->num - (this->den * B.num);
			this->den = this->den * B.den;
		}
	}
	void operator-=(const int B) {
		this->num = this->num - B * this->den;
		this->den = this->den;
	}

	Fraction operator*(const Fraction& B) {
		Fraction temp;
		temp.num = this->num * B.num;
		temp.den = this->den * B.den;
		return temp;
	}
	void operator*=(const Fraction& B) {
		this->num = this->num * B.num;
		this->den = this->den * B.den;
	}
	Fraction operator/(const Fraction& B) {
		Fraction temp;
		temp.num = this->num * B.den;
		temp.den = this->den * B.num;
		return temp;
	}
	void operator/=(const Fraction& B) {
		this->num = this->num * B.den;
		this->den = this->den * B.num;
	}

	bool operator <(const Fraction& B) {
		if (float(this->num / this->den) < float(B.num / B.den)) {
			return true;
		}
		return false;
	}
	bool operator <=(const Fraction& B) {
		if ((this->num / this->den) < (B.num / B.den)) {
			return true;
		}
		else if ((this->num / this->den) == (B.num / B.den)) {
			return true;
		}
		return false;
	}
	bool operator >(const Fraction& B) {
		if ((this->num / this->den) > (B.num / B.den)) {
			return true;
		}
		return false;
	}
	bool operator >=(const Fraction& B) {
		if ((this->num / this->den) > (B.num / B.den)) {
			return true;
		}
		else if ((this->num / this->den) == (B.num / B.den)) {
			return true;
		}
		return false;
	}
	bool operator ==(const Fraction& B) {
		if ((this->num / this->den) == (B.num / B.den)) {
			return true;
		}
		return false;
	}
	bool operator !=(const Fraction& B) {
		if ((this->num / this->den) != (B.num / B.den)) {
			return true;
		}
		return false;
	}

	Fraction& operator++ () {//++i
		this->num = this->num + this->den;
		return *this;
	}
	Fraction operator++(int) {//i++
		Fraction temp = *this;
		this->num = this->num + this->den;
		return temp;
	}
	Fraction& operator--() {
		this->num = this->num - this->den;
		return *this;
	}
	Fraction operator--(int) {
		Fraction temp = *this;
		this->num = this->num - this->den;
		return temp;
	}

	friend ostream& operator<<(ostream& output, const Fraction& D) {
		output << "分子 : " << D.num << "\t分母 : " << D.den;
		return output;
	}
	friend istream& operator>>(istream& input, Fraction& D) {
		input >> D.num >> D.den;
		return input;
	}
};