///*
//	Bài 10: Viết chương trình nhập vào chuỗi st (dạng con trỏ). 
//	a. Xuất giá trị từng ký tự của st thông qua con trỏ trỏ đến chuỗi.
//	b. Chuyển các ký tự của chuỗi về dạng chữ hoa (gợi ý: thay đổi mã ASCII)
//	c. Chuyển các ký tự đầu mỗi từ (đứng sau dấu cách) của chuỗi về dạng chữ hoa (gợi ý: thay 
//	đổi mã ASCII)
//	Ví dụ: “truong dai hoc CNTP TPHCM”  “Truong Dai Hoc CNTP TPHCM”
//*/
//
//#include <stdio.h>
//#include <ctype.h>
//#include <stdlib.h>
//
//int main() {
//	// Khai báo chuỗi st
//	char st[100];
//
//	// Nhập vào chuỗi st
//	printf("Nhap vao chuoi: ");
//	fgets(st, sizeof(st), stdin);
//
//	// a. Xuất giá trị từng ký tự của st thông qua con trỏ trỏ đến chuỗi
//	char *ptr = st;
//	printf("\nGia tri tung ky tu cua chuoi la:\n");
//	while (*ptr != '\0') {
//		printf("%c ", *ptr);
//		ptr++;
//	}
//
//	// b. Chuyển các ký tự của chuỗi về dạng chữ hoa
//	ptr = st;
//	while (*ptr != '\0') {
//		*ptr = toupper(*ptr);
//		ptr++;
//	}
//	printf("\nChuoi sau khi chuyen ve chu hoa: %s", st);
//
//	// c. Chuyển các ký tự đầu mỗi từ (đứng sau dấu cách) của chuỗi về dạng chữ hoa
//	ptr = st;
//	int startOfWord = 1;
//	while (*ptr != '\0') {
//		if (startOfWord && isalpha(*ptr)) {
//			*ptr = toupper(*ptr);
//			startOfWord = 0;
//		}
//		else if (*ptr == ' ') {
//			startOfWord = 1;
//		}
//		else {
//			*ptr = tolower(*ptr);
//		}
//		ptr++;
//	}
//	printf("Chuoi sau khi chuyen ky tu dau moi tu ve chu hoa: %s", st);
//
//	system("pause");
//	return 0;
//}
