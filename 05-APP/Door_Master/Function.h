#ifndef FUNCTION_H
#define FUNCTION_H

#define E_KEY 0xDC
#define EEPROM_ADDRESS 0x00
#define TRY_ADDRESS 0x05
#define SLAVE 0xCC
#define KEYDELAY 500


void SetPass (void);
u8 CheckPass (void);
void LockedOut (void);
void Wrongpass (void);



#endif
