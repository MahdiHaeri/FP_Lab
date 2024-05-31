#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    struct Linked_list* class_list;
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

struct Node {
    struct Student* data;
    struct Node* next;
};

struct Linked_list {
    struct Node* head;
    struct Node* tail;
    int count;
};

// ----------------- Constructors ---------------------

void linked_list_constructor(struct Linked_list* linked_list) { 
    linked_list->head = NULL;
    linked_list->tail = NULL;
    linked_list->count = 0;
}

void class_constructor(struct Class* class, char* class_name, char* teacher_name) {
    class->class_list = (struct Linked_list*) malloc(sizeof(struct Linked_list));
    linked_list_constructor(class->class_list);
    class->class_name = class_name;
    class->teacher_name = teacher_name;
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

void insert(struct Linked_list* linked_list, struct Student* student);

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
    insert(class->class_list, student);
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

// -----------------  Linked list Methods ---------------------

// check if a student is exist in a class or not 
struct Node* is_exist(struct Linked_list* linked_list, struct Student* student) {
    struct Node* current_node = linked_list->head;
    while (current_node != NULL) {
        if (current_node->data == student) {
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}

// delete a student from a class list
void delete(struct Linked_list* linked_list, struct Student* student) {
    struct Node* current_node = linked_list->head->next;
    struct Node* befor_current_node = linked_list->head;
    if (befor_current_node->data == student) {
        linked_list->head = current_node;
        free(befor_current_node);
        linked_list->count--;
        return;
    }

    while (current_node != NULL) {
        if (current_node->data == student) {
            if (current_node == linked_list->tail) {
                linked_list->tail = befor_current_node;
            }
            befor_current_node->next = current_node->next;
            free(current_node);
            linked_list->count--;
            return;
        }
        current_node = current_node->next;
        befor_current_node = befor_current_node->next;
    }
    printf("There is no student %s by id %d in class\n", student->student_name, student->id);
}   


// insert a student to a class list
void insert(struct Linked_list* linked_list, struct Student* student) {
    if (is_exist(linked_list, student) != NULL) {
        printf("This student recently is exist. id: %d, name: %s\n", student->id, student->student_name);
        return;
    }
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = student;
    new_node->next = NULL;
    
    linked_list->count++;
    if (linked_list->head == NULL) {
        linked_list->head = new_node;
        linked_list->tail = new_node;
        return;
    }  
    linked_list->tail->next = new_node;
    linked_list->tail = new_node;
}

void print_class_list(struct Class* class) {
    struct Node* current_node = class->class_list->head;
    while (current_node != NULL) {
        printf("id: %d / Name: %s\n", current_node->data->id, current_node->data->student_name);
        current_node = current_node->next;
    }
}


// swap the data of two nodes in a linked list 
void swap(struct Linked_list* linked_list, struct Node* first_node, struct Node* second_node) {
    struct Student* temp_student = first_node->data;
    first_node->data = second_node->data;
    second_node->data = temp_student;
}


// sort the class list by student name
void sort_list(struct Class* class) {
    struct Node* current_node;
    for (int i = class->class_list->count - 1; i >= 0; i--) {
        current_node = class->class_list->head;
        for (int j = 0; j < i; j++) {
            if (strcmp(current_node->data->student_name, current_node->next->data->student_name) > 0) {
                swap(class->class_list, current_node, current_node->next);
            }
            current_node = current_node->next;
        }
    }
}

int main(int argc, char const *argv[]) {
    struct Student student1;
    struct Student student2;
    struct Student student3;
    struct Student student4;
    struct Student student5;

    student_constructor(&student1, "Reza", "Kerman", 1, 20);
    student_constructor(&student2, "Goli", "Tehran", 2, 19);
    student_constructor(&student3, "Mahdi", "Yazd", 3, 18);
    student_constructor(&student4, "Sara", "Tehran", 4, 22);
    student_constructor(&student5, "Ali", "Tehran", 5, 17);

    struct Class class1;
    struct Class class2;

    class_constructor(&class1, "Math", "Khosravi");
    class_constructor(&class2, "Physics", "Doroodi");
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
    

    // insert(class2.class_list, &student2);
    // delete(class2.class_list, &student1);
    // delete(class2.class_list, &student3);
    // insert(class2.class_list, &student1);

    
    sort_list(&class1);
    sort_list(&class2);

    print_class_list(&class1);
    printf("-------------------------------------\n");
    print_class_list(&class2);
    return 0;
}
