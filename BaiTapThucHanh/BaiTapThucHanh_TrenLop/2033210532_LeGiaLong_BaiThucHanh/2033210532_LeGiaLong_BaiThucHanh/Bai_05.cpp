/*
	Bài 05: Nhập 3 số nguyên a, b, c. Xuất kết quả c/(a-b).
*/

#include <stdio.h>
#include <stdlib.h> // Thu vien de su dung "pause" dung man hinh de xem ket qua

int main() {
	int a, b, c;
	printf("Nhap so nguyen a: ");
	scanf("%d", &a);
	printf("Nhap so nguyen b: ");
	scanf("%d", &b);
	printf("Nhap so nguyen c: ");
	scanf("%d", &c);

	// Kiem tra dieu kien a va b khong bang nhau de tranh chia cho 0
	if (a == b) {
		printf("Loi: Phep chia cho 0 khong hop le.\n");
	}
	else {
		float result = (float)c / (a - b);
		printf("Ket qua cua phep chia c/(a-b) la: %.2f\n", result);
	}

	system("pause"); // Dung man hinh xem ket qua
	return 0;
}
