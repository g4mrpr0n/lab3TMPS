#pragma once
class PaymentLibrary {
public:
	float calculatePaymentRate(char a) {
		if (a == 'a')
			return 0.5;
		else if (a == 'c')
			return 1.0;
	}
};
