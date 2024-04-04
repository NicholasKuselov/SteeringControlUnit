// Encoder pins
int pinA = 2; 
int pinB = 3;

// Ініціалізуйте змінні
int lastStateA = 0;
int currentStateA = 0;
int direction = 0;  // 0 - без обертання, 1 - за годинниковою стрілкою, -1 - проти годинникової стрілки

unsigned long previousMillis = 0;
const long interval = 100; // MilSec

void setup() {
    pinMode(pinA, INPUT_PULLUP);
    pinMode(pinB, INPUT_PULLUP);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    currentStateA = digitalRead(pinA);


    if (currentStateA != lastStateA) {
       unsigned long currentMillis = millis();
       if (currentMillis - previousMillis <= interval)
       {
        lastStateA = currentStateA;
          return;
       }
        
        int stateB = digitalRead(pinB);

        // Check direction
        if (stateB != currentStateA) {
            direction = 1;  // Down
        } else {
            direction = -1;  // Up
        }


        if (direction != 0) {
            if (direction == 1) {
                Serial.println("Вниз");
                digitalWrite(7, HIGH);
                delay(50);
                digitalWrite(7, LOW);
            } else {
                Serial.println("Уверх");
                digitalWrite(6, HIGH);
                delay(50);
                digitalWrite(6, LOW);
                
            }
        }
        previousMillis = currentMillis;
        
        lastStateA = currentStateA;
    }

    //delay(10);
}

