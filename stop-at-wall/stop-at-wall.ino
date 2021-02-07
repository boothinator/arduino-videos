void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  // Set up left motor pins as outputs
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(5, OUTPUT);

  // Set up right motor pins as outputs
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(6, OUTPUT);

  // Set up sonar echo pin A4 as input
  pinMode(A4, INPUT);

  // Set up sonar trigger pin A5 as output
  pinMode(A5, OUTPUT);
}

void loop() {
  /*
   * Measure distance to obstacle using sonar
   */

  // Make sure sonar trigger connected to pin A5 is low
  digitalWrite(A5, LOW);
  delayMicroseconds(2);

  // Trigger sonar pulse by setting trigger pin to high for a little bit
  // 20 microseconds is enough
  digitalWrite(A5, HIGH);
  delayMicroseconds(20);

  // Stop the sonar pulse by going low again
  digitalWrite(A5, LOW);

  // The echo signal is connected to pin A4. It's normally low, but
  // it will go high when it gets the signal. The length of time it is
  // high corresponds to the length of time that the sonar puls took to return.
  // This number is in microseconds.
  unsigned long pulseLength = pulseIn(A4, HIGH);

  // Divide pulse length by 58 to get distance in centimeters
  // This number is based on the speed of sound
  int distanceCm = pulseLength / 58;

  // If distance is less than 15cm then stop
  if (distanceCm < 15) {
    /* Left motors */
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    
    /* Right motors */
    digitalWrite(9, HIGH);
    digitalWrite(11, HIGH);
  } else {
    // If distance is more than 15cm, then drive forward
    /* Left motors */
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    analogWrite(5, 128);
    
    /* Right motors */
    digitalWrite(9, LOW);
    digitalWrite(11, HIGH);
    analogWrite(6, 128);
  }

  // Delay for a bit, then continue
  delay(50);
}
