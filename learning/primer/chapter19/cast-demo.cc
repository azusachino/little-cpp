#include <iostream>

using namespace std;


class QueryBase {
public:
	QueryBase() {}
	virtual ~QueryBase() {}
};

class BinaryQuery : public QuueryBase {
public:
	BinaryQuery() {}
	virtual ~BinaryQuery() {}
};

class AndQuery : public BinaryQuery {
public:
	AndQuery() = default;
	virtual ~AndQuery() {};
};

int main() {
	QueryBase* qb = new QueryBase;
	if (dynamic_cast<AndQuery*>(qb) != nullptr) {
		cout << "success." << endl;
	}
	else {
		cout << "failure." << endl;
	}
}

int main2() {
	QueryBase* qb = new QueryBase;
	try {
		dynamic_cast<AndQuery&>(qb);
		cout << "success." << endl;
	}
	catch (bad_cast& bc) {
		cout << "failure." << endl;
	}
}