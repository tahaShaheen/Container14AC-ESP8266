void timeCheck(){
  timeClient.update();
  String currentTime = timeClient.getFormattedTime();
  delayMicroseconds(50);
}

