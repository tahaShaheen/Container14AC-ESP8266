/*
   This pulsIR stuff came from https://github.com/tahaShaheen/Container14AC-IRGrab.git
*/

void SendCode(int whichSetting) {
  switch (whichSetting) {
    case 1:
      //16 degree C, TURBO, Mode: COOL
      Serial.println("16C TURBO");
      pulseIR(6300);      delayMicroseconds(7580);      pulseIR(580);      delayMicroseconds(1660);
      pulseIR(580);      delayMicroseconds(1700);      pulseIR(580);      delayMicroseconds(1680);
      pulseIR(580);      delayMicroseconds(1660);      pulseIR(560);      delayMicroseconds(1680);
      pulseIR(600);      delayMicroseconds(1640);      pulseIR(580);      delayMicroseconds(1660);
      pulseIR(580);      delayMicroseconds(1680);      pulseIR(580);      delayMicroseconds(580);
      pulseIR(600);      delayMicroseconds(540);      pulseIR(540);      delayMicroseconds(620);
      pulseIR(580);      delayMicroseconds(560);      pulseIR(540);      delayMicroseconds(640);
      pulseIR(560);      delayMicroseconds(520);      pulseIR(580);      delayMicroseconds(600);
      pulseIR(580);      delayMicroseconds(560);      pulseIR(580);      delayMicroseconds(1680);
      pulseIR(580);      delayMicroseconds(1660);      pulseIR(580);      delayMicroseconds(1680);
      pulseIR(580);      delayMicroseconds(560);      pulseIR(540);      delayMicroseconds(1660);
      pulseIR(580);      delayMicroseconds(1660);      pulseIR(580);      delayMicroseconds(1640);
      pulseIR(600);      delayMicroseconds(1620);      pulseIR(600);      delayMicroseconds(580);
      pulseIR(580);      delayMicroseconds(600);      pulseIR(560);      delayMicroseconds(560);
      pulseIR(540);      delayMicroseconds(1700);      pulseIR(580);      delayMicroseconds(580);
      pulseIR(540);      delayMicroseconds(620);      pulseIR(560);      delayMicroseconds(580);
      pulseIR(540);      delayMicroseconds(580);      pulseIR(580);      delayMicroseconds(1680);
      pulseIR(580);      delayMicroseconds(600);      pulseIR(540);      delayMicroseconds(1680);
      pulseIR(600);      delayMicroseconds(560);      pulseIR(540);      delayMicroseconds(1700);
      pulseIR(600);      delayMicroseconds(1660);      pulseIR(580);      delayMicroseconds(1680);
      pulseIR(540);      delayMicroseconds(1720);      pulseIR(580);      delayMicroseconds(580);
      pulseIR(540);      delayMicroseconds(1720);      pulseIR(580);      delayMicroseconds(560);
      pulseIR(600);      delayMicroseconds(1640);      pulseIR(560);      delayMicroseconds(580);
      pulseIR(580);      delayMicroseconds(540);      pulseIR(580);      delayMicroseconds(580);
      pulseIR(580);      delayMicroseconds(540);      pulseIR(580);      delayMicroseconds(1680);
      pulseIR(540);      delayMicroseconds(660);      pulseIR(540);      delayMicroseconds(580);
      pulseIR(520);      delayMicroseconds(1720);      pulseIR(580);      delayMicroseconds(1660);
      pulseIR(600);      delayMicroseconds(1640);      pulseIR(560);      delayMicroseconds(1700);
      pulseIR(600);      delayMicroseconds(1660);      pulseIR(580);      delayMicroseconds(600);
      pulseIR(540);      delayMicroseconds(1700);      pulseIR(580);      delayMicroseconds(1680);
      pulseIR(560);      delayMicroseconds(560);      pulseIR(600);      delayMicroseconds(560);
      pulseIR(580);      delayMicroseconds(560);      pulseIR(560);      delayMicroseconds(560);
      pulseIR(580);      delayMicroseconds(580);      pulseIR(560);      delayMicroseconds(1700);
      pulseIR(580);      delayMicroseconds(1680);      pulseIR(540);      delayMicroseconds(1720);
      pulseIR(580);      delayMicroseconds(1640);      pulseIR(580);      delayMicroseconds(1680);
      pulseIR(580);      delayMicroseconds(560);      pulseIR(560);      delayMicroseconds(1660);
      pulseIR(580);      delayMicroseconds(1660);      pulseIR(600);      delayMicroseconds(580);
      pulseIR(580);      delayMicroseconds(540);      pulseIR(580);      delayMicroseconds(600);
      pulseIR(580);      delayMicroseconds(520);      pulseIR(600);      delayMicroseconds(560);
      pulseIR(540);      delayMicroseconds(1700);      pulseIR(580);      delayMicroseconds(540);
      pulseIR(560);      delayMicroseconds(600);      pulseIR(600);      delayMicroseconds(560);
      pulseIR(560);      delayMicroseconds(1660);      pulseIR(580);      delayMicroseconds(560);
      pulseIR(580);      delayMicroseconds(1680);      pulseIR(540);      delayMicroseconds(600);
      pulseIR(580);      delayMicroseconds(1640);      pulseIR(580);      delayMicroseconds(540);
      pulseIR(580);      delayMicroseconds(600);      pulseIR(540);      delayMicroseconds(1660);
      pulseIR(600);      delayMicroseconds(560);      pulseIR(540);      delayMicroseconds(1700);
      pulseIR(580);      delayMicroseconds(540);      pulseIR(580);      delayMicroseconds(1680);
      pulseIR(600);      delayMicroseconds(540);      pulseIR(580);      delayMicroseconds(1660);
      pulseIR(560);      delayMicroseconds(1680);      pulseIR(600);      delayMicroseconds(7560);
      pulseIR(580);      break;
    case 2:
      Serial.println("Turning OFF");
      pulseIR(6300);      delayMicroseconds(7600);      pulseIR(580);      delayMicroseconds(1660);
      pulseIR(600);      delayMicroseconds(1660);      pulseIR(560);      delayMicroseconds(1700);
      pulseIR(600);      delayMicroseconds(1660);      pulseIR(600);      delayMicroseconds(1660);
      pulseIR(540);      delayMicroseconds(1720);      pulseIR(600);      delayMicroseconds(1660);
      pulseIR(580);      delayMicroseconds(1700);      pulseIR(540);      delayMicroseconds(600);
      pulseIR(580);      delayMicroseconds(580);      pulseIR(600);      delayMicroseconds(560);
      pulseIR(580);      delayMicroseconds(560);      pulseIR(560);      delayMicroseconds(580);
      pulseIR(580);      delayMicroseconds(580);      pulseIR(520);      delayMicroseconds(580);
      pulseIR(600);      delayMicroseconds(560);      pulseIR(560);      delayMicroseconds(1700);
      pulseIR(600);      delayMicroseconds(1620);      pulseIR(600);      delayMicroseconds(1660);
      pulseIR(580);      delayMicroseconds(1700);      pulseIR(560);      delayMicroseconds(1680);
      pulseIR(600);      delayMicroseconds(1660);      pulseIR(560);      delayMicroseconds(1700);
      pulseIR(600);      delayMicroseconds(1660);      pulseIR(580);      delayMicroseconds(600);
      pulseIR(580);      delayMicroseconds(560);      pulseIR(580);      delayMicroseconds(540);
      pulseIR(580);      delayMicroseconds(580);      pulseIR(600);      delayMicroseconds(540);
      pulseIR(540);      delayMicroseconds(620);      pulseIR(580);      delayMicroseconds(560);
      pulseIR(540);      delayMicroseconds(600);      pulseIR(600);      delayMicroseconds(1660);
      pulseIR(580);      delayMicroseconds(1640);      pulseIR(560);      delayMicroseconds(1700);
      pulseIR(600);      delayMicroseconds(1660);      pulseIR(600);      delayMicroseconds(1680);
      pulseIR(560);      delayMicroseconds(1660);      pulseIR(580);      delayMicroseconds(1680);
      pulseIR(580);      delayMicroseconds(1660);      pulseIR(580);      delayMicroseconds(620);
      pulseIR(560);      delayMicroseconds(560);      pulseIR(520);      delayMicroseconds(600);
      pulseIR(580);      delayMicroseconds(580);      pulseIR(540);      delayMicroseconds(620);
      pulseIR(560);      delayMicroseconds(580);      pulseIR(560);      delayMicroseconds(580);
      pulseIR(540);      delayMicroseconds(600);      pulseIR(560);      delayMicroseconds(1680);
      pulseIR(560);     delayMicroseconds(1680);      pulseIR(580);      delayMicroseconds(1660);
      pulseIR(580);      delayMicroseconds(580);      pulseIR(540);      delayMicroseconds(1720);
      pulseIR(560);      delayMicroseconds(560);      pulseIR(560);      delayMicroseconds(1680);
      pulseIR(600);      delayMicroseconds(1660);      pulseIR(660);      delayMicroseconds(520);
      pulseIR(540);      delayMicroseconds(600);      pulseIR(620);      delayMicroseconds(520);
      pulseIR(560);      delayMicroseconds(1700);      pulseIR(640);      delayMicroseconds(540);
      pulseIR(540);     delayMicroseconds(1640);      pulseIR(680);      delayMicroseconds(480);
      pulseIR(680);      delayMicroseconds(460);     pulseIR(640);      delayMicroseconds(520);
      pulseIR(580);      delayMicroseconds(1680);      pulseIR(560);      delayMicroseconds(580);
      pulseIR(580);      delayMicroseconds(1660);      pulseIR(580);      delayMicroseconds(1700);
      pulseIR(640);      delayMicroseconds(500);      pulseIR(640);      delayMicroseconds(1580);
      pulseIR(580);      delayMicroseconds(1700);      pulseIR(660);      delayMicroseconds(1580);
      pulseIR(660);      delayMicroseconds(480);      pulseIR(600);      delayMicroseconds(1660);
      pulseIR(580);      delayMicroseconds(560);      pulseIR(560);      delayMicroseconds(620);
      pulseIR(620);      delayMicroseconds(1580);      pulseIR(640);      delayMicroseconds(480);
      pulseIR(580);      delayMicroseconds(560);      pulseIR(660);      delayMicroseconds(480);
      pulseIR(580);      delayMicroseconds(1680);      pulseIR(600);      delayMicroseconds(560);
      pulseIR(580);      delayMicroseconds(1680);      pulseIR(600);      delayMicroseconds(560);
      pulseIR(580);      delayMicroseconds(1640);      pulseIR(660);      delayMicroseconds(520);
      pulseIR(640);      delayMicroseconds(500);      pulseIR(560);      delayMicroseconds(1680);
      pulseIR(660);      delayMicroseconds(500);      pulseIR(580);      delayMicroseconds(1640);
      pulseIR(600);      delayMicroseconds(560);      pulseIR(640);      delayMicroseconds(1580);
      pulseIR(580);      delayMicroseconds(600);      pulseIR(560);      delayMicroseconds(1660);
      pulseIR(580);      delayMicroseconds(1640);      pulseIR(560);      delayMicroseconds(7620);
      pulseIR(580);      break;
    case 3:
      //22C NORMAL
      Serial.println("22C NORMAL");
      pulseIR(6300);      delayMicroseconds(7580);      pulseIR(600);      delayMicroseconds(1660);
      pulseIR(580);      delayMicroseconds(1680);      pulseIR(580);      delayMicroseconds(1680);
      pulseIR(600);      delayMicroseconds(1620);      pulseIR(580);      delayMicroseconds(1680);
      pulseIR(580);      delayMicroseconds(1680);      pulseIR(600);      delayMicroseconds(1640);
      pulseIR(580);      delayMicroseconds(1660);      pulseIR(580);      delayMicroseconds(580);
      pulseIR(600);      delayMicroseconds(560);      pulseIR(580);      delayMicroseconds(560);
      pulseIR(580);      delayMicroseconds(560);      pulseIR(580);      delayMicroseconds(560);
      pulseIR(600);      delayMicroseconds(540);      pulseIR(580);      delayMicroseconds(540);
      pulseIR(580);      delayMicroseconds(560);      pulseIR(580);      delayMicroseconds(1660);
      pulseIR(580);      delayMicroseconds(1680);      pulseIR(600);      delayMicroseconds(1660);
      pulseIR(600);      delayMicroseconds(1660);      pulseIR(580);      delayMicroseconds(1680);
      pulseIR(600);      delayMicroseconds(1660);      pulseIR(580);      delayMicroseconds(1680);
      pulseIR(600);      delayMicroseconds(1660);      pulseIR(580);      delayMicroseconds(560);
      pulseIR(660);      delayMicroseconds(520);      pulseIR(580);      delayMicroseconds(540);
      pulseIR(660);      delayMicroseconds(520);      pulseIR(580);      delayMicroseconds(540);
      pulseIR(580);      delayMicroseconds(580);      pulseIR(580);      delayMicroseconds(540);
      pulseIR(580);      delayMicroseconds(580);      pulseIR(600);      delayMicroseconds(1660);
      pulseIR(580);      delayMicroseconds(1680);      pulseIR(580);      delayMicroseconds(1680);
      pulseIR(580);      delayMicroseconds(1640);      pulseIR(600);      delayMicroseconds(1660);
      pulseIR(660);      delayMicroseconds(1580);      pulseIR(580);      delayMicroseconds(1680);
      pulseIR(580);      delayMicroseconds(1660);      pulseIR(580);      delayMicroseconds(600);
      pulseIR(640);      delayMicroseconds(500);      pulseIR(680);      delayMicroseconds(460);
      pulseIR(580);      delayMicroseconds(560);      pulseIR(600);      delayMicroseconds(540);
      pulseIR(600);      delayMicroseconds(560);      pulseIR(660);      delayMicroseconds(460);
      pulseIR(600);      delayMicroseconds(560);      pulseIR(580);      delayMicroseconds(1680);
      pulseIR(600);      delayMicroseconds(560);      pulseIR(580);      delayMicroseconds(1680);
      pulseIR(600);      delayMicroseconds(560);      pulseIR(660);      delayMicroseconds(1600);
      pulseIR(680);      delayMicroseconds(460);      pulseIR(660);      delayMicroseconds(1560);
      pulseIR(660);      delayMicroseconds(1600);     pulseIR(680);      delayMicroseconds(480);
      pulseIR(660);      delayMicroseconds(1560);      pulseIR(660);      delayMicroseconds(480);
      pulseIR(660);      delayMicroseconds(1580);      pulseIR(580);      delayMicroseconds(520);
      pulseIR(660);      delayMicroseconds(1620);      pulseIR(660);      delayMicroseconds(460);
      pulseIR(660);      delayMicroseconds(500);      pulseIR(680);      delayMicroseconds(1580);
      pulseIR(660);      delayMicroseconds(500);      pulseIR(680);      delayMicroseconds(440);
      pulseIR(660);      delayMicroseconds(1600);      pulseIR(660);      delayMicroseconds(1620);
      pulseIR(660);      delayMicroseconds(460);      pulseIR(660);      delayMicroseconds(1580);
      pulseIR(700);      delayMicroseconds(1540);      pulseIR(680);      delayMicroseconds(480);
      pulseIR(660);      delayMicroseconds(1600);      pulseIR(660);      delayMicroseconds(1600);
      pulseIR(620);      delayMicroseconds(460);      pulseIR(680);      delayMicroseconds(500);
      pulseIR(660);      delayMicroseconds(1560);      pulseIR(660);      delayMicroseconds(460);
      pulseIR(680);      delayMicroseconds(480);      pulseIR(680);      delayMicroseconds(500);
      pulseIR(660);      delayMicroseconds(1580);      pulseIR(680);      delayMicroseconds(440);
      pulseIR(660);      delayMicroseconds(1600);      pulseIR(660);      delayMicroseconds(440);
      pulseIR(740);      delayMicroseconds(1520);      pulseIR(660);      delayMicroseconds(480);
      pulseIR(660);      delayMicroseconds(500);      pulseIR(620);      delayMicroseconds(1600);
      pulseIR(680);      delayMicroseconds(480);      pulseIR(660);      delayMicroseconds(1560);
      pulseIR(680);      delayMicroseconds(460);      pulseIR(680);      delayMicroseconds(1540);
      pulseIR(660);      delayMicroseconds(460);      pulseIR(660);      delayMicroseconds(1660);
      pulseIR(620);      delayMicroseconds(1560);      pulseIR(660);      delayMicroseconds(7520);
      pulseIR(660);      break;
    default:
      digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
  }
}
