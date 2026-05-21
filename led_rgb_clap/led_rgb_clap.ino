
const int RED_PIN   = 2;
const int GREEN_PIN = 6;
const int BLUE_PIN  = 5;

// Цифровой пин для датчика звука
const int SOUND_DO_PIN = 7;

// Массив цветов
int colors[6][3] = {{255,0,0}, {0,255,0}, {0,0,255}, {255,255,0}, {255,0,255}, {0,255,255}};
int currentColor = 0;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(SOUND_DO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(SOUND_DO_PIN) == LOW) {
    currentColor = (currentColor + 1) % 6;
    analogWrite(RED_PIN, colors[currentColor][0]);
    analogWrite(GREEN_PIN, colors[currentColor][1]);
    analogWrite(BLUE_PIN, colors[currentColor][2]);
    
    Serial.println("frfr");
    delay(50);
  }
}