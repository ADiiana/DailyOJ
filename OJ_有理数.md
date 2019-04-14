# OJ_有理数

~~~C
#include<iostream>
#include<cmath>
//计算最大公约数
long long calcGCD(long long a, long long b){
	if (b == 0){
		return a;
	}
	return calcGCD(b, a % b);
}

class RationalNumber{
public:

	//构造函数(分子、分母),考虑了分子分母的各种情况，并由两个数
	//实例了一个有理数，这其中可能会调用Fraction函数。
	RationalNumber(long long numerator, long long denominator)
			:m_infinate(false),
			m_negative(false),
			m_fraction(nullptr)
	{
		if (numerator < 0){
			m_negative = true;
		}

		//分子为零，有理数无穷大。
		if (denominator == 0){
			m_infinate = true;
		}

		//保证分母不为负，当分母为负时，将负号转化到分子上。
		if (denominator < 0){
			m_negative = true;
			numerator *= -1;
			denominator *= -1;
		}

		//得出一个整数，计算如果余数不为0，则要转化为分数
		//由最大公约数化简分数
		m_integer = numerator / denominator;
		long long reminder = numerator % denominator;	//这是一个临时判断值
		if (reminder != 0){
			long long gcd = calcGCD(abs(reminder), denominator);
			m_fraction = new Fraction(reminder / gcd, denominator / gcd);
		}
	}

	//析构函数
	~RationalNumber(){
		if (m_fraction != nullptr){
			delete m_fraction;
		}
	}
public:
	RationalNumber operator+(RationalNumber const& o)const{
		long long numerator = this->numerator() * o.denominator()\
			+ o.numerator() * this->denominator();
		long long denominator = this->denominator() * o.denominator();

		return RationalNumber(numerator, denominator);
	}

	RationalNumber operator-(RationalNumber const& o)const{
		long long numerator = this->numerator() * o.denominator()\
			- o.numerator() * this->denominator();
		long long denominator = this->denominator() * o.denominator();

		return RationalNumber(numerator, denominator);
	}

	RationalNumber operator*(RationalNumber const& o) const{
		long long numerator = this->numerator() * o.numerator();
		long long denominator = this->denominator() * o.denominator();

		return RationalNumber(numerator, denominator);
	}

	RationalNumber operator/(RationalNumber const& o)const{
		long long numerator = this->numerator() * o.denominator();
		long long denominator = this->denominator() * o.denominator();

		return RationalNumber(numerator, denominator);
	}

public:
	friend std::ostream& operator<<(std::ostream& os, RationalNumber const& rn){
		if (rn.m_infinate){
			os << "Inf";
			return os;
		}

		if (rn.m_negative){
			os << "(-";
		}

		if (rn.m_integer != 0 || rn.m_fraction  != nullptr){
			long long integer = rn.m_integer;
			if (rn.m_integer){
				integer *= -1;
			}
			os << integer;
			if (rn.m_fraction != nullptr){
				os << " ";
			}
		}
		if (rn.m_fraction != nullptr){
			os << *(rn.m_fraction);
		}

		if (rn.m_negative){
			os << ")";
		}

		return os;
	}
public:
	long long numerator() const{
		if (m_fraction == nullptr){
			return m_integer;
		}
		else{
			return m_integer * m_fraction->m_denominator + m_fraction->m_numerator;
		}
	}

	long long denominator() const{
		if (m_fraction == nullptr){
			return 1;
		}
		else{
			return m_fraction->m_denominator;
		}
	}
private:

	//构造分数类
	class Fraction{
	public:

		//构造函数
		Fraction(long long numberator, long long denominator)
		:m_negative(false),
		m_numerator(numberator),
		m_denominator(denominator)
		{
			//如果是负数，输出时要标记。
			if (numberator < 0){
				m_negative = true;
			}
		}

		//分数的输出
		friend std::ostream& operator<<(std::ostream &os, Fraction const& f){
			long long numerator = f.m_numerator;
			if (f.m_negative){
				numerator *= -1;
			}
			os << numerator << '/' << f.m_denominator;

			return os;
		}

	public:
		long long m_numerator;	//分子
		long long m_denominator;	//分母
		bool m_negative;
	};

	bool m_infinate;	//分母是否为0
	bool m_negative;		//是不是负数
	long long m_integer;	//最小整数
	Fraction* m_fraction;	//分数的情况
};

int main(){

	long long a1, b1, a2, b2;
	scanf_s("%lld%lld%lld%lld", &a1, &b1, &a2, &b2);
	RationalNumber rn1(a1, b1), rn2(a2, b2);
	/*设计一个类，a1和b1处理之后，再做运算，其中要考虑分数的情况。*/
	std::cout << rn1 << " + " << rn2 << " = " << rn1 + rn2 << '\n';
	std::cout << rn1 << " - " << rn2 << " = " << rn1 - rn2 << '\n';
	std::cout << rn1 << " * " << rn2 << " = " << rn1 * rn2 << '\n';
	std::cout << rn1 << " / " << rn2 << " = " << rn1 / rn2 << '\n';

	system("pause");
	return 0;
}
~~~

