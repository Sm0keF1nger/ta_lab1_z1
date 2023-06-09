#include <stdio.h>
#include <stdlib.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    int numStudents, i;
    float grade, sum = 0, avg;

    // Введення кількості студентів
    while (true) {
        printf_s("Enter the number of students in the group: ");
        if (scanf_s("%d", &numStudents) != 1) {
            printf_s("Invalid input. Please enter a valid integer.\n");
            clearInputBuffer();
        }
        else {
            break;
        }
    }

    // Введення балів успішності студентів та обчислення загального середнього
    FILE* file;
    if (fopen_s(&file, "average_grade.txt", "w") != 0) {
        printf_s("Error opening file. Exiting program.");
        return 1;
    }

    for (i = 1; i <= numStudents; i++) {
        while (true) {
            printf_s("Enter the average grade of student %d: ", i);
            if (scanf_s("%f", &grade) != 1) {
                printf_s("Invalid input. Please enter a valid floating-point number.\n");
                clearInputBuffer();
            }
            else {
                fprintf(file, "Student %d grade: %.2f\n", i, grade);
                sum += grade;
                break;
            }
        }
    }

    fclose(file);

    // Обчислення середнього балу групи
    avg = sum / numStudents;

    // Додавання середнього балу групи в кінець файлу
    if (fopen_s(&file, "average_grade.txt", "a") != 0) {
        printf_s("Error opening file. Exiting program.");
        return 1;
    }

    fprintf(file, "Group average grade: %.2f\n", avg);
    fclose(file);

    printf_s("File with the average grade and student grades has been created.");

    return 0;
}
