int echo = 2;  // Pin connected to the Echo pin of the ultrasonic sensor
int trig = 3;  // Pin connected to the Trigger pin of the ultrasonic sensor
int in1 = 4;   // Pin connected to the motor control

void setup() {
  pinMode(echo, INPUT);  // Set echo pin as input
  pinMode(trig, OUTPUT); // Set trigger pin as output
  pinMode(in1, OUTPUT);  // Set motor control pin as output
  
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Send a short pulse to trigger the ultrasonic sensor
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);

  // Measure the time taken for the echo to return
  int duration = pulseIn(echo, HIGH);
  Serial.println(duration); // Print raw duration value

  // Calculate distance in cm
  int distance = duration * 0.034 / 2;

  Serial.print("distance : ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(200);

  // If an object is detected within 10 cm, activate the motor
  if (distance < 10) {
    Serial.println("detect");
    digitalWrite(in1, HIGH);  // Turn the motor on
    delay(600);                // Keep motor running for 600ms
    digitalWrite(in1, LOW);   // Turn the motor off
    delay(2000);               // Wait for 2 seconds before rechecking
  }
  else {
    digitalWrite(in1, LOW);  // Ensure motor remains off if no object is detected
  }
}
