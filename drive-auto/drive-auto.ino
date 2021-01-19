void setup()
{
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  /*
   * Full course
   * |-----|     |-----|
   *       |     |
   *       |     |
   *       |-----|
   */
  
  /*
   * Current position
   * X-----|     |-----|
   *       |     |
   *       |     |
   *       |-----|
   */
  // Go forward for 1.5 seconds
  // Right motors
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  analogWrite(5, 128);

  // Right motors
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);
  analogWrite(6, 128);

  delay(1500);

  
  /*
   * Current position
   * |-----X     |-----|
   *       |     |
   *       |     |
   *       |-----|
   */
  // Brake for half a second
  // Right motors
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  analogWrite(5, 128);

  // Right motors
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  analogWrite(6, 128);

  delay(500);

  // Turn right
  // Right motors
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  analogWrite(5, 128);

  // Right motors
  digitalWrite(9, HIGH);
  digitalWrite(11, LOW);
  analogWrite(6, 128);
  
  delay(750);
  
  // Brake for half a second
  // Right motors
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  analogWrite(5, 128);

  // Right motors
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  analogWrite(6, 128);
  
  delay(500);
  
  // Go forward for 1.5 seconds
  // Right motors
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  analogWrite(5, 128);

  // Right motors
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);
  analogWrite(6, 128);

  delay(1500);
  
  // Brake for half a second
  // Right motors
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  analogWrite(5, 128);

  // Right motors
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  analogWrite(6, 128);
  delay(500);
  
  /*
   * Current position
   * |-----|     |-----|
   *       |     |
   *       |     |
   *       X-----|
   */

  // Turn left
  // Right motors
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  analogWrite(5, 128);

  // Right motors
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);
  analogWrite(6, 128);
  
  delay(750);
  
  // Brake for half a second
  // Right motors
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  analogWrite(5, 128);

  // Right motors
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  analogWrite(6, 128);
  delay(500);
  
  // Go forward for 1.5 seconds
  // Right motors
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  analogWrite(5, 128);

  // Right motors
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);
  analogWrite(6, 128);

  delay(1000);
  
  /*
   * Current position
   * |-----|     |-----|
   *       |     |
   *       |     |
   *       |-----X
   */
  
  // Brake for half a second
  // Right motors
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  analogWrite(5, 128);

  // Right motors
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  analogWrite(6, 128);
  delay(500);

  // Turn left
  // Right motors
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  analogWrite(5, 128);

  // Right motors
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);
  analogWrite(6, 128);
  
  delay(750);
  
  // Brake for half a second
  // Right motors
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  analogWrite(5, 128);

  // Right motors
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  analogWrite(6, 128);
  delay(500);
  
  // Go forward for 1.5 seconds
  // Right motors
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  analogWrite(5, 128);

  // Right motors
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);
  analogWrite(6, 128);

  delay(1000);
  
  // Brake for half a second
  // Right motors
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  analogWrite(5, 128);

  // Right motors
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  analogWrite(6, 128);
  delay(500);
  
  /*
   * Current position
   * |-----|     X-----|
   *       |     |
   *       |     |
   *       |-----|
   */

  // Turn right
  // Right motors
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  analogWrite(5, 128);

  // Right motors
  digitalWrite(9, HIGH);
  digitalWrite(11, LOW);
  analogWrite(6, 128);
  
  delay(750);
  
  // Brake for half a second
  // Right motors
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  analogWrite(5, 128);

  // Right motors
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  analogWrite(6, 128);
  delay(500);
  
  // Go forward for 1.5 seconds
  // Right motors
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  analogWrite(5, 128);

  // Right motors
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);
  analogWrite(6, 128);

  delay(1500);
  
  // Brake
  // Right motors
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  analogWrite(5, 128);

  // Right motors
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  analogWrite(6, 128);
  
  /*
   * Current position
   * |-----|     |-----X
   *       |     |
   *       |     |
   *       |-----|
   */

  // Do nothing forever
  while(true) {}
}
