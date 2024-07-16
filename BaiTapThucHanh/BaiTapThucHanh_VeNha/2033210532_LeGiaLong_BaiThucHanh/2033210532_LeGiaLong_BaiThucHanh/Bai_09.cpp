///*
//	Bài 09: Xét lại bài 3, tính các giá trị tổng, hiệu, tích, thương của 2 số a, b thông qua các con trỏ
//	pa, pb. Xuất ra kết quả và địa chỉ các ô nhớ chứa tổng, hiệu, tích thương đó.
//*/
//
//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	// Khai báo biến thực a và b
//	float a, b;
//
//	// Nhập giá trị cho a và b
//	printf("Nhap so thuc a: ");
//	scanf("%f", &a);
//	printf("Nhap so thuc b: ");
//	scanf("%f", &b);
//
//	// Khai báo con trỏ pa và pb
//	float *pa = &a;
//	float *pb = &b;
//
//	// Xuất giá trị các con trỏ pa, pb
//	printf("\nDia chi cua a: %p", (void*)pa);
//	printf("\nDia chi cua b: %p", (void*)pb);
//
//	// Tính tổng, hiệu, tích, thương thông qua con trỏ
//	float tong = *pa + *pb;
//	float hieu = *pa - *pb;
//	float tich = (*pa) * (*pb);
//	float thuong = (*pa) / (*pb);
//
//	// Xuất kết quả và địa chỉ các ô nhớ chứa tổng, hiệu, tích, thương
//	printf("\nTong: %f, Dia chi: %p", tong, (void*)&tong);
//	printf("\nHieu: %f, Dia chi: %p", hieu, (void*)&hieu);
//	printf("\nTich: %f, Dia chi: %p", tich, (void*)&tich);
//	printf("\nThuong: %f, Dia chi: %p", thuong, (void*)&thuong);
//
//	system("pause");
//	return 0;
//}
