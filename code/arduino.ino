/*
The code below is designed for a Monitoring System and may require adjustments 
for different sensors or applications. Ensure compatibility before deploying with new sensors.

!THIS CODE SHOULD BE CONTINUOUSLY RUNNING ON THE ARDUINO BOARD!
*/


// Declaration of global variables to store sensor readings
float temp = 0;
float light = 0;
float carb = 0;
float mos = 0;

void setup() {
  // Initialize serial communication at a baud rate of 9600
  Serial.begin(9600);
}

void loop() {
  // Reading five times and making an average from those readings
  for (int i = 0; i < 5; i++) {
    // Read sensor values from analog pins and accumulate them for averaging
    temp += analogRead(0);
    light += analogRead(1); // Range from 7 to 10
    carb += analogRead(2);
    mos += analogRead(5);
  }
  // Calculate average values for each sensor
  temp = temp / 5;
  light = light / 5;
  carb = carb / 5;
  mos = mos / 5;

  // Convert sensor readings to desired units and print results to the serial monitor
  Serial.print(temp * (5.0 / 10.24)); // Convert temperature using a specific formula
  Serial.print(","); // Delimiter for separating values
  Serial.print(light); // Print light sensor reading
  Serial.print(","); // Delimiter for separating values
  Serial.print(carb); // Print carbon sensor reading
  Serial.print(","); // Delimiter for separating values
  Serial.println(mos); // Print moisture sensor reading
  delay(10000); // Delay 10 seconds before the next iteration
}
