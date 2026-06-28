#include <SPI.h>
#include <mcp_can.h>
#include <DHT.h>

#define DHTPIN 3
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
MCP_CAN CAN(10);

void setup()
{
  Serial.begin(115200);
  dht.begin();

  while(CAN_OK != CAN.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ))
  {
    Serial.println("CAN Init Failed");
    delay(1000);
  }

  CAN.setMode(MCP_NORMAL);
}

void loop()
{
  float temp = dht.readTemperature();

  int temperature = temp * 10;

  byte data[2];

  data[0] = highByte(temperature);
  data[1] = lowByte(temperature);

  CAN.sendMsgBuf(0x100, 0, 2, data);

  Serial.print("Temp Sent: ");
  Serial.println(temp);

  delay(1000);
}