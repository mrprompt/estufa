void iluminacao()
{
  if (ultimaLeituraIluminacao > 0 && (millis() - ultimaLeituraIluminacao < INTERVALO_LEITURA_ILUMINACAO)) {
    return;
  }

  Serial.print("- Controlando luz: ");

  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Estado da Luz");

  if (horaAtual >= HORARIO_LIGAR_LUZES && horaAtual <= HORARIO_DESLIGAR_LUZES) {
    lampadaAcesa = true;
  } else {
    lampadaAcesa = false;
  }
  
  if (lampadaAcesa == true) {
    ligaLuz();

    lcd.setCursor(5, 1);
    lcd.print("LIGADA");
  } else {
    desligaLuz();

    lcd.setCursor(3, 1);
    lcd.print("DESLIGADA");
  }

  ultimaLeituraIluminacao = millis();

  delay(INTERVALO_DISPLAY);
}

void ligaLuz()
{
  digitalWrite(RELE_PIN, HIGH);

  Serial.println("ligada");
}

void desligaLuz()
{
  digitalWrite(RELE_PIN, LOW);

  Serial.println("desligada");
}

