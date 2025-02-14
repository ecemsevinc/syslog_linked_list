<h1>Syslog Kayıtlarını Bağlı Liste ile Tutma</h1>
<p>Bu proje, Linux işletim sisteminde sistem günlüklerini (syslog) bağlı liste (linked list) veri yapısı kullanarak tutan bir C uygulamasıdır. Syslog kayıtları, bağlı liste ile dinamik olarak yönetilir ve ekrana yazdırılır.</p>

<h2>Proje Amacı</h2>
<p>Bu projenin amacı, Linux sistemlerinde kullanılan syslog mekanizmasını açıklamak ve bu kayıtları bağlı liste veri yapısı ile tutarak dinamik bir şekilde yönetmektir. Syslog kayıtları; zaman damgası(timestamp), kaynak (facility), önem seviyesi (severity) ve mesaj içeriği gibi bilgileri içerir. Bu bilgiler, bağlı liste kullanılarak etkili bir şekilde saklanır ve işlenir.</p>

<h2>Özellikler</h2>
<ul>
  <li>Syslog kayıtları bağlı liste ile tutulur.</li>
  <li>Yeni kayıtlar dinamik olarak eklenir.</li>
  <li>Kayıtlar ekrana yazdırılır.</li>
  <li>Bellek yönetimi doğru bir şekilde uygulanır (malloc ve free).</li>
  <li>Kod; basit, anlaşılır ve modüler bir yapıdadır.</li>
</ul>

<h2>Kod Yapısı</h2>
<ol>
  <li><b>SyslogEntry Yapısı:
  <ul>
    <li>timestamp: Kaydın zaman damgası.</li>
    <li>facility: Kaynak (örnek: "auth", "kernel").</li>
    <li>severity: Önem seviyesi (örnek: "info", "error").</li>
    <li>message: Mesaj içeriği.</li>
    <li>next: Bir sonraki kaydı işaret eden pointer.</li>
  </ul>

  <li>Fonksiyonlar:</li>
  <ul>
  <li>addSyslogEntry: Yeni bir syslog kaydı ekler.</li>
  <li>printSyslogEntries: Bağlı listedeki tüm kayıtları ekrana yazdırır.</li>
  <li>freeSyslogEntries: Bağlı listeyi bellekten siler.</li>
 </ul>

<li>main Fonksiyonu:</li>
<ul>
<li>Örnek syslog kayıtları ekler.</li>
<li>Kayıtları ekrana yazdırır.</li>
<li>Belleği temizler.</li>
</ul>
    
</li>
</ol>


<h2>Örnek Kullanım</h2>
<p>Program çalıştırıldığında aşağıdaki çıktıyı üretir:</p>
<p>Syslog Kayitlari: <br>
Timestamp: 2025-02-14 12:10:00, Facility: mail, Severity: warning, Message: Mail server queue full <br>
Timestamp: 2025-02-14 12:05:00, Facility: kernel, Severity: error, Message: Disk I/O error <br>
Timestamp: 2025-02-14 12:00:00, Facility: auth, Severity: info, Message: User login successful</p>


<h2>Lisans</h2>
<p>Bu proje MIT Lisansı altında lisanslanmıştır. Daha fazla bilgi için LICENSE dosyasını inceleyebilirsiniz.</p>
