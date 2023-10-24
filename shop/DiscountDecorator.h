#pragma once
#include "..\inventory\BookDecorator.h"
class DiscountDecorator : public BookDecorator {
private:
	double discountPercentage;

public:
	DiscountDecorator(BookAbstract* b, double discount) : BookDecorator(b), discountPercentage(discount) {}

	double getPrice() override {
		double originalPrice = BookDecorator::getPrice();
		return originalPrice * (1 - discountPercentage);
	}
};