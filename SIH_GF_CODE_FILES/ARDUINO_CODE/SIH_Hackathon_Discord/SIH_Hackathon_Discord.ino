#include <Discord_WebHook.h>

Discord_Webhook discord;
String DISCORD_WEBHOOK = "https://discordapp.com/api/webhooks/1010173362707910677/6FNCa-IxBikDfzD4hHEiN1KuyTsxv-uCX_wH9V5MLqYikcNzmoc_YMkYbRiHXQJ1iyUH";

int buttonstate=0;
int i=0;

void setup() {
  Serial.begin(115200);
  discord.begin(DISCORD_WEBHOOK); 
  discord.addWiFi("powerx", "17231183");
  discord.connectWiFi(); 
  discord.send("Nodemcu_started"); 

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  buttonstate=digitalRead(D2);
  
  if (buttonstate==0){
    digitalWrite(LED_BUILTIN, LOW);//LOW means led **ON**
     }

  if (buttonstate==1){
// when buttonstate is 0 means signal recevied is low
// led will blink and also send message to DISCORD

    
    digitalWrite(LED_BUILTIN, LOW);
    delay(1);
    digitalWrite(LED_BUILTIN, HIGH);  
    
    
    discord.send("Signal is HIGH from raspberry pi ");
    }
    
}
