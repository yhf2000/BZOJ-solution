#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	while(1){
		printf("%d\n", ++ n);
		system("1009gen.exe > 1009.in"); printf("date is ok\n");
		system("1009.exe < 1009.in > 1009.out");printf("1 is ok\n");
	//	system("1009.exe < 1009.in"); printf("\n");
		system("1009_.exe < 1009.in > 1009.ans");printf("2 is ok\n");
	//	system("1009_.exe < 1009.in"); printf("\n");
	//	system("pause");
		if(system("fc 1009.out 1009.ans")) break;
	}
	return 0;
}
