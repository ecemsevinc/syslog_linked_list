#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Syslog kayd�n� temsil eden yap� (struct)
typedef struct SyslogEntry {
    char timestamp[20];  //Kayd�n Zaman damgas� (�rnek: "2023-10-01 12:00:00")
    char facility[10];   // Kayna�� belirtir (�rnek: "auth", "kernel")
    char severity[10];   // �nem seviyesini belirtir (�rnek: "info", "error")
    char message[100];   // Mesaj i�eri�ini tutar  (�rnek: "User login successful")
    struct SyslogEntry* next;  // Bir sonraki kayd� i�aret eden pointer
} SyslogEntry;

// Yeni bir syslog kayd� ekleme fonksiyonu
void addSyslogEntry(SyslogEntry** head, char timestamp[], char facility[], char severity[], char message[]) {
    // Yeni bir d���m (node) i�in bellek ay�rma
    SyslogEntry* newEntry = (SyslogEntry*)malloc(sizeof(SyslogEntry)); //malloc ile bellekten yer ay�r�r.
    
    // Verileri yeni d���me kopyalama
    strcpy(newEntry->timestamp, timestamp);
    strcpy(newEntry->facility, facility);
    strcpy(newEntry->severity, severity);
    strcpy(newEntry->message, message);
    
    // Yeni d���m� listenin ba��na ekleme
    newEntry->next = *head;  // Yeni d���m, mevcut ba�� i�aret eder
    *head = newEntry;        // Listenin ba�� art�k yeni d���md�r
}

// Syslog kay�tlar�n� ekrana yazd�rma fonksiyonu
void printSyslogEntries(SyslogEntry* head) {
    SyslogEntry* current = head;  // Listenin ba��n� i�aret eden ge�ici pointer
    while (current != NULL) {     // Liste sonuna kadar d�ng�
        printf("Timestamp: %s, Facility: %s, Severity: %s, Message: %s\n",
               current->timestamp, current->facility, current->severity, current->message);
        current = current->next;  // Bir sonraki d���me ge�
    }
}

// Belle�i temizleme fonksiyonu (ba�l� listeyi silme)
void freeSyslogEntries(SyslogEntry* head) {
    SyslogEntry* current = head;  // Listenin ba��n� i�aret eden ge�ici pointer
    SyslogEntry* next;            // Bir sonraki d���m� saklamak i�in
    while (current != NULL) {     // Liste sonuna kadar d�ng�
        next = current->next;    // Bir sonraki d���m� sakla
        free(current);           // Mevcut d���m� bellekten sil
        current = next;          // Bir sonraki d���me ge�
    }
}



int main(int argc, char *argv[]) {
	SyslogEntry* head = NULL;  // Ba�l� listenin ba��n� NULL olarak ba�lat

    // �rnek syslog kay�tlar� ekleme
    addSyslogEntry(&head, "2025-02-14 12:00:00", "auth", "info", "User login successful");
    addSyslogEntry(&head, "2025-02-14 12:05:00", "kernel", "error", "Disk I/O error");
    addSyslogEntry(&head, "2025-02-14 12:10:00", "mail", "warning", "Mail server queue full");

    // Syslog kay�tlar�n� ekrana yazd�rma
    printf("Syslog Kayitlari:\n");
    printSyslogEntries(head);

    // Belle�i temizleme (ba�l� listeyi silme)
    freeSyslogEntries(head);
	return 0;
}
