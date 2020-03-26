#include <stdio.h>

enum 
{
	NOM = 1,
	TUE,
	WED,
	THU,
	FRI,
	SAT,
	SUN
};
int main()
{
	int time;
	while (1)
	{
		printf("请输入数字1-7: ");
		scanf("%d",&time);
		switch(time)
		{
			case NOM:
				printf("今天是星期一\n");
				break;
			case TUE:
				printf("今天是星期二\n");
				break;
			case WED:
				printf("今天是星期三\n");
				break;
			case THU:
				printf("今天是星期四\n");
				break;
			case FRI:
				printf("今天是星期五\n");
				break;
			case SAT:
				printf("今天是星期六\n");
				break;
			case SUN:
				printf("今天是星期天\n");
				break;
			default:
				printf("没有这个日期\n");
		}
	}
	return 0;
}
