#define _CRT_SECURE_NO_WARNINGS
#define N 50
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


struct music {
	char name[50];
	char executor[50];
	int mn;
	char genre[50];
}*mus;

typedef struct music MUSIK;
void addd(MUSIK* mus, int count);
void vivod(MUSIK* mus, int count);
void menu2(MUSIK* mus, int count);
void menu1();
MUSIK search(MUSIK* mus, int count);
void sort(MUSIK* mus, int count);
int write(char* namefile, MUSIK* mus, int count);
int read(char* namefile);
int main()
{
	system("chcp 1251");
	system("cls");
	setlocale(LC_ALL, "Rus");
	int kol = 0;
	MUSIK p;
	MUSIK* mus = &p;
	int size;
	puts("Сколько пользователей ?");
	scanf("%d", &size);
	mus = (struct MUSIK*)malloc(size * sizeof(MUSIK));
	int flag1 = 1, choice1, choice2, compl;
	char namefile[100];
	printf("_______________________________________\n");
	printf("|             База данных             |\n");
	printf("|Тема: Музыка                         |\n");
	printf("|Выполнил: Бойченко Арсений Сергеевич |\n");
	printf("|Группа: бИСТ-221                     |\n");
	printf("|_____________________________________|\n");
	system("pause");
	while (flag1)
	{
		system("cls");
		printf("Выберите функцию\n1.Ввод значений.\n2.Вывод значений\n3.Поиск структуры по заданному критерию\n4.Сортировка данных\n5.Запись данных в файл\n6.Чтение данных из файла\n0.Выход из программы\n");
		scanf("%d", &choice1);
		system("cls");
		switch (choice1)
		{
		case 1:
			printf("Введите кол-во записей (меньше 50)\n");
			scanf("%d", &kol);
			addd(mus, kol);
			break;


		case 2:

			vivod(mus, kol);
			break;


		case 3:
			search(mus, kol);
			system("pause");
			break;
		case 4:
			sort(mus, kol);
			break;
		case 5:
			printf("Введите название файла\n");
			scanf("%s", &namefile);
			write(namefile, mus, kol);
			break;
		case 6:
			printf("Введите название файла\n");
			scanf("%s", &namefile);
			read(namefile);
			system("pause");
			break;

		case 0:

			flag1 = 0;
			printf("Программа заверешна\n");
			break;
		default:
			puts("Данный выбор невозможен");

		}

	}
	free(mus);
	system("pause");
}

void addd(MUSIK* mus, int count)
{
	if (count > 50)
	{
		printf("Недостаточно места для записи");

	}
	for (int z = 0; z < count; z++)
	{
		printf("Введите название песни = ");
		scanf("%s", &mus[z].name);
		printf("Исполнитель = ");
		scanf("%s", &mus[z].executor);
		printf("Продолжительность (в секундах) = ");
		scanf("%d", &mus[z].mn);
		printf("Жанр = ");
		scanf("%s", &mus[z].genre);
		printf("\n");
	}
}
void vivod(MUSIK* mus, int count)
{
	printf("---------------------------------------------------------------------\n");
	printf("|| Название песни  ||  Исполнитель ||  Продолжительность ||  Жанр  ||\n");
	printf("---------------------------------------------------------------------\n");
	for (int q = 0; q < count; q++)
	{
		printf("||      %s     ||    %s        ||      %d Сек.       ||   %s   ||\n", mus[q].name, mus[q].executor, mus[q].mn, mus[q].genre);
		printf("--------------------------------------------------------------------\n");
	}
	system("pause");
	return 0;

}
void menu2(MUSIK* mus, int count)
{
	int t;
	printf("||%s|%s||%d Сек.||%s||\n", (mus + count)->name, (mus + count)->executor, (mus + count)->mn, (mus + count)->genre);
	printf("--------------------------------------------------------------------------\n");
}
void menu1()
{
	printf("---------------------------------------------------------------------\n");
	printf("|| Название песни  ||  Исполнитель ||  Продолжительность ||  Жанр  ||\n");
	printf("---------------------------------------------------------------------\n");
}
MUSIK search(MUSIK* mus, int count)
{
	char kr1[10];
	int choice, kr2, kr3, kr4, kr5, flag2 = 1;
	printf("Выберите критерий поиска\n");
	printf("1.Название песни\n");
	printf("2.Исполнитель\n");
	printf("3.Продолжительность\n");
	printf("4.Жанр\n");
	scanf("%d", &choice);
	if (choice == 1)
	{
		printf("Введите название песни\n");
		scanf("%s", kr1);
		menu1();
		for (int i = 0; i < count; i++)
		{
			if (strcmp((mus + i)->name, kr1) == 0)
			{
				menu2(mus, i);
			}


		}
		mus++;
	}
	if (choice == 2)
	{
		printf("Введите исполнителя\n");
		scanf("%s", &kr2);
		menu1();
		for (int i = 0; i < count; i++)
		{
			if ((mus + i)->executor == kr2)
			{
				menu2(mus, i);
			}


		}
		mus++;
	}
	if (choice == 3)
	{
		printf("Введите продолжительность\n");
		scanf("%d", &kr4);
		menu1();
		for (int i = 0; i < count; i++)
		{
			if ((mus + i)->mn == kr4)
			{
				menu2(mus, i);
			}

		}
		mus++;
	}
	if (choice == 4)
	{
		printf("Жанр\n");
		scanf("%s", &kr3);
		menu1();
		for (int i = 0; i < count; i++)
		{
			if ((mus + i)->genre == kr3)
			{
				menu2(mus, i);
			}

		}
		mus++;
	}
	return *mus;
}
int write(char* namefile, MUSIK* mus, int count)
{
	FILE* data;
	int i;
	if ((data = fopen(namefile, "wt")) == NULL)
	{
		fprintf(stderr, "Файл нельзя открыть для записи\n");
		system("pause");
		return -1;

	}
	else
	{
		fprintf(data, "---------------------------------------------------------------------\n");
		fprintf(data, "|| Название песни  ||  Исполнитель ||  Продолжительность ||  Жанр  ||\n");
		fprintf(data, "---------------------------------------------------------------------\n");
		for (i = 0; i < count; i++)
		{
			fprintf(data, "||         %s      ||      %s      ||     %d Сек.        ||    %s  ||\n", mus[i].name, mus[i].executor, mus[i].mn, mus[i].genre);
			fprintf(data, "-----------------------------------------------------------------\n");


		}
		fclose(data);
		printf("Данные записаны\n");
		system("pause");
	}
	return 0;
}
int read(char* namefile)
{
	FILE* open;
	char file[200];
	open = fopen(namefile, "r");
	if (open != NULL)
	{
		printf("Файл открыт\n");
		while (!feof(open))
		{
			fgets(file, 200, open);
			if (!feof(open))
			{
				puts(file);
			}
		}
		return 1;
	}
	else
	{
		printf("Файл не удалось открыть\n");
		system("pause");
		return-1;
	}
	fclose(open);
	return 1;

}



void sort(MUSIK* mus, int count) {

	char str[50];
	int mn1;
	for (int i = 1; i < count; i++) {
		for (int j = 0; j < count - i; j++)
			if (strcmp(mus[j].name, mus[j + 1].name) > 0) {
				strcpy(str, mus[j].name);
				strcpy(mus[j].name, mus[j + 1].name);
				strcpy(mus[j + 1].name, str);

				strcpy(str, mus[j].executor);
				strcpy(mus[j].executor, mus[j + 1].executor);
				strcpy(mus[j + 1].executor, str);

				strcpy(str, mus[j].genre);
				strcpy(mus[j].genre, mus[j + 1].genre);
				strcpy(mus[j + 1].genre, str);

				mn1 = mus[j].mn;
				mus[j].mn = mus[j + 1].mn;
				mus[j + 1].mn = mn1;
			}
	}

}
