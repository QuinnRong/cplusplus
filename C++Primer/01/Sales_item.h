#ifndef SALESITEM_H
#define SALESITEM_H

#include <iostream>
#include <string>

class Sales_item
{
friend std::istream& operator>>(std::istream&, Sales_item&);
friend std::ostream& operator<<(std::ostream&, const Sales_item&);
public:
	// constructor
	Sales_item() = default;
	// operator
	Sales_item& operator+=(const Sales_item&);
	// member function or method
	double avg_price() const;
	std::string isbn() const { return bookNo; }
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_item operator+(const Sales_item&, const Sales_item&);

Sales_item& Sales_item::operator+=(const Sales_item& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

double Sales_item::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

std::istream& operator>>(std::istream& in, Sales_item& s)
{
	double price;
	in >> s.bookNo >> s.units_sold >> price;
	// check that the inputs succeeded
	if (in)
		s.revenue = s.units_sold * price;
	else
		s = Sales_item();
	return in; 
}

std::ostream& operator<<(std::ostream& out, const Sales_item& s)
{
	std::cout << s.bookNo << " " << s.units_sold << " "
			  << s.revenue << " " << s.avg_price();
	return out;
}

Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs)
{
	Sales_item ret(lhs);
	ret += rhs;
	return ret;
}

#endif
