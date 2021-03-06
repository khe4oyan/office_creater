#include "function.h"

/* ---RULES by Hayk Darbinyan---
	1. don't use static arrays
	2. main have only functions
	3. function have meaningful names
	5. dont use char's array
	4. if function is bigger, divided in small functions
*/

/*
	ստեղծեք մեկ Office օբյեկտ և տվյալ օբյեկը արժեքավորեք create_office ֆունկցիայի միջոցով։
	Այնուհետև գրել ֆունկցիա, որը կվերադարձնի վեց ամիս անց տվյալ օբյեկտի հաշվեկշռին մնացած գումարի չափսը։
*/

int main() {
	ofc::Office* f = ofc::create_office();
	ofc::count_money_month(f);
	ofc::office_delete(f);
}