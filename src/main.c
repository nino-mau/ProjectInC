// Librairies
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Headers
#include "student.h"
#include "colors.h"

// Variables
#define MAX_CLASS_SIZE 30
#define MAX_STUDENTS 150

int main()
{

   // === Variables ===

   Student students[MAX_STUDENTS]; // Store students info (name, grade)
   int studentCount = 0;
   int loopCount = 0;

   // === Main Loop ===

   printf("\n");
   printf("\n");
   printf(YELLOW "=== Welcome to student grades management software ===\n" RESET);
   printf("\n");

   while (1)
   {

      // == Display options ==

      int selectedOption;

      printf(BOLD "Option 1: Insert students\n" RESET);
      printf(BOLD "Option 2: Get class average score\n" RESET);
      printf(BOLD "Option 3: Show all students infos\n" RESET);
      printf(BOLD "Option 4: Edit students\n" RESET);

      // == Take user input ==

      printf("Please choose an option (1: Insert, 2: Average, 3: Show All, 4: Edit ): ");
      scanf("%d", &selectedOption);

      // == Handle input ==

      switch (selectedOption)
      {

      // === Add Student ===
      case 1:
         char studentName[50];
         int studentGrade;

         int userInput;

         printf("\n");
         printf(YELLOW "=== Add Student ===\n" RESET);
         printf("\n");

         for (int i = 0; i < MAX_CLASS_SIZE; i++)
         {
            printf("\n");
            printf(YELLOW "Student N°%d\n" RESET, studentCount + 1);

            if (i == MAX_CLASS_SIZE - 1)
            {
               printf(RED "You have reached class size limit, you will not be able to add another student after this one\n" RESET);
            }

            printf("Student name: ");
            scanf("%s", studentName);

            strcpy(students[i].name, studentName);

            printf("Student grade: ");
            scanf("%d", &studentGrade);

            students[i].grade = studentGrade;

            studentCount++;

            printf("Enter 1 to continue OR 0 to leave: ");
            scanf("%d", &userInput);

            // To exit loop
            if (userInput == 0)
            {
               break;
            }
         }
         printf("\n");
         break;

      // === See average class grade ===
      case 2:
         printf("\n");

         if (studentCount)
         {
            int averageClassGrade = getAverageClassGrade(students, studentCount);

            printf(GREEN "The average grade of this class is: %d\n" RESET, averageClassGrade);
            printf("\n");
         }
         else
         {
            printf(RED "You haven't added any student grade yet !\n" RESET);
            printf("\n");
         }
         break;

      // === Print the info of the entire class ===
      case 3:
         printStudents(students, studentCount);
         break;

      // === Open submenu to allow editing student info ===
      case 4:
         printf("\n");
         printf(YELLOW "=== Edit Student ===\n" RESET);
         printf("\n");

         char newName[50];
         char oldName[50];
         int newGrade;

         printf("Enter student name\n");
         scanf("%s", oldName);

         printf("Enter new name\n");
         scanf("%s", newName);

         printf("Enter new grade\n");
         scanf("%d", &newGrade);

         int res = editStudent(students, studentCount, oldName, newName, newGrade);

         if (res)
         {
            printf(GREEN "Succesfully edited student infos\n" RESET);
         }
         else
         {
            printf(RED "Couldn't find student !\n" RESET);
         }

         printf("\n");
         break;

      default:
         printf(RED "INVALID OPTION" RESET);
         printf("\n");
         break;
      }

      loopCount++;
   }
};
