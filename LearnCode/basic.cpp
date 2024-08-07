#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<iomanip>
#include<bitset>
#include<string>
#include<cstring>//tv string của cstyle, mảng ký tự
#include<cstdlib>//random
#include<ctime>

#include<random>//random C++11
#include<array>

#include<vector>
#include<functional>
#include"Header.h"


using namespace std;
using namespace header;

bool tron = true;
const float g = tron ? 10 : 9.8;
int global = 3;
extern int a = 5;

/***************************************/
		/*******FUNCION*******/
/***************************************/
#if 1 FUNCION
	/*********VARIABLE FUNCION*******/
	#if 0 static_var_funcion
	void static_var(){
		static int i = 0;
		cout << i++ << endl;
		}
	#endif

	#if 1 //array
	void arrayfuncion(int arr2[]) {

		arr2[0] = 1000;
	}
	void printarray(int arr[], int n) {
		for (int i = 0; i < n; i++) {
			cout << arr[i]<<"\t";
		}
	}
	void themMotPhanTuVaoMang(int a[], int &n, int idx, int x)
	{
		if (idx >= 0 && idx <= n)
		{
			for (int i = n; i > idx; i--)
				a[i] = a[i - 1];
			a[idx] = x;
			n++;
		}
	}	
	void printarray2(array<int, 4> &arr) {
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << "\t";
		}
	}
	#endif

#endif


/*************************************************/
			/***** MAIN ****/
/*************************************************/
#if 0
int main() {

		/***************IOMANIP*******************/
#if 0
		int n;
		cin >> hex >> n;
		cout << dec << n;
#endif
		/************** BITSET *******************/
#if 0 đây là block bề bitset
		int a = 1;
		int b = a << 1;
		int c = ~a;
		int d = a | b;
		cout << bitset<8>(a) << endl;
		cout << bitset<8>(b) << endl;
		cout << bitset<16>(c) << endl;
		cout << bitset<8>(d) << endl;
#endif 
		/**************	STRING *******************/
#if 0 đây là block về string
	/*sring*/
#if 0 add string
		string a = "hello";
		string b = " world";
		a += b;
		cout << a;
#endif	
		/*getline*/
#if 0 đây là block string getline
		string chao = "Hello World";
		cout << chao << endl;

		string name;
		string age;

		cout << "nhap ten: ";
		// khi nhấn phím enter thì lấy dòng phía trên
		// getline(cin, strVar,'_')  gặp '_' thì mới dừng
		getline(cin, name);


		cout << "nhap tuoi: ";
		cin >> age;

		cout << name << "\t" << age;

#endif
		/*cin.ignore*/
#if 0 đây là block về cinignore

		string name;
		string age;

		cout << "nhap tuoi: ";
		cin >> age;
		cin.ignore();// cin.ignore( số ký tự cần xoá { max 32767 }, "ký tự gặp đến")

		cout << "nhap ten: ";
		// khi nhấn phím enter thì lấy dòng phía trên, ở đây enter ở age nên cần xoá bộ nhớ đệm
		getline(cin, name);
		cout << name << "\t" << age;
#endif

#endif 
		/*****************VARIABLE****************/
#if 0 variable : global-local-static_
		//không nên dùng biến toàn cục global
		int var = 10;
		int var2 = 6;
		{
			int var = 11;//đè lên var trước - khởi tạo biến mới
			var2 = 8; // là biến ở ngoài
			cout << var << endl;//11
			cout << var2 << endl;//8

			int global = 4;
			cout << global << endl;//4
			cout << ::global << endl;//3 (::là biến toàn cục)

		}
		cout << var << endl;//10
		cout << var2 << endl;//8
#endif
#if 0 static_var : external - internal_	 
		// static int a
		// lưỡng tính: ko bị huỷ - ko thấy khi rời hàm
		// được tạo ra 1 lần duy nhất, huỷ khi kết thúc chương trình
		// lần sau gọi thì giữ yên giá trị

		//extern int g_a-> dùng được ở file ngoài (khai báo ở đầu)
		//static int g_a-> chỉ dùng trong file, dùng giống như global (khai báo ở đầu)
		static_var();//0
		static_var();//1
		static_var();//2
		static_var();//3
		static_var();//4
#endif
		/**************** ÉP KIỂU ****************/
#if 0 ép kiểu
		//a) ép kieery ngầm định
			//nếu kiểu dl có size < int -> ép về int khi tính toán
			// không thì chuyển về theo thứ tự ưu tiên cao-> thấp
			/*
			-ld
			-d
			-f
			-ull
			-ul
			-l
			-ui
			-int
			*/
			//b) ép kiểu tường minh
				/*
				toán hạng cùng kiểu dữ liệu thì ko ép kiểu ngầm định
				double a=3.0/2
				double b = x*1.0/3

				1) Cstyle
				double(x);
				(double)x

				2) Static cast -  nên dùng
				static_cast<double>(x)

				*/
		double a = 1 / 3;	//0
		int x = 2;
		double b = x * 1.0 / 3;	//0.333333

		float c = 0.1f;//float
		float d = 0.1;//double


		cout << a << endl;
		cout << b << endl;
#endif

		/****************** HÀM ******************/
#if 0 hàm
		/*
		tham số - parameter
			void foo(int x){}-> x là tham số

		đối số - argument
			foo(1)-> 1 là đối số
			-> truyền giá trị, tham chiếu, địa chỉ

			a) truyền giá trị:
				->đối số là biến, hằng, biểu thức, struct, class, enumerator
				->đối số không bị thay đổi khi gọi hàm
				->chỉ có thể trả về 1 giá trị khi return
				->gây chậm do phải sao chép
			b) truyền tham chiếu
				b.1) tham chiếu
					int x=1
					void foo(int &y){}
					foo(x)

					-> đối số là biến
					-> thay đổi biến y thì x cũng thay đổi
					-> x và y cùng ở 1 vị trí trên ram

				b.2) tham chiếu hằng (nên dùng thay cho giá trị nếu có thể)
					void foo(const int &y){}
					foo(x)
					-> đối số có thể là hằng, biến
					-> đối số không bị thay đổi dù ở ngoài hay trong hàm (x,y không đổi)
					-> dùng tăng hiệu suất

		*/
#endif

		/****** TIỀN KHAI BÁO - ĐỊNH NGHĨA *******/
#if 0
	/*
	KHAI BÁO:
		+ dùng để cho ctrinh biết sự tồn tại của 1 cái gì đó -> chưa cần bộ nhớ
		+ có thể khai báo nhiều lần

		-biến:
			extern int y;-> để ctrinh biết y được khai báo chỗ khác-> chưa cầm khởi tạo biến

		-nguyên mẫu hàm:
			void foo(int x);
			void foo(int);

	ĐỊNH NGHĨA
		+ chỉ định nghĩa 1 lần

		int x=1;-> cần bộ nhớ
		void foo(int x){...}
	*/
#endif

	/********** CẤU TRÚC ĐIỀU KHIỂN **********/
#if 0 if_case_try_while_for... 
		/*
		-GO TO
			statement:
			...
			goto statement;

		-LỆNH DỪNG
			exit(0) //exit & return 0

		-RẼ NHÁNH
			if(){}
			else if(){}
			else{}

			condition ? a_if_true : b_if_false

			switch (n){ // không khởi tạo biến trong case, phải dùng const sau case
				case 1:
				...
				break;


				default:
				.....
				break;
			}
		-LẶP
			-while(){}
			-do{}while()

					int n;
					do{
						cout << "nhap n: ";
						cin >> n;

						if (cin.fail()) {
							cin.clear();
							cin.ignore();
						}
					} while (n % 2 == 1);

			-for (int i=0;i<n;i++){cout<<arr[i]}
			-for each (C++11)
				lặp các phần tử trên 1 mảng, vector, linkedlist, trees, maps
				không làm việc với con trỏ đến 1 mảng
				for each (auto i:arr){cout<<i}

		-NGOẠI LỆ (rộng hơn ERROR)
			https://viettuts.vn/lap-trinh-cpp/xu-ly-ngoai-le-trong-cpp
			https://cppdeveloper.com/c-nang-cao/xu-ly-ngoai-le-exception-handling-trong-c/
			- các đoạn code có thể gây ra lỗi được để trong try để giám sát, nếu lỗi nhảy đến đoạn code xử lý lỗi (if else khó thể biết được điều kiện lỗi nên dùng exception)

			-throw:	 Một chương trình ném một Exception khi một vấn đề xuất hiện. Việc này được thực hiện bởi sử dụng từ khóa throw trong C++.
			-catch:	 Một chương trình bắt một Exception với một Exception Handler tại vị trí trong một chương trình nơi bạn muốn xử lý vấn đề đó.
					 Từ khóa catch trong C++ chỉ dẫn việc bắt một exception.
			-try:	 Một khối try có thể được bắt bởi một số lượng cụ thể exception. Nó được theo sau bởi một hoặc nhiều khối catch.


	*****************************************************
			try
			{
			   // phan code duoc bao ve
			} catch( ten_Exception e ) hoac(...)
			{
			  // phan code de xu ly ngoai le co ten la ten_Exception
			}
	*****************************************************
			1	std::exception			Exception chung nhất và là class cụ tổ của tất cả các exception chuẩn khác trong C++
			2	std::bad_alloc			Cấp phát bộ nhớ không thành công. Có thể được ném ra bởi toán tử new:   vd: int *array= new int[99999999999999999999999]
			3	std::bad_cast			Ép kiểu động không thành công. Có thể được ném ra bởi dynamic_cast
			4	std::bad_exception		Có một exception nào đó được ném ra một cách không mong muốn
			5	std::bad_typeid			Được ném ra khi toán tử typeid thực hiện trên một con trỏ null
			6	std::logic_error		Các lỗi liên quan tới logic, thuật toán, tính hợp lệ của dữ liệu. Là class cha của các exception liên quan đến logic
			7	std::domain_error		Dữ liệu vượt quá khoảng cho phép
			8	std::invalid_argument	Truyền tham số không đúng cách
			9	std::length_error		Sử dụng các giá trị không hợp lệ để chỉ định kích thước / độ dài của tập hợp dữ liệu
			10	std::out_of_range		Sử dụng các indexs / keys không hợp lệ trong khi truy cập các bộ dữ liệu được đánh số / key
			11	std::runtime_error		Nó được thiết kế để đại diện cho tất cả các exceptions gây ra bởi các tình huống có thể xảy ra trong quá trình chạy của chương trình throw runtime_error("......")
			12	std::overflow_error		Tràn bộ nhớ do dữ liệu quá lớn so với kích thước bộ nhớ dùng để chứa nó
			13	std::range_error		Kết quả tính toán vượt quá khoảng cho phép
			14	std::underflow_error	Dữ liệu quá nhỏ để có thể biểu diễn giá trị có ý nghĩa
		*/

		/************** VD1 ****************/
		int x = 0;
		try {
			if (x == 0) throw "ban dang chia cho khong";
		}
		catch (const char* msg) {
			cout << "day la ngoai le" << endl;
		}
		/************** VD2 ****************/
		string name = "dung";
		try {
			//throw 123; catched by (...)
			cout << name.at(4) << endl;
			int* arr = new int[99999999999];
		}


		catch (out_of_range& e) {// hiện ra lỗi này do name.at(4) thực hiện trước
			cout << e.what();
		}
		catch (bad_alloc& e) {
			cout << e.what();
		}
		catch (exception& e) {// chung nhất
			cout << "exception catch: " << e.what() << endl;
		}
		catch (...) {// catch all
			cout << "Default exception catch" << endl;
		}

#endif
		/*************BREAK CONTINUE*************/
#if 0
		/*
		break; :	 dừng hàm đang chạy
		continue; :	 bỏ qua lần lặp và nhảy đến lần lặp tiếp theo
		*/
#endif
		/*****************RANDOM*****************/
#if 0
		/* C1 lấy thời gian thực hệ thống
		dùng thư viện cstd, ctime
		*/
		srand(time(NULL));

		// số ngẫu nhiên
		int a = rand();
		cout << a << endl;

		// giới hạn từ 1-100
		int b = rand() % 100 + 1;
		cout << b << endl;


		/*C2 dùng thư viện random - ưu tiên dùng
		mt19937 :		32bit
		mt19937_64 :	64bit
		*/
		random_device rd;
		mt19937 rdnumber(rd());
		// khởi tạo
		auto n = rdnumber();
		cout << n << endl;

		//để lấy giá trị nằm trong khoảng nào đó
		uniform_int_distribution<int> uni(1, 1000);
		auto m = uni(rdnumber);
		cout << m << endl;

#endif
		/******************MẢNG******************/
#if 0
		int arr[100];
		random_device rd;
		mt19937 rn(rd());
		uniform_int_distribution<int> uni(1, 1000);

		for (int i = 0; i < 100; i++) {
			arr[i] = uni(rn);
			//cout << arr[i] << endl;
		}


		int arr2[4] = { 1,2,3,4 };
		arrayfuncion(arr2);// change a[0] = 1000
		//printarray(arr2,4);

		int n = 4;
		addarray(arr2, n, 2, 9999);
		printarray(arr2, n);


#endif
#if 0 mảng ký tự
		//cin.getline(arr0, 10); nhận 10 giá trị thì dừng
		char arr[] = "dung";
		char arr2[] = "nguyen";
		cout << arr[4];
		cout << arr << endl;//ko can vong lap for
		cout << strlen(arr) << endl;

		//upper lower
		_strupr_s(arr);//strlwr
		cout << arr << endl;

		//copy
		char des[20];
		strcpy(des, arr);
		cout << des << endl;
		//nối chuỗi
		strcat(des, arr);
		cout << des << endl;
		//so sánh
		int cmp = strcmp(des, arr);
		cout << cmp << endl;
		// tìm kiếm chuỗi con, tim arr trong arr2
		if (strstr(arr2, arr) == NULL) cout << "khong thay" << endl;
		else cout << "thay" << endl;
#endif
		/***************** AUTO *****************/
#if 0 
	//auto before C++11
	//auto after C++11 để tự động nhận kiểu dữ liệu
	/*

	*/

#endif
	/**************** LỚP DỰNG SẴN **********/
#if 0
		array<int, 4> arr0 = { 1,4,2,3 };
		cout << arr0[3] << endl;
		cout << arr0.at(3) << endl;//quăng ra exception
		cout << arr0.size() << endl;

		cout << "xep tang: ";
		sort(arr0.begin(), arr0.end());//xep tang
		printarray2(arr0);
		sort(arr0.rbegin(), arr0.rend());
		cout << "\nxep giam: ";
		printarray2(arr0);

		// void arr(array<int, MAX> &arr){}
#endif
/****************** CON TRỎ **************/
#if 0
			// kích thước phụ thuộc vào cấu trúc máy tính
			// địa chỉ &
			// giá trị tại địa chỉ *
		int x;
		int* ptr = &x;
		*ptr = 10;
		std::cout << ptr << endl;
		std::cout << x;
		//trỏ NULL
		ptr = nullptr;


		//con trỏ void-> có thể trỏ đến bất cứ địa chỉ thuộc kiểu dữn liệu nào
		void* nptr;
		nptr = &x;
		static_cast<int*>(nptr);//chuyển thành int
#endif

#if 0
		//ptr+1 sẽ nhận địa chỉ có giá trị cùng kiểu dữ liệu tiếp theo
		int* ptrn = nullptr;

		int arr1[] = { 1,2,3,4 };
		int* ptr2 = arr1;
		cout << *(ptr2 + 1);
#endif
		/************** CẤP PHÁT ĐỘNG ***************/
#if 0
			//https://howkteam.vn/course/khoa-hoc-lap-trinh-c-can-ban/cap-phat-dong-trong-c-dynamic-memory-allocation-2734
			//dùng vùng nhớ heap - quản lý bởi HDH
		int* ptr = new int(5);
		cout << *ptr;
		delete ptr;//// trả lại vùng nhớ ptr đang trỏ đến cho hệ điều hành
		ptr = nullptr;// ko có vùng nhớ nào được cấp phát cho vùng nhớ này

#endif
#if 0 mảng động
		//int* arr = new int[4] {1, 2, 3, 4};
		// resize
		int size = 4;
		int* array = new int[size] {1, 2, 3, 4};

		int newsize = 10;
		int* narr = new int[newsize];


		for (int i = 0; i < size; i++) {
			narr[i] = array[i];
		}
		delete[] array;
		size = newsize;

		array = narr;
		delete[] array;
		// dễ lỗi -> dùng vector
#endif
/*************** CON TRỎ HẰNG **************/
#if 0
			//con trỏ hằng ko thể thay đổi giá trị mà nó trỏ đến
		const int var = 10;
		int x = 9;
		const int* ptr = &var;
		const int* ptr1 = &x;
		//*ptr1 = 11; lỗi
		x = 11;
		std::cout << *ptr1 << endl;
		std::cout << *ptr << endl;



		//hằng con trỏ ko thể thay đổi địa chỉ mà nó trỏ đến
		int var2 = 10;
		int var3 = 11;
		int* const ptr2 = &var2;
		*ptr2 = 10;
		//hằng con trỏ hằng
		int var4 = x;
		int* const ptr4 = &var4;

#endif
/************* THAM CHIẾU **************/
#if 0
			//biến: giá trị, con trỏ, tham chiếu
			// tham chiếu: ko cấp phát bộ nhớ, bí danh cho đối tượng được tham chiếu
			// địa chỉ đùng chung
			//an toàn hơn con trỏ, khởi tạo khi khai báo
			//khởi tạo với giá trị không phải hằng-> dùng tham chiếu hằng
			//const int &x=y;


			//dưới dạng bí danh
		int x1 = 10;
		int& x2 = x1;
		x2 = 11;
		cout << x1 << endl;

		//dưới dạng tham số hàm-> cho vào hàm
		//không tốn thêm bộ nhớ khởi tạo

#endif
/****** CON TRỎ TRỎ ĐẾN CON TRỎ ********/
#if 0
		//tránh sử dụng
		int row = 4;
		int col = 5;
		int** arr = new int* [row];
		for (int i = 0; i < row; i++) {
			arr[i] = new int[col];
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				arr[i][j] = i * j;
			}
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				std::cout << arr[i][j] << " ";
			}
			std::cout << endl;
		}

		for (int i = 0; i < row; i++) {
			delete[] arr[i];
			arr[i] = nullptr;
		}
		delete[] arr;

#endif
/************** VECTOR ****************/
#if 0
		//nên sử dụng
		//ngăn được rò rỉ bộ nhớ
		//thao tác với mảng động thay thế cho cấp phát động
		vector<int> arr = { 1,2,3,4 };
		cout << arr.at(3) << endl;
		cout << arr.size() << endl;
		cout << arr.capacity() << endl;
		arr.resize(5);
		arr.push_back(1);
		arr.pop_back();
		arr.pop_back();
		arr.pop_back();
		arr.pop_back();
		cout << arr.size() << endl;
		cout << arr.capacity() << endl;

		for (auto  &i : arr) {
			cout << i<<" ";
		}

#endif
/******* TRUYỀN ĐỊA CHỈ CHO HÀM *******/
#if 0
		/*


			void swap1(int &x, int&y ){
				int a;
				a=x;
				x=y;
				y=a;
			}




			void swap2(int *x, int *y){
				int a;
				a=*x;
				*x=*y;
				*y=a;
			}
			int main(){
			int x=1;
			int y=2;

			int z=3;
			int t=4;

			swap1(x,y);
			swap2(&z, &t);

			cout<<x<<endl;
			cout<<y<<endl;
			cout<<z<<endl;
			cout<<t<<endl;


			return 0;
			}
		
		*/

#endif
#if 0 truyền địa chỉ cho hàm bằng tham chiếu
		//void foo(int *&ptr){}
#endif

/*HÀM TRẢ VỀ GIÁ TRỊ, THAM CHIẾU, ĐỊA CHỈ*/
#if 0
		/*ham tra ve dia chi
		 
		int * makearray(int size){
		int *ptr= new int[size]

		return &ptr;
		}
		int main(){

		int *ptr2= makearray(10);

		}

		*/


		/* ham tra ve tham chieu (thông 2 chiều)
		* trả về tham chiếu tới phần tử truyền vào
		int & foo(){}



		foo()=10;
		
		
		*/
#endif
/************* HÀM NỘI TUYẾN **************/
#if 0
		/*
		* chương trình nhỏ thì gọi hàm tốn thời gian đáng kể để tìm, sao chép,.....
		* đề nghị thực hiện hàm nội tuyến
		* chèn hàm tại vị trí đang gọi
		* lặp, biến tĩnh, đệ quy, switch, go to->? ko gọi inline
		inline int max(int x, int y){
		return a>b?a:b;
		}
		int main(){
		cout<<max(3,6);<=> cout<<a>b?a:b;
		}
		
		* 
		*/
#endif

/************** NẠP CHỒNG HÀM **************/
#if 0
/*	overloading  
	//cùng 1 tên nhưng khác kiểu dữ liệu
	//nạp chông hàm với const khi là tham chiếu hoặc con trỏ

*/
#endif
/********* HÀM CÓ ĐỐI SỐ MẶC ĐỊNH *********/
#if 0
//default arguments
/*

int sum(int a, int b, int c=0){}
khai báo 1 trong 2

*/
#endif



/**************CON TRỎ HÀM***************/
#if 0
int arr[] = { 1,2,3,4 };
void(*funcptr)(int*, int ) = printarray;
(*funcptr)(arr, 4);


				// nắm giữ địa chỉ của 1 hàm

				/*
				bool tang(int a, int b){
					return a>b;
				}


				bool giam(int a, int b){
					return a<b;
				}

				void sort(int *arr, int n, bool(*funcptr)(int, int)){
					for(int i=0;i<n;i++){
						for(int j=i;j<n;j++){
							if((*funcptr)(arr[i], arr[j])){
								int a=arr[i];
								arr[i]=arr[j];
								arr[j]=a;
							}
						}
					}
				}
				void print(int *arr, int n){
					for(int i=0;i<n;i++){
						cout<<arr[i]<<" ";
					}
				}
				int main(){
				int arr[]={1,5,6,89,23,5,7,3.4};
				int n=sizeof(arr)/sizeof(int);

				sort(arr, n, tang);
				print(arr, n);
				return 0;
				}


				*/



#endif

#if 0 //#include funtional

	//để tiện hơn thì dùng #include<funcional>
	//funcion<kiểu dữ liệu hàm(kiểu dữ liệu truyền vào)> funcptr=func;
	int arr[] = { 1,2,3,4 };
	function<void(int*, int)> funcptr = printarray;
	funcptr(arr, 4);
	
#endif

#if 0 //từ khoá auto
	auto funcptr = printarray;
#endif


/**************** ĐỆ QUY *************/
#if 0
#endif

/************ KHUÔN MẪU HÀM *********/
#if 0
	/*
			template <class T>

			T add(T a, T b){
			return a+b;
			}

			int main(){
			cout<<add(1.2,2.2);
			return 0;
			}
	*/
#endif
	return 0;
}
#endif