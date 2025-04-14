#include <stdio.h>
#include <string.h>

// Headers
#include "student.h"
#include "colors.h"

// === Functions ===

void printStudents(Student students[], int studentCount)
{
   printf("\n");
   printf(YELLOW "=== Students List ===\n" RESET);
   printf("\n");

   for (int i = 0; i < studentCount; i++)
   {
      printf(BOLD GREEN "%s, %d\n" RESET, students[i].name, students[i].grade);
   }
   printf("\n");
}

int editStudent(Student students[], int studentCount, char *studentName, char *newName, int newGrade)
{
   for (int i = 0; i < studentCount; i++)
   {
      if (!strcmp(students[i].name, studentName))
      {
         strcpy(students[i].name, newName);
         students[i].grade = newGrade;

         return 1;
      }
   }
   return 0;
}

int getAverageClassGrade(Student students[], int studentCount)
{
   int classGradeTotal = 0;

   for (int i = 0; i < studentCount; i++)
   {
      classGradeTotal += students[i].grade;
   }

   return classGradeTotal / studentCount;
}