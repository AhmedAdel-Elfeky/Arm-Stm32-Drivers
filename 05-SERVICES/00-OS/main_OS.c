

#includes


void LED0()
{
	static u8 Local_u8Pin0 = 0;
	TOG_BIT(Local_u8Pin0,0);
	MGPIO_voidSetPinValue(GPIO_PORT_A,PIN0,Local_u8Pin0);
}

void LED1()
{
	static u8 Local_u8Pin1 = 0;
	TOG_BIT(Local_u8Pin1,0);
	MGPIO_voidSetPinValue(GPIO_PORT_A,PIN1,Local_u8Pin1);
}

void LED2()
{
	static u8 Local_u8Pin2 = 0;
	TOG_BIT(Local_u8Pin2,0);
	MGPIO_voidSetPinValue(GPIO_PORT_A,PIN2,Local_u8Pin2);
}

int main(void)
{
	/*initialization */
	// RCC
	
	// Enable GPIO RCC PERTA
	//GPIO initialization Direction
	
	SOS_voidCreateTask(0,1000,LED0);
	SOS_voidCreateTask(0,1000,LED1);
	SOS_voidCreateTask(0,1000,LED2);
	SOS_voidStart();
	while(1)
	{
		
	}	
	return 0;
}