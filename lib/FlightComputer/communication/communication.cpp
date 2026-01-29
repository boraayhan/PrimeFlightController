#include "communication.h"

uint8_t address[][6] = {"1Node", "2Node"};
RF24 radio(RADIO_PIN_CE, RADIO_PIN_CSN);
RadioPayload radioPayload;

void ReceiveRadio()
{ // Receives radio payload {id, p1, p2}, processes accordingly
  uint8_t pipe;
  if (radio.available(&pipe))
  {
    radio.read(&radioPayload, sizeof(RadioPayload)); // Receive the payload
    Serial.print(radioPayload.id);
    int id = radioPayload.id;
    float p1 = radioPayload.p1;
    float p2 = radioPayload.p2;

    if (id == 0)
    { // Joystick input
      inputRoll = p1;
      inputPitch = p2;
      if (abs(p1) > AUTOPILOT_DISENGAGE_THRESHOLD || abs(p2) > AUTOPILOT_DISENGAGE_THRESHOLD)
      { // Disengage autopilot
        DisengageAutopilot();
      }
    }

    if (id == 1)
    {              // Trim
      if (p1 == 0) // Aileron trim
      {
        surfaces[AILERON_LEFT].trim(p2);
        surfaces[AILERON_RIGHT].trim(p2);

        surfaces[AILERON_LEFT].move(0);
        surfaces[AILERON_RIGHT].move(0);
      }
      if (p1 == 1) // Elevator trim
      {
        surfaces[ELEVATOR_LEFT].trim(p2);
        surfaces[ELEVATOR_RIGHT].trim(p2);

        surfaces[ELEVATOR_LEFT].move(0);
        surfaces[ELEVATOR_RIGHT].move(0);
      }
    }

    if (id == 3)
    { // Throttle
      if (p1 < 0.07)
      {
        throttle = 0;
      }
      else
      {
        throttle = p1;
      }
    }

    if (id == 4)
    { // Resets trim on all surfaces
      for (ControlSurface &s : surfaces)
      {
        s.trimAngle = 0;
        s.move(0);
      }
    }
  }
}

void SetupRadio()
{ // Initializes radio
  if (!radio.begin())
  {
    Serial.println(F("Error: Radio hardware failure!"));
    while (1)
    {
    }
  }
  radio.setPALevel(RF24_PA_LOW);
  radio.setPayloadSize(sizeof(RadioPayload));
  radio.openReadingPipe(1, address[0]);
  radio.startListening();
}
