#include <Servo.h>

// Create servo object
Servo servo;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  // Configure servo
  // Servos respond to the length of signal pulses in microseconds
  // The first number is the pin the servo is connected to
  // The second number is the pulse width in microseconds to signal that
  // the servo should be at 0-degrees
  // The third number is the pulse width in microseconds to signal that
  // the servo should be at 180-degrees
  servo.attach(3, 600, 2600);

  // Make sure servo starts out pointing straight ahead (90 degrees)
  servo.write(90);

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
  // Then, turn sonar left and right and measure distances
  // to figure out which way to turn
  if (distanceCm < 15) {
    // Stop
    /* Left motors */
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    
    /* Right motors */
    digitalWrite(9, HIGH);
    digitalWrite(11, HIGH);

    // Turn servo to the right (0-degrees)
    servo.write(0);

    // Wait for the servo to get into position
    delay(1000);

    // Get distance to the obstacle at the right
    // This distance measuring code is the same as at the start
    // I just removed the comments
    digitalWrite(A5, LOW);
    delayMicroseconds(2);
    digitalWrite(A5, HIGH);
    delayMicroseconds(20);
    digitalWrite(A5, LOW);
    pulseLength = pulseIn(A4, HIGH); // This is reusing the pulseLength variable
    int distanceCmRight = pulseLength / 58;

    // Turn servo to the left (180-degrees)
    servo.write(180);

    // Wait for the servo to get into position
    delay(1000);
    
    // Get distance to the obstacle at the left
    // This distance measuring code is the same as at the start
    // I just removed the comments
    digitalWrite(A5, LOW);
    delayMicroseconds(2);
    digitalWrite(A5, HIGH);
    delayMicroseconds(20);
    digitalWrite(A5, LOW);
    pulseLength = pulseIn(A4, HIGH); // This is reusing the pulseLength variable
    int distanceCmLeft = pulseLength / 58;

    // Return servo to forward (90-degrees)
    servo.write(90);

    // Wait for the servo to get into position
    delay(1000);

    // Pick the direction with the biggest distance to the next obstacle
    // and turn in that direction
    // If both directions have close obstacles, turn around
    if (distanceCmRight > 15 && distanceCmRight > distanceCmLeft) {
      // The distance to the right obstacle is more than 15cm,
      // and the right obstacle is farther than the left obstacle
      // We want to turn right
      
      /* Left motors */
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      analogWrite(5, 128);
      
      /* Right motors */
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      analogWrite(6, 128);
      
      delay(750);
      
      // Stop
      /* Left motors */
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      
      /* Right motors */
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);

      // Wait a little for the robot to stop moving
      delay(1000);
    } else if (distanceCmLeft > 15 && distanceCmLeft > distanceCmRight) {
      // The distance to the left obstacle is more than 15cm,
      // and the left obstacle is farther than the right obstacle
      // We want to turn left
      
      /* Left motors */
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      analogWrite(5, 128);
      
      /* Right motors */
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      analogWrite(6, 128);
      
      delay(750);
      
      // Stop
      /* Left motors */
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      
      /* Right motors */
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);

      // Wait a little for the robot to stop moving
      delay(1000);
    } else {
      // Left, forward, and right are all bad. Turn around
      
      // Left motors
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      analogWrite(5, 128);
    
      // Right motors
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      analogWrite(6, 128);
      
      delay(1500);
      
      // Stop
      /* Left motors */
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      
      /* Right motors */
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);

      // Wait a little for the robot to stop moving
      delay(1000);
    }

    // Now that we figured out a new direction, keep driving forward
    /* Left motors */
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    analogWrite(5, 128);
    
    /* Right motors */
    digitalWrite(9, LOW);
    digitalWrite(11, HIGH);
    analogWrite(6, 128);
    
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
