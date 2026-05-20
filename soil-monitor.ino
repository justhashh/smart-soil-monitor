int temp = A1;
int soil_moisture = A0;
int led = 7;

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

    Serial.print("Soil Moisture Value: ");
    Serial.println(soilm);

    if (soilm <= 512)
    {
        Serial.println("PERFECT WATERING CONDITION");
    }

    else if (soilm > 512 && soilm <= 800)
    {
        Serial.println("MAYBE WATER IS TOO MUCH");
    }

    else
    {
        Serial.println("WATER IS LESS IG");
    }

    delay(1000);
}
