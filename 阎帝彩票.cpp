//阎帝彩票 
#include<bits/stdc++.h>
using namespace std;
int ye;
bool xysz[110];
bool f[4][8];
int sm[10],shuzi[20],cp6[20];
int qpow(int a,int b)
{
    int ans=1;
    for(;b;b>>=1,a=a*a)if(b&1)ans=ans*a;
    return ans;
}
void yandi()
/*
cp6_player_id:  a05ec0dc-597e-48de-9b55-d6edea4a5477
cp6_oauth2_state:  MMO57p2aO9btwMEvyhbTibxd1OH7W1yi
*/
{
    system("cls");
    puts("增加多少?");
    int jiba;scanf("%d",&jiba);
    ye+=jiba;
    printf("·");_sleep(1000);
    printf("·");_sleep(1000);
    printf("·");_sleep(1000);
    printf("·");_sleep(1000);
    printf("·");_sleep(1000);
    puts("");
    puts("成功!");
    _sleep(1000);
}
int  main()
{
    srand(time(0));
    ye=100;
    while(1)
    {
        system("cls");
        printf("余额:%d\n",ye);
        puts("1:购买彩票");
        puts("2:查看规则");
        puts("3:重新开始");
        int cz;scanf("%d",&cz);
        if(cz==3)
        {
        	system("cls");
        	puts("确定吗?(重新开始后无法撤回)");
        	puts("Y/N");
        	char sss[10];scanf("%s",sss);
        	if(sss[0]=='Y'){ye=100;continue;}
		}
        if(cz==1)
        {
            system("cls");
            puts("1.无穷彩票(不建议)");
            puts("2.传统彩票");
            puts("3.幸运数字");
            puts("4.刮刮乐");
            puts("5.单色球");
            puts("6.未命名");
            puts("0.退出");
            int cpzl;scanf("%d",&cpzl);
            if(cpzl==1)//无限 
            {
                system("cls");
                puts("无限彩票");
                puts("买几张彩票？");//购买 
                int gs;scanf("%d",&gs);
                if(gs==0)continue;
                if(gs*10>ye){puts("余额不足…");_sleep(1000);continue;}
                ye-=gs*10;
                _sleep(100);
                int sumcp=0;
                for(int i=1;i<=gs;i++)//每张 
                {
                    for(int j=0;j<=63;j++)
                    {
                        int sj=rand()%3;
                        if(sj==0||sj==1)
                        {
                            printf("第%d张中了%d元！\n",i,qpow(3,j)/3*10);
                            ye+=qpow(3,j)/3*10;
                            sumcp+=qpow(3,j)/3*10;
                            if(gs>1000)_sleep(1);
                            else if(gs>100)_sleep(50);
                            else if(gs>20)_sleep(100);
                            else _sleep(1000);
                            break;
                        }
                    }
                }
                printf("总共中了%d元！\n",sumcp);
                _sleep(100);
                printf("平均每张%lf元\n",1.0*sumcp/gs);
                puts("press enter to continue…");
                char dfslka=getchar();
                dfslka=getchar();
            } 
            else if(cpzl==2)//传统 
            {
                system("cls");
                puts("传统彩票");
                puts("买几张彩票？");//购买 
                int gs;scanf("%d",&gs);
                if(gs==0)continue;
                if(gs*10>ye){puts("余额不足…");_sleep(1000);continue;}
                ye-=gs*10;
                _sleep(100);
                int sumcp=0;
                for(int i=1;i<=gs;i++)
                {
                    int sj=rand()%100;
                    if(sj<=50)printf("第%d张中0元\n",i);
                    else if(sj<=80)printf("第%d张中10元\n",i),sumcp+=1;
                    else if(sj<=90)printf("第%d张中50元\n",i),sumcp+=5;
                    else if(sj<=100)printf("第%d张中20元\n",i),sumcp+=2;
                    if(gs>1000)_sleep(0);
                    else if(gs>100)_sleep(50);
                    else if(gs>20)_sleep(100);
                    else _sleep(1000);
                }
                ye+=sumcp*10;
                printf("总共中了%d元！\n",sumcp*10);
                _sleep(100);
                printf("平均每张%lf元\n",1.0*sumcp*10/gs);
                puts("press enter to continue…");
                char dfslka=getchar();
                dfslka=getchar();
            }
            else if(cpzl==3)
            {
                system("cls");
                puts("幸运数字");
                printf("可以选择:\n");
                memset(xysz,0,sizeof(xysz));
                for(int i=1;i<=100;i++)
                {
                    int sj=rand()%3;
                    if(!sj)xysz[i]=1,printf("%d ",i);
                }
                puts("");
                int dajiang=rand()%100+1;
                _sleep(500);
                puts("买几张?");
                int gs;scanf("%d",&gs);
                if(gs==0)continue;
                if(gs*20>ye){puts("余额不足…");_sleep(1000);continue;}
                ye-=gs*20;
                puts("请选择:");
                bool pd=(gs==6),bk=0;
                int sumcp=0;
                for(int i=1,x,y;i<=gs;i++)
                {
                    scanf("%d",&x);
                    if(!xysz[x]){puts("错误");i--;}
                    else
                    {
                        xysz[x]=1;
                        if(abs(x-dajiang)<=0)
                        {
                            printf("中%d元!\n",100);
                            sumcp+=10*10;
                        }
                        else if(abs(x-dajiang)<=3)
                        {
                            puts("中50元!");
                            sumcp+=5*10;
                        }
                        else if(abs(x-dajiang)<=5)
                        {
                            puts("中30元!");
                            sumcp+=3*10;
                        }
                        else if(abs(x-dajiang)<=10)
                        {
                            puts("中20元!");
                            sumcp+=2*10;
                        }
                        else if(abs(x-dajiang)<=15)
                        {
                            puts("中10元!");
                            sumcp+=1*10;
                        }
                        else puts("没中…");
                    }
                    y=x;
                }
                if(bk)continue;
                _sleep(500);
                printf("大奖是…");
                _sleep(1000);
                printf("%d!\n",dajiang);
                _sleep(1000);
                ye+=sumcp;
                printf("总共中了%d元！\n",sumcp);
                _sleep(100);
                printf("平均每张%lf元\n",1.0*sumcp/gs);
                puts("press enter to continue…");
                char dfslka=getchar();
                dfslka=getchar();
            }//数字
            else if(cpzl==4)
            {
                system("cls");
                puts("1.10元");
                puts("2.20元");
                puts("3.30元");
                puts("4.50元");
                puts("选择种类:");
                int zl;scanf("%d",&zl);
                if(zl==0)continue;
                if((zl==1&&ye<10)||(zl==2&&ye<20)||(zl==3&&ye<30)||(zl==4&&ye<50)){puts("余额不足…");_sleep(1000);continue;}
                int q;
                if(zl==1)q=rand()%21,ye-=10;
                if(zl==2)q=rand()%41,ye-=20;
                if(zl==3)q=rand()%61,ye-=30;
                if(zl==4)q=rand()%101,ye-=50;
                int sumcp=q;
                int len=0;
                memset(sm,-1,sizeof(sm));
                while(q)sm[++len]=q%10,q/=10;
                memset(f,0,sizeof(f));
                if(len==0)sm[1]=0;len=3;
                for(int i=len,x;i>=1;i--)
                {
                    /*
                      1
                     2 3
                      4
                     5 6
                      7
                    */
                    x=sm[i];
                    if(x==1)f[len-i][3]=f[len-i][6]=1;
                    if(x==2)f[len-i][3]=f[len-i][1]=f[len-i][4]=f[len-i][5]=f[len-i][7]=1;
                    if(x==3)f[len-i][3]=f[len-i][1]=f[len-i][4]=f[len-i][6]=f[len-i][7]=1;
                    if(x==4)f[len-i][3]=f[len-i][2]=f[len-i][4]=f[len-i][6]=1;
                    if(x==5)f[len-i][1]=f[len-i][2]=f[len-i][4]=f[len-i][6]=f[len-i][7]=1;
                    if(x==6)f[len-i][1]=f[len-i][2]=f[len-i][4]=f[len-i][6]=f[len-i][7]=f[len-i][5]=1;
                    if(x==7)f[len-i][1]=f[len-i][3]=f[len-i][6]=1;
                    if(x==8)f[len-i][1]=f[len-i][2]=f[len-i][3]=f[len-i][4]=f[len-i][5]=f[len-i][6]=f[len-i][7]=1;
                    if(x==9)f[len-i][1]=f[len-i][2]=f[len-i][3]=f[len-i][4]=f[len-i][6]=f[len-i][7]=1;
                    if(x==0)f[len-i][1]=f[len-i][2]=f[len-i][3]=f[len-i][5]=f[len-i][6]=f[len-i][7]=1;
                }
                for(int i=0;i<=31;i++)
                {
                    system("cls");
                    puts("--------------------------------");
                    printf("|");
                    for(int j=1;j<=i;j++){if(f[j/10][1]&&j%10>=2&&j%10<=7)printf("*");else printf(" ");}
                    for(int j=i;j<=30;j++)printf("?");puts("|");
                           
                    printf("|");for(int j=1;j<=i;j++){if((f[j/10][2]&&j%10==1)||(f[j/10][3]&&j%10==8))printf("*");else printf(" ");}
                    for(int j=i;j<=30;j++)printf("?");puts("|");
                    printf("|");for(int j=1;j<=i;j++){if((f[j/10][2]&&j%10==1)||(f[j/10][3]&&j%10==8))printf("*");else printf(" ");}
                    for(int j=i;j<=30;j++)printf("?");puts("|");
                    printf("|");for(int j=1;j<=i;j++){if((f[j/10][2]&&j%10==1)||(f[j/10][3]&&j%10==8))printf("*");else printf(" ");}
                    for(int j=i;j<=30;j++)printf("?");puts("|");
                           
                    printf("|");for(int j=1;j<=i;j++){if(f[j/10][4]&&j%10>=2&&j%10<=7)printf("*");else printf(" ");}
                    for(int j=i;j<=30;j++)printf("?");puts("|");
                           
                    printf("|");for(int j=1;j<=i;j++){if((f[j/10][5]&&j%10==1)||(f[j/10][6]&&j%10==8))printf("*");else printf(" ");}
                    for(int j=i;j<=30;j++)printf("?");puts("|");
                    printf("|");for(int j=1;j<=i;j++){if((f[j/10][5]&&j%10==1)||(f[j/10][6]&&j%10==8))printf("*");else printf(" ");}
                    for(int j=i;j<=30;j++)printf("?");puts("|");
                    printf("|");for(int j=1;j<=i;j++){if((f[j/10][5]&&j%10==1)||(f[j/10][6]&&j%10==8))printf("*");else printf(" ");}
                    for(int j=i;j<=30;j++)printf("?");puts("|");
                           
                    printf("|");for(int j=1;j<=i;j++){if(f[j/10][7]&&j%10>=2&&j%10<=7)printf("*");else printf(" ");}
                    for(int j=i;j<=30;j++)printf("?");puts("|");
                    puts("--------------------------------");
                    system("pause");
                }
                ye+=sumcp;
                printf("中了%d元！\n",sumcp);
                puts("press enter to continue…");
                char dfslka=getchar();
                dfslka=getchar();
            }//刮刮乐 
            else if(cpzl==36233){yandi();continue;}
            else if(cpzl==5)
            {
                system("cls");
                int sumcp=0;
                puts("买几张？");
                int gs;scanf("%d",&gs);
                if(gs==0)continue;
                if(gs*10>ye){puts("余额不足…");_sleep(1000);continue;}
                ye-=10*gs;
                system("cls");
                printf("输入%d组数字\n",gs);
                memset(shuzi,0,sizeof(shuzi));
                while(gs--)for(int i=1,x;i<=6;i++)scanf("%d",&x),shuzi[x]++;
                for(int i=1,x,sl=0;i<=6;i++)
                {
                    x=rand()%16+1;
                    printf("第%d个数是...",i);
                    _sleep(1000);
                    printf("%d!\n",x);
                    sumcp+=shuzi[x]*5;
                    //if(dsq&1<<x)sl++,sumcp+=sl*5;
                    _sleep(1000);
                }
                ye+=sumcp;
                printf("中了%d元！\n",sumcp);
                puts("press enter to continue…");
                char dfslka=getchar();
                dfslka=getchar();
            }//单色球 
            else if(cpzl==6)
            {
            	system("cls");
            	puts("_______________________________________________________");
            	puts("|                          |                          |");
            	puts("|        1.小（1~3）       |        2.大（4~6）       |");
            	puts("|__________________________|__________________________|");
            	puts("|                 |                 |                 |");
            	puts("|   3.小（1~2）   |   4.中（3~4）   |   5.大（5~6）   |");
            	puts("|_________________|_________________|_________________|");
            	puts("|        |        |        |        |        |        |");
            	puts("|   6.1  |   7.2  |   8.3  |   9.4  |  10.5  |  11.6  |");
            	puts("|________|________|________|________|________|________|");
            	puts("");
            	int gs;printf("买几张？");
            	scanf("%d",&gs);
            	if(gs==0)continue;
            	if(gs*10>ye){puts("余额不足…");_sleep(1000);continue;}
            	ye-=gs*10;
            	memset(cp6,0,sizeof(cp6));
            	int sumcp=0;
            	puts("买那些点？");
            	for(int i=1,x;i<=gs;i++)
            	{
            		scanf("%d",&x);
            		cp6[x]++;
				}
				system("cls");
				for(int i=1;i<=15;i++)
				{
					printf("%d",rand()%6+1);
					_sleep(40);
					system("cls");
				}
				for(int i=1;i<=10;i++)
				{
					printf("%d",rand()%6+1);
					_sleep(100);
					system("cls");
				}
				int ans=rand()%6+1;
				printf("%d",ans);
				_sleep(250);
				sumcp+=cp6[ans/4+1]*20+cp6[ans/3+3]*30+cp6[ans+5]*60;
				ye+=sumcp;
				puts("");
                printf("中了%d元！\n",sumcp);
                puts("press enter to continue…");
                char dfslka=getchar();
                dfslka=getchar();
			}
        }
        if(cz==2)
        {
            system("cls");
            puts("|~~~~~~~~~~~~~~~~~|");
            puts("|     无穷彩票    |");
            puts("|中i元概率：1/3*i |");
            puts("|      零售价:10元|");
            puts("|                 |");
            puts("~~~~~~~~~~~~~~~~~~~");
            puts("");
            puts("|~~~~~~~~~~~~~~~~~|");
            puts("|     传统彩票    |");
            puts("| 中10元概率：30% |");
            puts("| 中20元概率：10% |");
            puts("| 中50元概率：10% |");
            puts("|      零售价:10元|");
            puts("|                 |");
            puts("~~~~~~~~~~~~~~~~~~~");
            puts("");
            puts("|~~~~~~~~~~~~~~~~~|");
            puts("|     幸运数字    |");
            puts("|   大奖：100元   |");
            puts("|    差3：50元    |");
            puts("|    差5：30元    |");
            puts("|   差10：20元    |");
            puts("|   差15：10元    |");
            puts("|      零售价:20元|");
            puts("|                 |");
            puts("~~~~~~~~~~~~~~~~~~~");
            puts("");
            puts("|~~~~~~~~~~~~~~~~~|");
            puts("|      刮刮乐     |");
            puts("|      10:0~20    |");
            puts("|      20:0~40    |");
            puts("|      30:0~60    |");
            puts("|      50:0~100   |");
            puts("|      零售价:10元|");
            puts("|                 |");
            puts("~~~~~~~~~~~~~~~~~~~");
            puts("");
            puts("|~~~~~~~~~~~~~~~~~|");
            puts("|      单色球     |");
            puts("|   每张6个数     |");
            puts("|   每中一个5元   |");
            puts("|     零售价：10元|");
            puts("|                 |");
            puts("~~~~~~~~~~~~~~~~~~~");
            puts("");
            puts("press enter to continue…");
            char dfslka=getchar();
            dfslka=getchar();
        }
    }
}
