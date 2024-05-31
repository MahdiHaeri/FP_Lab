#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define MAX_ARRAY_SIZE 100
#define CLOUMN_SIZE 15

// ----------------- Structs ---------------------
struct Student;
struct Class;
struct Score;
struct Node;

struct Class {
    char* class_name;
    char* teacher_name;
    struct Linked_list* class_list;
};

struct Student {
    char* student_first_name;
    char* student_last_name;
    int id;
    char* city;
    int age;
    int count_of_classes;
    struct Class* list_of_classes[MAX_ARRAY_SIZE];
    struct Score* list_of_scores[MAX_ARRAY_SIZE];
};

struct Score {
    struct Class* class;
    struct Student* student;
    double amount;
};

struct Node {
    struct Student* student;
    struct Score* score;
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
    class->class_name = class_name;
    class->teacher_name = teacher_name;
    class->class_list = (struct Linked_list*) malloc(sizeof(struct Linked_list));
    linked_list_constructor(class->class_list);
}

void student_constructor(struct Student* student, char* student_first_name, char* student_last_name, int id, char* city, int age) {
    student->student_first_name = student_first_name;
    student->student_last_name = student_last_name;
    student->city = city;
    student->id = id;
    student->age = age;
    student->count_of_classes = 0;
}

void score_constructor(struct Score* score, struct Student* student, struct Class* class) {
    score->student = student;
    score->class = class;
    score->amount = 0;
}

void node_constructor(struct Node* node, struct Student* student, struct Score* score) {
    node->student = student;
    node->score = score;
    node->next = NULL;
}

// ----------------- Methods ---------------------

void set_score(struct Student* student, struct Class* class, double score) {
    // find the class in student's list of classes
    for (int i = 0; i < student->count_of_classes; i++) {
        if (student->list_of_classes[i] == class) {
            student->list_of_scores[i]->amount = score; // set score
            break;
        }
    }
}

double get_average_score_of_class(struct Class* class) {
    if (class->class_list->count == 0) {
        return 0;
    }
    double sum = 0;
    struct Node* current_node = class->class_list->head;
    while (current_node != NULL) {
        sum += current_node->score->amount;
        current_node = current_node->next;
    }
    return sum / class->class_list->count;
}

// -------------------- linked list method ------------------------------

// is_exist: check the student is exist in the linked list
struct Node* is_exist(struct Linked_list* linked_list, struct Student* student) {
    struct Node* current_node = linked_list->head;
    while (current_node != NULL) {
        if (current_node->student == student) {
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}

// delete_node: delete the node from the linked list
void delete_node(struct Linked_list* linked_list, struct Node* node) {
    struct Node* current_node = linked_list->head;
    struct Node* previous_node = NULL;
    while (current_node != NULL) {
        if (current_node == node) {
            if (previous_node == NULL) {
                linked_list->head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            linked_list->count--;
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
}


void delete_class_from_classes_of_student(struct Student* student, struct Class* class) {
    for (int i = 0; i < student->count_of_classes; i++) {
        if (student->list_of_classes[i] == class) {
            student->list_of_classes[i] = NULL;
            student->list_of_scores[i] = NULL;
            student->count_of_classes--;
            break;
        }
    }
}

void delete_student_from_class(struct Class* class, struct Student* student) {
    struct Node* node = is_exist(class->class_list, student);
    if (node != NULL) {
        delete_node(class->class_list, node);
    }
    delete_class_from_classes_of_student(student, class);
}

void insert_node(struct Linked_list* linked_list, struct Node* node) {
    if (is_exist(linked_list, node->student) != NULL) {
        printf("This student recently is exist, ID: %d, Name: %s %s\n", node->student->id, node->student->student_first_name, node->student->student_last_name);
        return;
    }
    if (linked_list->head == NULL) {
        linked_list->head = node;
        linked_list->tail = node;
    } else {
        linked_list->tail->next = node;
        linked_list->tail = node;
    }
    linked_list->count++;
}

void add_student_to_class_list(struct Class* class, struct Student* student) {
    struct Score* new_score = (struct Score*) malloc(sizeof(struct Score));
    score_constructor(new_score, student, class);
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    node_constructor(new_node, student, new_score);
    insert_node(class->class_list, new_node);
}

void add_class_to_classes_of_student(struct Student* student, struct Class* class, struct Score* score) {
    student->list_of_classes[student->count_of_classes] = class;
    student->list_of_scores[student->count_of_classes] = score;
    student->count_of_classes++;
}

void insert_student_to_class(struct Student* student, struct Class* class) {
    if (is_exist(class->class_list, student) != NULL) {
        printf("This student recently is exist, ID: %d, Name: %s %s\n", student->id, student->student_first_name, student->student_last_name);
        return;
    }
    add_student_to_class_list(class, student);
    add_class_to_classes_of_student(student, class, class->class_list->tail->score);
}

void print_class_list(struct Class* class) {
    struct Node* current_node = class->class_list->head;
    printf("Class Name: %s\n", class->class_name);
    printf("Teacher Name: %s\n", class->teacher_name);
    printf("--------------------------------------------\n");
    printf("%*s %*s %*s\n", -CLOUMN_SIZE, "ID:", -CLOUMN_SIZE, "First Name:", -CLOUMN_SIZE, "Last Name:");
    printf("--------------------------------------------\n");
    while (current_node != NULL) {
        printf("%*d %*s %*s\n", -CLOUMN_SIZE, current_node->student->id, -CLOUMN_SIZE, current_node->student->student_first_name, -CLOUMN_SIZE, current_node->student->student_last_name);
        current_node = current_node->next;
    }
}

// swap the student of two nodes in a linked list 
void swap(struct Linked_list* linked_list, struct Node* first_node, struct Node* second_node) {
    struct Student* temp_student = first_node->student;
    first_node->student = second_node->student;
    second_node->student = temp_student;
}

// sort the class list by student name
void sort_list(struct Class* class) {
    struct Node* current_node;
    for (int i = class->class_list->count - 1; i >= 0; i--) {
        current_node = class->class_list->head;
        for (int j = 0; j < i; j++) {
            if (strcmp(current_node->student->student_last_name, current_node->next->student->student_last_name) > 0) {
                swap(class->class_list, current_node, current_node->next);
            }
            current_node = current_node->next;
        }
    }
}

void get_students_list_from_csv_file(char* file_address, struct Class* class) {
    FILE* file = fopen(file_address, "r");
    char line[MAX_ARRAY_SIZE];
    char* token;

    fgets(line, MAX_ARRAY_SIZE, file); // skip first line
    while (fgets(line, MAX_ARRAY_SIZE, file) != NULL) {
        int* id = (int*) malloc(sizeof(int));
        char* first_name = (char*) malloc(sizeof(char) * MAX_ARRAY_SIZE);
        char* last_name = (char*) malloc(sizeof(char) * MAX_ARRAY_SIZE);

        token = strtok(line, ",");
        *id = atoi(token);
        token = strtok(NULL, ",");
        strcpy(first_name, token);
        token = strtok(NULL, ",");
        token[strlen(token) - 1] = '\0';
        strcpy(last_name, token);

        struct Student* student = (struct Student*) malloc(sizeof(struct Student));
        student_constructor(student, first_name, last_name, *id, NULL, 0);
        insert_student_to_class(student, class);
    }
}

void set_random_score(struct Class* class) {
    struct Node* current_node = class->class_list->head;
    while (current_node != NULL) {
        current_node->score->amount = rand() % 20 + 1;
        current_node = current_node->next;
    }
}

void write_student_info(struct Student* student, FILE* file_pointer) {
    fprintf(file_pointer, "%*d %*s %*s ", -CLOUMN_SIZE,student->id, -CLOUMN_SIZE, student->student_first_name, -CLOUMN_SIZE, student->student_last_name);
}

void write_score_info(struct Score* score, FILE* file_pointer) {
    fprintf(file_pointer, "%.2lf\t", score->amount);
}

void write_class_info(struct Class* class, char* file_address) {
    FILE* file_pointer = fopen(file_address, "w");
    struct Node* current_node = class->class_list->head;
    fprintf(file_pointer, "Class Name: %s\n", class->class_name);
    fprintf(file_pointer, "Teacher Name: %s\n", class->teacher_name);
    fprintf(file_pointer, "Average: %lf\n", get_average_score_of_class(class));
    fprintf(file_pointer, "--------------------------------------------------------\n");
    fprintf(file_pointer, "%*s %*s %*s %*s\n", -CLOUMN_SIZE, "ID:", -CLOUMN_SIZE, "First Name:", -CLOUMN_SIZE, "Last Name:", -CLOUMN_SIZE, "Score:");
    fprintf(file_pointer, "--------------------------------------------------------\n");
    while (current_node != NULL) {
        write_student_info(current_node->student, file_pointer);
        write_score_info(current_node->score, file_pointer);
        fprintf(file_pointer, "\n");
        current_node = current_node->next;
    }
}


int main(int argc, char const *argv[]) {
    srand(time(NULL)); // set random seed 

    struct Class class1; // create a class
    class_constructor(&class1, "Math", "Khosravi"); // set class name and teacher name and initialize class list 

    get_students_list_from_csv_file("./SuperClass.csv", &class1); // get students list from csv file and add them to class list
    set_random_score(&class1);

    write_class_info(&class1, "./ClassInfo.txt"); // write class info to a file
    // print_class_list(&class1); // print class list to console


    // ----------------------------------
    // struct Student student1;
    // struct Student student2;
    // struct Student student3;

    // student_constructor(&student1, "Ali", "AA", 1, "Tehran", 0);
    // student_constructor(&student2, "Mohammad", "AB", 2, "Yazd", 0);
    // student_constructor(&student3, "Sara", "AC", 3, "Kerman", 0);

    // insert_student_to_class(&student1, &class1);
    // insert_student_to_class(&student2, &class1);
    // insert_student_to_class(&student3, &class1);
    
    // set_score(&student1, &class1, 20);
    // set_score(&student2, &class1, 19);
    // set_score(&student3, &class1, 18);
    // ----------------------------------

    
    // sort_list(&class1);

    // print_class_list(&class1);
    return 0;
}
