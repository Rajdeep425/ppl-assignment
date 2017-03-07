#include <iostream>
using namespace std;

struct node
{
	int value;
	node *link;
	
};

node *insert(node *start,node *end)
{	
	node *newnode=new node();
	if(start==NULL)
		{
			start = newnode;
		}
	if(end!=NULL)
		{
			end->link=newnode;
		}
	end=newnode;
	newnode->link=NULL;
	int num,l,i;
	cin>>num;
	switch(num)
	{
		case 1: l= 1;
			break;
		case 2: l= 2;
			break;
		case 3: l= 3;
			break;
		case 4: l= 4;
			break;
		case 5: l= 5;
			break;
		case 6: l= 6;
			break;
		case 7: l= 7;
			break;
		case 8: l= 8;
			break;
		case 9: l= 9;
			break;
		case 0: l= 0;
			break;
		case 99: i= 99;
		default: break;	
	}
	if(i!=99)
		{
			newnode->value=l;	
			insert(start,end);
		}
	return start;
}

node *reverse(node *start)
{	
	node *startrev=NULL;
	for(;start!=NULL;start=start->link)
	{
		node *newnode=new node();
		newnode->value=start->value;
		newnode->link=startrev;
		startrev=newnode;
	}
	
	return startrev;
}

int add(node *s1,node *s2)
{	
	int carry=0,sum;
	node *startr =NULL;
	node *endr =NULL;
	
	cout<<"Addition is: "<<endl;
	
	while(s1!=NULL || s2!=NULL)
	{	
		sum = carry + (s1? s1->value: 0) + (s2? s2->value: 0);
 		carry = (sum >= 10)? 1 : 0;;
		sum=sum%10;
		
		node *newnode = new node();
		if(startr==NULL)
		{
			startr = newnode;
		}
		if(endr!=NULL)
		{
			endr->link=newnode;
		}
		endr=newnode;
		newnode->link=NULL;
		newnode->value=sum;
		
		if(s1!=NULL)
			s1=s1->link;
		if(s2!=NULL)
			s2=s2->link;
		
	}
	
	if(carry>0)
	{
		node *newnode = new node();
		endr->link=newnode;
		endr=newnode;
		newnode->link=NULL;
		newnode->value=carry;
	}
	
	
	
	node *finalstart=reverse(startr);
	cout<<endl;
	for(;finalstart->link!=NULL;finalstart=finalstart->link)
		cout<<finalstart->value;
	cout<<endl;
	
	return 0;
}

int main()
{
	node *start1 = NULL;
	node *end1 = NULL;
	node *start2 = NULL;
	node *end2 = NULL;
	cout<<"\nINSEERT FIRST NUMBER(MSB to LSB One digit at a time): ";
	cout<<endl<<"\n\"PRESS 99 WHEN FINISHED\"\t(It'll not be included in your number)\n\n1\t2\t3\n\n4\t5\t6\n\n7\t8\t9\n\n\t0"<<endl;
	start1=insert(start1,end1);
	cout<<endl<<"INSERT SECOND NUMBER(MSB to LSB One digit at a time): ";
	cout<<endl<<"\n\"PRESS 99 WHEN FINISHED\"\t(It'll not be included in your number)\n\n1\t2\t3\n\n4\t5\t6\n\n7\t8\t9\n\n\t0"<<endl;
	start2=insert(start2,end2);
	node *start3=reverse(start1);
	node *start4=reverse(start2);
	
	add(start3,start4);
	
	return 0;
}