#include "document.hpp"

class Member {
public:
	Member(string _name) {
		name = _name;
	}
	string get_name() {
		return name; 
	}
	void check_being_borrowed_already(string doc_title);
	void check_docs_num_limit();
	void borrow(string doc_title, int date,vector<Document*> documents);
	void extend(string doc_name, int date);
	bool is_borrowd(string doc_title);
	void return_document(string document_title,int date);
	int get_penalty(int date);

protected:
	string name;
	int max_docs;
    vector<Document*> borrowed_docs;
	int penalty = 0;
};

class Student : public Member {
public:
	Student(string _id, string _name)
		: Member(_name) {
		id = _id;
		max_docs = STUDENT_MAX_DOCS_NUMBER;
	}
private:
	string id;
};

class Professor : public Member {
public:
	Professor(string _name) : Member(_name) {
		max_docs = PROFESSER_MAX_DOCS_NUMBER;
	}
};
