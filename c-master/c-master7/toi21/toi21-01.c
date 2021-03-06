#include "myheader.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	Date *array_p; //  確保する領域へのポインタ
	int i;         //  カウンタ変数

	array_p = (Date *)malloc(sizeof(Date) * 5); // ５個分の領域確保
	if (array_p == NULL) {
		printf("メモリを確保できませんでした。\n");
		return (1);
	}

	for (i = 0; i < 5; i++) {
		(array_p + i)->year = i + 2000; // メンバyearへiの値を代入(アロー演算子)
	}

	printf("Date size = %d\n", sizeof(Date));
	//  各データの格納アドレスと内容を表示
	for (i = 0; i < 5; i++) {
		printf("%d:address = %p, year = %d\n", i, (array_p + i), (array_p + i)->year);
	}
	free(array_p);

	return (0);
}
