//Array simbolo grau
byte grau[8] = { B00001100,
                 B00010010,
                 B00010010,
                 B00001100,
                 B00000000,
                 B00000000,
                 B00000000,
                 B00000000,
               };

void temperatura()
{
  if (ultimaLeituraTemperatura > 0 && (millis() - ultimaLeituraTemperatura < INTERVALO_LEITURA_TEMPERATURA)) {
    return;
  }

  Serial.println("- Controlando temperatura");
  
  lcd.createChar(0, grau);
  lcd.clear();
  
  sensorInterno();
  sensorExterno();

  ultimaLeituraTemperatura = millis();

  delay(3000);
}

void sensorInterno()
{  
  float UmidadeInterna;
  float TemperaturaInterna;
    
  UmidadeInterna = dht_internal.readHumidity();
  TemperaturaInterna = dht_internal.readTemperature();

  if (isnan(UmidadeInterna) || isnan(TemperaturaInterna)) {
    UmidadeInterna = 0;
    TemperaturaInterna = 0;
  }

  lcd.setCursor(0, 0);
  lcd.print("INT: ");
  lcd.print((int) TemperaturaInterna);
  lcd.write((byte)0);  
  lcd.print(" / "); 
  lcd.print((int) UmidadeInterna); 
  lcd.print("%"); 
}

void sensorExterno()
{
  float UmidadeExterna;
  float TemperaturaExterna;
    
  UmidadeExterna = dht_external.readHumidity();
  TemperaturaExterna = dht_external.readTemperature();

  if (isnan(UmidadeExterna) || isnan(TemperaturaExterna)) {
    UmidadeExterna = 0;
    TemperaturaExterna = 0;
  }

  lcd.setCursor(0, 1);
  lcd.print("EXT: ");
  lcd.print((int) TemperaturaExterna);
  lcd.write((byte)0); 
  lcd.print(" / "); 
  lcd.print((int) UmidadeExterna); 
  lcd.print("%"); 
}

