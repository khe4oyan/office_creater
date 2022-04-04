#include <iostream>
#include "structures.h"

int get_salary_or_tax(Worker* w, int size, std::string type);
void worker_set(Worker* worker);
void tax_set(Tax* tax_types);
void input_output_money(Office* office, bool showM);
Office* create_office();
void office_delete(Office *f);
void count_money_month(Office* f, int n);

//==================


// Ֆունկցիա որի միջոցով արժեքավորում էնք աշխատակցի տվյալներից անունը և ամսավճարը 
// և վերադարձնում ստացվածը
void worker_set(Worker* worker) {
	std::cout << "Enter name: ";
	std::cin >> worker->name;
	worker->month_salary = 45000 + (rand() * 1000) % 155001;
}

void tax_set(Tax* tax_types) {
	int prevTaxs[3]{};
	for (int i = 0; i < 3; ++i) {
		int tmp = (5 + rand() % 5);

		for (int j = 0; j < 3; ++j) {
			if (tmp == prevTaxs[j]) {
				continue;
			}
			prevTaxs[i] = tmp;
			break;
		}

		tax_types[i] = (Tax)tmp;
	}
}

// Ֆունկցիա որի միջոցով արժեքավորում էնք հաշվեկշռին 
//վերաբերվող բոլոր տվյալները և վերադարձնում ստացված օբյեկտը
void input_output_money(Office* office, bool showM = false) {
	static int month = 1;
	office->month_input_money = get_salary_or_tax(office->workers, office->worker_count, "salary");
	office->month_output_money = get_salary_or_tax(office->workers, office->worker_count, "tax");

	int tax = office->tax_types[0];
	for (int i = 1; i < 3; ++i) {
		tax += office->tax_types[i];
	}

	office->month_output_money *= tax / 100;

	office->all_money += office->month_input_money - office->month_output_money;

	if (showM) {
		std::cout << "Month " << month++ << ": " << office->all_money << std::endl;
	}
}

// Ֆունկցիա որի միջոցով արժեքավորում էնք աշխատավայրին վերաբերվող բոլոր տվյալները
// և վերադարձնում ստացված օբյեկտը  
Office* create_office() {
	Office* office = new Office;
	std::cout << "Enter worker count: ";
	std::cin >> office->worker_count;
	office->workers = new Worker[office->worker_count];

	for (int i = 0; i < office->worker_count; ++i) {
		worker_set(&(office->workers[i]));
	}

	tax_set(office->tax_types);

	input_output_money(office);

	return office;
}

// ֆունկցիա որի միջոցով ստանում էնք մեկ աշխատակցի կողմից
// վճարվող հարկերի ընդհանուր գումարային չափսը 
// և վերադարձնում ստացված գումարը
int get_salary_or_tax(Worker* w, int size, std::string type) {
	int tmp = 0;
	for (int i = 0; i < size; ++i) {
		if (type == "salary")		{tmp += w[i].month_salary;}
		else if (type == "tax") {tmp += w[i].month_tax;}
	}

	return tmp;
}

void office_delete(Office * f) {
	delete [] f->workers;
	delete f;
}

void count_money_month(Office *f) {
	int n{};
	std::cout << "\nEnter month: ";
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		input_output_money(f, true);
	}
}