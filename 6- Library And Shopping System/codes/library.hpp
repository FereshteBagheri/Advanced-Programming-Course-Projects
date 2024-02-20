#include "member.hpp"

class Library {
public:
	void add_student_member(string student_id, string strudent_name); 
	void add_prof_member(string prof_name);
	void add_book(string book_title, int copies); 
	void add_magazine(string magazine_title, int year, int number, int copies);
	void add_reference(string reference_title, int copies);
	void borrow(string member_name, string document_title); 
	void extend(string member_name, string document_title); 
	void return_document(string member_name, string document_title);
	int get_total_penalty(string member_name);
	void time_pass(int days);
	bool has_joined_before(string _name);
	void check_membership(string _name);
	void check_doc_existence(string _name);
	void add_available_docs(string _title, int copies);
	bool is_doc_available(string _name);
	void delete_borrowed_doc(string doc_title);
	vector <Document*> get_documents() {
		return documents;
	}
	vector<string> available_titles() {
		return available_docs;
	}

private:
	int date=0;
	vector <Member*> members;
	vector <Document*> documents;
	vector <string> available_docs;
};
