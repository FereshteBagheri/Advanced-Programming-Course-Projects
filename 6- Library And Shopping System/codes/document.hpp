#include "define.hpp"

class Document {
public:
	Document(string _title) {
		title = _title;
	}
	string get_title() {
		return title;
	}
	void set_borrowing_date(int date);
	virtual void extend(int date);
	virtual int calculate_penalty(int date)=0;

protected:
	string title;
	int borrowing_period;
	int max_extend_num;
	int borrowing_date;
	int extension_num = 0;
	int return_date;
};

class Book : public Document {
public:
	Book(string _title) : Document(_title) {
		borrowing_period = BOOK_BORROWING_PERIOD;
		max_extend_num = BOOK_MAX_EXTEND_NUMBER;
	}
	virtual int calculate_penalty(int date);
};

class Magazine : public Document {
public:
	Magazine(string _title, int _year, int _number) : Document(_title) {
		year = _year;
		number = _number;
		borrowing_period = MAGAZINE_BORROWING_PERIOD;
		max_extend_num = MAGAZINE_MAX_EXTEND_NUMBER;
	}
	virtual int calculate_penalty(int date);
	virtual void extend(int date);
private:
	int year;
	int number;
};

class Reference : public Document {
public:
	Reference(string _title) : Document(_title) {
		borrowing_period = REFERENCE_BORROWING_PERIOD;
		max_extend_num = REFERENCE_MAX_EXTEND_NUMBER;
	}
	virtual int calculate_penalty(int date);
};

