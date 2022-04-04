enum Tax{KP=5, HP, VP, EP, SP};

struct Worker {
	std::string name{};
	int month_salary{};
	int month_tax{};
};

struct Office {
	int worker_count{};
	Tax tax_types[3];
	Worker* workers = nullptr;
	
	long long all_money = 5000000;
	long long month_input_money{};
	long long month_output_money{};
};

