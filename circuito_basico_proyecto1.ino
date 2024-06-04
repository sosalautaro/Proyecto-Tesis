// C++ code
//
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Dirección I2C de la pantalla y dimensiones (16 columnas, 2 filas)
int SensorPin = A0;  // Pin del sensor de humedad
int BombaPin = 8;  // Pin de control de la bomba

void setup() {
  pinMode(BombaPin, OUTPUT);  // Configurar el pin de la bomba como salida
  lcd.init();  // Inicializar la pantalla LCD
  lcd.backlight();  // Encender la retroiluminación
  lcd.setCursor(0, 0);  // Posicionar cursor en la primera línea
  lcd.print("Humedad");  // Mostrar título
  Serial.begin(9600);  // Iniciar puerto serie
}

void loop() {
  int humedad = analogRead(SensorPin);  // Leer el valor de humedad
  Serial.println(humedad);  // Mostrar lectura de humedad en el puerto serie

  if (humedad >= 870) {
    digitalWrite(BombaPin, LOW);  // Desactivar la bomba si la humedad es alta
  } else {
    digitalWrite(BombaPin, HIGH);  // Activar la bomba si la humedad es baja
  }

  int suelo = analogRead(SensorPin);  // Leer el valor de humedad nuevamente para el suelo
  suelo = constrain(suelo, 0, 876);  // Restringir a un rango de medición
  int porcentaje = map(suelo, 0, 876, 0, 100);  // Mapear a valores porcentuales

  lcd.setCursor(0, 1);  // Posicionar cursor en la segunda línea
  lcd.print(porcentaje);  // Mostrar valor porcentual de humedad
  lcd.print("%");  // Mostrar símbolo de porcentaje
  delay(1000);  // Esperar 1 segundo
  lcd.setCursor(0, 1);  // Posicionar cursor en la segunda línea
  lcd.print("      ");  // Limpiar línea para actualizar
  delay(1);
}