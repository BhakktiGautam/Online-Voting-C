#include<stdio.h>
#include<string.h>
struct Candidate{
	int candidate_id;
	char firstname[50];
	char lastname[50];
	char symbol[45];
	int votes;
};

struct Voter{
	int voter_id;
	char firstname[50];
	char lastname[50];
	int has_voted;
};
struct Candidate candidate_list[100];
struct Voter voter_list[5000];
int Votes_cast=0;
int total_candidates=0;
int total_voters=0;
void add_candidates()
{
	printf("---------Enter Candidate details--------\n");
	printf("Enter the candidate ID:\n");
	scanf("%d",&candidate_list[total_candidates].candidate_id);
	printf("Enter the firstname of candidate :\n");
	scanf("%s",candidate_list[total_candidates].firstname);
	printf("Enter the lastname of candidate:\n");
	scanf("%s",candidate_list[total_candidates].lastname);
	printf("Enter the symbol of the party to which candidate belongs:\n");
	scanf("%s",candidate_list[total_candidates].symbol);
	printf("Enter the no. of votes given to candidate:\n");
	scanf("%d",&candidate_list[total_candidates].votes);
	printf("Record added successfully\n");
	total_candidates++;
}
void register_voters()
{
	printf("---------Enter Voter details--------\n");
	printf("Enter the Voter ID :\n");
	scanf("%d",&voter_list[total_voters].voter_id);
	printf("Enter the Firstname of voter:\n");
	scanf("%s",voter_list[total_voters].firstname);
	printf("Enter the lastname of voter:\n");
	scanf("%s",voter_list[total_voters].lastname);
	printf("Enter the status of voting of the voter:\n");
	scanf("%d",&voter_list[total_voters].has_voted);
	printf("Voter registered successfully\n");
	total_voters++;
}
void display_candidates()
{
	
	for(int n=0;n<total_candidates;n++)
	{
	printf("--------------------CANDIDATE DETAILS---------------------\n");
	printf("Candidate ID:%d\n",candidate_list[n].candidate_id);
	printf("Name:%s ",candidate_list[n].firstname);
	printf("%s\n",candidate_list[n].lastname);
	printf("Symbol:%s\n",candidate_list[n].symbol);
	printf("Votes :%d\n",candidate_list[n].votes);
	printf("-----------------------------------------------------------\n");
	}
}
void result()
{
		printf("---------------Result of Election----------------\n");
		int max_votes=0;
		int winner_index;
		printf("%-15s %-10s %-10s","CandidateID","Votes","Percentage");
		printf("-------------------------------\n");
		for(int e=0;e<total_candidates;e++)
		{
			printf("%-15d",candidate_list[e].candidate_id);
			printf("%-10d",candidate_list[e].votes);
			float percentage=((float)candidate_list[e].votes/total_voters)*100;
			printf("%-10.2f\n",percentage);
		}

		for(int i=0;i<total_candidates;i++)
		{
			if(candidate_list[i].votes>max_votes)
			{
					max_votes=candidate_list[i].votes;
					winner_index=i;
			}
			
		}
		printf("Winner Candidate ID:%d\n",candidate_list[winner_index].candidate_id);
}

void castvote()
{
	int found=0,id;
	char smbl[15];
	printf("Enter voter ID:\n");
	scanf("%d",&id);
	for(int s=0;s<total_voters;s++)
	{
		if(voter_list[s].voter_id==id)
		{
			if(voter_list[s].has_voted==0)
			{
				printf("Enter the symbol you want to vote\n");
				scanf("%s",smbl);
				for(int d=0;d<total_candidates;d++)
				{
					if(strcmp(candidate_list[d].symbol,smbl)==0)
					{
						candidate_list[d].votes+=1;
						Votes_cast++;
						voter_list[s].has_voted=1;
						found=1;
						break;
					}
				}
			
		}
			else
			{
				printf("Already Voted\n");
				found=1;
			}
	}
if(found==0)
{
	printf("Either voter or candidate not found\n");
}
}}
	
void votingstats()
{
	float turnout;
	printf("Total Votes :%d\n",total_voters);
	printf("Votes Cast :%d\n",Votes_cast);
	turnout=((float)Votes_cast/total_voters)*100;
	printf("Turnout:%.2f\n",turnout);
}


int main()
{
	int choice;
	printf("=======================================\n");
	printf("         1 ONLINE VOTING SYSTEM         \n");
	printf("=======================================\n");
	do{
	printf("1.Add Candidates\n2.Add voters\n3.Cast Vote\n4.Show Candidates\n5.Show results\n6.Voting Statistics\n7.Exit\n");
	printf("Enter your choice:\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		add_candidates();
	}
	else if(choice==2)
	{
		register_voters();
	}
	else if(choice==3)
	{
		castvote();
	}
	else if(choice==4)
	{
		display_candidates();
	}
	else if(choice==5)
	{
		result();
	}
	else if(choice==6)
	{
		votingstats();
	}
	else if(choice==7)
	{
		printf("Returning to console.......\n");
		break;
	}
	else
		printf("Invalid input\n");
	}while(choice!=7);
return 0;
}
	


























