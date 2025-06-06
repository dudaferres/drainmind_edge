# 💧 Monitoramento de Nível de Água com ESP32

## 🚩 Descrição do Problema
- As intensas chuvas e enchentes que atingiram não apenas o Rio Grande do Sul em 2024, mas também diversas regiões do Brasil, evidenciaram a fragilidade da infraestrutura urbana no gerenciamento das águas pluviais. Um dos principais fatores agravantes é a obstrução de bueiros e sistemas de drenagem, provocada pelo acúmulo de lixo e pela ausência de monitoramento eficiente e a falta de equipes para as limpezas constantes. Sem dados em tempo real, as autoridades atuam de forma reativa, dificultando a prevenção de alagamentos e ampliando os danos à população e ao meio ambiente.

---

## 💡 Visão Geral da Solução

- Este projeto propõe a automação do monitoramento de bueiros por meio de sensores inteligentes capazes de detectar o nível da água e a presença de resíduos sólidos. A solução permite o acompanhamento em tempo real, a geração de alertas preventivos e o controle eficiente do fluxo hídrico, contribuindo para a prevenção de enchentes e a melhoria da gestão urbana.

O sistema utiliza:
- **ESP32**
- **Sensor Ultrassônico**
- **LEDs** (vermelho, amarelo, verde)
- **Servo Motor**
- **MQTT** para monitoramento remoto

### Funcionalidades:
- 📏 Mede o nível de água (distância do sensor ultrassônico)
- 🚦 Indica o status do reservatório com LEDs:
  - 🔴 Máximo
  - 🟡 Atenção
  - 🟢 Estável
- 🤖 Aciona um servo motor para redirecionar o fluxo quando o nível máximo é atingido
- 🌐 Envia os dados via MQTT para monitoramento remoto

---

## ▶️ Instruções para Execução e Simulação

### 🖥️ Simulação no Wokwi
1. Acesse o link do projeto no Wokwi abaixo.
2. Clique em **Start Simulation**.
3. Observe os LEDs e o movimento do servo conforme a distância simulada.
4. Os dados são publicados no tópico MQTT `sensor/dist/gabi` no broker `test.mosquitto.org`.

### 🛠️ Execução em Hardware Real

1. **Componentes necessários:**
   - ESP32 DevKit
   - Sensor Ultrassônico HC-SR04
   - Servo Motor
   - LEDs (Vermelho, Amarelo, Verde)
   - Resistores, jumpers e protoboard
     
2. **Montagem:**
   - Siga o mapeamento de pinos conforme o código:
     - `trigger`: GPIO 5
     - `echo`: GPIO 18
     - LEDs: 2 (vermelho), 14 (verde), 16 (amarelo)
     - servo: 4
       
3. **Configuração Wi-Fi:**
   - Altere o SSID e senha no código, se necessário
     
5. **Upload do código:**
   
   - Instale as bibliotecas:
     - `WiFi.h`
     - `ESP32Servo.h`
     - `PubSubClient.h`
     - `ArduinoJson.h`
   - Faça o upload para o ESP32
6. **Monitoramento MQTT:**
   - Use um cliente MQTT para visualizar o tópico `sensor/dist/gabi`

---

## 🌎 Link para o Projeto no Wokwi

[🔗 Simule este projeto no Wokwi](https://wokwi.com/projects/432396740170267649)

---

## 📢 Link para o Vídeo no Youtube

[🔗 Veja o vídeo deste projeto no Youtube](https://youtu.be/mnotd0-J_a0)

---

## 💌 Desenvolvedoras

- 1ESPB

- Gabriela Queiroga Cocuzza da Silva   RM - 560035
- GitHub    https://github.com/gabiqueiroga1
- LinkedIn   https://www.linkedin.com/in/gabriela-queiroga-493260338/

<hr>

- 𝙼𝚊𝚛𝚒𝚊 𝙴𝚍𝚞𝚊𝚛𝚍𝚊 𝙵𝚎𝚛𝚛𝚎́𝚜   RM - 560418
- GitHub    https://github.com/dudaferres
- Linkedin   https://www.linkedin.com/in/mariaeduardaferres/
