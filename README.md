<h1>Syslog Kayıtlarını Bağlı Liste ile Tutma</h1>
<p>Bu proje, Linux işletim sisteminde sistem günlüklerini (syslog) bağlı liste (linked list) veri yapısı kullanarak tutan bir C uygulamasıdır. Syslog kayıtları, bağlı liste ile dinamik olarak yönetilir ve ekrana yazdırılır.</p>
<ul>
  <li> <b>Syslog Mekanizması Nedir,Ne İçin Kullanılır? </b></li>
  Syslog,Linux ve diğer Unix benzeri işletim sistemlerinde sistem yöneticilerinin sistem olaylarını kaydetmek,izlemek ve analiz etmek için kullandığı protokoldür.Syslog,sistem olaylarını kaydeden ve yöneten bir günlük(log)sistemidir.Sistem yöneticileri, donanım, yazılım, güvenlik olayları veya kullanıcı etkileşimleri gibi tüm önemli olayları izlemek için syslog'u kullanır.Syslog, /var/log/ dizini altında farklı dosyalarda saklanır. Örneğin:<br>
  <ul>
    <li><b>syslog:</b> Genel sistem günlükleri</li>
    <li><b>auth.log:</b> Kimlik doğrulama ile ilgili olaylar</li>
    <li><b>kern.log:</b>Çekirdek ile ilgili olaylar</li>
  </ul>
  <b>Kullanım Alanları:</b>
  <ul>
    <li>Sistem hatalarının tespiti ve çözümü</li>
    <li>Güvenlik olaylarının izlenmesi</li>
    <li>Performans analizi ve optimizasyon</li>
    <li>Uygulama davranışlarının incelenmesi.</li>
  </ul>

  <li> <b>Bağlı Liste Veri Yapısı İle Syslog Kayıtlarının Tutulması </b></li>
  Syslog kayıtları,genellikle metin tabanlı ve sıralı bir şekilde tutulur.Bu kayıtları izlemek ve yönetmek için bağlı liste veri yapısı kullanılabilir.Bağlı liste,dinamik bellek yönetimi ve esnek veri ekleme/silme işlemleri için idealdir. <br>
  <p> <b>Bağlı Liste Veri Yapısı Nedir?:</b>Bağlı liste , dinamik olarak büyüyen veya küçülen bir veri yapısıdır.
Her bir düğüm (node), veriyi ve bir sonraki düğümün adresini içerir.Bağlı listeler, bellek kullanımında esneklik sağlar ve diziye göre daha dinamik bir yapı sunar.İki temel türü vardır:
    <ul>
      <li><b>Tek Yönlü Bağlı Liste :</b>Her düğüm sadece bir sonraki düğümü işaret eder.</li>
      <li><b>Çift Yönlü Bağlı Liste :</b>Her düğüm hem önceki hem de sonraki düğümü işaret eder.</li>
    </ul>
  <p><b>Kullanılan Bağlı Liste Türü:</b>tek yönlü bağlı liste(singly listed list) <br></p>
  <p><b>Tercih Sebebi:</b>Syslog kayıtları genellikle sadece baştan sona okunur ve genellikle sıralı bir şekilde eklendiğinden dolayı tek yönlü bağlı liste bu bu tür verileri tutmak için yeterlidir.Bellek kullanımı açısından verimli olduğundan dolayı hafızanın verimli kullanılmasını sağlar.</p>

  <li> <b>Bağlı Liste Yapısının Syslog Kayıtlarıyla İlişkisi </b></li>
  Syslog kayıtları,genellikle zaman damgası (timestamp),mesaj kaynağı (facility),önem seviyesi (severity) ve mesaj içeriği gibi bilgiler içerir.Bu kayıtları bağlı liste ile tutarken her bir düğüm (node) bir syslog kaydını temsil eder.Düğümler,bir sonraki kaydı işaret eden işaretçi yani pointer içerir. <br>
  <p><b>Tek Yönlü Bağlı Liste Seçilmesinin Sebebi:</p>
    <ul>
      <li><b>Baitlik:</b>Daha az bellek kullanımı ve daha az karmaşıklık.</li>
      <li>Syslog kayıtları genellikle sadece baştan sona okunur, geriye dönüş ihtiyacı nadiren ortaya çıkar.</li>
    </ul>
  <p> <b>Avantajları:</b>
    <ul>
      <li>Yeni kayıtların eklenmesi kolaydır.</li>
      <li>Bellek dinamik olarak yönetilir.</li>
      <li>Kayıtlar arasında hızlı geçiş yapılabilir.</li>
    </ul>
  </p>
    
</ul>

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
  <li> <b>SyslogEntry Yapısı:</b> </li>
  <ul>
    <li>timestamp: Kaydın zaman damgası.</li>
    <li>facility: Kaynak (örnek: "auth", "kernel").</li>
    <li>severity: Önem seviyesi (örnek: "info", "error").</li>
    <li>message: Mesaj içeriği.</li>
    <li>next: Bir sonraki kaydı işaret eden pointer.</li>
  </ul>

  <li> <b>Fonksiyonlar:</b></li>
  <ul>
  <li>addSyslogEntry: Yeni bir syslog kaydı ekler.</li>
  <li>printSyslogEntries: Bağlı listedeki tüm kayıtları ekrana yazdırır.</li>
  <li>freeSyslogEntries: Bağlı listeyi bellekten siler.</li>
 </ul>

 <li> <b>main Fonksiyonu:</b></li>
 <ul>
 <li>Örnek syslog kayıtları ekler.</li>
 <li>Kayıtları ekrana yazdırır.</li>
 <li>Belleği temizler.</li>
 </ul>
    
</li>
</ol>


<h2>Örnek Kullanım</h2>
<p>Program çalıştırıldığında aşağıdaki çıktıyı üretir:</p>
<p><b>Syslog Kayitlari: <br>
Timestamp: 2025-02-14 12:10:00, Facility: mail, Severity: warning, Message: Mail server queue full <br>
Timestamp: 2025-02-14 12:05:00, Facility: kernel, Severity: error, Message: Disk I/O error <br>
Timestamp: 2025-02-14 12:00:00, Facility: auth, Severity: info, Message: User login successful</b></p>


<h2>Lisans</h2>
<p>Bu proje MIT Lisansı altında lisanslanmıştır. Daha fazla bilgi için <b>LICENSE</b> dosyasını inceleyebilirsiniz.</p>
