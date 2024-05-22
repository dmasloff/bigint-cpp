//
// Created by Даниил Маслов on 29.11.2022.
//
#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class BigInteger;
class Rational;

BigInteger operator+(BigInteger a, const BigInteger& b);
BigInteger operator-(BigInteger a, const BigInteger& b);
BigInteger operator*(BigInteger a, const BigInteger& b);
BigInteger operator/(BigInteger a, const BigInteger& b);
BigInteger operator%(BigInteger a, const BigInteger& b);
bool operator==(const BigInteger& a, const BigInteger& b);
bool operator!=(const BigInteger& a, const BigInteger& b);
bool operator<(const BigInteger& a, const BigInteger& b);
bool operator>(const BigInteger& a, const BigInteger& b);
bool operator<=(const BigInteger& a, const BigInteger& b);
bool operator>=(const BigInteger& a, const BigInteger& b);
std::ostream& operator<<(std::ostream& os, const BigInteger& bigInteger);
std::istream& operator>>(std::istream& is, BigInteger& bigInteger);
BigInteger operator""_bi(unsigned long long num);
BigInteger operator""_bi(const char* c, size_t len);

Rational operator+(Rational a, const Rational& b);
Rational operator-(Rational a, const Rational& b);
Rational operator*(Rational a, const Rational& b);
Rational operator/(Rational a, const Rational& b);
bool operator==(const Rational& a, const Rational& b);
bool operator!=(const Rational& a, const Rational& b);
bool operator<(const Rational& a, const Rational& b);
bool operator>(const Rational& a, const Rational& b);
bool operator<=(const Rational& a, const Rational& b);
bool operator>=(const Rational& a, const Rational& b);
std::ostream& operator<<(std::ostream& os, Rational& r);

class BigInteger {
 public:
  BigInteger(long long num);
  BigInteger(const std::string& str);
  BigInteger();

  BigInteger& operator=(BigInteger other);
  BigInteger operator+() const;
  BigInteger operator-() const;
  BigInteger& operator+=(const BigInteger& other);
  BigInteger& operator-=(const BigInteger& other);
  BigInteger& operator*=(long long num);
  BigInteger& operator*=(const BigInteger& other);
  BigInteger& operator/=(const BigInteger& other);
  BigInteger& operator%=(const BigInteger& other);
  BigInteger& operator++();
  BigInteger operator++(int);
  BigInteger& operator--();
  BigInteger operator--(int);

  std::string toString() const;
  bool isNegative() const;
  void changeSign();
  void makePositive();
  void Swap(BigInteger& other);
  explicit operator bool() const;
  explicit operator int() const;
  ~BigInteger();

 private:
  static inline const long long kBase_ = 1e9;
  std::vector<long long> digits_;
  long long size_;
  bool isNegative_;

  long long operator[](long long ind) const;
  void shrinkDigits();
  void subtractionWithConstSign(const BigInteger& other);
  void subtractionWithChangeableSign(const BigInteger& other);
  void addition(const BigInteger& other);
  void commonCaseAddition(const BigInteger& other, bool isAddition);
  std::pair<BigInteger, BigInteger> division(const BigInteger& other);
  bool absGreater(const BigInteger& b) const;

  friend bool operator==(const BigInteger& a, const BigInteger& b);
  friend bool operator<(const BigInteger& a, const BigInteger& b);
};

BigInteger gcd(const BigInteger& a, const BigInteger& b);

class Rational {
 public:
  Rational(int num);
  Rational(const BigInteger& bi);
  Rational();
  Rational& operator=(const Rational& r);
  Rational& operator+=(const Rational& r);
  Rational& operator-=(const Rational& r);
  Rational& operator*=(const Rational& r);
  Rational& operator/=(const Rational& r);
  Rational operator-() const;
  Rational operator+() const;
  explicit operator double() const;
  std::string toString() const;
  std::string asDecimal(size_t precision) const;
  ~Rational();

  friend bool operator==(const Rational& a, const Rational& b);
  friend bool operator<(const Rational& a, const Rational& b);

 private:
  BigInteger numerator_, denominator_;
  void normalize();
};

#endif