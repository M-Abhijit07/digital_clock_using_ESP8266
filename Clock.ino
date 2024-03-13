#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
unsigned long startingTime = 00 * 3600000 + 00 * 60000;

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  display.clearDisplay();
  
 // Get the current time in milliseconds
  unsigned long currentTime = millis() + startingTime; // Add the starting time

  // Convert milliseconds to hours, minutes, and seconds
  int hours = currentTime / 3600000;
  int minutes = (currentTime % 3600000) / 60000;
  int seconds = (currentTime % 60000) / 1000;

  // Display hours and minutes with text size 3
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5, 10); // Adjust the position as needed
  if (hours < 10) {
    display.print("0"); // Add leading zero for single-digit minutes
  }
  display.print(hours);
  display.print(":");
  if (minutes < 10) {
    display.print("0"); // Add leading zero for single-digit minutes
  }
  display.print(minutes);

  // Display seconds with text size 2
  display.setTextSize(2);
  
  display.setCursor(100, 15); // Adjust the position as needed
  if (seconds < 10) {
    display.print("0"); // Add leading zero for single-digit seconds
  }
  display.print(seconds);

  display.display();
}
