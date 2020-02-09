#include<stdio.h>
#include<string.h>//只有一个变量
#include<math.h>
char list[11][5]={"零","一","二","三","四","五","六","七","八","九","十"}; //标记汉字
int flag=0;
int swap(char a[]){   //将汉字转换为数字
    int i;
    for(i=0;i<11;i++){
        if(strcmp(list[i],a)==0){ //strcmp判断是否相等
            return i;
        }
    }
}

int bai(char a[]){//三位数的输入
	char b[10],c[10],d[10];
	if(strlen(a)==4){
		b[0]=a[0];
		b[1]=a[1];
		b[2]='\0';
		return swap(b)*100;//对应几百类型的数字
	}
	else if(strlen(a)==6){
		b[0]=a[4];//十位
		b[1]=a[5];
		b[2]='\0';
		c[0]=a[0];//百位
		c[1]=a[1];
		c[2]='\0';
		return swap(b)*10+swap(c)*100;//对应一百几类型的数字
	}	
	else if(strlen(a)==8){
        b[0]=a[6];//个位
        b[1]=a[7];
        b[2]='\0';
        c[0]=a[4];//十位
        c[1]=a[5];
        c[2]='\0';
		d[0]=a[0];//百位
        d[1]=a[1];
        d[2]='\0';
		if(swap(b)!=10) 
			return swap(b)+swap(d)*100;//对应"一百零几”类型的数字
		else
			return swap(d)*100+swap(c)*10;//对应"一百几十”类型的数字
    }
	else if(strlen(a)==10){
        b[0]=a[8];//个位
        b[1]=a[9];
        b[2]='\0';
        c[0]=a[4];//十位
        c[1]=a[5];
        c[2]='\0';
		d[0]=a[0];//百位
        d[1]=a[1];
        d[2]='\0';
        return swap(b)+swap(c)*10+swap(d)*100;//对应“一百几十几”类型的数字
	}
}


int num(char a[]){//将汉字分割，再转换成数字的形式
    char b[10],c[10],d[10];
	char r[3]="百",e[3]="十";
	int i;
	if((a[2]==r[0])&&(a[3]==r[1]))//判断输入是否三位数啊	
		flag=1;//是
	else
		flag=0;
	if(flag==1){
		return bai(a);
	}
	else
	{
		if(strlen(a)==2){//一个汉字用两个字节表示
			return swap(a); //对应零一二等单个汉字
		}
		else if(strlen(a)==4){
			b[0]=a[2];
			b[1]=a[3];
			b[2]='\0';      
				if(swap(b)!=10) return 10+swap(b);//对应十一、十二等以十开头的两个汉字
				else{
					b[0]=a[0];
					b[1]=a[1];
					b[2]='\0';
					return 10*swap(b);//对应二十、三十等以十结尾的数字
				}
		}
		else if(strlen(a)==6){
			b[0]=a[4];//个位
			b[1]=a[5];
			b[2]='\0';
			c[0]=a[0];//两位数的十位，三位数的百位
			c[1]=a[1];
			c[2]='\0';
			d[0]=a[2];//三位数的十位
			d[1]=a[3];
			d[2]='\0';
			for(i=0;i<strlen(a);i+=2){//判断输入是否三位数啊
				if((a[i]==e[0])&&(a[i+1]==e[1])){
					return swap(b)+swap(c)*10;//对应“几十几”类型的数字
				}
				else
					return swap(b)+swap(d)*10+swap(c)*100;//对应一零零，二四三等类型的数字
			}
		}	
	}
}



int suan(int n,char a[],char b[]){//运算符号
    int sum1;
    sum1=num(b);//将数字赋值给sum1
    if(strcmp(a,"增加")==0) return n+sum1;
    else if(strcmp(a,"减少")==0) return n-sum1;
    else if(strcmp(a,"乘")==0) return n*sum1;
    else if(strcmp(a,"除以")==0)return n/sum1;		
}

char kan(char a[],char m[]){
	int i;
	if(!strcmp(a,"看看")){
		for(i=1;i<strlen(m)-2;i=i+2)
			printf("%c%c",m[i],m[i+1]);
		printf("\n");
		return 0;
	}
}

char out(int sum){
	if(sum>=0&&sum<=10){//两位数输出
        printf("%s\n",list[sum]);
	}
    else if(sum<=99){
        if(sum%10==0){
            printf("%s十\n",list[sum/10]);
			return 0;
		}
        else if(sum<=19){
            printf("十%s\n",list[sum%10]);
			return 0;
        }
        else {
            printf("%s十%s\n",list[sum/10],list[sum%10]);
			return 0;
        }
    } 
	else 
		{//三位数输出
			flag=1;
            if(sum%100==0){
                printf("%s百\n",list[sum/100]);
				return 0;
			}
            else if(sum%10==0){
				printf("%s百%s十\n",list[sum/100],list[(sum/10)%10]);
				return 0;
			}
			else if((sum/10)%10==0){
				printf("%s百零%s\n",list[sum/100],list[sum%10]);
				return 0;
			}
			else{ 
				printf("%s百%s十%s\n",list[sum/100],list[(sum/10)%10],list[sum%10]); 
				return 0;
			}
		}   
}

int main(){
    int i,sum,l,sum1,h;
    char a[100],b[100],c[100],d[100],e[100],m[100],k[100],a1[100],c1[100];
	char r[3]="点",g[3]="负";
	a:scanf("%s",a);
	while(1){
			if(!strcmp(a,"整数")||!strcmp(d,"整数")){
			memset(c, 0, sizeof (c)); 
			scanf("%s %s %s",a,b,c);
			if(strcmp(a,a1)!=0){//判断是否是新变量  
				h=1;
			}
			else
				h=0;
			for(i=0;i<strlen(c);i+=2){//判断输入是否为整数
				if((c[i]==r[0])&&(c[i+1]==r[1]))
				{	printf("请输入整数哦，重新输入吧\n");
					goto a;
				}
				else if((c[i]==g[0])&&(c[i+1]==g[1]))//一开始输入为负数
				{
					for(i=0;i<=strlen(c)-2;i++){
						c[i]=c[i+2];
					}
					sum=-num(c);
				}
				else
					sum=num(c);
					
			}
		}
		else{
			printf("输入格式错误(输入格式例：整数，钱包，等于，十),请重新输入\n");
			scanf("%s %s %s",a,b,c);
			goto a;
		}
		printf("%d\n",sum);//测试点：（测试转换成数字是否正确）
		k:while(scanf("%s",d)!=EOF){//判断输入是否结束
			  if(strcmp(a,d)==0){ //可在运算过程中重复运用查看功能
				  scanf("%s %s",b,c);
				  if((strcmp(c,"零")==0)&&(strcmp(b,"除以")==0))
					  printf("除数不能为零哦");
				  else
				  {
					  sum=suan(sum,b,c);
					  printf("%d\n",sum);//测试点：测试sum是否运算正确  
				  }			 
			  }
			  else if(strcmp(a1,d)==0){
				  scanf("%s %s",b,c);	
				  if((strcmp(c,"零")==0)&&(strcmp(b,"除以")==0))
					  printf("除数不能为零哦");
				  else
				  {
					  sum1=suan(sum1,b,c);
					  printf("%d\n",sum1);//测试点：测试sum是否运算正确  
				  }			 
			  }
			  else if(strcmp(d,"如果")==0)
			  {
				  scanf("%s %s %s",b,e,m);
				  l=num(m);
				  if(strcmp(a,b)==0 || strcmp(a1,b)==0){
					scanf("%s %s %s",d,b,m);
					if(strcmp(e,"大于")==0){
						if(sum>l|| sum1>l){
							if(strcmp(a,b)==0){
								scanf("%s",k);
								sum=suan(sum,m,k);
								scanf("%s %s",b,m);
							}
							else if(strcmp(a1,b)==0){
								scanf("%s",k);
								sum1=suan(sum1,m,k);
								scanf("%s %s",b,m);
							}
							else{
								kan(b,m);	
								scanf("%s %s %s",d,b,m);
							}
							
						}
						else{
							if(strcmp(a,b)==0 || strcmp(a1,b)==0){
								scanf("%s %s",d,b);
								if((strcmp(d,"否则")==0)&&strcmp(b,"无")!=0)
									kan(b,m);
							}
							else{
								scanf("%s %s %s",d,b,m);
								if((strcmp(d,"否则")==0)&&strcmp(b,"无")!=0)
									kan(b,m);
							}
						}
					}
					else{
						if(sum<l || sum<l){
							if(strcmp(a,b)==0){
								scanf("%s",k);
								sum=suan(sum,m,k);
								scanf("%s %s",b,m);
							}
						    else if(strcmp(a1,b)==0){
								scanf("%s",k);
								sum1=suan(sum1,m,k);
								scanf("%s %s",b,m);
							}
							else{
								kan(b,m);
								scanf("%s %s %s",d,b,m);
							}
							
						}
						else{
							if(strcmp(a,b)==0 || strcmp(a1,b)==0){
								scanf("%s %s",d,b);
								if((strcmp(d,"否则")==0)&&strcmp(b,"无")!=0)
									kan(b,m);
							}
							else{
								scanf("%s %s %s",d,b,m);
								if((strcmp(d,"否则")==0)&&strcmp(b,"无")!=0)
									kan(b,m);
							}
						}
					}
				}
			  }
			  else if(!strcmp(d,"看看")){
				scanf("%s",b);
				flag=0;
				if(strcmp(b,a1)==0)
				{
					if(sum1<0)
					{//负数输出
						printf("负");
						out(abs(sum1));
					}
					else
						out(sum1);
				}
				else
				{
					if(sum<0)
					{//负数输出
						printf("负");
						out(abs(sum));
					}
					else
						out(sum);
				}
			}
			  else if(!strcmp(d,"整数"))
				break;
		  }
		  if(h==1){
			for(i=0;i<strlen(a);i++)//保存变量
			{
				a1[i]=a[i];	
			}
			a1[i]='\0';;
			sum1=sum;//保存数值
		  }		  
}
return 0;       
}