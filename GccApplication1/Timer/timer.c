/*
 * timer.c
 *
 * Created: 2016/5/25 10:32:26
 *  Author: ljq51
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

#define CPU_F 11059200
#define Timer0_1S (CPU_F/255)
#define Timer1_1S (CPU_F / 65535)
/***********************************************************
 *Part: Timer0
 *                         
 ***********************************************************/
static int  gT0_ovf_count = 0;
static int  gT1_ovf_count = 0;
void timer0_init(){
	TCCR0 |= (1 << CS00);   //No Prescaling
	TCNT0 = 0;
	TIMSK |= (1 << TOIE0);  //enable overflow interrupt
}

ISR(TIMER0_OVF_vect){
	// cli();
	gT0_ovf_count++;
	if(gT0_ovf_count >= Timer0_1S){
		gT0_ovf_count = 0;
		//PrintUart('0')
		on1s("0");
	}
	// sei();
}
/***********************************************************
 *Part: Timer1
 *                         
 ***********************************************************/

void timer1_init() {
  TCNT1 = 0;
  //Normal mode
  
  TCCR1B |= (1 << CS10); //No Prescaling
  TIMSK |= ( 1 << TOIE1);//enable overflow interrupt
}

/***********************************************************/
ISR(TIMER1_OVF_vect){
  gT1_ovf_count++;
  if (gT1_ovf_count >= Timer1_1S) {
    gT1_ovf_count = 0;
    // PrintUart('1')
    on1s("1");
  }
}

/***********************************************************/
ISR(TIMER1_COMPA_vect){

}


void on1s(char * str){

}