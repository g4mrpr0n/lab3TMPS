#pragma once

class PaymentAbstract {
public:
	virtual float getRate(char x) = 0;
};