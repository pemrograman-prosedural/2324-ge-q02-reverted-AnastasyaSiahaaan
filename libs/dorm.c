#include "dorm.h"

#define MAX_DORMS 100

unsigned short dorm_size = 0;
unsigned short students_size = 0; 


struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender) {
    struct dorm_t dorm; 

    
    if (_capacity == 0) {
        fprintf(stderr, "Error: Dorm capacity cannot be zero.\n");
        return dorm; /
    }

    strcpy(dorm.name, _name);
    dorm.capacity = _capacity;
    dorm.residents_num = 0;
    dorm.gender = _gender;

    return dorm;
}


void print_dorm(struct dorm_t dorm) {
    printf("%s|%d|", dorm.name, dorm.capacity);
    if (dorm.gender == GENDER_FEMALE) {
        printf("female\n");
    } else {
        printf("male\n");
    }
}


void print_dorm_all_detail(struct dorm_t dorm) {
    printf("%s|%d|", dorm.name, dorm.capacity);
    (dorm.gender == GENDER_MALE) ? printf("male|") : printf("female|");
    printf("%d\n", dorm.residents_num);
    fflush(stdout);
}

short dorm_index(char *_name, struct dorm_t dorms[], int length) {
    for (int i = 0; i < length; i++) {
        if (strcmp(_name, dorms[i].name) == 0) {
            return i;
        }
    }
    return -1; 
}


void empty_dorm(struct dorm_t *dorm, char *students) {
    for (int i = 0; i < students_size; i++) {
        if (students[i].dorm == dorm) {
            students[i].dorm= NULL; 
        }
    }
    dorm->residents_num = 0;
}
