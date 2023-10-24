#pragma once
#include "..\abstractions\payments\PaymentAbstract.h"
#include "PaymentLibrary.h"
class PaymentLibraryAdapter : public PaymentAbstract {
private:
	PaymentLibrary externalPayment;

public:
	PaymentLibraryAdapter(PaymentLibrary extPayment) : externalPayment(extPayment) {}

	float getRate(char x) override {
		return externalPayment.calculatePaymentRate(x);
	}
};
