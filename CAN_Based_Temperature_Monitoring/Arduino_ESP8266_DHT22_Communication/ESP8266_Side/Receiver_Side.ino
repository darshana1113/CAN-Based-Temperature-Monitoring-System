#include <SPI.h>
#include <mcp_can.h>

#define LED_PIN D2

MCP_CAN CAN(D8);

void setup()
{
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  while(CAN_OK != CAN.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ))
  {
    Serial.println("CAN Init Failed");
    delay(1000);
  }

  CAN.setMode(MCP_NORMAL);
}

void loop()
{
  unsigned long rxId;
  byte len;
  byte buf[8];

  if(CAN_MSGAVAIL == CAN.checkReceive())
  {
    CAN.readMsgBuf(&rxId, &len, buf);

    int temperature = (buf[0] << 8) | buf[1];

    float temp = temperature / 10.0;

    Serial.print("Engine Temp: ");
    Serial.println(temp);

    if(temp >= 30)
    {
      Serial.println("OVERHEAT WARNING");

      digitalWrite(LED_PIN, HIGH);
      delay(300);
      digitalWrite(LED_PIN, LOW);
      delay(300);
    }
    else
    {
      digitalWrite(LED_PIN, LOW);
    }
  }
}