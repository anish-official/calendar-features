#include <stdio.h>
#include <string.h>

#define FILE_HANDEL FILE *record_file = fopen("calendar-notes.txt", "rb+")

#pragma pack(1)
typedef struct noteHandel {
    int year, month, date ; // add DAY_NUMBER after merging with DAY_OF_WEEK function
    char note[100];
}noteStruct;


#pragma pack()

void appendNote(int, int,int , char *);
void deleteNote(int, int , int );
int totalNoteCount(FILE *);
void tempDisplayNotes();

int main(){
    int date, month, year;
    char text[100];

    printf("Enter Note Details [DD<space>MM<space>YYYY]: ");
    scanf("%d %d %d ", &date, &month, &year);

    printf("Enter Note : ");
    fgets(text, sizeof(text), stdin);

    appendNote(date, month, year, text);

     printf("Enter Note Details [DD<space>MM<space>YYYY]: ");
    scanf("%d %d %d ", &date, &month, &year);

    printf("Enter Note : ");
    fgets(text, sizeof(text), stdin);
    appendNote(date, month, year, text);

     printf("Enter Note Details [DD<space>MM<space>YYYY]: ");
    scanf("%d %d %d ", &date, &month, &year);

    printf("Enter Note : ");
    fgets(text, sizeof(text), stdin);
    appendNote(date, month, year, text);
    tempDisplayNotes();
    return 0;


}

void appendNote(int date, int month, int year, char * text){
    FILE_HANDEL;
    noteStruct note;
    note.date = date;
    note.month = month;
    note.year = year;
    strcpy(note.note, text);
    fseek(record_file, 0, SEEK_END);
    int ret = fwrite(&note, sizeof(note), 1, record_file);
    fclose(record_file);
}

void deleteNote(int date, int month, int year){
    FILE_HANDEL;
    int totalNotes = totalNotesCount(record_file);
    noteStruct notes[totalNotes];
    fseek(record_file, 0, SEEK_SET);
    fread(&notes, sizeof(notes), 1, record_file);   //might trigger a BUG
    int current = 0;
    int temp;
    while (current <= totalNotes)
    {
        if (notes[current].year == year)
        {
            if (notes[current].month == month)
            {
                if (notes[current].date == date)
                {
                    temp = current;
                    while (temp <= totalNotes)
                    {
                        notes[temp] = notes[temp + 1];
                    }
                }   
            }
        }
        else {
            current ++;
        }
        
    }
    fseek(record_file, 0, SEEK_SET);
    fwrite(&notes, sizeof(notes), 1, record_file);
    fclose(record_file);
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
        printf("date -- %d/%d/%d \n", note[i].date, note[i].month, note[i].year);
        printf("%s\n", note[i].note);
    }
    fclose(record_file);
}

int totalNotesCount(FILE *file){
    fseek(file, 0, SEEK_END);
    return (ftell(file));
}