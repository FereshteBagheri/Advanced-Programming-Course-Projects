#include "member.hpp"

int Member::get_penalty(int date) {
	for (int i = 0; i < borrowed_docs.size(); i++) {
		penalty += borrowed_docs[i]->calculate_penalty(date);
	}
	return penalty;
}

bool Member::is_borrowd(string doc_title) {
	for (int i = 0; i < borrowed_docs.size(); i++) {
		if (borrowed_docs[i]->get_title() == doc_title) {
			return true;
		}
	}
	return false;
}

void Member :: check_docs_num_limit(){
	if (borrowed_docs.size() == max_docs) {
		cerr << DOCS_NUMBER_LIMIT_ERROR << endl;
		exit(EXIT_SUCCESS);
}
}

void Member:: check_being_borrowed_already(string doc_title) {
	for (int i = 0; i < borrowed_docs.size(); i++) {
		if (borrowed_docs[i]->get_title() == doc_title) {
			cerr << ALREADY_BORROWED << endl;
			exit(EXIT_SUCCESS);
		}
	}
}

void Member::borrow(string doc_title, int date, vector<Document*> documents) {
	check_docs_num_limit();
	check_being_borrowed_already(doc_title);
	for (int i = 0; i < documents.size(); i++) {
		if (documents[i]->get_title() == doc_title) {
			Document* borrowed_doc = documents[i];
			borrowed_doc->set_borrowing_date(date);
			borrowed_docs.push_back(borrowed_doc);
			borrowing_history.push_back(doc_title);
			break;
		}
	}
}

void Member:: extend(string doc_title, int date) {
	if (!is_borrowd(doc_title)) {
		cerr << NOT_BORROWD_ERROR << endl;
		exit(EXIT_SUCCESS);
	}
	for (int i = 0; i < borrowed_docs.size(); i++) {
		if (borrowed_docs[i]->get_title() == doc_title) {
			borrowed_docs[i]->extend(date);
			break;
		}
	}
}

void Member::return_document(string document_title, int date) {
	if (!is_borrowd(document_title)) {
		cerr << NOT_BORROWD_ERROR << endl;
		exit(EXIT_SUCCESS);
	}
	for (int i = 0; i < borrowed_docs.size(); i++) {
		if (borrowed_docs[i]->get_title() == document_title) {
			penalty += borrowed_docs[i]->calculate_penalty(date);
			borrowed_docs.erase(borrowed_docs.begin() + i);
			break;
		}
	}
}
