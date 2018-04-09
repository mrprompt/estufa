void solo()
{
  if (ultimaLeituraSolo > 0 && (millis() - ultimaLeituraSolo < INTERVALO_LEITURA_SOLO)) {
    return;
  }

  Serial.println("- Controlando umidade de solo");
  
  lcd.clear();
  lcd.setCursor(0, 0);

  lcd.print("V1: ");
  lcd.print(map(analogRead(SOIL_SENSOR_1_PIN), 1023, 0, 0, 100));
  lcd.print("% ");
  lcd.print(" V2: ");
  lcd.print(map(analogRead(SOIL_SENSOR_2_PIN), 1023, 0, 0, 100));
  lcd.print("% ");

  lcd.setCursor(0, 1);
  lcd.print("V3: ");
  lcd.print(map(analogRead(SOIL_SENSOR_3_PIN), 1023, 0, 0, 100));
  lcd.print("% ");
  lcd.print(" V4: ");
  lcd.print(map(analogRead(SOIL_SENSOR_4_PIN), 1023, 0, 0, 100));
  lcd.print("%");

  ultimaLeituraSolo = millis();

  delay(3000);
}

