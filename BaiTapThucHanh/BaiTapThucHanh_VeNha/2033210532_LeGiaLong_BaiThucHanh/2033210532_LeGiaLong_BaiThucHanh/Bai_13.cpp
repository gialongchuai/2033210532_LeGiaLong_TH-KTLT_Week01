///*
//	Bài 13: Xét 2 mảng 1 chiều a và b. Tính và xuất kết quả các phép chia của phần tử mảng a cho
//	phần tử mảng b. Hãy xét các trường hợp ngoại lệ có thể có trong bài toán này.
//*/
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_SIZE 100 // Số lượng tối đa phần tử trong mảng là 100
//
//void tinhVaXuatKetQua(float a[], float b[], int n) {
//	for (int i = 0; i < n; ++i) {
//		if (b[i] == 0) {
//			printf("Loi: Chia cho 0 tai vi tri %d\n", i);
//		}
//		else {
//			float ketqua = a[i] / b[i];
//			printf("%.2f / %.2f = %.2f\n", a[i], b[i], ketqua);
//		}
//	}
//}
//
//int main() {
//	int n;
//	printf("Nhap so luong phan tu cua mang: ");
//	scanf("%d", &n);
//
//	if (n > MAX_SIZE) {
//		printf("Loi: So luong phan tu qua lon\n");
//		return 1;
//	}
//
//	float a[MAX_SIZE], b[MAX_SIZE];
//
//	printf("Nhap cac phan tu cua mang a:\n");
//	for (int i = 0; i < n; ++i) {
//		printf("a[%d] = ", i);
//		scanf("%f", &a[i]);
//	}
//
//	printf("Nhap cac phan tu cua mang b:\n");
//	for (int i = 0; i < n; ++i) {
//		printf("b[%d] = ", i);
//		scanf("%f", &b[i]);
//	}
//
//	tinhVaXuatKetQua(a, b, n);
//
//	system("pause");
//	return 0;
//}
