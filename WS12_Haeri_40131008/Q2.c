#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 100

// ----------------- Structs ---------------------
struct Student;
struct Class;
struct Score;
struct Students_and_scores;

struct Students_and_scores { // this struct is used to store a student and his score together in a class 
    struct Student* student;
    struct Score* score;
};

struct Class { // class has a list of students and a list of scores for each student
    char* class_name;
    char* teacher_name;
    int count_of_students;
    struct Students_and_scores* students_and_scores[MAX_ARRAY_SIZE];
};

struct Student { // student has a list of classes and a list of scores for each class
    char* student_name;
    char* city;
    int id;
    int age;
    int count_of_classes;
    struct Class* list_of_classes[MAX_ARRAY_SIZE];
    struct Score* list_of_scores[MAX_ARRAY_SIZE];
};

struct Score { // score has a student and a class and a score
    struct Class* class;
    struct Student* student;
    double score;
};

// ----------------- Constructors ---------------------

void class_constructor(struct Class* class) {
    class->count_of_students = 0;
}

void student_constructor(struct Student* student, char* student_name, char* city, int id, int age) {
    student->student_name = student_name;
    student->city = city;
    student->id = id;
    student-> age = age;
    student->count_of_classes = 0;
}

void score_constructor(struct Score* score, struct Student* student, struct Class* class) {
    score->student = student;
    score->class = class;
    score->score = 0;
}

// ----------------- Methods ---------------------

// join student to class and create a score 0 for student in class
void join_student_to_class(struct Student* student, struct Class* class) {
    struct Score* new_score = (struct Score*) malloc(sizeof(struct Score));
    score_constructor(new_score, student, class);
    
    student->list_of_classes[student->count_of_classes] = class;
    student->list_of_scores[student->count_of_classes] = new_score;
    student->count_of_classes++;

    class->students_and_scores[class->count_of_students] = (struct Students_and_scores*) malloc(sizeof(struct Students_and_scores));
    class->students_and_scores[class->count_of_students]->student = student;
    class->students_and_scores[class->count_of_students]->score = new_score;
    class->count_of_students++;
}

void set_score(struct Student* student, struct Class* class, double score) {
    // find the class in student's list of classes
    for (int i = 0; i < student->count_of_classes; i++) {
        if (student->list_of_classes[i] == class) {
            student->list_of_scores[i]->score = score; // set score
            break;
        }
    }
}

void print_average_score_of_class(struct Class* class) {
    if (class->count_of_students == 0) { // if there is no student in class print error message and return
        printf("There is no student in class %s\n", class->class_name);
        return;
    }
    double sum = 0;
    for (int i = 0; i < class->count_of_students; i++) {
        sum += class->students_and_scores[i]->score->score;
    }
    printf("Average score of class %s is: %f\n" , class->class_name, sum / class->count_of_students);
}

int main(int argc, char const *argv[]) {
    struct Student student1 = {"Ali", "Kerman", 1, 20};
    struct Student student2 = {"Reza", "Tehran", 2, 19};
    struct Student student3 = {"Mahdi", "Yazd", 3, 18};
    struct Student student4 = {"Goli", "Tehran", 4, 22};
    struct Student student5 = {"Sara", "Tehran", 5, 17};

    struct Class class1 = {"Math", "Khosravi", 0};
    struct Class class2 = {"Physics", "Doroodi", 0};
    
    // ---------------------------------------------------

    join_student_to_class(&student1, &class1);
    join_student_to_class(&student2, &class1);
    join_student_to_class(&student3, &class1);

    join_student_to_class(&student1, &class2);
    join_student_to_class(&student4, &class2);
    join_student_to_class(&student5, &class2);
    
    // ---------------------------------------------------

    set_score(&student1, &class1, 20);
    set_score(&student2, &class1, 19);
    set_score(&student3, &class1, 18);

    set_score(&student1, &class2, 17);
    set_score(&student4, &class2, 16);
    set_score(&student5, &class2, 15);
    
    // ---------------------------------------------------

    print_average_score_of_class(&class1);
    print_average_score_of_class(&class2);
    return 0;
}
