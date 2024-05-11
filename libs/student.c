#include "student.h"

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender) {
    struct student_t student;

    memset(student.id, 0, sizeof(student.id));
    memset(student.name, 0, sizeof(student.name));
    memset(student.year, 0, sizeof(student.year));
    student.gender = _gender;
    strncpy(student.id, _id, sizeof(student.id));
    strncpy(student.name, _name, sizeof(student.name));
    strncpy(student.year, _year, sizeof(student.year));
    student.dorm = NULL;

    return student;
}

void print_student(struct student_t student) {
    printf("%s|%s|%s|", student.id, student.name, student.year);
    if (student.gender == GENDER_MALE) {
        printf("male");
    } else if (student.gender == GENDER_FEMALE) {
        printf("female");
    }
    if (student.dorm == NULL) {
        printf("\n");
    } else {
        printf("%s\n", student.dorm->name);
    }
}

void assign_student(struct student_t *students, int students_size, struct dorm_t *dorms, int dorm_size) 
{
    for (int i = 0; i < students_size; i++){
        for (int j = 0; j < dorm_size; j++){
            if (students[i].gender == dorms[j].gender){
                if (dorms[j].capacity != dorms[j].residents_num){
                    students[i].dorm = malloc(sizeof(struct dorm_t)); 
                    strcpy(students[i].dorm->name, dorms[j].name);
                    dorms[j].residents_num++;
                    break;
                }
            }
        }
    }
}

void print_student_all_detail (struct student_t student) {
  printf("%s|%s|%s|", student.id, student.name, student.year);
}