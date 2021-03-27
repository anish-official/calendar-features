#include <stdio.h>
#include <string.h>

#define FLUSH fflush(stdin)
#define FILE_HANDEL FILE * record_file = fopen("calendar-notes.bin", "rb+")

#pragma pack(1)
typedef struct noteHandel {
    int year, month, date ; // add DAY_NUMBER after merging with DAY_OF_WEEK function
    char note[100];
}noteStruct;


#pragma pack()

void appendNote(int, int,int , char *);
void deleteNote(int, int , int );
int totalNotesCount(FILE *);
void tempDisplayNotes();

int main(){
    tempDisplayNotes();
    int date, month, year;
    char text[100];
    for (int i = 0; i < 5; i++)
    {
        FLUSH;
        printf("Enter Note Details [DD <enter key> MM <enter key> YYYY]: ");
        scanf("%d %d %d", &date, &month, &year);

        FLUSH;
        printf("Enter Note : ");
        gets(text);

        appendNote(date, month, year, text);
    }
    printf("Enter Note FOR DELETE_NOTE [DD<space>MM<space>YYYY]: ");
    scanf("%d %d %d", &date, &month, &year);
    deleteNote(date, month, year);
    tempDisplayNotes(); 
    return 0;


}

void appendNote(int date, int month, int year, char * text){
    noteStruct note;
    note.date = date;
    note.month = month;
    note.year = year;
    strcpy(note.note, text);
    FILE_HANDEL;
    fseek(record_file, 0, SEEK_END);
    fwrite(&note, sizeof(note), 1, record_file);
    fclose(record_file);
}

void deleteNote(int date, int month, int year){
    FILE_HANDEL;
    int noteCount = totalNotesCount(record_file);
    int triggered = 0;
    noteStruct note[noteCount];
    fseek(record_file, 0, SEEK_SET);
    fread(&note, sizeof(note), 1, record_file);
    for (int i = 0; i < noteCount; i++)
    {
        if ((note[i].date == date) && (note[i].month == month) && (note[i].year == year))
        {
            for (int j = i; j < noteCount; j++)
            {
                note[i] = note[i+1];
            }
            triggered++;
        }
        
    }
    fclose(record_file);
    FILE *write_file = fopen("calendar-notes.bin", "wb+");
    fseek(write_file, 0, SEEK_SET);
    for (int i = 0; i < (noteCount - triggered); i++)
    {
        fwrite(&note[i], sizeof(note[i]), 1, write_file);
    }
    fclose(write_file);
}

/* 
void display_notes( ){

}
 */
void tempDisplayNotes(){
    FILE_HANDEL;
    int noteCount = totalNotesCount(record_file);
    noteStruct note[noteCount];
    fseek(record_file, 0, SEEK_SET);
    fread(&note, sizeof(note), 1, record_file);
    
    for (int i = 0; i < noteCount; i++)
    {
        printf("%d .\n", i);
        printf("\tdate -- %d/%d/%d \n", note[i].date, note[i].month, note[i].year);
        printf("\t%s\n", note[i].note);
    }
    fclose(record_file);
}

int totalNotesCount(FILE *file){
    fseek(file, 0, SEEK_END);
    return (((ftell(file)) / sizeof(noteStruct)));
}
