#include <LittleFS.h>
#include <DHT.h>

#define DHTPIN 5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

unsigned long startTime;

void setup() {
  Serial.begin(115200);

  // Initialize LittleFS
  if (!LittleFS.begin(true)) {
    Serial.println("LittleFS failed");
    while (1);
  }

  // Initialize DHT11
  dht.begin();

  // Create CSV file
  File file = LittleFS.open("/temperature.csv", "w");

  if (file) {
    file.println("Time(s),Temperature(C),Humidity(%)");
    file.close();
    Serial.println("CSV created!");
  } else {
    Serial.println("Failed to create file!");
  }

  startTime = millis();
}

void loop() {

  // Read temperature and humidity
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check sensor reading
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT11 read failed!");
    delay(2000);
    return;
  }

  // Calculate elapsed time
  unsigned long t = (millis() - startTime) / 1000;

  // Append data to CSV
  File file = LittleFS.open("/temperature.csv", "a");

  if (file) {
    file.print(t);
    file.print(",");
    file.print(temperature);
    file.print(",");
    file.println(humidity);
    file.close();
  }

  // Print data to Serial Monitor
  Serial.print("Time: ");
  Serial.print(t);
  Serial.print(" s   Temp: ");
  Serial.print(temperature);
  Serial.print(" C   Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000);
}
