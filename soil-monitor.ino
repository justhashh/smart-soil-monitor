int temp = A1;
int soil_moisture = A0;
int led = 7;

float previousTemp = 0;
float threshold = 5; // sudden temp rise threshold

void setup()
{
    Serial.begin(9600);

    pinMode(led, OUTPUT);

    digitalWrite(led, HIGH);
    delay(500);

    digitalWrite(led, LOW);
    delay(500);
}

void loop()
{
    int tempValue = analogRead(temp);
    int soilm = analogRead(soil_moisture);

    // Convert analog value to temperature
    float currentTemp =
        tempValue * (5.0 / 1023.0) * 100;

    // Print readings
    Serial.print("Temperature: ");
    Serial.print(currentTemp);
    Serial.println(" C");

    Serial.print("Soil Moisture Value: ");
    Serial.println(soilm);

    // Soil moisture conditions
    if (soilm <= 512)
    {
        Serial.println("PERFECT WATERING CONDITION");
    }

    else if (soilm > 512 && soilm <= 800)
    {
        Serial.println("SOIL MOISTURE IS QUITE HIGH");
    }

    else
    {
        Serial.println("SOIL MOISTURE IS QUITE LOW");
    }

    // Dry soil alert
    if (soilm > 800)
    {
        digitalWrite(led, HIGH);

        Serial.println(
            "SOIL IS DRY - WATER NEEDED");
    }

    else
    {
        digitalWrite(led, LOW);
    }

    // Rapid temperature rise detection
    if ((currentTemp - previousTemp)
         > threshold)
    {
        Serial.println(
          "⚠️ RAPID TEMP INCREASE!");

        Serial.println(
          "⚠️ POSSIBILITY OF PEST ATTACK!");
    }

    // Store temp for next loop
    previousTemp = currentTemp;

    Serial.println("-------------------");

    delay(1000);
}
