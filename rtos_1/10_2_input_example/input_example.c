


int main2()
{
	while (1)
	{
		key = read_gpio();
		if (key)
		{
			// 1. key ==> InputEvent
			// 2. 处理
		}

		packet = read_net();
		if (packet)
		{
			// 1. packet ==> InputEvent
			// 2. 处理
		}

		str = scanf();
		if (str)
		{
			// 1. str ==> InputEvent
			// 2. 处理
		}

		other = read_other();

	}
}


int main()
{
	while (1)
	{
		event = GetInputEventFromDevices();
		switch (event)
		{
			case 'a':
				process_a();
				break;
			case 'b':
				process_b();
				break;
		}
	}
}

