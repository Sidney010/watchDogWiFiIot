# include <WiFi.h>

// Substitua pelas suas credenciais de rede
const char* ssid      = "A54 do Julio";
const char* password = "Julio12345678";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Conectando a: ");
  Serial.println(ssid);

  // Inicia conexão com Station
  WiFi.begin(ssid, password);

  int tentativas = 0;
  while (WiFi.status() != WL_CONNECTED && tentativas <20) {
    delay(500);
    Serial.print(",");
    tentativas++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✔️ Conectado!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("RSSI (sinal): ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBn");
  } else {
    Serial.println("\n❌ Falha na conexão!");
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  // Verifica conexão a cada 10 segundos
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Reconectando...");
    WiFi.reconnect();
  }
  delay(10000);
}
