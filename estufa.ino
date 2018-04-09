#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define TEMP_SENSOR_INTERNAL_PIN 12
#define TEMP_SENSOR_INTERNAL_TYPE DHT11
#define TEMP_SENSOR_EXTERNAL_PIN 11
#define TEMP_SENSOR_EXTERNAL_TYPE DHT11

#define SOIL_SENSOR_1_PIN A0
#define SOIL_SENSOR_2_PIN A1
#define SOIL_SENSOR_3_PIN A2
#define SOIL_SENSOR_4_PIN A3

#define RELE_PIN 9

#define I2C_ADDR 0x27
#define BACKLIGHT_PIN 3

#define DS1307_ADDRESS 0x68

#define INTERVALO_LEITURA_TEMPERATURA 10000
#define INTERVALO_LEITURA_SOLO 10000
#define INTERVALO_LEITURA_ILUMINACAO 10000
#define INTERVALO_CALENDAR 10000

#define HORARIO_LIGAR_LUZES 4
#define HORARIO_DESLIGAR_LUZES 20

DHT dht_internal(TEMP_SENSOR_INTERNAL_PIN, TEMP_SENSOR_INTERNAL_TYPE);
DHT dht_external(TEMP_SENSOR_EXTERNAL_PIN, TEMP_SENSOR_EXTERNAL_TYPE);

LiquidCrystal_I2C  lcd(I2C_ADDR, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

long ultimaLeituraTemperatura = 0;
long ultimaLeituraSolo = 0;
long ultimaLeituraIluminacao = 0;
long ultimaAmostraCalendario = 0;
bool lampadaAcesa = true;
byte zero = 0x00;
int horaAtual = 0;
int minutoAtual = 0;

void setup() {
  Serial.begin(9600);

  Wire.begin();

  pinMode(RELE_PIN, OUTPUT);
  pinMode(SOIL_SENSOR_1_PIN, INPUT);
  pinMode(SOIL_SENSOR_2_PIN, INPUT);
  pinMode(SOIL_SENSOR_3_PIN, INPUT);
  pinMode(SOIL_SENSOR_4_PIN, INPUT);

  digitalWrite(RELE_PIN, HIGH);

  lcd.begin (16, 2);
  lcd.clear();
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home ();

  dht_internal.begin();
  dht_external.begin();

//  SelecionaDataeHora();
}

void loop() {
  temperatura();
  iluminacao();
  solo();
  datahora();
}
