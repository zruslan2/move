#include <iostream>

class string_ {
	char* str;
	int size;
public:
	string_(const char*v = nullptr) {
		str = new char[10];
	}
	string_(const string_&o) {}
	string_& operator=(const string_&o) {
		this->~string_();
		
	}
	~string_() { delete[]str; }

	string_(string_&&obj) {
		this->str = obj.str;
		this->size = obj.size;

		obj.size = 0;
		obj.str = nullptr;
	}
	string_& operator=(string_&&obj) {
		this->~string_();

		this->str = obj.str;
		this->size = obj.size;

		obj.size = 0;
		obj.str = nullptr;
	}

};


string_ getCurDate() {
	string_ dt;
	
	return std::move(dt);
}

void main() {

	string_ str(string_("hello"));//�����������

	string_ str2(str);//�����������

	string_ str3(std::move(str2));//�����������
								  //str2 = "sdfsdf";
	str2 = string_("asdasdasd");//�����������

	str2 = str3;//�����������
	str2 = std::move(str3);//�����������
						   //getCurDate() = str;
	int z;
	z = 5;
	//z lvalue
	//5 rvalue
	//5 = z;
}