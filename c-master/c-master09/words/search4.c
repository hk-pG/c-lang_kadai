#include "allocwords.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	int n;
	char **p;
	int l = 0, r, m, place = -1, i = 0;

	// コマンドライン引数の確認
	if (argc <= 1 || argc > 2) {
		// コマンドラインに引数が渡されていない
		fprintf(stderr, "引数を正しく指定してください\n");
		return (1);
	} else {
		if ((p = allocwords(&n)) == (char **)NULL) {
			fprintf(stderr, "words allocation failed\n");
			exit(8);
		}

		// 探索
		r = n - 1;
		m = (l + r) / 2;
		while (place == -1 && l <= r) {
			if (strcmp(argv[ i ], p[ i ]) < 0) {
				r = m - 1;
			} else if (strcmp(p[ i ], argv[ 1 ]) > 0) {
				l = m + 1;
			} else {
				place = m;
			}
			m = (l + r) / 2;
			i++;
		}

		if (strcmp(p[ m ], argv[ 1 ]) != 0) {
			printf("\nline %d: '%s' found\n", place + 1, argv[ 1 ]);
		} else {
			fprintf(stderr, "\n%s does not found\n", argv[ 1 ]);
		}

		freeWords(p, n);
	}

	return 0;
}
