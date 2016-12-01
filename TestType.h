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
#ifdef WIN32
		itoa(v, buf, 10);
#else
		sprintf(buf, "%d", v);
#endif

		int sz = strlen(buf);
		data = (char*)malloc(sz + 1);
		memcpy(data, buf, sz);
		data[sz] = 0;
	}

	~TestTypeStr(){
		free(data);
	}

};



class StaticString
{
public:
    StaticString() : _offset(0), _size(0), _alloc(0) {}

	StaticString(const int v){
		char buf[16];
#ifdef WIN32
		itoa(v, buf, 10);
#else
		sprintf(buf, "%d", v);
#endif
		create(buf, strlen(buf));
	}

    explicit StaticString(const char *s)
    {
        create(s, strlen(s));
    }
 
    StaticString(const StaticString &other)
    {
        create(other.data(), other.size());
    }
 
    ~StaticString()
    {
        if (_alloc)
            deallocate(data());
    }

	StaticString operator =(const int v)
    {
		char buf[16];
#ifdef WIN32
		itoa(v, buf, 10);
#else
		sprintf(buf, "%d", v);
#endif
		deallocate(data());
		create(buf, strlen(buf));
		return *this;
	}
 
    StaticString operator =(const StaticString &other)
    {
        if (this == &other)
            return *this;
        // Don't try this at home!
        deallocate(data());
        create(other.data(), other.size());
        return *this;
    }

	StaticString operator +=(const StaticString &other)
    {
		*this = atoi(data()) + atoi(other.data());
		 return *this;
	}

	operator int(){
		return atoi(data());
	}
 
    char *data() { return _size ? thisPtr() + _offset : nullptr; }
    const char *data() const { return _size ? thisPtr() + _offset : nullptr; }
    size_t size() const { return _size; }
 
private:
    char *thisPtr() { return reinterpret_cast<char *>(this); }
    const char *thisPtr() const { return reinterpret_cast<const char *>(this); }
    void setData(char *data) { _offset = data - thisPtr(); }
    char *allocate(size_t size) { return reinterpret_cast<char *>(malloc(size)); }
    void deallocate(char *data) { free(data); }
    void create(const char *s, size_t len)
    {
        len++;
        auto data = allocate(len);
        memmove(data, s, len);
        setData(data);
        _size = len - 1;
        _alloc = len;
    }
 
private:
    ptrdiff_t _offset;
    size_t _size;
    size_t _alloc;
};