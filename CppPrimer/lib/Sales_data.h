#ifndef CPPLEARNING_SALES_DATA_H
#define CPPLEARNING_SALES_DATA_H

#include <string>
#include <iostream>

using namespace std;

class Sales_data {
// 为Sales_data的非成员函数所做的友元声明
    friend Sales_data add(const Sales_data &, const Sales_data &);

    friend istream &read(istream &, Sales_data &);

    friend ostream &print(ostream &, const Sales_data &);

public:
    Sales_data() = default;

    Sales_data(const string s, unsigned n, double p) : bookNo(std::move(s)), units_sold(n), revenue(p * n) {}

    Sales_data(const string &s) : bookNo(s) {}

    Sales_data(istream &);

    string isbn() const { return bookNo; }

    Sales_data &combine(const Sales_data &);

    double avg_price() const;

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

double Sales_data::avg_price() const {
    return units_sold ? revenue / units_sold : 0;
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// Sales_data接口的非成员组成部分的声明
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

istream &read(istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}


#endif //CPPLEARNING_SALES_DATA_H
