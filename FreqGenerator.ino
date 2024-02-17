const int outPin = 13;
int freq;
int d;

int freqToDelay(int freq) {
  return 1000 / (2 * freq);
}

void setup() {
  pinMode(outPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("\nSet freq (1...999), current freq = 1 Hz");
  freq = 1;
  d = freqToDelay(freq);
}

void loop() {
  if(Serial.available()) {
    int len = 3;
    char buf[len];
    for(int i = 0; i < len; i++) {
      buf[i] = "\0";
    }
    Serial.readBytesUntil(10, buf, len);
    freq = atoi(buf);
    if(freq > 0 && freq < 1000) {
      Serial.print("Set to ");
      Serial.print(freq);
      Serial.println(" Hz");
      d = freqToDelay(freq);
    }
  }
  digitalWrite(outPin, LOW);
  delay(d);
  digitalWrite(outPin, HIGH);
  delay(d);
}
