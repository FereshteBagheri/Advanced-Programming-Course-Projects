#include "document.hpp"

void Document :: set_borrowing_date(int date) {
	borrowing_date = date;
	return_date = borrowing_date + borrowing_period;
}

void Document :: extend(int date) {
	if (date == borrowing_date) {
		cerr << EXTEND_AT_FIRST_DAY_ERROR << endl;
		exit(EXIT_SUCCESS);
	}
	if (extension_num == max_extend_num) {
		cerr << EXTENSION_NUM_LIMIT_ERROR << endl;
		exit(EXIT_SUCCESS);
	}
	if (date > return_date) {
		cerr << LATE_EXTENSION_ERROR << endl;
		exit(EXIT_SUCCESS);
	}
	return_date += borrowing_period;
 }

 int Book :: calculate_penalty(int date) {
	int delay_period = date - return_date;
	int penalty = 0;
	if (delay_period < 1) {
		return 0;
	}
	if (delay_period < 8) {
		penalty = delay_period * (2000);
	}
	else if (delay_period > 7 && delay_period < 22) {
		penalty = 7 * (2000) + (delay_period - 7) * (3000);
	}
	else{
		penalty = 7 * (2000) + 14 * (3000)+(delay_period-21)*(5000);
	}
	return penalty;
}

int Magazine::calculate_penalty(int date) {
	int delay_period = date - return_date;
	int penalty = 0;
	if (delay_period < 1) {
		return 0;
	}
	if (year < (1390)) {
		penalty = delay_period * (2000);
	}
	else {
		penalty = delay_period * (3000);
	}
	return penalty;
}

 void Magazine::extend(int date) {
	 cout << MAGAZINE_EXTEND_ERROR << endl;
	 exit(EXIT_SUCCESS);
}

int Reference::calculate_penalty(int date) {
	int delay_period = date - return_date;
	int penalty = 0;
	if (delay_period < 1) {
		return 0;
	}
	if (delay_period < 3) {
		penalty = delay_period * (5000);
	}
	else {
		penalty = 3 * (5000)  + (delay_period - 3) * (7000);
	}
	return penalty;
}
