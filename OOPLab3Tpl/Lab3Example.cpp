#include <iostream>
#include <math.h>

using namespace std;

class Rectangle {
	double height; //висота
	double width; //ширина
	unsigned int color; //колір
public:
	Rectangle() : height(5.0), width(5.0), color(0) {}
	Rectangle(double height1, double width1) : color(0) {
		if (height1 < 0 || height1 > 1.e+100) {
			cout << " Error input height !!! \n";
			height = 1;
		}
		else
			height = height1;
		if (width1 < 0 || width1 > 1.e+100) {
			cout << " Error input height !!! \n";
			width = 1;
		}
		else
			width = width1;
		return;
	}
	Rectangle(double width1) : height(5.0), color(0) {
		if (width1 < 0 || width1 > 1.e+100) {
			cout << " Error input height !!! \n";
			width = 1;
		}
		else
			width = width1;
		return;
	}
	Rectangle(int color1) : height(5.0), width(5.0) {
		if (color1 < 0 || color1 > 10000) {
			cout << " Error input height !!! \n";
			color = 0;
		}
		else
			color = color1;
		return;
	}
	Rectangle(double height1, double width1, int color1) {
		if (height1 < 0 || height1 > 1.e+100) {
			cout << " Error input height !!! \n";
			height = 1;
		}
		else
			height = height1;

		if (width1 < 0 || width1 > 1.e+100) {
			cout << " Error input height !!! \n";
			width = 1;
		}
		else
			width = width1;

		if (color1 < 0 || color1 > 10000) {
			cout << " Error input height !!! \n";
			color = 0;
		}
		else
			color = color1;
	
		return;
	}
	double getHeight() const {
		return height;
	}
	double getWidth() const {
		return width;
	}
	double getColor() const {
		return color;
	}
	void setHeight(double height) {
		if (height < 0 || height > 1.e+100) {
			cout << " Error input height !!! \n";
			return;
		}
		this->height = height;
	}
	void setWidth(double width) {
		if (width < 0 || width > 1.e+100) {
			cout << " Error input width !!! \n";
			return;
		}
		this->width = width;
	}
	void setColor(int col) {
		if (col < 0 || col > 10000) {
			cout << " Error set color !!! \n";
			return;
		}
		this->color = col;
	}
	double S() {
		return height * width;
	}
	double P() {
		return 2 * height + 2 * width;
	}
	void printInfo() {
		cout << " height = " << height << " width = " << width << " color = " << color << endl;
		cout << " S = " << S() << " P = " << P() << endl;
	}
};

int mainExample1()
{
	Rectangle obj;
	obj.printInfo();
	double in_height; double in_width; int in_color;
	cout << " Input height, width, color Rectangle  "; cin >> in_height >> in_width >> in_color;
	Rectangle obj1(in_height, in_width), obj2(in_width), obj3(in_color), obj4(in_height, in_width, in_color);
	cout << " N1: " << endl;
	obj1.printInfo();
	cout << " N2: " << endl;
	obj2.printInfo();
	cout << " N3: " << endl;
	obj3.printInfo();
	cout << " N4: " << endl;
	obj4.printInfo();
	cout << " N5: " << endl;
	obj.setHeight(-5);
	obj.printInfo();
	cout << " N6: " << endl;
	obj.setHeight(50);
	obj.printInfo();
	cout << " N7: " << endl;
	obj.setHeight(2.e100);
	obj.printInfo();
	cout << " N8: " << endl;
	obj.setWidth(-5);
	obj.printInfo();
	cout << " N9: " << endl;
	obj.setWidth(50);
	obj.printInfo();
	cout << " N10: " << endl;
	obj.setWidth(2.e100);
	obj.printInfo();
	cout << " N11: " << endl;
	obj.setColor(-10);
	obj.printInfo();
	cout << " N12: " << endl;
	obj.setColor(100);
	obj.printInfo();
	cout << " N13: " << endl;
	obj.setColor(10001);
	obj.printInfo();

	cout << "\n End testing Example 1 \n";

	return 1;
}
/*Створити тип даних - клас вектор, який має вказівник на double, число елементів і змінну стану. У класі визначити
- конструктор без параметрів( виділяє місце для одного елемента та інінціалізує його в нуль); /Done/
- конструктор з одним параметром - розмір вектора( виділяє місце та інінціалізує масив значенням нуль); /Done/
- конструктор із двома параметрами - розмір вектора та значення ініціалізації(виділяє місце (значення перший аргумент) та інінціалізує значенням другого аргументу);/Done/
- конструктор копій та операцію присвоєння; 
- деструктор звільняє пам'ять; /Done/
- визначити функцію, яка присвоює елементу масиву деяке значення;/Done/
- функцію яка одержує деякий елемент масиву;/Done/
- визначити функції друку, додавання, віднімання, які здійснюють ці арифметичні операції з даними цього класу, множення та ділення на скаляр типу double;/Done/
- визначити функції порівняння: більше, менше або рівно, які повертають true або false.
У змінну стани встановлювати код помилки, коли не вистачає пам'яті, виходить за межі масиву.*/

class DOUBLE {
	double* Vec;
	int num;   
	int state = 0;
public:
	DOUBLE() : DOUBLE(1) {}
	DOUBLE(int n);
	DOUBLE(int n, double b);
	DOUBLE(int n, int p);
	DOUBLE& operator = (const DOUBLE& s);
	~DOUBLE() {
		cout << " Vector was deleted !!! \n";
		if (Vec) delete[] Vec;
	}
	void SetX();
	int GetX();
	void AddX();
	void MinusX();
	void MultiplicationX();
	void DilennyaX();
	void PorivnyannyaX1();
	void PorivnyannyaX2();
	void PorivnyannyaX3();
	void Output();

};
DOUBLE::DOUBLE(int n) {
	if (n <= 0) n = 1;
	num = n;
	Vec = new double[n];
	for (int i = 0; i < n; i++) {
		Vec[i] = 0.0;
	}
}
DOUBLE::DOUBLE(int n, double b) : DOUBLE(n) {
	for (int i = 0; i < num; i++) {
		Vec[i] = b;
	}
}
DOUBLE::DOUBLE(int n, int p) : DOUBLE(n) {
	for (int i = 0; i < num; i++)
		Vec[i] = p;
}
DOUBLE& DOUBLE::operator=(const DOUBLE& s) {
	if (num != s.num)
	{
		if (Vec) delete[] Vec;
		num = s.num;
		Vec = new double[num];
		state = 0;
	}
	for (int i = 0; i < num; i++)   Vec[i] = s.Vec[i];
	return *this;
}
void DOUBLE::SetX() {
	int n, x;
	do {
		cout << " Введіть значення N (на якій позиції) та Х (на яке число замінити): ";
		cin >> n >> x;
		if (n<0 || n>num) {
			state = 1;
			cout << "ERROR";
		}
	} while (n<0 || n>num);
	state = 0;

	Vec[n] = x;
}
int DOUBLE::GetX() {
	int n;
	do {
		cout << " Введіть значення N з якої позиції потрібно витягти елемент: ";
		cin >> n;
	} while (n<0 || n>num);

	return Vec[n];
}
void DOUBLE::AddX() {
	int x;
	cout << " Введіть значення X - яке число потрібно додати: ";
	cin >> x;
	for (int i = 0; i < num; i++) {
		Vec[i] += x;
	}
}
void DOUBLE::MinusX() {
	int x;
	cout << " Введіть значення X - яке число потрібно відняти: ";
	cin >> x;
	for (int i = 0; i < num; i++) {
		Vec[i] -= x;
	}
}
void DOUBLE::MultiplicationX() {
	double x;
	cout << " Введіть значення X - яке число потрібно помножити: ";
	cin >> x;
	for (int i = 0; i < num; i++) {
		Vec[i] *= x;
	}
}
void DOUBLE::DilennyaX() {
	double x;
	cout << " Введіть значення X - яке число потрібно помножити: ";
	cin >> x;
	for (int i = 0; i < num; i++) {
		Vec[i] /= x;
	}
}
void DOUBLE::PorivnyannyaX1() {
	cout << " Порівнюємо значення вектора, якщо воно рівно з числом 50 \n";
	
	for (int i = 0; i < num; i++) {
		if (Vec[i] == 50)
			cout << "True !!! \n";
		else
			cout << "False !!! \n";
	}
}
void DOUBLE::PorivnyannyaX2() {
	cout << " Порівнюємо значення вектора, якщо воно більше з числом 50 \n";

	for (int i = 0; i < num; i++) {
		if (Vec[i] >= 50)
			cout << "True !!! \n";
		else
			cout << "False !!! \n";
	}
}
void DOUBLE::PorivnyannyaX3() {
	cout << " Порівнюємо значення вектора, якщо воно менше з числом 50 \n";

	for (int i = 0; i < num; i++) {
		if (Vec[i] <= 50)
			cout << "True !!! \n";
		else
			cout << "False !!! \n";
	}
}
void DOUBLE::Output() {
	if (num != 0) {
		for (int i = 0; i < num; i++) {
			cout << " v[" << i << "] = " << Vec[i] << endl;
		}
	}
}

int mainExample2() {
	int a;
	DOUBLE B;
	DOUBLE P1, P2(5), P3(5, 12);
	cout << " - конструктор без параметрів( виділяє місце для одного елемента та інінціалізує його в нуль); \n";
	P1.Output();
	cout << " - конструктор з одним параметром - розмір вектора( виділяє місце та інінціалізує масив значенням нуль); \n";
	P2.Output();
	cout << " - конструктор із двома параметрами - розмір вектора та значення ініціалізації(виділяє місце(значення перший аргумент) \n";
	cout << " та інінціалізує значенням другого аргументу); \n";
	P3.Output();
	cout << " Введіть число а: ";
	cin >> a;
	DOUBLE P4(6, a);
	P4.Output();
	cout << " - конструктор копій та операцію присвоєння; \n";
	B = P4;
	B.Output();
	cout << " - функцію, яка присвоює елементу масиву деяке значення; \n";
	P4.SetX();
	P4.Output();
	cout << " - функцію яка одержує деякий елемент масиву; \n";
	cout << " Значення в позиції N: " << P4.GetX();
	cout << '\n';
	cout << " - функція додавання; \n";
	P4.AddX();
	P4.Output();
	cout << " - функція віднімання; \n";
	P4.MinusX();
	P4.Output();
	cout << " - функція множення; \n";
	P4.MultiplicationX();
	P4.Output();
	cout << " - функція ділення; \n";
	P4.DilennyaX();
	P4.Output();
	cout << " - функція порівняння; \n";
	P4.PorivnyannyaX1();
	P4.PorivnyannyaX2();
	P4.PorivnyannyaX3();
	return 1;
}
/*Створити клас матриця.Даний клас містить вказівник на double, розміри рядків і стовпців та стан помилки.У класі визначити/Done/
- конструктор без параметрів(виділяє місце для матриці 4 на 3 елемента та інінціалізує його в нуль);/Done/
- конструктор з одним параметром - розмір n матриці(виділяє місце для матриці n на n та інінціалізує матрицю значенням нуль);/Done/
- конструктор із трьома розміри матриці(n, m) та значення ініціалізації value (виділяє місце перші аргументи та інінціалізує значенням третього аргументу - value);/Done/
- конструктор копій та операцію присвоєння; // !!! /Done/
- деструктор звільняє пам'ять; /Done/
- визначити функцію, яка присвоює елементу масиву деяке значення (параметр за замовчуванням);/Done/
- функцію яка одержує деякий елемент матриці за індексами i та j;/Done/
- визначити функції друку, додавання,віднімання, множення на скаляр типу double, які здійснюють ці арифметичні операції з даними цього класу;
- визначити функції порівняння : більше, менше або рівно, які повертають true або false.
Написати програму тестування всіх можливостей цього класу.*/

class Matrix {
	double* Mat;
	int row;
	int collum;
	int state = 0;
public:
	Matrix();
	Matrix(int n);
	Matrix(int n, int m, double x);
	Matrix& operator = (const Matrix& s);
	void setX(double x);
	double getX();
	void MultiplicationX();
	void AddX(Matrix& A);
	void MinusX(Matrix& A);
	void СalculationX1(Matrix& A);
	void СalculationX2(Matrix& A);
	void СalculationX3(Matrix& A);
	~Matrix() {
		cout << " Matrix was deleted !!! \n";
		if (Mat) delete[] Mat;
	}
	void Output();
};
Matrix::Matrix() {
	row = 4;
	collum = 3;
	Mat = new double[row * collum];
	for (int i = 0; i < row * collum; i++) {
		Mat[i] = 0;
	}
}
Matrix::Matrix(int n) {
	if (n < 0 || n > 1.e+100)
		cout << " ERROR !!!\n";
	else {
		row = n;
		collum = n;
		Mat = new double[row * collum];
		for (int i = 0; i < row * collum; i++) {
			Mat[i] = 0;
		}
	}
}
Matrix::Matrix(int n, int m, double x) {
	if (n < 0 || n > 1.e+100 || m < 0 || m > 1.e+100)
		cout << " ERROR !!!\n";
	else {
		row = n;
		collum = m;
		Mat = new double[row * collum];
		for (int i = 0; i < row * collum; i++) {
			Mat[i] = x;
		}
	}
}
Matrix& Matrix::operator=(const Matrix& s) {
	if (Mat) delete[] Mat;
	row = s.row;
	collum = s.collum;
	Mat = new double[row * collum];
	for (int i = 0; i < row * collum; i++) {
		Mat[i] = s.Mat[i];
	}
	return *this;
}
void Matrix::setX(double x = 10) {
	int z, y;
	cout << " Введіть значення n та m якому саме елементу поставити значення по замовчуванню: ";
	cin >> z >> y;
	if (z < 0 || z > row || y < 0 || y > collum)
		cout << " ERROR !!!\n";
	else {
		Mat[z * collum + y] = 10;
	}
}
double Matrix::getX() {
	int z, y;
	cout << "Введіть значення n та m з якого місця ви хочете отримати значення: ";
	cin >> z >> y;
	if (z < 0 || z > row || y < 0 || y > collum)
		cout << " ERROR !!!\n";
	else {
		return Mat[z * collum + y];
	}
}
void Matrix::MultiplicationX(){
	double z;
	cout << "Введіть значення на яке хочете перемножити: ";
	cin >> z;

	for (int i = 0; i < row * collum; i++) {
		Mat[i] *= z;
	}
}
void Matrix::AddX(Matrix& A) {
	if(A.row != row || A.collum != collum)
		cout << " ERROR !!!\n";
	else {
		for (int i = 0; i < row * collum; i++) {
			Mat[i] += A.Mat[i];
		}
	}
}
void Matrix::MinusX(Matrix& A) {
	if (A.row != row || A.collum != collum)
		cout << " ERROR !!!\n";
	else {
		for (int i = 0; i < row * collum; i++) {
			Mat[i] -= A.Mat[i];
		}
	}
}
void Matrix::СalculationX1(Matrix& A) {
	double x = 0, y = 0;
	for (int i = 0; i < A.row * A.collum; i++) {
		x = x + A.Mat[i];
	}
	for (int i = 0; i < row * collum; i++) {
		y = y + Mat[i];
	}
	if (x == y)
		cout << "True !!! \n";
	else
		cout << "False !!! \n";
}
void Matrix::СalculationX2(Matrix& A) {
	double x = 0, y = 0;
	for (int i = 0; i < A.row * A.collum; i++) {
		x = x + A.Mat[i];
	}
	for (int i = 0; i < row * collum; i++) {
		y = y + Mat[i];
	}
	if (x >= y)
		cout << "True !!! \n";
	else
		cout << "False !!! \n";
}
void Matrix::СalculationX3(Matrix& A) {
	double x = 0, y = 0;
	for (int i = 0; i < A.row * A.collum; i++) {
		x = x + A.Mat[i];
	}
	for (int i = 0; i < row * collum; i++) {
		y = y + Mat[i];
	}
	if (x <= y)
		cout << "True !!! \n";
	else
		cout << "False !!! \n";
}

void Matrix::Output() {
	if (row != 0 && collum != 0) {
		for (int i = 0; i < row ; i++) {
			for (int j = 0; j < collum; j++) {
				cout << "      " << Mat[i * collum + j];
			}
			cout << "\n";
		}
	}
}
int mainExample3() {
	Matrix B1;
	Matrix M1, M2(10), M3(5, 4, 25), M4(5, 4, 80), M5(5, 4, 200);
	cout << "Матриця 4 на 3 заповнена нулями: \n";
	M1.Output();
	cout << "Матриця n на n заповнена нулями: \n";
	M2.Output();
	cout << "Матриця n на m заповнена значенням value(x): \n";
	M3.Output();
	B1 = M3;
	cout << "Матриця B1: \n";
	B1.Output();
	cout << "Матриця яка приймає параметр по замовчуванню: \n";
	M3.setX();
	M3.Output();
	cout << "Матриця яка приймає параметр по замовчуванню: " << M3.getX() << "\n";
	cout << "Множення матриці на число: \n";
	M3.MultiplicationX();
	M3.Output();
	cout << "Додавання двох матриць: \n";
	M3.AddX(M4);
	M3.Output();
	cout << "Віднімання двох матриць: \n";
	M3.MinusX(M5);
	M3.Output();
	cout << "Порівняння двох матриць: \n";
	M3.СalculationX1(M5);
	M3.СalculationX2(M5);
	M3.СalculationX3(M5);
	/*======================================================================================================================*/
	Matrix Q1(-10), Q2(-4, 3, 20), Q3(4, -3, 20);
	M1.setX();
	M1.getX();
	Matrix Q4(9, 5, 25);
	M3.AddX(Q4);
	M3.MinusX(Q4);

	return 1;
}