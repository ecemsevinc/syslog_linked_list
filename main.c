#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Syslog kaydini temsil eden yapi (struct)
typedef struct SyslogEntry {
    char timestamp[20];  //Kaydin Zaman damgasi (Örnek: "2025-02-14 12:00:00")
    char facility[10];   // Kaynagi belirtir (Örnek: "auth", "kernel")
    char severity[10];   // Önem seviyesini belirtir (Örnek: "info", "error")
    char message[100];   // Mesaj icerigini tutar  (Örnek: "User login successful")
    struct SyslogEntry* next;  // Bir sonraki kaydi isaret eden pointer
} SyslogEntry;

// Yeni bir syslog kaydi ekleme fonksiyonu
void addSyslogEntry(SyslogEntry** head, char timestamp[], char facility[], char severity[], char message[]) {
    // Yeni bir dügüm (node) için bellek ayirma
    SyslogEntry* newEntry = (SyslogEntry*)malloc(sizeof(SyslogEntry)); //malloc ile bellekten yer ayirir.
    
    // Verileri yeni dügüme kopyalama
    strcpy(newEntry->timestamp, timestamp);
    strcpy(newEntry->facility, facility);
    strcpy(newEntry->severity, severity);
    strcpy(newEntry->message, message);
    
    // Yeni dügümü listenin basina ekleme
    newEntry->next = *head;  // Yeni dügüm, mevcut basi iþaret eder
    *head = newEntry;        // Listenin basi artýk yeni dügümdür
}

// Syslog kayitlarini ekrana yazdirma fonksiyonu
void printSyslogEntries(SyslogEntry* head) {
    SyslogEntry* current = head;  // Listenin basini isaret eden gecici pointer
    while (current != NULL) {     // Liste sonuna kadar dongu
        printf("Timestamp: %s, Facility: %s, Severity: %s, Message: %s\n",
               current->timestamp, current->facility, current->severity, current->message);
        current = current->next;  // Bir sonraki dugume gec
    }
}

// Bellegi temizleme fonksiyonu (bagli listeyi silme)
void freeSyslogEntries(SyslogEntry* head) {
    SyslogEntry* current = head;  // Listenin basini iþaret eden gecici pointer
    SyslogEntry* next;            // Bir sonraki dugumu saklamak icin
    while (current != NULL) {     // Liste sonuna kadar döngü
        next = current->next;    // Bir sonraki dügümü sakla
        free(current);           // Mevcut dugumu bellekten sil
        current = next;          // Bir sonraki dugume geç
    }
}



int main(int argc, char *argv[]) {
	SyslogEntry* head = NULL;  // Bagli listenin baþini NULL olarak baþlat

    // Örnek syslog kayitlari ekleme
    addSyslogEntry(&head, "2025-02-14 12:00:00", "auth", "info", "User login successful");
    addSyslogEntry(&head, "2025-02-14 12:05:00", "kernel", "error", "Disk I/O error");
    addSyslogEntry(&head, "2025-02-14 12:10:00", "mail", "warning", "Mail server queue full");

    // Syslog kayitlarini ekrana yazdýrma
    printf("Syslog Kayitlari:\n");
    printSyslogEntries(head);

    // Bellegi temizleme (bagli listeyi silme)
    freeSyslogEntries(head);
	return 0;
}
