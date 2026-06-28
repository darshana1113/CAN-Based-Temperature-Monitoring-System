/*
  ESP8266 NodeMCU -> MCP2515 CAN Receiver

  Connections:
  MCP2515    ESP8266
  -----------------------
  VCC        VIN
  GND        GND
  CS         D8
  SO         D6
  SI         D7
  SCK        D5
  INT        D1
*/

#include <SPI.h>
#include <mcp_can.h>

#define CAN_CS_PIN D8
#define CAN_INT_PIN D1

MCP_CAN CAN(CAN_CS_PIN);

void setup()
{
  Serial.begin(115200);

  while (CAN.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) != CAN_OK)
  {
    Serial.println("CAN Initialization Failed...");
    delay(1000);
  }

  Serial.println("CAN Initialized Successfully");

  CAN.setMode(MCP_NORMAL);

  pinMode(CAN_INT_PIN, INPUT);
}

void loop()
{
  if (!digitalRead(CAN_INT_PIN))
  {
    unsigned long rxId;
    byte len = 0;
    byte rxBuf[8];

    CAN.readMsgBuf(&rxId, &len, rxBuf);

    Serial.println("--------------------------------");
    Serial.print("Received ID : 0x");
    Serial.println(rxId, HEX);

    Serial.print("Length      : ");
    Serial.println(len);

    Serial.print("Counter     : ");
    Serial.println(rxBuf[0]);

    Serial.print("Message     : ");

    for (int i = 1; i < len; i++)
    {
      Serial.print((char)rxBuf[i]);
    }

    Serial.println();
    Serial.println("--------------------------------");
  }
}
