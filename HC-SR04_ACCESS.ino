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
