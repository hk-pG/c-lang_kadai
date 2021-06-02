#include <stdio.h>

int threeTimes(void);

int main() {
	int i;

	for (i = 1; i <= 10; i++) {
		printf("%2d回目: %d\n", i, threeTimes());
	}

	return (0);
}

/* threeTimes()
    概要:呼び出される度に前の呼び出しで返した値の３倍の値を返す
*/
// 第一引数: 無し
// 返り値  : 初回の戻り値「１」を除き、前回返した値の３倍の値を返す
int threeTimes(void) {
	static count, firstSet = 1;
	count = firstSet;
	firstSet *= 3;
	return (count);
}
