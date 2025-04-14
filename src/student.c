#include <stdio.h>
#include "student.h"

// === Functions ===

void printStudents(Student students[], int length)
{
   for (int i = 0; i < length; i++)
   {
      printf("=== Students List ===\n");
      printf("Name: %s, Grade: %d\n", students[i].name, students[i].grade);
   }
}