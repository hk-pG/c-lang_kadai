#include <math.h>
#include <stdio.h>
#include "complex.h"
#define POW(x) ((x) * (x))

/* cAdd()
    概要:x = a + bj, y = c + djの時、x + y を計算する
*/
// 第1引数: 計算する複素数a + bj
// 第2引数: 計算する複素数c + dj
// 返り値  : 計算した x + y
Complex cAdd(Complex x, Complex y) {
	Complex added;
	double real, imag;

	real = cReal(x) + cReal(y);
	imag = cImag(x) + cImag(y);

	added = cCreate(real, imag);

	return (added);
}

/* cSub()
    概要:x = a + bj, y = c + djの時、x - y を計算する
*/
// 第1引数: 計算する複素数a + bj
// 第2引数: 計算する複素数c + dj
// 返り値  : 計算した x - y
Complex cSub(Complex x, Complex y) {
	double b, d;
	// 引き算はマイナスの足し算なのでcAdd()が使える
	b = cReal(y);
	d = cImag(y);

	// yの各符号を反転する
	b = -b;
	d = -d;

	// 符号を反転した値で足し算を行う
	Complex substracted;
	substracted = cAdd(x, cCreate(b, d));

	return (substracted);
}

/* cMul()
    概要:x = a + bj, y = c + djの時、x * y を計算する
*/
// 第1引数: 計算する複素数a + bj
// 第2引数: 計算する複素数c + dj
// 返り値  : 計算した x * y
Complex cMul(Complex x, Complex y) {
	double a, b, c, d;
	a = cReal(x);
	b = cImag(x);
	c = cReal(y);
	d = cImag(y);

	Complex multiplied;

	double real, imag;
	real = (a * c) - (b * d);
	imag = (a * d) + (b * c);

	multiplied = cCreate(real, imag);

	return (multiplied);
}

/* cDiv()
   概要:x = a + bj, y = c + djの時、x / y を計算する
*/
// 第1引数: 計算する複素数a + bj
// 第2引数: 計算する複素数c + dj
// 返り値  : 計算した x / y
Complex cDiv(Complex x, Complex y) {
	double a, b, c, d;
	a = cReal(x);
	b = cImag(x);
	c = cReal(y);
	d = cImag(y);

	double realNumerator, imagNumerator, denominator;
	denominator = POW(c) + POW(d);
	realNumerator = a * c + b * d;
	imagNumerator = b * c - a * d;

	Complex isDivision;
	double real, imag;
	real = realNumerator / denominator;
	imag = imagNumerator / denominator;

	isDivision = cCreate(real, imag);

	return (isDivision);
}

/* cCreate()
    概要:実数a, bから複素数a + bjを初期化（生成）する
*/
// 第1引数 : 複素数a + bjの実数部a
// 第2引数 : 複素数a + bjの虚数部b
// 返り値  : 生成した複素数a + bj
Complex cCreate(double a, double b) {
	Complex create;
	create.real = a;
	create.imag = b;

	return (create);
}

/* cPrint()
    概要:複素数xをa + bjのように表示する
*/
// 第1引数: 表示したい複素数x
// 返り値  : なし
void cPrint(Complex x) {
	double real, imag;
	real = cReal(x);
	imag = cImag(x);

	if (imag == 0) {
		printf("%g", real);
	} else if (imag < 0) {
		imag = -imag;
		printf("%g - %gj", real, imag);
	} else {
		printf("%g + %gj", real, imag);
	}

	return;
}

/* cReal()
    概要:x = a + bjから、実数部aを取り出す
*/
// 第1引数: 複素数x
// 返り値  : xの実数部a
double cReal(Complex x) {
	return (x.real);
}

/* cImag()
    概要:x = a + bjから、虚数部bを取り出す
*/
// 第1引数: 複素数x
// 返り値  : xの虚数部b
double cImag(Complex x) {
	return (x.imag);
}