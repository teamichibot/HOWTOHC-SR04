# 📏 HC-SR04 Ultrasonic Distance Sensor with Arduino

Proyek ini menunjukkan cara menggunakan sensor **HC-SR04** untuk mengukur jarak menggunakan **Arduino**, dengan hasil ditampilkan di **Serial Monitor**. Cocok untuk pemula yang ingin belajar interfacing sensor ultrasonik.

## 🚀 Fitur
- Mengukur jarak 2 cm hingga 400 cm
- Output dalam satuan **centimeter**
- Presisi menggunakan kecepatan suara (`0.0343 cm/µs`)

## 🧰 Hardware yang Dibutuhkan
- Arduino Uno / Nano / lainnya : https://s.shopee.co.id/gDgfg1Tfi
- Sensor Ultrasonic HC-SR04 : https://s.shopee.co.id/8fFyCPo9n2
- Kabel jumper : https://s.shopee.co.id/9ACEnPFVL1
- (Opsional) Breadboard : https://github.com/teamichibot/HOWTOHC-SR04

## 🔌 Koneksi HC-SR04 ke Arduino

| HC-SR04 Pin | Arduino Pin |
|-------------|-------------|
| VCC         | 5V          |
| GND         | GND         |
| Trig        | D9          |
| Echo        | D10         |

## 💻 Source Code

```cpp
#define trigPin 9
#define echoPin 10

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Bersihkan pin Trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Kirim sinyal trigger 10µs
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Baca durasi sinyal Echo
  duration = pulseIn(echoPin, HIGH);

  // Hitung jarak
  distance = (duration * 0.0343) / 2;

  // Tampilkan di Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}
