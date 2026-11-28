#include <stdio.h>

int main()
{
    int n, i, j;
    int marks[100][5];
    int total[100];
    float percentage[100];

    int passMark;
    int topper = 0;
    int classTotal = 0;
    int fail = 0;

    /* Create a file pointer */
    FILE *file;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("Enter the passing marks for each subject: ");
    scanf("%d", &passMark);

    /* Input marks */
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the marks of Student %d:\n", i + 1);

        total[i] = 0;

        for (j = 0; j < 5; j++)
        {
            printf("Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);

            total[i] = total[i] + marks[i][j];
        }

        percentage[i] = total[i] / 5.0;

        classTotal = classTotal + total[i];
    }

    /* Find class topper */
    for (i = 1; i < n; i++)
    {
        if (total[i] > total[topper])
        {
            topper = i;
        }
    }

    /* Open file to save results */
    file = fopen("student_results.txt", "w");

    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    printf("\n========================================\n");
    printf("        STUDENT RESULT SUMMARY\n");
    printf("========================================\n");

    /* Write heading to file */
    fprintf(file, "========================================\n");
    fprintf(file, "        STUDENT RESULT SUMMARY\n");
    fprintf(file, "========================================\n");

    for (i = 0; i < n; i++)
    {
        fail = 0;

        printf("\nStudent %d\n", i + 1);
        fprintf(file, "\nStudent %d\n", i + 1);

        printf("\nSubject-wise Result:\n");
        fprintf(file, "\nSubject-wise Result:\n");

        for (j = 0; j < 5; j++)
        {
            printf("Subject %d : %d - ",
                   j + 1, marks[i][j]);

            fprintf(file, "Subject %d : %d - ",
                    j + 1, marks[i][j]);

            if (marks[i][j] >= passMark)
            {
                printf("PASS\n");
                fprintf(file, "PASS\n");
            }
            else
            {
                printf("FAIL\n");
                fprintf(file, "FAIL\n");

                fail = 1;
            }
        }

        printf("\nTotal      : %d / 500\n", total[i]);
        fprintf(file, "\nTotal      : %d / 500\n", total[i]);

        printf("Percentage : %.2f%%\n", percentage[i]);
        fprintf(file, "Percentage : %.2f%%\n", percentage[i]);

        /* Overall result */
        if (fail == 1)
        {
            printf("Grade      : F\n");
            printf("Status     : FAIL\n");

            fprintf(file, "Grade      : F\n");
            fprintf(file, "Status     : FAIL\n");
        }
        else
        {
            printf("Status     : PASS\n");
            fprintf(file, "Status     : PASS\n");

            if (percentage[i] >= 90)
            {
                printf("Grade      : A+\n");
                fprintf(file, "Grade      : A+\n");
            }

            else if (percentage[i] >= 80)
            {
                printf("Grade      : A\n");
                fprintf(file, "Grade      : A\n");
            }

            else if (percentage[i] >= 70)
            {
                printf("Grade      : B\n");
                fprintf(file, "Grade      : B\n");
            }

            else if (percentage[i] >= 60)
            {
                printf("Grade      : C\n");
                fprintf(file, "Grade      : C\n");
            }

            else if (percentage[i] >= 50)
            {
                printf("Grade      : D\n");
                fprintf(file, "Grade      : D\n");
            }

            else
            {
                printf("Grade      : E\n");
                fprintf(file, "Grade      : E\n");
            }
        }
    }

    /* Class performance report */
    printf("\n========================================\n");
    printf("        CLASS PERFORMANCE REPORT\n");
    printf("========================================\n");

    fprintf(file, "\n========================================\n");
    fprintf(file, "        CLASS PERFORMANCE REPORT\n");
    fprintf(file, "========================================\n");

    printf("Class Topper      : Student %d\n",
           topper + 1);

    fprintf(file, "Class Topper      : Student %d\n",
            topper + 1);

    printf("Topper Marks      : %d / 500\n",
           total[topper]);

    fprintf(file, "Topper Marks      : %d / 500\n",
            total[topper]);

    printf("Topper Percentage : %.2f%%\n",
           percentage[topper]);

    fprintf(file, "Topper Percentage : %.2f%%\n",
            percentage[topper]);

    printf("Class Average     : %.2f%%\n",
           classTotal / (n * 5.0));

    fprintf(file, "Class Average     : %.2f%%\n",
            classTotal / (n * 5.0));

    /* Close the file */
    fclose(file);

    printf("\nResults successfully saved in student_results.txt\n");

    return 0;
}
