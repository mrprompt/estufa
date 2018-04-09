void datahora()
{
  if (ultimaAmostraCalendario > 0 && (millis() - ultimaAmostraCalendario < INTERVALO_CALENDAR)) {
    return;
  }

  lcd.clear();
  
  // Le os valores (data e hora) do modulo DS1307
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_ADDRESS, 7);
  
  int segundos = ConverteparaDecimal(Wire.read());
  int minutos = ConverteparaDecimal(Wire.read());
  int horas = ConverteparaDecimal(Wire.read() & 0b111111);
  int diadasemana = ConverteparaDecimal(Wire.read());
  int diadomes = ConverteparaDecimal(Wire.read());
  int mes = ConverteparaDecimal(Wire.read());
  int ano = ConverteparaDecimal(Wire.read());

  horaAtual = horas;
  minutoAtual = minutos;

  // Mostra os dados no display
  lcd.setCursor(0, 0);
  lcd.print("     ");
  
  // Acrescenta o 0 (zero) se a hora for menor do que 10
  if (horas < 10)
    lcd.print("0");
  
  lcd.print(horas);
  lcd.print(":");
  
  // Acrescenta o 0 (zero) se minutos for menor do que 10
  if (minutos < 10)
    lcd.print("0");
  
  lcd.print(minutos);
  lcd.setCursor(2, 1);
  
  // Mostra o dia da semana
  switch (diadasemana)
  {
    case 0: lcd.print("Dom");
      break;
    case 1: lcd.print("Seg");
      break;
    case 2: lcd.print("Ter");
      break;
    case 3: lcd.print("Quar");
      break;
    case 4: lcd.print("Qui");
      break;
    case 5: lcd.print("Sex");
      break;
    case 6: lcd.print("Sab");
  }
  
  lcd.setCursor(6, 1);
  
  // Acrescenta o 0 (zero) se dia do mes for menor do que 10
  if (diadomes < 10)
    lcd.print("0");
  
  lcd.print(diadomes);
  lcd.print("/");
  
  // Acrescenta o 0 (zero) se mes for menor do que 10
  if (mes < 10)
    lcd.print("0");
  
  lcd.print(mes);
  lcd.print("/");
  lcd.print(ano);

  ultimaAmostraCalendario = millis();

  delay(3000);
}


//Seta a data e a hora do DS1307
void SelecionaDataeHora() 
{
  byte segundos = 00; //Valores de 0 a 59
  byte minutos = 48; //Valores de 0 a 59
  byte horas = 0; //Valores de 0 a 23
  byte diadasemana = 1; //Valores de 0 a 6 - 0=Domingo, 1 = Segunda, etc.
  byte diadomes = 9; //Valores de 1 a 31
  byte mes = 4; //Valores de 1 a 12
  byte ano = 18; //Valores de 0 a 99
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero); //Stop no CI para que o mesmo possa receber os dados

  //As linhas abaixo escrevem no CI os valores de
  //data e hora que foram colocados nas variaveis acima
  Wire.write(ConverteParaBCD(segundos));
  Wire.write(ConverteParaBCD(minutos));
  Wire.write(ConverteParaBCD(horas));
  Wire.write(ConverteParaBCD(diadasemana));
  Wire.write(ConverteParaBCD(diadomes));
  Wire.write(ConverteParaBCD(mes));
  Wire.write(ConverteParaBCD(ano));
  Wire.write(zero);
  Wire.endTransmission();
}

byte ConverteParaBCD(byte val)
{
  //Converte o número de decimal para BCD
  return ( (val / 10 * 16) + (val % 10) );
}

byte ConverteparaDecimal(byte val)
{
  //Converte de BCD para decimal
  return ( (val / 16 * 10) + (val % 16) );
}

