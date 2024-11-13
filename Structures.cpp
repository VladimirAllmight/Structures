#include <stdio.h>
#include <locale.h>
#include <string.h>

// Структура для хранения информации о студенте
struct ExName
{
	char ExamName[256];
	int grade;
};
struct Student
{
	char name[50];
	char surname[50];
	int day;
	char month[2];
	int year;
	char amountEx;
	ExName subjects[5];
};
//функция сортировки студентов по алфавиту
void sort(Student* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (strcmp(a[j].name, a[j + 1].name) > 0)
			{
				Student t = a[j];
				a[j] = a[j + 1];
				a[j] = t;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	printf("Введите количество студентов: ");
	int count;
	scanf("%d", &count);
	const int N = 3;
	Student group[N];
	for (int i = 0; i < count; i++) {
		printf("Введите информацию о студенте %d:\n", i + 1);
		printf("Фамилия: ");
		scanf("%s", group[i].surname);
		printf("Имя: ");
		scanf("%s", group[i].name);
		printf("Дата рождения (день месяц год): ");
		scanf("%d %s %d", &group[i].day, &group[i].month, &group[i].year);
		//printf("%d %s %d", group[i].day, group[i].month, group[i].year);
		do {
			printf("Введите количество экзаменов(от 3 до 5): ");
			scanf("%d", &group[i].amountEx);
		} while (3 > group[i].amountEx || group[i].amountEx > 5);

		for (int j = 0; j < group[i].amountEx; j++) {
			printf("Введите название %d дисциплины: ", j + 1);
			scanf("%s", &group[i].subjects[j].ExamName);

			do {
				printf("Введите оценку за экзамен по пятибальной шкале: ");
				scanf("%d", &group[i].subjects[j].grade);
			} while (group[i].subjects[j].grade > 5 || group[i].subjects[j].grade < 1);
		}
	}

	printf("\nАнкетные данные студентов:\n");
	printf("| %-10s | %-10s | %-10s || %-10s - %-10s \n", "Фамилия", "Имя", "Дата рожд.", "Сдаваемые предметы", "Оценка");
	printf("|------------|------------|------------||------------------------\n");
	for (int i = 0; i < count; i++) {
		printf("| %-10s | %-10s | %02d.%02s.%d ||", group[i].surname, group[i].name, group[i].day, group[i].month, group[i].year);
		for (int j = 0; j < group[i].amountEx; j++)
			printf("%3s - %d; ", group[i].subjects[j].ExamName, group[i].subjects[j].grade);
		printf("\n");
	}
	printf("\n \n");
	// вывод студентов с оценкой "отлично" по физике
	int check = 0;
	printf("Студенты, получившие ОТЛИЧНО по физике: \n");
	printf("| %-10s | %-10s | %-10s |\n", "Фамилия", "Имя", "Дата рожд.");
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < group[i].amountEx; j++)
		{
			if (group[i].subjects[j].grade == 5)
			{
				if (strcmp(group[i].subjects[j].ExamName, "phisics") == 0 || strcmp(group[i].subjects[j].ExamName, "Phisics") == 0)
				{
					check++;
					printf("|------------|------------|------------|\n");
					printf("| %-10s | %-10s | %02d.%02s.%d |", group[i].surname, group[i].name, group[i].day, group[i].month, group[i].year);

				}
			}

		}

	}
	if (check == 0) printf("Нет студентов, получивших оценку ОТЛИЧНО по физике");
	printf("\n \n");

	sort(group, count);

	printf("\nОтсортированные анкетные данные студентов:\n");
	printf("| %-10s | %-10s | %-10s || %-10s - %-10s \n", "Фамилия", "Имя", "Дата рожд.", "Сдаваемые предметы", "Оценка");
	printf("|------------|------------|------------||------------------------\n");
	for (int i = 0; i < count; i++)
	{
		printf("| %-10s | %-10s | %02d.%02s.%d ||", group[i].surname, group[i].name, group[i].day, group[i].month, group[i].year);
		for (int j = 0; j < group[i].amountEx; j++)
			printf("%3s - %d; ", group[i].subjects[j].ExamName, group[i].subjects[j].grade);
		printf("\n");
	}
	return 0;
}