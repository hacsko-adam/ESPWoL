#ifndef EEPROM_MANAGER
#define EEPROM_MANAGER
#include <Arduino.h>
#include <EEPROM.h>

class EepromManager
{
public:
    EepromManager()
    {
    }

    void writeWord(String word)
    {
        EEPROM.begin(512);
        delay(10);

        for (int i = 0; i < word.length(); ++i)
        {
            EEPROM.write(i, char(word[i]));
        }

        EEPROM.write(word.length(), '\0');
        EEPROM.commit();
        // char c = word[0];
        // EEPROM.begin(512);
        // int a = 69;
        // EEPROM.write(4, c);
        // EEPROM.commit();
        EEPROM.end();
    }

    String readWord()
    {
        EEPROM.begin(512);
        String word;
        char readChar;
        int i = 0;

        while (readChar != '\0')
        {
            readChar = char(EEPROM.read(i));
            delay(10);
            i++;

            if (readChar != '\0')
            {
                word += readChar;
            }
        }

        // EPROM.begin(512);
        // int a = EEPROM.read(4);
        // Serial.println("readed:");
        // Serial.println(a);E
        EEPROM.end();
        return String(word);
    }
};

#endif