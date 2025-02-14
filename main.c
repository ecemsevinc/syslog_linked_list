#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Syslog kaydini temsil eden yapi (struct)
typedef struct SyslogEntry {
    char timestamp[20];  //Kaydin Zaman damgasi (�rnek: "2025-02-14 12:00:00")
    char facility[10];   // Kayna�i belirtir (�rnek: "auth", "kernel")
    char severity[10];   // �nem seviyesini belirtir (�rnek: "info", "error")
    char message[100];   // Mesaj i�eri�ini tutar  (�rnek: "User login successful")
    struct SyslogEntry* next;  // Bir sonraki kaydi i�aret eden pointer
} SyslogEntry;

// Yeni bir syslog kaydi ekleme fonksiyonu
void addSyslogEntry(SyslogEntry** head, char timestamp[], char facility[], char severity[], char message[]) {
    // Yeni bir d�g�m (node) i�in bellek ay�rma
    SyslogEntry* newEntry = (SyslogEntry*)malloc(sizeof(SyslogEntry)); //malloc ile bellekten yer ayirir.
    
    // Verileri yeni d�g�me kopyalama
    strcpy(newEntry->timestamp, timestamp);
    strcpy(newEntry->facility, facility);
    strcpy(newEntry->severity, severity);
    strcpy(newEntry->message, message);
    
    // Yeni d�g�m� listenin ba��na ekleme
    newEntry->next = *head;  // Yeni d���m, mevcut ba�� i�aret eder
    *head = newEntry;        // Listenin ba�� art�k yeni d���md�r
}

// Syslog kayitlarnii ekrana yazdirma fonksiyonu
void printSyslogEntries(SyslogEntry* head) {
    SyslogEntry* current = head;  // Listenin ba�ini i�aret eden ge�ici pointer
    while (current != NULL) {     // Liste sonuna kadar dongu
        printf("Timestamp: %s, Facility: %s, Severity: %s, Message: %s\n",
               current->timestamp, current->facility, current->severity, current->message);
        current = current->next;  // Bir sonraki dugume gec
    }
}

// Bellegi temizleme fonksiyonu (bagli listeyi silme)
void freeSyslogEntries(SyslogEntry* head) {
    SyslogEntry* current = head;  // Listenin ba�ini i�aret eden gecici pointer
    SyslogEntry* next;            // Bir sonraki dugumu saklamak icin
    while (current != NULL) {     // Liste sonuna kadar d�ng�
        next = current->next;    // Bir sonraki d�g�m� sakla
        free(current);           // Mevcut dugumu bellekten sil
        current = next;          // Bir sonraki dugume ge�
    }
}



int main(int argc, char *argv[]) {
	SyslogEntry* head = NULL;  // Bagli listenin ba�ini NULL olarak ba�lat

    // �rnek syslog kayitlari ekleme
    addSyslogEntry(&head, "2025-02-14 12:00:00", "auth", "info", "User login successful");
    addSyslogEntry(&head, "2025-02-14 12:05:00", "kernel", "error", "Disk I/O error");
    addSyslogEntry(&head, "2025-02-14 12:10:00", "mail", "warning", "Mail server queue full");

    // Syslog kayitlarini ekrana yazd�rma
    printf("Syslog Kayitlari:\n");
    printSyslogEntries(head);

    // Bellegi temizleme (ba�li listeyi silme)
    freeSyslogEntries(head);
	return 0;
}
