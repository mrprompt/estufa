void iluminacao()
{
  if (ultimaLeituraIluminacao > 0 && (millis() - ultimaLeituraIluminacao < INTERVALO_LEITURA_ILUMINACAO)) {
    return;
  }
  
  Serial.print("- Controlando luz: ");

  if (horaAtual >= HORARIO_LIGAR_LUZES && horaAtual <= HORARIO_DESLIGAR_LUZES) {
    lampadaAcesa = true;
  } else {
    lampadaAcesa = false;
  }
  
  if (lampadaAcesa == true) {
    ligaLuz();
    
    Serial.println("ligada");
  } else {
    desligaLuz();

    Serial.println("desligada");
  }

  ultimaLeituraIluminacao = millis();
}

void ligaLuz()
{
  digitalWrite(RELE_PIN, HIGH);
}

void desligaLuz()
{
  digitalWrite(RELE_PIN, LOW);
}

