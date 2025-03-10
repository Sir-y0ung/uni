#include <stdio.h>
#include <string.h>

struct Student_t {
    char name[30];
    int absences;
    char description[68];
};

void readInput(FILE * infile,int* size, struct Student_t students[100]) {
    char line[100];

    while(fgets(line, 100, infile)) {       // parsing students
        sscanf(line, "%[^,],%d,%[^\n]", students[*size].name, &students[*size].absences, students[*size].description);
        (*size)++;
    }
}

void writeOutput(FILE * oufile, int size, struct Student_t students[100] ) {
    int counter = 0;
    fprintf(oufile, "ONOMATEPWNYMO                                  APOUSIES      \n");
    fprintf(oufile, "-------------------------------------------------------------\n");

    for (int i = 0; i < size;i++) {
        if (students[i].absences > 100) {

            fprintf(oufile, "%s", students[i].name);    // print name

            for (int j = 0; j < (50 - strlen(students[i].name)); j++) { // complete with spaces
                fprintf(oufile, " ");
            }
        
            fprintf(oufile,"%d\n", students[i].absences);
            counter++;
        }
    }
    fprintf(oufile, "-------------------------------------------------------------\n");
    fprintf(oufile, "SΥΝΟLΟ ΜΑTHIΤWΝ:                                   %d\n", size);
    fprintf(oufile, "SΥΝΟLΟ ΑPΟΝΤWΝ:                                    %d\n", counter);
}



int main() {
    FILE* infile = fopen("i2f9.dat", "r"); // D:\\Coddingg\\C\\Uni\\lab12//
    FILE* outfile = fopen("Do2f9.dat", "w");
    struct Student_t students[100];
    int size = 0;

    if (infile == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    readInput(infile,&size,  students);

    writeOutput(outfile, size, students);

    fclose(infile);
    fclose(outfile);
    return 0;
}
