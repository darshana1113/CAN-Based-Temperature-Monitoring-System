/*
  Arduino UNO -> MCP2515 CAN Transmitter

  Connections:
  MCP2515    Arduino UNO
  -----------------------
  VCC        5V
  GND        GND
  CS         D10
  SO         D12
  SI         D11
  SCK        D13
  INT        D2
*/

#include <SPI.h>
#include <mcp_can.h>

#define CAN_CS_PIN 10
#define CAN_INT_PIN 2

MCP_CAN CAN(CAN_CS_PIN);

unsigned long lastSend = 0;
byte counter = 0;

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

  Serial.println("Starting Transmission...");
}

void loop()
{
  if (millis() - lastSend >= 1000)
  {
    lastSend = millis();

    byte txData[8];

    txData[0] = counter;
    txData[1] = 'T';
    txData[2] = 'E';
    txData[3] = 'S';
    txData[4] = 'T';
    txData[5] = 'C';
    txData[6] = 'A';
    txData[7] = 'N';

    if (CAN.sendMsgBuf(0x100, 0, 8, txData) == CAN_OK)
    {
      Serial.print("Message Sent -> Counter = ");
      Serial.println(counter);
    }
    else
    {
      Serial.println("Error Sending Message");
    }

    counter++;
  }
}