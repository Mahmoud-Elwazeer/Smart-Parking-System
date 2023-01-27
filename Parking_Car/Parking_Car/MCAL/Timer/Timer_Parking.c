/*
 * Timer_Parking.c
 *
 * Created: 10/26/2022 8:54:38 PM
 *  Author: Elwazeer
 */ 

#include "Timer_Parking.h"

void timer_CTC_init_interrupt(void)
{
	/* select CTC mode*/
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=80;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* enable interrupt*/
	sei();
	SET_BIT(TIMSK,OCIE0);
}


void timer_wave_nonPWM(void)
{
	/* set OC0 as output pin */

	/* select CTC mode*/
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=64;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* toggle OC0 on compare match*/
	SET_BIT(TCCR0,COM00);
}

void timer1_wave_fastPWM_A(double value)
{
	/* set OC1A as output pin */

	/* select fast PWM mode*/
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/* load a value in OCR1A,ICR1 */
	OCR1A=value*1000;
	ICR1=19999;
	/* select timer clock, no prescaling */
	SET_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);
	/* clear OC1A on compare match, set OC1A at BOTTOM,(non inverting mode)*/
	SET_BIT(TCCR1A,COM1A1);
}
void timer1_wave_fastPWM_B(double value)
{
	/* set OC1B as output pin */
	
	/* select fast PWM mode*/
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/* load a value in OCR1B,ICR1 */
	OCR1B=value*1000;
	ICR1=19999;
	/* select timer clock, no prescaling */
	SET_BIT(TCCR1B,CS10);
	/* clear OC1B on compare match, set OC1B at BOTTOM,(non inverting mode)*/
	SET_BIT(TCCR1A,COM1B1);
}

void timer_wave_phasecorrectPWM(void)
{
	/* set OC0 as output pin */
	
	/* select phase correct PWM mode*/
	SET_BIT(TCCR0,WGM00);
	/* load a value in OCR0 */
	OCR0=64;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* Set OC0 on compare match when up-counting. Clear OC0 on compare match when down counting.*/
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}
