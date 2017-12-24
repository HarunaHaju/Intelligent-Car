#include <reg52.h>
#define uchar unsigned char
unsigned char c;
bit flag;

sbit P1_0=P1^0;
sbit P1_1=P1^1;


void delay_nus(unsigned int i)
{ 
  i=i/10;
  while(--i);
}   

void delay_nms(unsigned int n)
{ 
  n=n+1;
  while(--n)  
  delay_nus(900);
}   

void Initialize(){
	SCON=0x50;
	TMOD=0x20;
	TH1=0xFd;
	TL1=0xFd;
	TR1=1;

	EA=1;

	REN=1;
}

void send_data(unsigned char x)
{
 	SBUF=x;
	while(!TI);
		TI=0;
}

 void send_str(unsigned char *s)
 {
 	while(*s!='\0')
	{
		send_data(*s);
		s++;
	}
 }

void Forward()
{
	int i;
	for(i=1;i<5;i++)
	{
		P1_1=1;
		delay_nus(1700);
    	P1_1=0;
		P1_0=1;
		delay_nus(1300);
		P1_0=0;
		delay_nms(20);
	}
}
void Left_Turn(void)
{
	int i;
    for(i=1;i<=5;i++)
	{
		P1_1=1;
		delay_nus(1300);
    P1_1=0;
		P1_0=1;
		delay_nus(1300);
		P1_0=0;
		delay_nms(20);
	}
}
void Right_Turn(void)
{
	int i;
    for(i=1;i<=5;i++)
	{
		P1_1=1;
		delay_nus(1700);
        P1_1=0;
		P1_0=1;
		delay_nus(1700);
		P1_0=0;
		delay_nms(20);
	}
}
void Backward(void)
{
	int i;
    for(i=1;i<=5;i++)
	{
		P1_1=1;
		delay_nus(1300);
        P1_1=0;
		P1_0=1;
		delay_nus(1700);
		P1_0=0;
		delay_nms(20);
	}
}

int main()
{
	
	Initialize();
	flag=0;
	send_str("Please input message");
	ES=1;
	while(1)
	{
		if(flag==1)
		{
			ES=0;
			send_data(c);
			flag=0;
			ES=1;
		}
	}
}

void get() interrupt 4
{
	if(RI)
	{
		RI=0;
		flag=1;
		c=SBUF;
		switch(c)
		{
			case '1':
				Forward();
				break;
			case '2':
				Left_Turn();
				break;
			case '3':
				Right_Turn();
				break;
			case '4':
				Backward();
				break;
			default:
				break;
		}
	}
	if(TI){
	TI=0;	}
}
