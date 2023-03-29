#include <avr/io.h>
#include <avr/delay.h>

#define SEG_PORT PORTA
#define SEG_DDR  DDRA

#define CY_PORT PORTC
#define CY_DDR DDRC
#define CY1  (1<<PC0)
#define CY2  (1<<PC1)
#define CY3 (1<<PC2)
#define CY4  (1<<PC3)

#define CY_OFF   CY_PORT |= CY1 | CY2  | CY3 | CY4;
#define CY1_ON    CY_PORT &= ~CY1
#define CY2_ON    CY_PORT &= ~CY2
#define CY3_ON    CY_PORT &= ~CY3
#define CY4_ON    CY_PORT &= ~CY4

#define KLAWISZ_1 (1<<PD7)
#define K_1_PRESSED  !(PIND & KLAWISZ_1)
#define KLAWISZ_2 (1<<PD6)
#define K_2_PRESSED  !(PIND & KLAWISZ_2)
#define KLAWISZ_3 (1<<PD5)
#define K_3_PRESSED  !(PIND & KLAWISZ_3)
#define KLAWISZ_4 (1<<PD4)
#define K_4_PRESSED  !(PIND & KLAWISZ_4)


uint8_t cyfra[10]={0x81,0xF3,0x49,0x61,0x33,0x25,0x05,0xF1,0x01,0x21};

int main(void) {
    SEG_DDR = 0XFF;
    CY_DDR |= CY1 | CY2 | CY3 | CY4;

    PORTD |= KLAWISZ_1;
    PORTD |= KLAWISZ_2;
    PORTD |= KLAWISZ_3;
    PORTD |= KLAWISZ_4;

    uint8_t je;
    uint8_t dz ;
    uint16_t se ;
    uint8_t ty ;

    uint16_t liczba = 0;
    int a = 0;

    for(;;){

        se = liczba%1000;
        ty = liczba/1000;
        dz = se%100;
        se = se/100;
        je = dz%10;
        dz = dz/10;

        CY_OFF;
        CY1_ON;
        SEG_PORT = cyfra[ty];
        _delay_ms(5);
        CY_OFF;
        CY2_ON;
        SEG_PORT = cyfra[se];
        _delay_ms(5);
        CY_OFF;
        CY3_ON;
        SEG_PORT = cyfra[dz];
        _delay_ms(5);
        CY_OFF;
        CY4_ON;
        SEG_PORT = cyfra[je];
       _delay_ms(5);


       }
}