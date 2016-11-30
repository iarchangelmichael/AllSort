// New Base Type Int
class TestTypeInt{
	unsigned int val;
public:	

	TestTypeInt(){
		val = 0;
	}

	TestTypeInt(int v){
		val = v;
	}

	TestTypeInt(const TestTypeInt &v){
		val = v.val;
	}

	TestTypeInt& operator=(int v){
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

	void operator+=(int v){
		val += v;
	}

	void operator+=(TestTypeInt &v){
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

	TestTypeStr(int v){
		Set(v);
	}

	 TestTypeStr(TestTypeStr &v){
		Set(v);
	}

	TestTypeStr& operator=(int v){
		free(data);
		Set(v);
		return *this;
	}

	TestTypeStr& operator=(TestTypeStr &v){
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
		itoa(v, buf, 10);

		int sz = strlen(buf);
		data = (char*)malloc(sz + 1);
		memcpy(data, buf, sz);
		data[sz] = 0;
	}

	~TestTypeStr(){
		free(data);
	}

};