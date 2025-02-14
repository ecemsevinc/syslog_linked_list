#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Syslog kaydýný temsil eden yapý (struct)
typedef struct SyslogEntry {
    char timestamp[20];  //Kaydýn Zaman damgasý (Örnek: "2023-10-01 12:00:00")
    char facility[10];   // Kaynaðý belirtir (Örnek: "auth", "kernel")
    char severity[10];   // Önem seviyesini belirtir (Örnek: "info", "error")
    char message[100];   // Mesaj içeriðini tutar  (Örnek: "User login successful")
    struct SyslogEntry* next;  // Bir sonraki kaydý iþaret eden pointer
} SyslogEntry;

// Yeni bir syslog kaydý ekleme fonksiyonu
void addSyslogEntry(SyslogEntry** head, char timestamp[], char facility[], char severity[], char message[]) {
    // Yeni bir düðüm (node) için bellek ayýrma
    SyslogEntry* newEntry = (SyslogEntry*)malloc(sizeof(SyslogEntry)); //malloc ile bellekten yer ayýrýr.
    
    // Verileri yeni düðüme kopyalama
    strcpy(newEntry->timestamp, timestamp);
    strcpy(newEntry->facility, facility);
    strcpy(newEntry->severity, severity);
    strcpy(newEntry->message, message);
    
    // Yeni düðümü listenin baþýna ekleme
    newEntry->next = *head;  // Yeni düðüm, mevcut baþý iþaret eder
    *head = newEntry;        // Listenin baþý artýk yeni düðümdür
}

// Syslog kayýtlarýný ekrana yazdýrma fonksiyonu
void printSyslogEntries(SyslogEntry* head) {
    SyslogEntry* current = head;  // Listenin baþýný iþaret eden geçici pointer
    while (current != NULL) {     // Liste sonuna kadar döngü
        printf("Timestamp: %s, Facility: %s, Severity: %s, Message: %s\n",
               current->timestamp, current->facility, current->severity, current->message);
        current = current->next;  // Bir sonraki düðüme geç
    }
}

// Belleði temizleme fonksiyonu (baðlý listeyi silme)
void freeSyslogEntries(SyslogEntry* head) {
    SyslogEntry* current = head;  // Listenin baþýný iþaret eden geçici pointer
    SyslogEntry* next;            // Bir sonraki düðümü saklamak için
    while (current != NULL) {     // Liste sonuna kadar döngü
        next = current->next;    // Bir sonraki düðümü sakla
        free(current);           // Mevcut düðümü bellekten sil
        current = next;          // Bir sonraki düðüme geç
    }
}



int main(int argc, char *argv[]) {
	SyslogEntry* head = NULL;  // Baðlý listenin baþýný NULL olarak baþlat

    // Örnek syslog kayýtlarý ekleme
    addSyslogEntry(&head, "2025-02-14 12:00:00", "auth", "info", "User login successful");
    addSyslogEntry(&head, "2025-02-14 12:05:00", "kernel", "error", "Disk I/O error");
    addSyslogEntry(&head, "2025-02-14 12:10:00", "mail", "warning", "Mail server queue full");

    // Syslog kayýtlarýný ekrana yazdýrma
    printf("Syslog Kayitlari:\n");
    printSyslogEntries(head);

    // Belleði temizleme (baðlý listeyi silme)
    freeSyslogEntries(head);
	return 0;
}
