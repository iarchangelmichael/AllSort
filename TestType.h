// New Base Type Int
class TestTypeInt{
	unsigned int val;
public:	

	TestTypeInt(){
		val = 0;
	}

	TestTypeInt(const int v){
		val = v;
	}

	TestTypeInt(const TestTypeInt &v){
		val = v.val;
	}

	TestTypeInt& operator=(const int v){
		val = v;
		return *this;
	}

	void operator=(const TestTypeInt &v){
		val = v.val;
	}

	void operator=(TestTypeInt &&v){
		val = v.val;
		v.val = 0;
	}

	void operator+=(const int v){
		val += v;
	}

	void operator+=(const TestTypeInt &v){
		val += v.val;
	}

	operator int(){
		return val;
	}

};


// New Base Type String
class TestTypeStr{
	char *data;
public:

	TestTypeStr(){
		data = 0;
	}

	TestTypeStr(const int v){
		Set(v);
	}

	 TestTypeStr(const TestTypeStr &v){
		Set(v);
	}

	TestTypeStr& operator=(const int v){
		free(data);
		Set(v);
		return *this;
	}

	TestTypeStr& operator=(const TestTypeStr &v){
		free(data);
		Set(v);
		return *this;
	}

	TestTypeStr& operator=(TestTypeStr &&v){
		free(data);
		data = v.data;
		v.data = 0;
		return *this;
	}

	TestTypeStr& operator+=(const TestTypeStr &v){
		char *odata = data;
		Set(this->operator int() + v.operator int());

		free(odata);
		return *this;
	}

	operator int() const{
		return atoi(data);
	}

	void Set(int v){
		char buf[16];
		//itoa(v, buf, 10);
		sprintf(buf, "%d", v);

		int sz = strlen(buf);
		data = (char*)malloc(sz + 1);
		memcpy(data, buf, sz);
		data[sz] = 0;
	}

	~TestTypeStr(){
		free(data);
	}

};