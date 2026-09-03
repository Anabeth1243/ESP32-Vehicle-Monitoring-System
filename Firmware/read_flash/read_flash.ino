#include <LittleFS.h>

void setup() {

  Serial.begin(115200);

  // Initialize LittleFS
  if (!LittleFS.begin(true)) {
    Serial.println("LittleFS failed");
    while (1);
  }

  // Open the recorded CSV file
  File file = LittleFS.open("/temperature.csv", "r");

  if (!file) {
    Serial.println("File not found");
    return;
  }

  Serial.println("----- DATA START -----");

  // Read and print the CSV file
  while (file.available()) {
    Serial.write(file.read());
  }

  file.close();

  Serial.println();
  Serial.println("----- DATA END -----");
}

void loop() {
}
