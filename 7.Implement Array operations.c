#include <stdio.h>
int arr[20],n,i,pos,ele;


int main()
{
int create();
int Display();
int delete();
int search();
int insert();
int op;
char ch='y';
do
{printf("\nSelect the operations from the below...\n");
printf("1--> Create\n2--> Delete\n3--> Search\n4--> Insert\n5--> Display\n6--> Exit\n");
printf("Enter Your Choice:");
scanf("%d",&op);
if(op==1)
{create();}
else if(op==2)
{delete();}
else if(op==3)
{search();}
else if(op==4)
{insert();}
else if(op==5)
{Display();}
else if(op==6)
{break;}
else
printf("Invalid Option");
}
while(ch=='y'||ch=='Y');
scanf("%c",&ch);
}


int create()
{
printf("Enter the number of elements to be created:");
scanf("%d",&n);
printf("Enter the elements:");
for(i=0;i<n;i++)
{scanf("%d",&arr[i]);}
}
int delete()
{printf("\n Enter the position u want to delete::");
scanf("%d", &pos);
if(pos>=n)
{printf("\n Invalid Location::");}
else
{for(i=pos+1;i<n;i++)
{arr[i-1]=arr[i];}
n--;}
printf("\n The Elements after deletion:");
for(i=0;i<n;i++)
{printf("\t%d", arr[i]);}
}

int search()
{printf("\n Enter the Element to be searched:");
scanf("%d", &ele);
int pos,flag=0;
for(i=0;i<n;i++)
{if(arr[i]==ele)
{flag=1;
pos=i;
break;}
}
if(flag==1)
{printf("Element is found at %d Position", pos+1);}
else
{printf("Element not found");}
}
int insert()
{
printf("\n Enter the position u need to insert::");
scanf("%d", &pos);
if(pos>=n)
{
printf("\n invalid Location::");
}
else
{
for(i=20-1;i>=pos-1;i--)
{arr[i+1]=arr[i];}
printf("\n Enter the element to insert::\n");
scanf("%d",&ele);
arr[pos]=ele;
n++;
}}
int Display()
{
printf("The elements of array are....");
for(i=0;i<n;i++)
{printf(" %d",arr[i]);}
}