#include <WiFi.h> // Biblioteca para conexão Wi-Fi
#include <ESP32Servo.h> // Biblioteca para controle do servo motor
#include <PubSubClient.h> // Biblioteca para comunicação MQTT
#include <ArduinoJson.h> // Biblioteca para manipulação de JSON


// Definindo os LED's
#define ledR 2
#define ledG 14
#define ledY 16

#define servopin 4 // Pino do servo motor
Servo servo; // Objeto do servo motor

#define trigger 5 // Pino trigger do sensor ultrassônico
#define echo 18 // Pino echo do sensor ultrassônico

int dist = 0; // Variável para armazenar a distância medida

// Objetos para conexão Wi-Fi e MQTT
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void setup() {
  Serial.begin(115200); // Inicializa a comunicação serial
  pinMode(trigger, OUTPUT); // Configura o pino trigger como saída
  pinMode(echo, INPUT); // Configura o pino echo como entrada
  pinMode(ledR, OUTPUT); // Configura o LED vermelho como saída
  pinMode(ledG, OUTPUT); // Configura o LED verde como saída
  pinMode(ledY, OUTPUT); // Configura o LED amarelo como saída
  pinMode(servopin, OUTPUT); // Configura o pino do servo como saída

  servo.attach(servopin); // Anexa o servo ao pino definido

  WiFi.begin("Wokwi-GUEST", ""); // Conecta ao Wi-Fi (SSID e senha)
  while (WiFi.status() != WL_CONNECTED) delay(100); // Aguarda conexão

  mqttClient.setServer("test.mosquitto.org", 1883); // Define o broker MQTT

  mqttClient.connect("esp32-cliente"); // Conecta ao broker MQTT

}

void loop() {
  mqttClient.loop(); // Mantém a conexão MQTT ativa

  // Dispara o sensor ultrassônico
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  // Mede o tempo do pulso (distância)
  dist = pulseIn(echo, HIGH);
  dist = dist/58; // Converte o tempo em centímetros

  // Cria um objeto JSON para enviar a distância
  StaticJsonDocument<100> json;
  json["distancia"] = dist;

  char jsonBuffer[200];
  serializeJson(json, jsonBuffer); // Serializa o JSON para string

  mqttClient.publish("sensor/dist/gabi", jsonBuffer); // Publica no tópico MQTT

  // Lógica de controle dos LEDs e do servo motor
  if (dist <= 5){ // Nível máximo atingido
    digitalWrite(ledR, HIGH); // Liga LED vermelho
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    servo.write(90); // Gira o servo para redirecionar o fluxo
    Serial.println("Nível Máximo atingido. Redirecionando para outro reservátório");
  }else if (dist > 50){ // Nível estável
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, HIGH); // Liga LED verde
    digitalWrite(ledY, LOW);
    servo.write(0); // Servo na posição inicial
    Serial.println("Nível da água estável.");
  }else{ // Nível intermediário
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, HIGH); // Liga LED amarelo
    Serial.println("Cuidado! Pode transbordar");
  }
  delay(2000); // Aguarda 2 segundos antes da próxima leitura

}
