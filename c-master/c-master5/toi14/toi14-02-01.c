/*================================
    予想
    まず、while文の中で、初めてf()関数が呼ばれた時に、
    恒久的記憶クラスの変数「cnt」が宣言と同時に0で初期化される。
     次に、printf()関数の中で、cntが1加算されてからその値が表示される。
    f()関数の中で宣言されたcntの値は次回の呼び出し以降も継続されるため、
    前回表示された値に1加算した値が次々と表示され、cntの値がSTOP（17）に
    なると、if文の条件分岐によりexit(0)が実行され、プログラムが終了する
================================*/

#include <stdio.h>
#include <stdlib.h>

#define FOREVER 1
#define STOP 17

void f(void);

int main() {
	while (FOREVER) {
		f();
	}
}

void f(void) {
	static int cnt = 0;

	printf("cnt = %d\n", ++cnt);
	if (cnt == STOP) {
		exit(0);
	}
}

/*========================================
    結果
	予想の通り、f()関数内で宣言、初期化されたcntの値が
	保持され、STOPの値である17までcntが加算、出力され、プログラムが終了した。
========================================*/