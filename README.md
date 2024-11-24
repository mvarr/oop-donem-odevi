# oop-donem-odevi

24-11-2024 oop dersi dönem ödevi kaynak kodları

## Proje Hakkında

Bu repo, OOP (Nesne Yönelimli Programlama) dersinde iki kişilik ekip olarak hazırladığımız dönem ödevini içermektedir.

## Ekip Üyeleri

- <a href="https://github.com/Dartsemih"> <img src="https://avatars.githubusercontent.com/u/165713244?v=4" alt="Avatar" height=50> </a> **Semih Doğan (425470)**
</a>
- **Mehmet Melih Var (434388)** <a href="https://github.com/mvarr">
  <img src="https://avatars.githubusercontent.com/u/147834815?v=4" alt="Avatar" height=50>
</a>

## İçerik

Bu projede aşağıdaki OOP kavramlarını uygulamaya çalıştık:

- **Temel Dizi İşlemleri**
- **Dosya ve Veri Yönetimi (Okuma/Yazma, Giriş-Çıkış İşlemleri)**
- **Veri Yapılarının Kullanımı**
- **Matematiksel İşlemler (Ortalama Hesaplama, Geçme Notu, Koşullu Kontrol ve Kıyaslama)**
- **Listeleme ve Filtreleme (Tüm Öğrencilerin Listelenmesi, Geçen ve Kalan Öğrenciler)**

# Proje Yapısı

## Gereksinimler

- C++ derleyici (bu proje yazılırken GCC tercih edilmiştir)
- CSV dosyası okuma desteği
- Dosya işleme kütüphaneleri

### Student Sınıfı

Student sınıfı aşağıdaki özelliklere sahiptir:

#### Veri Üyeleri

- `string* ad` - Öğrenci adları
- `string* ogrNo` - Öğrenci numaraları
- `float* araSinav` - Ara sınav notları
- `float* ikinciSinav` - İkinci sınav notları
- `float* odev` - Ödev notları
- `float* final` - Final notları
- `int* devamSayisi` - Devamsızlık sayısı (ödev dosyasında işlevi belirtilmediği için bu değişken kodun içinde aktif olarak kullanılmamıştır)
- `int size` - Toplam öğrenci sayısı

#### Metodlar

1. **Constructor ve Destructor**
   - Constructor: Değişkenlere ilk değeri atar ve dinamik dizileri oluşturur.
   - Destructor: Dinamik dizileri bellekten temizler.

2. **readFromCSV()**
   - CSV dosyasından verileri okur.
   - Verileri ilgili dizilere kaydeder.

3. **average()**
   - Her öğrenci için ortalama hesaplar.
   - Ağırlıklar:
     - Ara sınav: %20
     - İkinci sınav: %20
     - Ödev: %20
     - Final: %40

4. **print()**
   - Parametre girilmedi (NULL): Tüm listeyi yazdırır.
   - print(0): Kalan öğrencileri listeler.
   - print(1): Geçen öğrencileri listeler.
   - print("sonuc.txt"): Sonuçları dosyaya yazdırır.

## Kurulum ve Çalıştırma

1. Projeyi bilgisayarınıza klonlayın.
2. Proejyi derleyin veya ana dizindeki önceden derlenmiş programı başlatın:
   - `gcc main.cpp -o main`
   - `./main`
3. csv dosyasının doğru konumda bulunduğundan emin olun. Varsayılan csv okuma ismi "girdi.csv", ancak program içinde ismi değiştirilebilir.

## Notlar

- Geçme notu 50'dir. Ortalaması bu notun altındaki öğrenciler kalmış sayılır.
- CSV dosyasındaki alanlar virgülle ayrılmıştır
- Devam sayısı kısmı boş olan öğrencilerin devamsızlık sayısı varsayılan olarak 0 sayılır.

## Katkıda Bulunma

Önerileriniz ve geri bildirimleriniz için Issues bölümünü kullanabilirsiniz.

## İletişim

Proje ile ilgili sorularınız için bizimle iletişime geçebilirsiniz.
