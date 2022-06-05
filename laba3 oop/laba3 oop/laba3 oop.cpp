//2. Реализовать класс String для работы со строками символов.
//Перегрузить для объектов класса String операторы «!»(пуст ли объект
//	класса), «()(int, int)»(возвращение подстроки объекта), «[]»(возвращение
//		некоторого символа строки объекта).Реализовать конструкторы(по
//			умолчанию, с параметрами, копирования), деструкторы.Реализовать friendфункции для операторов ввода / вывода в поток.


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

int CreateInt();
int CheckInt(char c[]);

class String {
private:
	char* str;
	int size;
public:
	String();
	String(String& stroka);
	String(char* s);
	String(int size);
	String(char* str, int size);
	int operator !(); //пуст ли объект
	char* operator ()(int, int); //подстрока
	char operator [](int); //символ
	void operator =(String&);
	friend void display(String s);
};

String::String() {
	size = 4;
	str = new char[size];
	str[0] = 'А';
	str[1] = 'н';
	str[2] = 'я';
	str[3] = '\0';
}

String::String(String& stroka) {
	this->size = stroka.size;
	str = new char[this->size];
	strcpy(this->str, stroka.str);
}

String::String(char* s) {
	size = strlen(s) + 1;
	str = new char[size];
	strcpy(str, s);
}

String::String(int size) {
	this->size = size;
	str = new char[size];
	for (int i = 0; i < size; i++) {
		str[i] = 'w';
	}
}

String::String(char* str, int size) {
	this->size = size;
	this->str = new char[size];
	for (int i = 0; i < size; i++) {
		this->str[i] = str[i];
	}
}

int String:: operator!() {
	if (size == 0) { return 1; }
	else { return 0; }
}

void String:: operator=(String& newStr) {
	strcpy(str, newStr.str);
	size = newStr.size;
}

char* String::operator()(int a, int b) {
	char newstr[100];
	if (a > size || b > size) {
		cout << "Некорректно введены границы" << endl;
		return NULL;
	}
	else {
		if (a > b) {
			swap(a, b);
		}
		for (int i = a - 1, k = 0; i < b; i++, k++) {
			cout << str[i];
			newstr[k] = str[i];
		}
		cout << endl;
		return newstr;
	}
}

char String:: operator[](int num) {
	return str[num];
}

void display(String s) {
	cout << s.str << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	String obj;
	int menu = 0;
	int cycle = 1;
	while (cycle) {
		cout << "Выберите необходимое действие:" << endl;
		cout << "1. Создать объект по умолчанию" << endl;
		cout << "2. Создать объект из другого объекта" << endl;
		cout << "3. Создать объект с заданной строкой" << endl;
		cout << "4. Создать объект с заданным количеством символов" << endl;
		cout << "5. Создать объект с заданной строкой с заданным количеством символов" << endl;
		cout << "6. Проверить, пуст ли объект" << endl;
		cout << "7. Вывести подстроку объекта" << endl;
		cout << "8. Вернуть символ по его номеру" << endl;
		cout << "9. Вывести объект" << endl;
		cout << "10.Выйти" << endl;
		menu = CreateInt();
		switch (menu) {
		case 1: {
			String obj1;
			obj = obj1;
			break;
		}
		case 2: {
			char mas[100];
			cout << "Создайте объект для копирования" << endl;
			cout << "Введите строку" << endl;
			cin >> mas;
			String obj1(mas);
			String obj2(obj1);
			obj = obj2;
			display(obj);
			break;
		}
		case 3: {
			char mas[100];
			cout << "Введите строку" << endl;
			cin >> mas;
			String obj1(mas);
			obj = obj1;
			break;
		}
		case 4: {
			int n;
			cout << "Введите количество символов" << endl;
			n = CreateInt();
			String obj1(n);
			obj = obj1;
			break;
		}
		case 5: {
			int n;
			char mas[100];
			cout << "Введите количество символов" << endl;
			n = CreateInt();
			cout << "Введите строку" << endl;
			cin >> mas;
			String obj1(mas, n);
			obj = obj1;
			break;
		}
		case 6: {
			if (!obj) {
				cout << "Объект пуст" << endl;
			}
			else {
				cout << "Объект не пуст" << endl;
			}
			break;
		}
		case 7: {
			int a, b;
			cout << "Введите границы подстроки" << endl;
			a = CreateInt();
			b = CreateInt();
			obj.operator()(a, b);
			break;
		}
		case 8: {
			int num;
			cout << "Введите номер символа" << endl;
			num = CreateInt();
			cout << "Символ:" << endl;
			cout << obj[num-1] << endl;
			break;
		}
		case 9: {
			display(obj);
			break;
		}
		case 10: {
			cycle = 0;
			break;
		}
		default: {
			cout << "Некорректный ввод" << endl;
		}
		}
	}
}

int CreateInt()
{
	char str[70] = "a";//заведомо ложное условие (не целое число)
	while (!CheckInt(str))
	{
		cin >> str;
		if (!CheckInt(str))
		{
			cout << "Некорректный ввод." << endl;
		}
	}
	int n = atoi(str);//перевод в целочисленный формат
	return n;
}

int CheckInt(char c[])
{
	for (int i = 0; i < strlen(c); i++)
	{
		if (c[i] > '9' || c[i] < '0')
		{
			return 0;//это не целое число
		}
	}
	return 1;//это целое число
}