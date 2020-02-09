## 作业要求

1.  发布一篇随笔，使用markdown语法进行编辑。
2.  在随笔前附上github仓库地址。

## 编程题目

汉字是迄今为止持续使用时间最长的文字，也是上古时期各大文字体系中唯一传承至今者，中国历代皆以汉字为主要的官方文字。我们在感叹汉字的源远流长时，也不禁感慨，为什么没有一门使用汉字编程的语言？  
小杨同学想到：用汉字来进行编程一定很有趣，来请你帮帮他。

### 编程要求

请编写一个程序，制作一个简易的中文语言编译器，即使用中文语法进行编程，输入为逐行输入，每行为一个语句，一个语句代变一个操作，满足以下语法要求（括号内代变格式类型，具体参考样例）：

-   变量定义：整数 （变量名） 等于 （数字）
-   运算（加法）：（变量名） 增加 （数字）
-   运算（减法）：（变量名） 减少 （数字）
-   输出：看看 （变量名） or 看看 “（字符串内容）”

附加要求：

-   选择：如果 （判断语句） 则 （操作语句） 否则 （操作语句）  
    若否则后没有任何操作使用（无）来进行填充（参考样例2）。

#### 样例1

输入：

```
整数 气温 等于 十
气温 减少 三
气温 增加 二
看看 气温
如果 气温 大于 八 则 看看 “你好，世界” 否则 看看 “冻死我了”
```

输出：

```
九
你好，世界
```

#### 样例2

输入:

```
整数 小杨年龄 等于 八
整数 小杨零花钱 等于 二
小杨年龄 增加 一
如果 小杨年龄 大于 八 则 小杨零花钱 增加 一 否则 无
看看 小杨零花钱
```

输出：

```
三
```

#### 注意事项

1.  输入输出采用utf-8编码，请在编码过程中注意。
2.  数字只会出现：零一二三四五六七八九十。(此条作废，可先完成0-10的情况)
3.  字符串输出的双引号是全角，即中文双引号。
4.  变量类型要求只有整数，如有余力，可以自己实现更多。
5.  测试数据会相较于样例复杂，请考虑充分需求。
6.  不限制编程语言。
7.  不能使用eval函数动态执行代码，或调用系统指令。
8.  数据输入形式为交互式运行，类似于shell。

## 记录

|代码行数|240行|
|-- |-- |
|需求分析时间|先是用十几分钟分析十以内的加减法，之后是一边写代码一边分析|
|编码时间|四舍五入约为一天|

## 分析
### 需求的思路
 1. 将汉字转换成数字，将数字转换成汉字
 2. 增加对于变量的运算
 3. 增加变量的判断
 4. 考虑三位数的输入，负数的输入，循环输入等情况
 5. 增加多个变量

### 分解成多个模块

 -  将汉字转换为数字
 ```
 int swap(char a[]){   //将汉字转换为数字
    int i;
    for(i=0;i<11;i++){
        if(strcmp(list[i],a)==0){ //strcmp判断是否相等
            return i;
        }
    }
}
```
- 将汉字分割，再转换成数字的形式
```
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
```
- 三位数的输入
```
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
```
- 运算部分
```
int suan(int n,char a[],char b[]){//运算符号
    int sum1;
    sum1=num(b);//将数字赋值给sum1
    if(strcmp(a,"增加")==0) return n+sum1;
    else if(strcmp(a,"减少")==0) return n-sum1;
    else if(strcmp(a,"乘")==0) return n*sum1;
   else if(strcmp(a,"除")==0) {return n/sum1;
	}
}
```
- 将数字转换成汉字
```
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
```
- main函数中包含了是否为新增加的变量（用h来判断，若是新增加的则为1，否则为零），用flag判断输入是否三位数（若是则flag为1，否则为0），判断输入是否为整数，一开始输入是否为负数，以及判断变量大于小于的语句，代码见完整代码处

### 为什么这样区分模块
区分出来的模块都是在运行代码的过程中需要反复用到的
区分出来这些模块可以减少代码量，并且便于出错的检查
## 目前还存在的问题

 1. 目前的代码只有支持两个变量。
 2. 目前代码的数据量只能从-999到999。
 3. 只考虑到了三位数例如一百用一零零表示的情况，没有考虑到两位数例如十二用一二表示的情况。
 4. 变量类型要求只有整数
 5. 还有很多问题和没有考虑到，没有考虑周全。
 6. 代码量太大，没有进行简化。
 7. 在编写代码的过程中，犯了很多低级错误。
 8. 编写的代码是很基础的，导致编写代码的时间太长。
 9. 还没有尝试用python或者Java写。
 ## 编辑代码中不会的知识
 
 1.在将汉字转换为数字的过程中 ，没有考虑到一个汉字占两个字节。参考链接：[enter link description here](https://zhidao.baidu.com/question/40819718.html)
 2.c语言中goto语句的用法，参考链接：[enter link description here](https://baike.baidu.com/item/goto%E8%AF%AD%E5%8F%A5/7603004?fr=aladdin)

 ## 完整代码（代码中含有两个测试点）
 ```
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
 ```
 ## 测试
 #### 测试一
 输入
 ```
 整数 小杨年龄 等于 八 
 整数 小杨零花钱 等于 二 
 小杨年龄 增加 一 如果 小杨年龄 大于 八 则 小杨零花钱 增加 一 否则 无 
 看看 小杨零花钱
 整数 气温 等于 十 
 气温 减少 三 
 气温 增加 二 
 看看 气温 
 如果 气温 大于 八 则 看看 “你好，世界” 否则 看看 “冻死我了”
 ```
 输出
 ![enter image description here](https://images.cnblogs.com/cnblogs_com/shu295/1644272/t_2002090818571.PNG?a=1581236331702)
 #### 测试二
 输入
 ```
 小数 气温 等于 三
 整数 气温 等于 三点三
 整数 钱包 等于 负四百二十
 看看 钱包
 钱包 增加 一百三十二
 看看 钱包
 钱包 增加 一百
 看看 钱包
钱包 减少 一百零二
 看看 钱包
 如果 钱包 大于 一百 则 看看 "好多钱" 否则 看看 "好穷"
 整数 压岁钱 等于 一百
 看看 压岁钱
 如果 钱包 大于 一百 则 压岁钱 增加 一 否则 无
 钱包 增加 四百
 如果 钱包 大于 一百 则 压岁钱 增加 一 否则 无
 看看 压岁钱
 如果 钱包 等于 一百 则 看看 "好多钱" 否则 看看 "好穷"
 ```
 输出
![enter image description here](https://images.cnblogs.com/cnblogs_com/shu295/1644272/t_2002090842552.PNG)
