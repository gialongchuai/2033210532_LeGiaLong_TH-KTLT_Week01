/*
	Bài 05: Nhập 3 số nguyên a, b, c. Xuất kết quả c/(a-b).
*/

#include <stdio.h>
#include <stdlib.h> // Để sử dụng hàm system("pause")

int main() {
	int a, b, c;
	char buffer[100]; // Buffer để đọc dữ liệu nhập từ người dùng

	// Vòng lặp để yêu cầu người dùng nhập lại khi nhập không phải số nguyên
	while (true) {
		printf("Nhap so nguyen a: ");
		if (scanf("%d", &a) == 1) {
			break; // Thoát khỏi vòng lặp nếu nhập đúng
		}
		else {
			printf("Loi: Ban phai nhap mot so nguyen. Vui long nhap lai.\n");
			scanf("%s", buffer); // Đọc và loại bỏ dữ liệu nhập sai
		}
	}

	while (true) {
		printf("Nhap so nguyen b: ");
		if (scanf("%d", &b) == 1) {
			break; // Thoát khỏi vòng lặp nếu nhập đúng
		}
		else {
			printf("Loi: Ban phai nhap mot so nguyen. Vui long nhap lai.\n");
			scanf("%s", buffer); // Đọc và loại bỏ dữ liệu nhập sai
		}
	}

	while (true) {
		printf("Nhap so nguyen c: ");
		if (scanf("%d", &c) == 1) {
			break; // Thoát khỏi vòng lặp nếu nhập đúng
		}
		else {
			printf("Loi: Ban phai nhap mot so nguyen. Vui long nhap lai.\n");
			scanf("%s", buffer); // Đọc và loại bỏ dữ liệu nhập sai
		}
	}

	// Kiểm tra điều kiện a và b không bằng nhau để tránh chia cho 0
	if (a == b) {
		printf("Loi: Phep chia cho 0 khong hop le.\n");
	}
	else {
		float result = (float)c / (a - b);
		printf("Ket qua cua phep chia c/(a-b) la: %.2f\n", result);
	}

	system("pause"); // Dừng màn hình để xem kết quả
	return 0;
}
