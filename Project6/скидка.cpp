#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <limits>



int size = 10;
int receiptSize = 1;


int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];


std::string* nameReceiptArr = new std::string[receiptSize];
int* countReceiptArr = new int[receiptSize];
double* priceReceiptArr = new double[receiptSize];




void Start();
void CreateStorage();

template <typename ArrType>
void FillArray(ArrType staticArray[], ArrType dinArray[], int size);

void Shop();
void ShowStorage();
void Selling();




template <typename ArrType>
void PrintArray(ArrType arr[], int size);



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);



	//Start();
	CreateStorage();
	ShowStorage();
	Selling();

	delete[]idArr;
	delete[]nameArr;
	delete[]countArr;
	delete[]priceArr;
	delete[]nameReceiptArr;
	delete[]countReceiptArr;
	delete[]priceReceiptArr;
	system("pause");
	return 0;
}

void Start()
{
	std::string adminLogin = "admin";
	std::string adminPassword = "admin";
	std::string login, password;
	bool exit = false;
	int choose;

	std::cout << "\n\t\t\tДобро пожаловать в Магазин химии\n\n";


	do
	{
		std::cout << "Логин: ";
		std::getline(std::cin, login, '\n');
		std::cout << "Пароль: ";
		std::getline(std::cin, password, '\n');

		if (login != adminLogin || password != adminPassword)
		{
			std::cerr << "Неверный логин и пароль\n\n";
			std::cout << "Попробовать ещё раз? \n1 - Да \n2 - Выход из программы\n";
			std::cin >> choose;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (choose == 2)
			{
				exit = true;
			}
		}
		else
		{
			exit = true;
			int chooseStorageType;
			do
			{
				std::cout << "Выберите формат склада: \n1 - Готовый склад\n2 - Создать склад вручную\n";
				std::cin >> chooseStorageType;
			} while (chooseStorageType < 1 || chooseStorageType > 2);
			if (chooseStorageType == 1)
			{
				CreateStorage();
				Shop();

			}
			else if (chooseStorageType == 2)
			{
				std::cout << "В разработке";
			}
			else
			{
				std::cerr << "Error chooseStorageType";
			}
		}
	} while (!exit);
}

void CreateStorage()
{
	const int staticSize = 10;
	int id[staticSize]{ 0,1,2,3,4,5,6,7,8,9 };
	std::string name[staticSize]{ "жидкое мыло\t",
		"тряпки\t",
	"перчатки\t", "дейзудоранд",
	"растворитель", "известковая вода\t",
	"швабра\t", "средства для чистки\t","порошок для стирки\t",
	"стиральные капсулы" };
	int count[staticSize]{ 8,4,5,8,10,2,3,6,8,5 };
	double price[staticSize]{ 194.0, 227.0 ,247.0, 169.0, 222.0,
		270.0, 184.0, 272.0, 155.0, 213.0 };
	FillArray(id, idArr, staticSize);
	FillArray(name, nameArr, staticSize);
	FillArray(count, countArr, staticSize);
	FillArray(price, priceArr, staticSize);
}

template<typename ArrType>
void FillArray(ArrType staticArray[], ArrType dinArray[], int size)
{
	for (int i = 0; i < size; i++)
	{
		dinArray[i] = staticArray[i];
	}
}

template<typename ArrType>
void PrintArray(ArrType arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}


/
void Shop()
{
	int choose;



	while (true)
	{
		do
		{
			std::cout << "1) Показать склад\n";
			std::cout << "2) Начать продажу\n";
			std::cout << "3) Изменить цену\n";
			std::cout << "4) Списасть товар\n";
			std::cout << "5) Пополнить товар\n";
			std::cout << "6) Изменение склада\n";
			std::cout << "0) Закончить смену\n";
			std::cin >> choose;
		} while (choose < 0 || choose > 6);
		if (choose == 1)
		{
			ShowStorage();
		}
		else if (choose == 2)
		{
			Selling();
		}
		else if (choose == 3)
		{

		}
		else if (choose == 4)
		{

		}
		else if (choose == 5)
		{

		}
		else if (choose == 6)
		{

		}
		else if (choose == 0)
		{

		}
		else
		{
			std::cerr << "Error";
		}








	}
}

void ShowStorage()
{
	std::cout << "id \t\t Название\t\t\t\t\tЦена\t Кол-во\n\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] + 1 << "\t" << nameArr[i] << "\t\t\t" <<
			priceArr[i] << "\t" << countArr[i] << "\n";
	}
}

void Selling()
{

	int chooseId, chooseCount, confirm;
	while (true)
	{
		do
		{
			std::cout << "Введите id товара для покупки: ";
			std::cin >> chooseId;
			if (chooseId < 1 || chooseId > size)
			{
				std::cerr << "Нет такого Id\n";
				continue;
			}
			do
			{
				std::cout << "\nВы выбрали: " << nameArr[chooseId - 1] << "\n";
				std::cout << "Кол-во товара на складе: " << countArr[chooseId - 1] << "\n";
				std::cout << "Выберите кол-во товара для покупки: ";
				std::cin >> chooseCount;
				if (chooseCount < 1 || chooseCount > countArr[chooseId - 1])
				{
					std::cerr << "Товара не хватает\n";
					continue;
				}
				else
				{
					break;
				}
			} while (true);

			std::cout << "\nВы выбрали: " << nameArr[chooseId - 1] << "\n";
			std::cout << "В кол-ве " << chooseCount << "\n";
			std::cout << "Подтвердите выбор: \n1 - подтвердить\n2 - повторить\n";
			std::cin >> confirm;

			if (confirm == 1)
			{
				break;
			}






		} while (true);





		int sum;
		double res;

		std::cout >> "Введите сумму покупки и нажми ENTER";
		std::cin << sum;
		if sum > 1000
		{
			res = sum * 0.10 + sum;
			std::cout >> "Сумма со скидкой в 10%: ", res;
		}
		else
		{
			std::cout >> "Стоимость товара менее 1000 руб. Скидки не будет";
		}



	}



}