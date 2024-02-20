#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;


const string EMPTY_FILED_ERROR = "Empty field";
const string MEMBER_ALREADY_EXISTS = "Name already exists";
const string DOCUMENT_ALREADY_EXISTS = "A document with the specified name already exists";
const string INVALID_NUMBER_ERROR = "Invalid number";
const string INVALID_YEAR_ERROR = "Invalid year";
const string DOC_NOT_AVAILABLE_ERROR = "This document does not exist";
const string ALREADY_BORROWED = "You borrowed this document already";
const string DOCS_NUMBER_LIMIT_ERROR = "Maximum number of allowed borrows exceeded";
const string MAGAZINE_EXTEND_ERROR = "You can't renew magazines";
const string EXTEND_AT_FIRST_DAY_ERROR = "You can't extend and borrow a document on the same day";
const string EXTENSION_NUM_LIMIT_ERROR = "You can't renew a document more than two times";
const string LATE_EXTENSION_ERROR = "You can't renew a document after receiving a penalty";
const string NOT_BORROWD_ERROR = "You have not borrowed this document";
const string  INVALID_DAY = "Invalid day";
const int BOOK_BORROWING_PERIOD = 10;
const int REFERENCE_BORROWING_PERIOD = 5;
const int MAGAZINE_BORROWING_PERIOD = 2;
const int STUDENT_MAX_DOCS_NUMBER = 2;
const int PROFESSER_MAX_DOCS_NUMBER = 5;
const int BOOK_MAX_EXTEND_NUMBER = 2;
const int REFERENCE_MAX_EXTEND_NUMBER = 2;
const int MAGAZINE_MAX_EXTEND_NUMBER = 0;