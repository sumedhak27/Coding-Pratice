#include <iostream>

using namespace std;
// static int n = 3;

void f1() {
	static int n = 5;
	while(cout<<n--<<" " && n > 0);
	cout<<endl;
}

void swapit(int &a, int &b) {
	a = a + b;
	b = a - b;
	a = a - b; 
}

void swappingHa(int &a, int&b){
	a^=b;
	b^=a;
	a^=b;
}

int main() {
	// static int n = 0;
	// f1();
	// if(cout<<++n<<" " && n<10 && main())
	int a = -18, b = -5;
	swapit(a,b);
	swappingHa(a,b);
	cout<<a<<" "<<b<<endl;
	int i = ~100^(~5);
	cout<<i<<endl;
	int j = 1;
	char* c = (char*)&j;
	for(int i = 0; i<sizeof(int); i++){
		printf(" %.2x", c[i]);
	}
	cout<<endl<<"*c = "<<(int)*c<<endl;
	if(*c) cout<<"Little endian"<<endl;
	else cout<<"Big Endian"<<endl;
	cout<<endl;
	return 0;
}

