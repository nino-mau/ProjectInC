#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

#define MAX_CLASS_SIZE 30
#define MAX_STUDENTS 150

int main()
{

   // === Variables ===

   Student students[MAX_STUDENTS]; // Store students info (name, grade)
   int studentCount = 0;

   // === Executable ===

   printf("=== Welcome to student grades management software ===\n");

   // Display options

   int selectedOption;

   printf("Option 1: Add Grades\n");

   // Take user input

   printf("Please choose an option: ");
   scanf("%d", &selectedOption);

   // Execute action depending on input

   switch (selectedOption)
   {
   case 1:
      // === Add Student ===

      char studentName[50];
      int studentGrade;

      int userInput;

      for (int i = 0; i < MAX_CLASS_SIZE; i++)
      {
         printf("=== Add student service ===\n");

         printf("Student name: ");
         scanf("%s", studentName);

         strcpy(students[i].name, studentName);

         printf("Student grade: ");
         scanf("%d", &studentGrade);

         students[i].grade = studentGrade;

         studentCount++;

         printf("Enter 1 to continue & 0 to leave\n");
         scanf("%d", &userInput);

         // To exit loop
         if (userInput == 0)
         {
            printStudents(students, studentCount);
            break;
         }
      }
      break;

   default:
      printf("INVALID OPTION");
      exit(0);
      break;
   }
};

// === Functions ===
