typedef struct
{
   char name[50];
   int grade;
} Student;

void printStudents(Student students[], int count);

int getAverageClassGrade(Student students[], int studentCount);

int editStudent(Student students[], int studentCount, char *studentName, char *newName, int newGrade);