// Definición de pines
#define PINBUZZER 10
#define PINBOTON 2
#define PINLED 13

// Función para esperar el botón
void WaitBoton() {
  // Entra en un bucle infinito de espera hasta que se presione el botón
  while (!digitalRead(PINBOTON)); // No hace nada dentro del bucle, solo espera
  beep(); // Se llama a la función beep() cuando se presiona el botón
}

// Función para emitir un sonido
void beep() {
  tone(PINBUZZER, 2000, 100); // Emite un tono de 2000 Hz durante 100 ms
  delay(200); // Espera 200 ms antes de continuar
}

void setup() {
  // Configuración de pines
  pinMode(PINBOTON, INPUT); // El pin del botón se configura como entrada
  pinMode(PINBUZZER, OUTPUT); // El pin del buzzer se configura como salida
  pinMode(PINLED, OUTPUT); // El pin del LED se configura como salida

  Serial.begin(115200); // Inicialización de la comunicación serial

  digitalWrite(PINLED, LOW); // Apaga el LED al inicio

  Serial.println("hola"); // Imprime "hola" en el monitor serial
  Serial.println("Presiona el botón para comenzar con el loop");

  WaitBoton(); // Espera a que se presione el botón

  Serial.println("Botón presionado");

  digitalWrite(PINLED, HIGH); // Enciende el LED después de presionar el botón
}

void loop() {
  digitalWrite(PINLED, HIGH); // Enciende el LED
  delay(500); // Espera 500 ms
  digitalWrite(PINLED, LOW); // Apaga el LED
  delay(500); // Espera 500 ms
}
