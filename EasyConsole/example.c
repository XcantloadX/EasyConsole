#include <stdio.h>
#include "console.h"

int main()
{
	console_init();
	console_clear();
	console_box(1, 1, 10, 20);
	console_goto(2, 2);

	for (int i = 0; i < 5; i++)
	{
		console_goto(2 + i, 6);
		printf("Item%d", i);
	}

	int choice = 0;
	while (1)
	{
		if (console_key_begin())
		{
			if (console_key_down(KEY_UP))
				choice--;
			if (console_key_down(KEY_DOWN))
				choice++;
			if (choice < 0)
				choice = 4;
			if (choice > 4)
				choice = 0;

			for (int i = 0; i < 5; i++)
			{
				console_goto(2 + i, 3);
				if (choice == i)
					printf("→");
				else
					printf("　");
			}
		}
		console_key_end();
	}
	return 0;
}