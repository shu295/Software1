#include<stdio.h>
#include<string.h>//ֻ��һ������
#include<math.h>
char list[11][5]={"��","һ","��","��","��","��","��","��","��","��","ʮ"}; //��Ǻ���
int flag=0;
int swap(char a[]){   //������ת��Ϊ����
    int i;
    for(i=0;i<11;i++){
        if(strcmp(list[i],a)==0){ //strcmp�ж��Ƿ����
            return i;
        }
    }
}

int bai(char a[]){//��λ��������
	char b[10],c[10],d[10];
	if(strlen(a)==4){
		b[0]=a[0];
		b[1]=a[1];
		b[2]='\0';
		return swap(b)*100;//��Ӧ�������͵�����
	}
	else if(strlen(a)==6){
		b[0]=a[4];//ʮλ
		b[1]=a[5];
		b[2]='\0';
		c[0]=a[0];//��λ
		c[1]=a[1];
		c[2]='\0';
		return swap(b)*10+swap(c)*100;//��Ӧһ�ټ����͵�����
	}	
	else if(strlen(a)==8){
        b[0]=a[6];//��λ
        b[1]=a[7];
        b[2]='\0';
        c[0]=a[4];//ʮλ
        c[1]=a[5];
        c[2]='\0';
		d[0]=a[0];//��λ
        d[1]=a[1];
        d[2]='\0';
		if(swap(b)!=10) 
			return swap(b)+swap(d)*100;//��Ӧ"һ���㼸�����͵�����
		else
			return swap(d)*100+swap(c)*10;//��Ӧ"һ�ټ�ʮ�����͵�����
    }
	else if(strlen(a)==10){
        b[0]=a[8];//��λ
        b[1]=a[9];
        b[2]='\0';
        c[0]=a[4];//ʮλ
        c[1]=a[5];
        c[2]='\0';
		d[0]=a[0];//��λ
        d[1]=a[1];
        d[2]='\0';
        return swap(b)+swap(c)*10+swap(d)*100;//��Ӧ��һ�ټ�ʮ�������͵�����
	}
}


int num(char a[]){//�����ַָ��ת�������ֵ���ʽ
    char b[10],c[10],d[10];
	char r[3]="��",e[3]="ʮ";
	int i;
	if((a[2]==r[0])&&(a[3]==r[1]))//�ж������Ƿ���λ����	
		flag=1;//��
	else
		flag=0;
	if(flag==1){
		return bai(a);
	}
	else
	{
		if(strlen(a)==2){//һ�������������ֽڱ�ʾ
			return swap(a); //��Ӧ��һ���ȵ�������
		}
		else if(strlen(a)==4){
			b[0]=a[2];
			b[1]=a[3];
			b[2]='\0';      
				if(swap(b)!=10) return 10+swap(b);//��Ӧʮһ��ʮ������ʮ��ͷ����������
				else{
					b[0]=a[0];
					b[1]=a[1];
					b[2]='\0';
					return 10*swap(b);//��Ӧ��ʮ����ʮ����ʮ��β������
				}
		}
		else if(strlen(a)==6){
			b[0]=a[4];//��λ
			b[1]=a[5];
			b[2]='\0';
			c[0]=a[0];//��λ����ʮλ����λ���İ�λ
			c[1]=a[1];
			c[2]='\0';
			d[0]=a[2];//��λ����ʮλ
			d[1]=a[3];
			d[2]='\0';
			for(i=0;i<strlen(a);i+=2){//�ж������Ƿ���λ����
				if((a[i]==e[0])&&(a[i+1]==e[1])){
					return swap(b)+swap(c)*10;//��Ӧ����ʮ�������͵�����
				}
				else
					return swap(b)+swap(d)*10+swap(c)*100;//��Ӧһ���㣬�����������͵�����
			}
		}	
	}
}



int suan(int n,char a[],char b[]){//�������
    int sum1;
    sum1=num(b);//�����ָ�ֵ��sum1
    if(strcmp(a,"����")==0) return n+sum1;
    else if(strcmp(a,"����")==0) return n-sum1;
    else if(strcmp(a,"��")==0) return n*sum1;
    else if(strcmp(a,"����")==0)return n/sum1;		
}

char kan(char a[],char m[]){
	int i;
	if(!strcmp(a,"����")){
		for(i=1;i<strlen(m)-2;i=i+2)
			printf("%c%c",m[i],m[i+1]);
		printf("\n");
		return 0;
	}
}

char out(int sum){
	if(sum>=0&&sum<=10){//��λ�����
        printf("%s\n",list[sum]);
	}
    else if(sum<=99){
        if(sum%10==0){
            printf("%sʮ\n",list[sum/10]);
			return 0;
		}
        else if(sum<=19){
            printf("ʮ%s\n",list[sum%10]);
			return 0;
        }
        else {
            printf("%sʮ%s\n",list[sum/10],list[sum%10]);
			return 0;
        }
    } 
	else 
		{//��λ�����
			flag=1;
            if(sum%100==0){
                printf("%s��\n",list[sum/100]);
				return 0;
			}
            else if(sum%10==0){
				printf("%s��%sʮ\n",list[sum/100],list[(sum/10)%10]);
				return 0;
			}
			else if((sum/10)%10==0){
				printf("%s����%s\n",list[sum/100],list[sum%10]);
				return 0;
			}
			else{ 
				printf("%s��%sʮ%s\n",list[sum/100],list[(sum/10)%10],list[sum%10]); 
				return 0;
			}
		}   
}

int main(){
    int i,sum,l,sum1,h;
    char a[100],b[100],c[100],d[100],e[100],m[100],k[100],a1[100],c1[100];
	char r[3]="��",g[3]="��";
	a:scanf("%s",a);
	while(1){
			if(!strcmp(a,"����")||!strcmp(d,"����")){
			memset(c, 0, sizeof (c)); 
			scanf("%s %s %s",a,b,c);
			if(strcmp(a,a1)!=0){//�ж��Ƿ����±���  
				h=1;
			}
			else
				h=0;
			for(i=0;i<strlen(c);i+=2){//�ж������Ƿ�Ϊ����
				if((c[i]==r[0])&&(c[i+1]==r[1]))
				{	printf("����������Ŷ�����������\n");
					goto a;
				}
				else if((c[i]==g[0])&&(c[i+1]==g[1]))//һ��ʼ����Ϊ����
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
			printf("�����ʽ����(�����ʽ����������Ǯ�������ڣ�ʮ),����������\n");
			scanf("%s %s %s",a,b,c);
			goto a;
		}
		printf("%d\n",sum);//���Ե㣺������ת���������Ƿ���ȷ��
		k:while(scanf("%s",d)!=EOF){//�ж������Ƿ����
			  if(strcmp(a,d)==0){ //��������������ظ����ò鿴����
				  scanf("%s %s",b,c);
				  if((strcmp(c,"��")==0)&&(strcmp(b,"����")==0))
					  printf("��������Ϊ��Ŷ");
				  else
				  {
					  sum=suan(sum,b,c);
					  printf("%d\n",sum);//���Ե㣺����sum�Ƿ�������ȷ  
				  }			 
			  }
			  else if(strcmp(a1,d)==0){
				  scanf("%s %s",b,c);	
				  if((strcmp(c,"��")==0)&&(strcmp(b,"����")==0))
					  printf("��������Ϊ��Ŷ");
				  else
				  {
					  sum1=suan(sum1,b,c);
					  printf("%d\n",sum1);//���Ե㣺����sum�Ƿ�������ȷ  
				  }			 
			  }
			  else if(strcmp(d,"���")==0)
			  {
				  scanf("%s %s %s",b,e,m);
				  l=num(m);
				  if(strcmp(a,b)==0 || strcmp(a1,b)==0){
					scanf("%s %s %s",d,b,m);
					if(strcmp(e,"����")==0){
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
								if((strcmp(d,"����")==0)&&strcmp(b,"��")!=0)
									kan(b,m);
							}
							else{
								scanf("%s %s %s",d,b,m);
								if((strcmp(d,"����")==0)&&strcmp(b,"��")!=0)
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
								if((strcmp(d,"����")==0)&&strcmp(b,"��")!=0)
									kan(b,m);
							}
							else{
								scanf("%s %s %s",d,b,m);
								if((strcmp(d,"����")==0)&&strcmp(b,"��")!=0)
									kan(b,m);
							}
						}
					}
				}
			  }
			  else if(!strcmp(d,"����")){
				scanf("%s",b);
				flag=0;
				if(strcmp(b,a1)==0)
				{
					if(sum1<0)
					{//�������
						printf("��");
						out(abs(sum1));
					}
					else
						out(sum1);
				}
				else
				{
					if(sum<0)
					{//�������
						printf("��");
						out(abs(sum));
					}
					else
						out(sum);
				}
			}
			  else if(!strcmp(d,"����"))
				break;
		  }
		  if(h==1){
			for(i=0;i<strlen(a);i++)//�������
			{
				a1[i]=a[i];	
			}
			a1[i]='\0';;
			sum1=sum;//������ֵ
		  }		  
}
return 0;       
}