#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<varchar.h>
#define SIZE 2000
typedef struct student
{
	int roll;
	varchar name;
}student;
void main()
{
	student s[100];
	int max_size,i,j,trunc,m,n,flag=0;
	char f,c;
	do
	{
		flag=0;
		clrscr();
		printf("\n\t\t\t\t***VARCHAR DATATYPE***\n");
		printf("\nEnter maximum size of varchar: ");
		scanf("%d",&max_size);
		if(max_size>SIZE)
		{
			flag=1;
			printf("Maximum size entered is invalid. The length exceeds the limit.\nEnter a valid size.\nPress enter to continue.\n");
			getch();
		}
		else
		{
			printf("\nEnter number of students: ");
			scanf("%d",&n);
			printf("\nEnter the details for %d students : ",n);
			for(i=0;i<n;i++)
			{
				s[i].name = create();
				scanf("%c",&f);
				printf("\n\tEnter the name of the student : ");
				while(c!='\n')
				{
					scanf("%c",&c);
					insertend(&s[i].name,c);

				}
				trunc = len(&s[i].name) - max_size -1;
				if(trunc>0)
				printf("* Note : Length exceeds the limit. Hence %d characters will be stored. *\n",max_size);
				for(j=1;j<=trunc;j++)
				{
					delend(&s[i].name);
				}
				printf("\tEnter roll no: ");
				scanf("%d",&s[i].roll);
				c='\0';
			}
			clrscr();
			printf("The records are :\n");
			printf("\nSr No.\tRoll No\tName\t\tLength\n\n");
			for(i=0;i<n;i++)
			{
				printf("%d\t",i+1);
				printf("%d\t",s[i].roll);
				m = (len(&s[i].name)>max_size)?max_size:len(&s[i].name);
				somedisplay(&s[i].name,m);
				printf("\t\t%d\n\n",varlen(&s[i].name));
			}
		}
	}while(flag==1);
	getch();
}
