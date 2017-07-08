#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int val = 0;
char *st_str;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9800);
  // init lcd.
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" [ CDS  VALUE ] ");
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(0);
  lcd.setCursor(0, 1);
  st_str = cds_power_str(val);
  lcd.print(st_str);
  delay(1000);
}

char *cds_power_str(int val) {
  char *str[] = {"    DELICATE    ", "     MEDIUM     ", "     STRONG     "};
  if(val>=800) return str[2];
  else if(val>500) return str[1];
  else return str[0];
  
}


