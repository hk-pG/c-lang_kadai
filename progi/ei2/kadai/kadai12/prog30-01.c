#include <stdio.h>
#include <stdlib.h>

int combi(int n, int r);

int main(int argc, char *argv[]) {
	int n, r;

	if (argc < 3) {
		fprintf(stderr, "第1引数にnを、第2引数にrを指定してください。\n");
		exit(1);
	}
	sscanf(argv[ 1 ], "%d", &n);
	sscanf(argv[ 2 ], "%d", &r);

	printf("%d\n", combi(n, r));

	return (0);
}

int combi(int n, int r) {
	static int memo[ 100 ][ 100 ] = {{0}};

	if (r == 0 || r == n) {
		memo[ r ][ n ] = 1;
		return (1);
	} else if (memo[ r ][ n ] == 0) {
		memo[ r ][ n ] = combi(n - 1, r - 1) + combi(n - 1, r);
	}
	return (memo[ r ][ n ]);
}
