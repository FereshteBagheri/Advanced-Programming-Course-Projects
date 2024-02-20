#include "library.hpp"

void Library::time_pass(int days) {
	if (days < 0) {
		cerr << INVALID_DAY << endl;
		exit(EXIT_SUCCESS);
	}
	date += days;
}

int Library ::get_total_penalty(string member_name) {
	for (int i = 0; i < members.size(); i++) {
		if (members[i]->get_name() == member_name) {
			return members[i]->get_penalty(date);
		}
	}
}

void Library:: delete_borrowed_doc(string doc_title) {
	for (int i = 0; i < available_docs.size(); i++) {
		if (available_docs[i] == doc_title) {
			available_docs.erase(available_docs.begin() + i);
			break;
		}
	}
}

bool Library::is_doc_available(string _name) {
	for (int i = 0; i < available_docs.size(); i++) {
		if (available_docs[i] == _name) {
			return true;
		}
	 }
	return false;
}

void Library:: add_available_docs(string _title, int copies) {
	for (int i = 0; i < copies; i++) {
		available_docs.push_back(_title);
	}
}

void Library :: check_doc_existence(string _name) {
	for (int i = 0; i < documents.size(); i++) {
		if (documents[i]->get_title() == _name) {
			cerr << DOCUMENT_ALREADY_EXISTS << endl;
			exit(EXIT_SUCCESS);
		}
	}
}


bool Library::has_joined_before(string _name) {
	for (int i = 0; i < members.size(); i++) {
		if (members[i]->get_name() == _name) {
			return true;
		}
	}
	return false;
}

void Library:: check_membership(string _name) {
	if (has_joined_before(_name)) {
		cerr << MEMBER_ALREADY_EXISTS << endl;
		exit(EXIT_SUCCESS);
	}
}

void Library::add_student_member(string student_id, string student_name) {
	if (student_id.empty() || student_name.empty()) {
		cerr << EMPTY_FILED_ERROR << endl;
		exit(EXIT_SUCCESS);
	}
	check_membership(student_name);
	Member* new_member = new Student(student_id, student_name);
	members.push_back(new_member);
}

void Library::add_prof_member(string prof_name) {
	if (prof_name.empty()) {
		cerr << EMPTY_FILED_ERROR << endl;
		exit(EXIT_SUCCESS);
	}
	check_membership(prof_name);
	Member* new_member = new Professor(prof_name);
	members.push_back(new_member);
}

void Library:: add_book(string book_title, int copies) {
	if (book_title.empty()) {
		cerr << EMPTY_FILED_ERROR << endl;
		exit(EXIT_SUCCESS);
	}
	check_doc_existence(book_title);
	Document* new_doc = new Book(book_title);
	documents.push_back(new_doc);
	add_available_docs(book_title, copies);
}

void Library::add_magazine(string magazine_title, int year, int number, int copies) {
	if (magazine_title.empty()) {
		cerr << EMPTY_FILED_ERROR << endl;
		exit(EXIT_SUCCESS);
	}
	check_doc_existence(magazine_title);
	if (number < 1) {
		cerr << INVALID_NUMBER_ERROR << endl;
		exit(EXIT_SUCCESS);
	}
	if (year < 1) {
		cerr << INVALID_YEAR_ERROR << endl;
		exit(EXIT_SUCCESS);
	}
	Document* new_doc = new Magazine(magazine_title,year,number);
	documents.push_back(new_doc);
	add_available_docs(magazine_title, copies);
}

void Library :: add_reference(string reference_title, int copies) {
	if (reference_title.empty()) {
		cerr << EMPTY_FILED_ERROR << endl;
		exit(EXIT_SUCCESS);
	}
	check_doc_existence(reference_title);
	Document* new_doc = new Reference(reference_title);
	documents.push_back(new_doc);
	add_available_docs(reference_title, copies);
}

void Library::borrow(string member_name, string document_title) {
	if (!is_doc_available(document_title)) {
		cerr << DOC_NOT_AVAILABLE_ERROR << endl;
		exit(EXIT_SUCCESS);
	}
	for (int i = 0; i < members.size(); i++) {
		if (members[i]->get_name() == member_name) {
			members[i]->borrow(document_title, date,get_documents());
			delete_borrowed_doc(document_title);
			break;
		}
	}
}

void Library:: extend(string member_name, string document_title) {
	for (int i = 0; i < members.size(); i++) {
		if (members[i]->get_name() == member_name) {
			members[i]->extend(document_title, date);
			break;
		}
	}
}

void Library:: return_document(string member_name, string document_title) {
	for (int i = 0; i < members.size(); i++) {
		if (members[i]->get_name() == member_name) {
			members[i]->return_document(document_title, date);
			break;
		}
	}
}
