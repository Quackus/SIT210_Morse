int led = D7;
int BASESPEED = 100;

char MORSECODE_CHAR [] = {'A','B','C','D','E','F',
                        'G','H','I','J','K','M',
                        'N','O','P','Q','R','S',
                        'T','U','V','W','X','Y','Z',
                        '1','2','3','4','5','6','7','8','9','0'};
String MORSECODE_SIGNAL [] = {"01","1000","1010","100","0","0010",
                            "110","0000","00","0111","101","0100",
                            "10","111","0110","1101","010","000",
                            "1","001","0001","100","1001","1011","1100",
                            "01111","00111","00011","00001","00000","10000","11000","11100","11110","11111"};

String testWord = "Rowern";

void setup() {
    pinMode(led,OUTPUT);
    digitalWrite(led,LOW);
    
}

void loop() {
    
    morseCodeSend(testWord);
    delay(3000);
}

void morseCodeSend(String message) {
    for (int i = 0; i < message.length(); i++) {
        morseCodeBlink(toupper(message[i]));
    }
}

void morseCodeBlink(char character) {
    String signal = "";
    
    for (int i = 0; i < sizeof(MORSECODE_CHAR); i++) {
        if (MORSECODE_CHAR[i] == character) {
            signal = MORSECODE_SIGNAL[i];
        }
    }
    
    for (int i = 0; i < signal.length(); i++) {
        switch (signal[i]) {
            case '0': ledDot();
                    break;
            case '1': ledDash();
                    break;
        }
    }
    delay(BASESPEED * 5);
}

void ledDot() {
    digitalWrite(led,HIGH);
    
    delay(BASESPEED);
    
    digitalWrite(led,LOW);
    
    delay(BASESPEED);
}

void ledDash() {
    digitalWrite(led,HIGH);
    
    delay(BASESPEED * 3);
    
    digitalWrite(led,LOW);
    
    delay(BASESPEED);
}

