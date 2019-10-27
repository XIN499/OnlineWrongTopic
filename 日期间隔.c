输入
第一行输入三个整数y m d表示第一个日期的年月日。
第二行输入三个整数yy mm dd表示第二个日期的年月日。
年月日之间空格分开（保证数据合法且两个日期不相同）。

输出
输出一行一个正整数，两个日期之间相隔的天数

















#include<stdio.h>
int MON_DAY[2][13]=
{
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}//二维数组定义月份天数，多加个0后面对应天数更方便 
 };//只是定义，分号隔开语句 
 
 int YEAR_DAY[2]=
 {
 	365,
 	366
 }; //这也太绝了 
 
int is_leap(int x)
{
	return(x%4==0&&x%100!=0)||(x%400==0);//判断闰年，是闰年返回1，不是返回0； 
}

int get_day(int y,int m,int d)
{
	int i, days=d;
	for(i=0;i<y;++i)
		days+=YEAR_DAY[is_leap(i)];
	for(i=1;i<m;++i)//这里i++和++i表示的是一样的 都是加一的意思 
		days+=MON_DAY[is_leap(y)][i]; 
		return days;
}

int main(){
	int y1,m1,d1,y2,m2,d2,k;
	scanf("%d%d%d%d%d%d",&y1,&m1,&d1,&y2,&m2,&d2);k=get_day(y1,m1,d1)-get_day(y2,m2,d2);
	
	printf("%d\n",abs(k));
	/*fabs()是math.h头文件里的 不管括号里是什么数据类型 输出必须是%f浮点数
	abs()是stdio.h头文件里的  不管括号里是什么 输出必须是%d整型 
	*/ 
	return 0;
} 








