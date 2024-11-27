#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>

// Define the screen dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Define the pins for SPI communication
#define OLED_MOSI 23
#define OLED_CLK  18
#define OLED_DC   5
#define OLED_CS   15
#define OLED_RESET 4

// Create an instance of the display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);

void setup() {
  // Initialize Serial communication
  Serial.begin(115200);
  while (!Serial) {
    delay(10); // wait for serial port to connect
  }
  Serial.println("Serial communication started.");

  // Initialize the display
  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  Serial.println("OLED initialized successfully.");

  // Clear the buffer
  display.clearDisplay();
  Serial.println("Display cleared.");

  // Display a message on the screen
  display.setTextSize(1);           // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);          // Start at top-left corner
  display.println(F("Hello, world!"));

  // Update the display with the content
  display.display();
  Serial.println("Displayed message: Hello, world!");
}

void loop() {
  // Do nothing here...
}
