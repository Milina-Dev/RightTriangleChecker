#include <iostream>
#include <fstream>

using namespace std;

//Запись в бинарный файл
void fileWrite(string filename)
{
	int a = 3;
	int b = 4;
	int c = 5;

	ofstream file(filename, ios::binary);
	file.write((char*)&a, sizeof(a));
	file.write((char*)&b, sizeof(b));
	file.write((char*)&c, sizeof(c));
	file.close();
}
// Проверка прямоугольниго треугольника
bool is90angle(int a, int b, int c)
{
	if (a * a + b * b == c * c ||
		a * a + c * c == b * b ||
		b * b + c * c == a * a)
	{
		return true;
	}
	return false;
}

int main()
{
	setlocale(0, "");
	int a;
	int b;
	int c;
	string filename = "triangle.bin";
	bool isWrite = true;

	if (isWrite)
	{
		fileWrite(filename);
	}

	// Чтение из бинарного файла
	ifstream readFile(filename, ios::binary);

	if (!readFile)
	{
		cout << "Ошибка";
		return 0;
	}

	if (!readFile.read((char*)&a, sizeof(a)) ||
		!readFile.read((char*)&b, sizeof(b)) ||
		!readFile.read((char*)&c, sizeof(c)))
	{
		cout << "Ошмбка чтения";
		return 0;
	}

	readFile.close();

	// Проверка существования треугольника
	if (a <= 0 || b <= 0 || c <= 0 ||
		a + b <= c || a + c <= b || b + c <= a)
	{
		cout << "Результат:" << endl;
		cout << "Не треугольник";
	}
	else if (is90angle(a, b, c))
	{
		cout << "Результат:" << endl;
		cout << "Прямоугольный треугольник " << "со сторанами: " << a << " " << b << " " << c;
	}
	else
	{
		cout << "Результат:" << endl;
		cout << "Не прямоугольный треугольник";
	}

	return 0;
}