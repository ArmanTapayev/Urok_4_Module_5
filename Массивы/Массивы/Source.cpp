#include<stdio.h>
#include<iostream>
#include<time.h>
#include<math.h>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int i, j, n;

	do
	{
		cout << "\nВведите номер задания: ";
		cin >> n;

		switch (n)
		{
			case 1:
			{
				/*1. Дано целое число в двоичной системе счисления,
				т.е. последовательность цифр 0 и 1. Составить программу
				перевода этого числа в восьмеричную систему счисления.*/

				int A[8], a = 0, b = 0;

				cout << "Число в двоичном формате: " << "\t";

					for (i = 0; i < 8; i++)
					{
						A[i] = 0 + rand() % 2;  // получаем число в двоичном представлении
						cout << A[i] << " ";
					}

					for (i = 7; i >= 0; i--)
					{
						a += A[i] * pow(2, 7 - i);		// переводим число в десятичный формат																							
					}

					cout << endl;
					cout << "Число в десятичном формате: " << "\t";
					cout << a << endl;

					i = 1;

					while (a != 0)
					{
						b += (a % 8)*i; // переводим число из десятичного в восьмеричный формат
						a /= 8;
						i *= 10;
					}

					cout << "Число в восьмеричном формате: " << "\t";
					cout << b << endl;

				cout << endl;

				system("pause");
				system("cls");

			}
			break;

			case 2:
			{
				/*2. Ввести два массива действительных чисел,
				состоящих из 7 и 9 элементов.
				Сформировать третий массив из упорядоченных
				по убыванию значений обоих массивов.*/

				double A[7], B[9], C[16];

				cout << "Первый массив: " << endl;

					for (i = 0; i < 7; i++)
					{
						A[i] = 10 + rand() % 50;
						cout << "A[" << i << "]=" << A[i] << "  ";
						C[i] = A[i];
					}

					cout << endl;
					cout << endl;

					cout << "Второй массив: " << endl;

					for (i = 0; i < 9; i++)
					{
						B[i] = 10 + rand() % 50;
						cout << "B[" << i << "]=" << B[i] << "  ";
						C[i + 7] = B[i];
					}

					cout << endl;
					cout << endl;

					cout << "Новый массив до сортировки: " << endl;

					for (i = 0; i < 16; i++)
					{
						cout << "C[" << i << "]=" << C[i] << "  ";

					}

					cout << endl;
					cout << endl;

					cout << "Новый массив после сортировки: " << endl;

						for (int i = 1; i < 16; i++)  // Для всех элементов кроме начального
						{
							int value = C[i];         // запоминаем значение элемента
							int index = i;            // и его индекс

								while ((index > 0) && (C[index - 1] < value))
								{
									// смещаем другие элементы к концу массива пока они меньше index
									C[index] = C[index - 1];
									index--;    // смещаем просмотр к началу массива
								}

							C[index] = value; // рассматриваемый элемент помещаем на освободившееся место

						}

						for (i = 0; i < 16; i++)
						{
							cout << "C[" << i << "]=" << C[i] << "  ";
						}

					cout << endl;

				system("pause");
				system("cls");
			}
			break;

			case 3:
			{
				/*3. Ввести массив, в котором только два одинаковых элемента.
				Определить их местоположение.*/

				int k[10];
				bool ex;
				ex = false;

					cout << "Введите 10 элементов массива с 2 одинаковыми элементами." << endl;

						for (i = 0; i < 10; i++)
						{
							cin >> k[i];
						}

						cout << endl;

						for (i = 0; i < 10; i++)
						{
							cout << "k[" << i << "]=" << k[i] << "  ";
						}

						cout << endl;

						for (i = 0; i < 10; i++)
						{
							for (j = 0; j <= i; j++)
							{
								if (k[i] == k[j] && i != j)
								{
									cout << "k[" << j << "]=" << k[j] << "  ";
									cout << "k[" << i << "]=" << k[i] << "  ";
									ex = true;
									break; 
								}
							}
						}

					cout << endl;

				system("pause");
				system("cls");

			}
			break;

			case 4:
			{
				/*4. Задан целочисленный массив. Определить,
				образуют ли значения его элементов геометрическую прогрессию.
				Если «да» – вывести знаменатель прогрессии,
				если «нет» – ответ «не образуют». */

				int A[5], a, flag;
				double q;

				cout << "Введите первые пять чисел геометрической последовательности: " << endl;

				for (i = 0; i < 5; i++)
				{
					cin >> a;
					A[i] = a;
				}

				q = A[1] / A[0]; // знаменатель

				for (i = 0; i < 4; i++)
				{
					flag = 0;
					if (A[i + 1] / A[i] == q) flag = 1;
				}

				if (flag == 1)
				{
					cout << "Последовательность образует геометрическую последовательность." << endl;
					cout << "Знаменатель прогрессии q=" << q << endl;
				}
				else
					cout << "Последовательность не образует геометрическую последовательность." << endl;

				system("pause");
				system("cls");
			}
			break;

			case 5:
			{
				/*5. Отсортировать по убыванию элементов
				последнего столбца целочисленный двухмерный массив 5×4*/
				int A[5][4], B[4], k;

				cout << "Элементы массивы A[5][4] до сортировки: " << endl;
				cout << endl;

				k = 0;

				for (i = 0; i < 5; i++)
				{
					for (j = 0; j < 4; j++)
					{
						A[i][j] = 10 + rand() % 70;
						cout << A[i][j] << "\t";
						if (j == 3)
						{
							B[k] = A[i][3];
							k++;
						}
					}

					cout << endl;
				}

				cout << endl;

				for (i = 0; i < 5; i++)
				{
					cout << "B[" << i << "]=" << B[i] << "  ";
				}

				cout << endl;

				for (int i = 1; i < 5; i++)  // Для всех элементов кроме начального
				{
					int value = B[i];         // запоминаем значение элемента
					int index = i;            // и его индекс

					while ((index > 0) && (B[index - 1] < value))
					{
						// смещаем другие элементы к концу массива пока они меньше index
						B[index] = B[index - 1];
						index--;    // смещаем просмотр к началу массива
					}

					B[index] = value; // рассматриваемый элемент помещаем на освободившееся место

				}

				cout << endl;

				for (i = 0; i < 5; i++)
				{
					cout << "B[" << i << "]=" << B[i] << "  ";
				}

				cout << endl;  cout << endl;

				cout << "Элементы массивы A[5][4] после сортировки: " << endl;
				cout << endl;

				k = 0;

				for (i = 0; i < 5; i++)
				{
					for (j = 0; j < 4; j++)
					{

						if (j == 3)
						{
							A[i][3] = B[k];
							k++;
						}

						cout << A[i][j] << "\t";
					}
					cout << endl;
				}

				system("pause");
				system("cls");

			}

			break;

			case 6:
			{
				/*6. В матрице А(3-строки,4-столбца) поменять местами
				наименьшие элементы в первой и третей строке.*/
				int A[3][4], B[4], C[4], k, l;

				cout << "Элементы массивы A[3][4] до перестановки: " << endl;
				cout << endl;

				k = 0;
				l = 0;

				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 4; j++)
					{
						A[i][j] = 10 + rand() % 70;
						cout << A[i][j] << "\t";

						if (i == 0)
						{
							B[k] = A[0][j];
							k++;
						}

						if (i == 2)
						{
							C[l] = A[2][j];
							l++;
						}

					}

					cout << endl;
				}

				cout << endl;

				int minB, minBindex;

				minB = 100000;

				for (i = 0; i < 4; i++)
				{
					cout << "B[" << i << "]=" << B[i] << "  ";

					if (B[i] < minB)
					{
						minB = B[i];
						minBindex = i;
					}

					A[0][minBindex] = B[minBindex];
				}

				cout << endl;
				cout << "B[" << minBindex << "]=" << B[minBindex] << " - минимальный элемент" << endl;
				cout << endl;

				int minC, minCindex;

				minC = 100000;

				for (i = 0; i < 4; i++)
				{
					cout << "C[" << i << "]=" << C[i] << "  ";

					if (C[i] < minC)
					{
						minC = C[i];
						minCindex = i;
					}

					A[2][minCindex] = C[minCindex];
				}

				cout << endl;
				cout << "C[" << minCindex << "]=" << C[minCindex] << " - минимальный элемент" << endl;
				cout << endl;

				int temp;

				temp = A[0][minBindex];
				A[0][minBindex] = A[2][minCindex];
				A[2][minCindex] = temp;

				cout << "Элементы массивы A[3][4] после перестановки: " << endl;
				cout << endl;

				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 4; j++)
					{
						cout << A[i][j] << "\t";
					}

					cout << endl;
				}

				system("pause");
				system("cls");
			}
			break;

			case 7:
			{
				/*7. Дан двухмерный массив 5×6.
				Определить среднее арифметическое каждого столбца,
				определить максимум и минимум каждой строки.*/

				int A[5][6], B[5], C[6], sum = 0, max = 0, min = 1000000;
				double average;

				cout << "\nЭлементы массивы A[5][6]: " << endl;
				cout << endl;

				for (i = 0; i < 5; i++)
				{

					for (j = 0; j < 6; j++)
					{
						A[i][j] = 1 + rand() % 20;
						cout << A[i][j] << "\t";

					}

					cout << endl;

				}

				cout << endl;

				for (i = 0; i < 5; i++)
				{
					max = 0;
					min = 1000000;

					for (j = 0; j < 6; j++)
					{
						cout << A[i][j] << "\t";

						C[i] = A[i][j];

						if (max < C[i]) max = C[i];
						if (min > C[i]) min = C[i];

					}
					cout << endl;
					cout << "Максимальный элемент " << i + 1 << " строки: " << max << endl;
					cout << "Минимальный элемент " << i + 1 << " строки: " << min << endl;

					cout << endl;

				}

				cout << endl;

				for (j = 0; j < 6; j++)
				{

					cout << "Элементы " << j + 1 << " столбца: " << endl;

					sum = 0;

					for (i = 0; i < 5; i++)
					{
						B[i] = A[i][j];
						cout << B[i] << "\t";
						sum += B[i];


					}

					average = sum / 5;
					cout << endl;
					cout << "Среднее арифметическое " << j + 1 << " столбца: " << average << endl;


					cout << endl;

				}

				system("pause");
				system("cls");

			}
			break;

			case 8:
			{
				/*8. Дан двухмерный массив n×m элементов,
				найти количество четных и нечетных чисел в массиве.*/

				int A[3][4], even = 0, odd = 0;

				cout << "\nЭлементы массивы A[3][4]: " << endl;
				cout << endl;

				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 4; j++)
					{
						A[i][j] = 1 + rand() % 10;
						cout << A[i][j] << "\t";

						if (A[i][j] % 2 == 0) even++;
						if (A[i][j] % 2 != 0) odd++;
					}

					cout << endl;

				}

				cout << endl;
				cout << "Количество четных элементов: " << even << endl;
				cout << "Количество нечетных элементов: " << odd << endl;

				system("pause");
				system("cls");
			}
			break;

			case 9:
			{
				/*9. Дан двухмерный массив n×m элементов.
				Определить, сколько раз встречается число 7
				среди элементов массива.*/

				int A[3][4], count = 0;

				cout << "\nЭлементы массивы A[3][4]: " << endl;
				cout << endl;

				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 4; j++)
					{
						A[i][j] = 1 + rand() % 10;
						cout << A[i][j] << "\t";
						if (A[i][j] == 7) count++;
					}
					cout << endl;
				}
				cout << endl;
				cout << "Число 7 встречается " << count << " раз." << endl;

				system("pause");
				system("cls");

			}
			break;

			case 10:
			{
				/*10. Дан массив из n × m элементов.
				Найти индексы первого наименьшего элемента массива*/

				int A[3][4], B[3][4], C[4], D[4], min, mini = 0, minj = 0, k = 0, l = 0;

				cout << "Элементы массивы A[3][4]: " << endl;
				cout << endl;

				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 4; j++)
					{
						A[i][j] = 10 + rand() % 70;
						cout << A[i][j] << "\t";
					}
					cout << endl;
				}

				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (min > A[i][j])
						{
							min = A[i][j];
							mini = i;
							minj = j;
							C[k] = mini;
							D[l] = minj;
							B[k][l] = A[i][j];
							k++;
							l++;
						}
					}
				}
				cout << endl;
				cout << "Первый наименьший элемент: А[" << C[0] << "][" << D[0] << "]=" << B[0][0] << endl;

				system("pause");
				system("cls");

			}
			break;
		}

	} while (n != 0);

}