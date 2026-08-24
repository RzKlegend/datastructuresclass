/*2. Music Playlist Navigation System 
A music application maintains a playlist using a Doubly Linked List.
Each node contains:
•	Song ID 
•	Song Name 
•	Artist Name 
•	Duration 
Develop a C program to:
1.	Add a song at the beginning, end, or specified position. 
2.	Remove a song using its Song ID. 
3.	Play the next song. 
4.	Play the previous song. 
5.	Search for a song. 
6.	Display the playlist in forward order. 
7.	Display the playlist in reverse order. 
(Write the complete C program here.)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    int songID;
    char songName[50];
    char artistName[50];
    float duration;
    struct Song* prev;
    struct Song* next;
};

struct Song* addSong(struct Song* head, int id, char* name, char* artist, float dur) {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    newSong->songID = id;
    strcpy(newSong->songName, name);
    strcpy(newSong->artistName, artist);
    newSong->duration = dur;
    newSong->next = NULL;
    
    if (head == NULL) {
        newSong->prev = NULL;
        return newSong;
    }
    
    struct Song* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newSong;
    newSong->prev = temp;
    return head;
}

void playNext(struct Song** current) {
    if (*current != NULL && (*current)->next != NULL) {
        *current = (*current)->next;
        printf("Now Playing: %s\n", (*current)->songName);
    } else {
        printf("End of playlist.\n");
    }
}

void playPrev(struct Song** current) {
    if (*current != NULL && (*current)->prev != NULL) {
        *current = (*current)->prev;
        printf("Now Playing: %s\n", (*current)->songName);
    } else {
        printf("Beginning of playlist.\n");
    }
}

void displayForward(struct Song* head) {
    struct Song* temp = head;
    while (temp != NULL) {
        printf("%s by %s\n", temp->songName, temp->artistName);
        temp = temp->next;
    }
}

int main() {
    struct Song* playlist = NULL;
    playlist = addSong(playlist, 101, "Song A", "Artist X", 3.5);
    playlist = addSong(playlist, 102, "Song B", "Artist Y", 4.2);
    
    printf("Playlist:\n");
    displayForward(playlist);
    
    struct Song* currentSong = playlist;
    printf("\nCurrently Playing: %s\n", currentSong->songName);
    
    playNext(&currentSong);
    playPrev(&currentSong);
    
    return 0;
}
