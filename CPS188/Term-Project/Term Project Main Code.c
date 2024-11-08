#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void quoteremover(char string[]) /*This user-defined function removes quotes from outputted strings that are actually numbers from the csv file. It makes it easier to use the string compare functions in the if statemetns below. It has one parameter, which is a string that is taken from the csv file*/
{
	int i=0, stringlen =strlen(string)-1;
	for (i=1;i<=stringlen;i++)
	{
			string[i-1]=string[i];
	}
	
}

void quoteforcharacter(char c[]) 
/*This function is very similar to the function above, it serves the same purpose but it is modified in a way so that it removes quotes from strings that are words. it is useful for us while comparing strings in the if statements below. */
{
    int i=0, j=0;
    for (i=0; i<strlen(c); i++) 
    {
        if(c[i] != '\"') 
        {
            c[j] = c[i];
            j++;
        }
    }
    c[j] = '\0';
}
double high(double array[])
{
  int i;
  double high=array[0];
  for(i=0;i<=28;i++)
  {
    if(high<array[i])
    {
      high=array[i];
    }
  }
  return(high);
}
double low(double array[])
{
  int i;
  double low=array[0];
  for(i=0;i<=28;i++)
  {
    if(low>array[i])
    {
      low=array[i];
    }
  }
  return(low);
}
  
int main(void) //main function
{
	FILE *data; // file pointer
	data = fopen("statscan_diabetes.csv", "r"); // open file in read mode
	char n[200], hprovince[200]; //string created to read the file row by row
	char*province,*age,*year,*percent,*lprovince; // variables crated per column
  
  double omax2015=0, qmax2015=0, brmax2015=0, amax2015=0, omax2016=0, omax2017=0, omax2018=0, omax2019=0, omax2020=0, omax2021=0, qmax2016=0, qmax2017=0, qmax2018=0, qmax2019=0, qmax2020=0, qmax2021=0, brmax2016=0, brmax2017=0, brmax2018=0, brmax2019=0, brmax2020=0, brmax2021=0, amax2016=0, amax2017=0, amax2018=0, amax2019=0, amax2020=0, amax2021=0;
	
  int qcount=0,ocount=0, brcount=0, acount=0, ccount=0, //"counter" variables created to use in the loop below, so that the average can be calculated
      ocount2015=0, ocount2016=0, ocount2017=0, ocount2018=0, ocount2019=0, ocount2020=0, ocount2021=0, 
      acount2015=0, acount2016=0, acount2017=0, acount2018=0, acount2019=0, acount2020=0, acount2021=0, 
      qcount2015=0, qcount2016=0, qcount2017=0, qcount2018=0, qcount2019=0, qcount2020=0, qcount2021=0, 
      brcount2015=0,brcount2016=0,brcount2017=0, brcount2018=0, brcount2019=0, brcount2020=0, brcount2021=0, 
      ccount2015=0, ccount2016=0, ccount2017=0, ccount2018=0, ccount2019=0, ccount2020=0, ccount2021=0, 
      ocount35to49=0, ocount50to64=0, ocount65=0, 
      acount35to49=0, acount50to64=0, acount65=0, 
      brcount35to49=0, brcount50to64=0, brcount65=0, 
      qcount35to49=0, qcount50to64=0, qcount65=0, 
      ccount35to49=0, ccount50to64=0, ccount65=0, k, hyear=0,lyear=0; 
  
  double qtotal=0, ototal=0, brtotal=0, atotal=0, ctotal=0, //"total" variables created to also use in the loop below so that for each row, the "total" value is updated
        ototal2015=0, ototal2016=0, ototal2017=0, ototal2018=0, ototal2019=0, ototal2020=0, ototal2021=0,
        qtotal2015=0, qtotal2016=0, qtotal2017=0, qtotal2018=0, qtotal2019=0, qtotal2020=0, qtotal2021=0,
        atotal2015=0, atotal2016=0, atotal2017=0, atotal2018=0, atotal2019=0, atotal2020=0, atotal2021=0, 
        brtotal2015=0, brtotal2016=0, brtotal2017=0, brtotal2018=0, brtotal2019=0, brtotal2020=0, brtotal2021=0, 
        ctotal2015=0, ctotal2016=0, ctotal2017=0, ctotal2018=0, ctotal2019=0, ctotal2020=0, ctotal2021=0, 
        ototal35to49=0, ototal50to64=0, ototal65=0, 
        atotal35to49=0, atotal50to64=0, atotal65=0, 
        brtotal35to49=0, brtotal50to64=0, brtotal65=0, 
        qtotal35to49=0, qtotal50to64=0, qtotal65=0, 
        ctotal35to49=0, ctotal50to64=0, ctotal65=0,highest=0,lowest=99999999;
  double ohigh=0, olow=9999;
  fgets(n,200,data); //first row scanned outside of loop below so that the file doesn't scan the column titles

  while((fgets(n,200,data))!=NULL) // main loop created to scan each important value in all scenarios. multiple if statemetns created below
	{
    if(strcmp(n,"\n")==0)
    {
      break;
    }
		year = strtok(n,",");
		province = strtok(NULL,",");		
		percent = strtok(NULL, ",");
		age = strtok(NULL,",");
		percent = strtok(NULL, ",");
		percent = strtok(NULL, ",");
		percent = strtok(NULL, ",");
		percent = strtok(NULL, ",");
		percent = strtok(NULL, ",");
		percent = strtok(NULL, ",");
		percent = strtok(NULL, ",");
		percent = strtok(NULL, ",");
		percent = strtok(NULL, ",");
		percent = strtok(NULL,",");
		
		quoteforcharacter(percent); //functions above used to remove quotations
    quoteforcharacter(year);
    quoteforcharacter(province);
// Finding Overall Max and Min Question 4
    
    if(highest<atof(percent) && atof(percent)!=0)
    {
      highest= atof(percent);
      hprovince[0] = province[0];
      hprovince[1] = province[1];
      hprovince[2] = province[2];
      hprovince[3] = province[3];
      hprovince[4] = province[4];
      hprovince[5] = province[5];
      hprovince[6] = province[6];

      hyear = atoi(year);
    }

    if(lowest>atof(percent) && atof(percent)!=0)
    {
      lowest = atof(percent);
      lprovince = province;
      lyear = atoi(year);
    }
    
    quoteforcharacter(age);

    //for each province (question 1a)
     
    /*means that if the province variable is so and so and the percent variable isn't 0, then the counter for quebec will increase by 1 and the total percentage will 
      be added to the previous value. this is done for each province to calculate the 4 averages in part 1 a*/
		if(strcmp(province, "Quebec")==0 && atof(percent)!=0)
		{
			qcount++;
      qtotal+=atof(percent);
		}
    
    if (strcmp(province, "Ontario")==0 && atof(percent) !=0)
		{
			ocount++;
      ototal+=atof(percent);
		}
    
    if(strcmp(province, "Alberta")==0 && atof(percent)!=0)
		{
			acount++;
      atotal+=atof(percent);
		}
    
   if(strcmp(province, "British Columbia")==0 && atof(percent)!=0)
		{
			brcount++;
      brtotal+=atof(percent);
		}
    
    //question 1b
    /*similar if statement as abov is used here to calculte the national average for part b*/
    if (strcmp(province, "Canada (excluding territories)")==0 && atof(percent)!=0)
    {
      ccount++;
      ctotal+=atof(percent);
    }
    
    //2015 all provinces (question 1c)
    if (strcmp(year, "2015")==0 && strcmp(province, "Ontario")==0 && atof(percent)!=0)
		{
			ocount2015++;
      ototal2015+=atof(percent);
      
		}

    if (strcmp(year, "2015")==0 && strcmp(province, "Quebec") && atof(percent)!=0)
		{
			qcount2015++;
      qtotal2015+=atof(percent);
		}
    
    if (strcmp(year, "2015")==0 && strcmp(province, "Alberta") && atof(percent)!=0)
    {
      acount2015++;
      atotal2015+=atof(percent); 
    }	
    if (strcmp(year, "2015")==0 && strcmp(province, "British Columbia") && atof(percent)!=0)
		{
			brcount2015++;
      brtotal2015+=atof(percent);
		}
    if (strcmp(year, "2015")==0 && strcmp(province, "Canada (excluding territories)") && atof(percent)!=0)
    {
      ccount2015++;
      ctotal2015+=atof(percent);
    }

    //2016 all provinces (question 1c)
    if (strcmp(year, "2016")==0 && strcmp(province, "Ontario") && atof(percent)!=0)
		{
			ocount2016++;
      ototal2016+=atof(percent);
		}

    if (strcmp(year, "2016")==0 && strcmp(province, "Quebec") && atof(percent)!=0)
		{
			qcount2016++;
      qtotal2016+=atof(percent);
		}
    
    if (strcmp(year, "2016")==0 && strcmp(province, "Alberta") && atof(percent)!=0)
    {
      acount2016++;
      atotal2016+=atof(percent); 
    }	
    if (strcmp(year, "2016")==0 && strcmp(province, "British Columbia") && atof(percent)!=0)
		{
			brcount2016++;
      brtotal2016+=atof(percent);
		}
    if (strcmp(year, "2016")==0 && strcmp(province, "Canada") && atof(percent)!=0)
		{
			ccount2016++;
      ctotal2016+=atof(percent);
		}

    //2017 all provinces (question 1c)
    if (strcmp(year, "2017")==0 && strcmp(province, "Ontario") && atof(percent)!=0)
		{
			ocount2017++;
      ototal2017+=atof(percent);
		}

    if (strcmp(year, "2017")==0 && strcmp(province, "Quebec") && atof(percent)!=0)
		{
			qcount2017++;
      qtotal2017+=atof(percent);
		}
    
    if (strcmp(year, "2017")==0 && strcmp(province, "Alberta") && atof(percent)!=0)
    {
      acount2017++;
      atotal2017+=atof(percent); 
    }	
    if (strcmp(year, "2017")==0 && strcmp(province, "British Columbia") && atof(percent)!=0)
		{
			brcount2017++;
      brtotal2017+=atof(percent);
		}
    if (strcmp(year, "2017")==0 && strcmp(province, "Canada") && atof(percent)!=0)
		{
			ccount2017++;
      ctotal2017+=atof(percent);
		}

    //2018 all provinces (question 1c)
    if (strcmp(year, "2018")==0 && strcmp(province, "Ontario") && atof(percent)!=0)
		{
			ocount2018++;
      ototal2018+=atof(percent);
		}

    if (strcmp(year, "2018")==0 && strcmp(province, "Quebec") && atof(percent)!=0)
		{
			qcount2018++;
      qtotal2018+=atof(percent);
		}
    
    if (strcmp(year, "2018")==0 && strcmp(province, "Alberta") && atof(percent)!=0)
    {
      acount2018++;
      atotal2018+=atof(percent); 
    }	
    if (strcmp(year, "2018")==0 && strcmp(province, "British Columbia") && atof(percent)!=0)
		{
			brcount2018++;
      brtotal2018+=atof(percent);
		}
    if (strcmp(year, "2018")==0 && strcmp(province, "Canada") && atof(percent)!=0)
		{
			ccount2018++;
      ctotal2018+=atof(percent);
		}

    //2019 all provinces (question 1c)
    if (strcmp(year, "2019")==0 && strcmp(province, "Ontario") && atof(percent)!=0)
		{
			ocount2019++;
      ototal2019+=atof(percent);
		}

    if (strcmp(year, "2019")==0 && strcmp(province, "Quebec") && atof(percent)!=0)
		{
			qcount2019++;
      qtotal2019+=atof(percent);
		}
    
    if (strcmp(year, "2019")==0 && strcmp(province, "Alberta") && atof(percent)!=0)
    {
      acount2019++;
      atotal2019+=atof(percent); 
    }	
    if (strcmp(year, "2019")==0 && strcmp(province, "British Columbia") && atof(percent)!=0)
		{
			brcount2019++;
      brtotal2019+=atof(percent);
		}
    if (strcmp(year, "2019")==0 && strcmp(province, "Canada") && atof(percent)!=0)
		{
			ccount2019++;
      ctotal2019+=atof(percent);
		}

    //2020 all provinces (question 1c)
    if (strcmp(year, "2020")==0 && strcmp(province, "Ontario") && atof(percent)!=0)
		{
			ocount2020++;
      ototal2020+=atof(percent);
		}

    if (strcmp(year, "2020")==0 && strcmp(province, "Quebec") && atof(percent)!=0)
		{
			qcount2020++;
      qtotal2020+=atof(percent);
		}
    
    if (strcmp(year, "2020")==0 && strcmp(province, "Alberta") && atof(percent)!=0)
    {
      acount2020++;
      atotal2020+=atof(percent); 
    }	
    if (strcmp(year, "2020")==0 && strcmp(province, "British Columbia") && atof(percent)!=0)
		{
			brcount2020++;
      brtotal2020+=atof(percent);
		}
    if (strcmp(year, "2020")==0 && strcmp(province, "Canada") && atof(percent)!=0)
		{
			ccount2020++;
      ctotal2020+=atof(percent);
		}
    
    //2021 all provinces (question 1c)
    if (strcmp(year, "2021")==0 && strcmp(province, "Ontario") && atof(percent)!=0)
		{
			ocount2021++;
      ototal2021+=atof(percent);
		}

    if (strcmp(year, "2021")==0 && strcmp(province, "Quebec") && atof(percent)!=0)
		{
			qcount2021++;
      qtotal2021+=atof(percent);
		}
    
    if (strcmp(year, "2021")==0 && strcmp(province, "Alberta") && atof(percent)!=0)
    {
      acount2021++;
      atotal2021+=atof(percent); 
    }	
    if (strcmp(year, "2021")==0 && strcmp(province, "British Columbia") && atof(percent)!=0)
		{
			brcount2021++;
      brtotal2021+=atof(percent);
		}
    if (strcmp(year, "2021")==0 && strcmp(province, "Canada") && atof(percent)!=0)
		{
			ccount2021++;
      ctotal2021+=atof(percent);
		}
    
    //ontario all age groups (question 1d)
    if (strcmp(province, "Ontario")==0 && strcmp(age,"35 to 49 years")==0 && atof(percent)!=0)
    {
      ocount35to49++;
      ototal35to49+=atof(percent);
    }
    if (strcmp(province, "Ontario")==0 && strcmp(age,"50 to 64 years")==0 && atof(percent)!=0)
    {
      ocount50to64++;
      ototal50to64+=atof(percent);
    }
    if (strcmp(province, "Ontario")==0 && strcmp(age,"65 years and over")==0 && atof(percent)!=0)
    {
      ocount65++;
      ototal65+=atof(percent);
    }
   //Alberta all age groups (question 1d)
    if (strcmp(province, "Alberta")==0 && strcmp(age,"35 to 49 years")==0 && atof(percent)!=0)
    {
      acount35to49++;
      atotal35to49+=atof(percent);
    }
    if (strcmp(province, "Alberta")==0 && strcmp(age,"50 to 64 years")==0 && atof(percent)!=0)
    {
      acount50to64++;
      atotal50to64+=atof(percent);
    }
    if (strcmp(province, "Alberta")==0 && strcmp(age,"65 years and over")==0 && atof(percent)!=0)
    {
      acount65++;
      atotal65+=atof(percent);
    }
   //British Columbia all age groups (Question 1d)
    if (strcmp(province, "British Columbia")==0 && strcmp(age,"35 to 49 years")==0 && atof(percent)!=0)
    {
      brcount35to49++;
      brtotal35to49+=atof(percent);
    }
    if (strcmp(province, "British Columbia")==0 && strcmp(age,"50 to 64 years")==0 && atof(percent)!=0)
    {
      brcount50to64++;
      brtotal50to64+=atof(percent);
    }
    if (strcmp(province, "British Columbia")==0 && strcmp(age,"65 years and over")==0 && atof(percent)!=0)
    {
      brcount65++;
      brtotal65+=atof(percent);
    }
    //Quebec all age groups (question 1d)
    if (strcmp(province, "Quebec")==0 && strcmp(age,"35 to 49 years")==0 && atof(percent)!=0)
    {
      qcount35to49++;
      qtotal35to49+=atof(percent);
    }
    if (strcmp(province, "Quebec")==0 && strcmp(age,"50 to 64 years")==0 && atof(percent)!=0)
    {
      qcount50to64++;
      qtotal50to64+=atof(percent);
    }
    if (strcmp(province, "Quebec")==0 && strcmp(age,"65 years and over")==0 && atof(percent)!=0)
    {
      qcount65++;
      qtotal65+=atof(percent);
    }
    //Canada all age groups (question 1d)
    if (strcmp(province, "Canada (excluding territories)")==0 && strcmp(age,"35 to 49 years")==0 && atof(percent)!=0)
    {
      ccount35to49++;
      ctotal35to49+=atof(percent);
    }
    if (strcmp(province, "Canada (excluding territories)")==0 && strcmp(age,"50 to 64 years")==0 && atof(percent)!=0)
    {
      ccount50to64++;
      ctotal50to64+=atof(percent);
    }
    if (strcmp(province, "Canada (excluding territories)")==0 && strcmp(age, "65 years and over")==0 && atof(percent)!=0)
    {
      ccount65++;
      ctotal65+=atof(percent);
    }
 
	}//end of while loop

    // the print statements are added  after the loop ends so that averages are only printed once and not the number of timnes the loop runs
  
  printf("\nQuestion 1.a");
  printf("\n The Average percentage of diabetes in Quebec is: %0.2lf", qtotal/qcount);
  printf("\n The Average percentage of diabetes in Ontario is: %0.2lf", ototal/ocount);
  printf("\n The Average percentage of diabetes in Alberta is: %0.2lf", atotal/acount);
  printf("\n The Average percentage of diabetes in British Columbia is: %0.2lf", brtotal/brcount);
  
  
  printf("\n\nQuestion 1.b");
  printf("\n The National average for all years and age group is: %0.2lf", ctotal/ccount);
  
  printf("\n\nQuestion 1.c");
  printf("\n The Average percentage of diabetes for Ontario in 2015 is: %0.2lf", ototal2015/ocount2015);
  printf("\n The Average percentage of diabetes for Quebec in 2015 is: %0.2lf", qtotal2015/qcount2015);
  printf("\n The Average percentage of diabetes for Alberta in 2015 is: %0.2lf", atotal2015/acount2015);
  printf("\n The Average percentage of diabetes for British Columbia in 2015 is: %0.2lf", brtotal2015/brcount2015);
  printf("\n The Average percentage of diabetes for Canada in 2015 is: %0.2lf", ctotal2015/ccount2015);
  
  printf("\n\n The Average percentage of diabetes for Ontario in 2016 is: %0.2lf", ototal2016/ocount2016);
  printf("\n The Average percentage of diabetes for Quebec in 2016 is: %0.2lf", qtotal2016/qcount2016);
  printf("\n The Average percentage of diabetes for Alberta in 2016 is: %0.2lf", atotal2016/acount2016);
  printf("\n The Average percentage of diabetes for British Columbia in 2016 is: %0.2lf", brtotal2016/brcount2016);
  printf("\n The Average percentage of diabetes for Canada in 2016 is: %0.2lf", ctotal2016/ccount2016);
  
  printf("\n\n The Average percentage of diabetes for Ontario in 2017 is: %0.2lf", ototal2017/ocount2017);
  printf("\n The Average percentage of diabetes for Quebec in 2017 is: %0.2lf", qtotal2017/qcount2017);
  printf("\n The Average percentage of diabetes for Alberta in 2017 is: %0.2lf", atotal2017/acount2017);
  printf("\n The Average percentage of diabetes for British Columbia in 2017 is: %0.2lf", brtotal2017/brcount2017);
  printf("\n The Average percentage of diabetes for Canada in 2017 is: %0.2lf", ctotal2017/ccount2017);

  printf("\n\n The Average percentage of diabetes for Ontario in 2018 is: %0.2lf", ototal2018/ocount2018);
  printf("\n The Average percentage of diabetes for Quebec in 2018 is: %0.2lf", qtotal2018/qcount2018);
  printf("\n The Average percentage of diabetes for Alberta in 2018 is: %0.2lf", atotal2018/acount2018);
  printf("\n The Average percentage of diabetes for British Columbia in 2018 is: %0.2lf", brtotal2018/brcount2018);
  printf("\n The Average percentage of diabetes for Canada in 2018 is: %0.2lf", ctotal2018/ccount2018);

  printf("\n\n The Average percentage of diabetes for Ontario in 2019 is: %0.2lf", ototal2019/ocount2019);
  printf("\n The Average percentage of diabetes for Quebec in 2019 is: %0.2lf", qtotal2019/qcount2019);
  printf("\n The Average percentage of diabetes for Alberta in 2019 is: %0.2lf", atotal2019/acount2019);
  printf("\n The Average percentage of diabetes for British Columbia in 2019 is: %0.2lf", brtotal2019/brcount2019);
  printf("\n The Average percentage of diabetes for Canada in 2019 is: %0.2lf", ctotal2019/ccount2019);

  printf("\n\n The Average percentage of diabetes for Ontario in 2020 is: %0.2lf", ototal2020/ocount2020);
  printf("\n The Average percentage of diabetes for Quebec in 2020 is: %0.2lf", qtotal2020/qcount2020);
  printf("\n The Average percentage of diabetes for Alberta in 2020 is: %0.2lf", atotal2020/acount2020);
  printf("\n The Average percentage of diabetes for British Columbia in 2020 is: %0.2lf", brtotal2020/brcount2020);
  printf("\n The Average percentage of diabetes for Canada in 2020 is: %0.2lf", ctotal2020/ccount2020);

  printf("\n\n The Average percentage of diabetes for Ontario in 2021 is: %0.2lf", ototal2021/ocount2021);
  printf("\n The Average percentage of diabetes for Quebec in 2021 is: %0.2lf", qtotal2021/qcount2021);
  printf("\n The Average percentage of diabetes for Alberta in 2021 is: %0.2lf", atotal2021/acount2021);
  printf("\n The Average percentage of diabetes for British Columbia in 2021 is: %0.2lf", brtotal2021/brcount2021);
  printf("\n The Average percentage of diabetes for Canada in 2021 is: %0.2lf", ctotal2021/ccount2021);
  
  
  printf("\n\nQuestion 1.d");
  printf("\n The Average percentage of diabetes in Ontario for ages 35 to 49 is: %0.2lf", ototal35to49/ocount35to49);
  printf("\n The Average percentage of diabetes in Ontario for ages 50 to 64 is: %0.2lf", ototal50to64/ocount50to64);
  printf("\n The Average percentage of diabetes in Ontario for ages 65 and over is: %0.2lf", ototal65/ocount65);

  printf("\n\n The Average percentage of diabetes in Alberta for ages 35 to 49 is: %0.2lf", atotal35to49/acount35to49);
  printf("\n The Average percentage of diabates in Alberta for ages 50 to 64 is: %0.2lf", atotal50to64/acount50to64);
  printf("\n The Average percentage of diabetes in Alberta for ages 65 and over is: %0.2lf", atotal65/acount65);

  printf("\n\n The Average percentage of diabetes in British Columbia for ages 35 to 49 is: %0.2lf", brtotal35to49/brcount35to49);
  printf("\n The Average percentage of diabetes in British Columbia for ages 50 to 64 is: %0.2lf", brtotal50to64/brcount50to64);
  printf("\n The Average percentage of diabetes in British Columbia for ages 65 and over is: %0.2lf", brtotal65/brcount65);

  printf("\n\n The Average percentage of diabetes in Quebec for ages 35 to 49 is: %0.2lf", qtotal35to49/qcount35to49);
  printf("\n The Average percentage of diabetes in Quebec for ages 50 to 64 is: %0.2lf", qtotal50to64/qcount50to64);
  printf("\n The Average percentage of diabetes in Quebec for ages 65 and over is: %0.2lf", qtotal65/qcount65);

  printf("\n\n The Average percentage of diabetes in Canada (excluding territories) for ages 35 to 49 is : %0.2lf", ctotal35to49/ccount35to49);
  printf("\n The Average percentage of diabetes in Canada (excluding territories) for ages 50 to 64 is: %0.2lf", ctotal50to64/ccount50to64);
  printf("\n The Average percentage of diabetes in Canada (excluding territories) for ages 65 and over is: %0.2lf", ctotal65/ccount65);


//question 2
/*this question asks us to find the provinces with the higest percentage, so all we did was compare the averages with each other and added a print statement for
  each if statement*/
  
  printf("\n\nQuestion 2"); 
  
  if ((qtotal/qcount) > (ototal/ocount) && (qtotal/qcount) > (atotal/acount) && (qtotal/qcount) > (brtotal/brcount))
  {
    printf("\n The province with the highest percentage of diabetes for all years and age groups is Quebec and its average is: %0.2lf", qtotal/qcount);
  }
  
  if ((ototal/ocount) > (qtotal/qcount) && (ototal/ocount) > (atotal/acount) && (ototal/ocount) > (brtotal/brcount))
  {
    printf("\n The province with the highest percentage of diabetes for all years and age groups is Ontario and its average is: %0.2lf", ototal/ocount);
  }
  
  if ((atotal/acount) > (qtotal/qcount) && (atotal/acount) > (ototal/ocount) && (atotal/acount) > (brtotal/brcount))
  {
    printf("\n The province with the highest percentage of diabetes for all years and age groups is Alberta and its average is: %0.2lf", atotal/acount);
  }

  if ((brtotal/brcount) > (qtotal/qcount) && (brtotal/brcount) > (ototal/ocount) && (brtotal/brcount) > (atotal/acount))
  {
    printf("\n The province with the lowest percentage of diabetes for all years and age groups is British Columbia and its average is: %0.2lf", brtotal/brcount);
  }

  if ((qtotal/qcount) < (ototal/ocount) && (qtotal/qcount) < (atotal/acount) && (qtotal/qcount) < (brtotal/brcount))
  {
    printf("\n The province with the lowest percentage of diabetes for all years and age groups is Quebec and its average is: %0.2lf", qtotal/qcount);
  }
  
  if ((ototal/ocount) < (qtotal/qcount) && (ototal/ocount) < (atotal/acount) && (ototal/ocount) < (brtotal/brcount))
  {
    printf("\n The province with the lowest percentage of diabetes for all years and age groups is Ontario and its average is: %0.2lf", ototal/ocount);
  }
  
  if ((atotal/acount) < (qtotal/qcount) && (atotal/acount) < (ototal/ocount) && (atotal/acount) < (brtotal/brcount))
  {
    printf("\n The province with the lowest percentage of diabetes for all years and age groups is Alberta and its average is: %0.2lf", atotal/acount);
  }

  if ((brtotal/brcount) < (qtotal/qcount) && (brtotal/brcount) < (ototal/ocount) && (brtotal/brcount) < (atotal/acount))
  {
    printf("\n The province with the lowest percentage of diabetes for all years and age groups is British Columbia and its average is: %0.2lf", brtotal/brcount);
  }

    //question 3
  printf("\n\nQuestion 3");
  if ((qtotal/qcount) > (ctotal/ccount))
  {
    printf("\n Quebec's average diabetes percentage is higher than the national average");
  }
  
  if ((ototal/ocount) > (ctotal/ccount))
  {
    printf("\n Ontario's average diabetes percentage is higher than the national average");
  }
  
  if ((atotal/acount) > (ctotal/ccount))
  {
    printf("\n Alberta's average diabetes percentage is higher than the national average");
  }
  
  if ((brtotal/brcount) > (ctotal/ccount))
  {
    printf("\n British Columbia's average diabetes percentage is higher than the national average");
  }

  if ((qtotal/qcount) < (ctotal/ccount))
  {
    printf("\n Quebec's average diabetes percentage is lower than the national average");
  }
  
  if ((ototal/ocount) < (ctotal/ccount))
  {
    printf("\n Ontario's average diabetes percentage is lower than the national average");
  }
  
  if ((atotal/acount) < (ctotal/ccount))
  {
    printf("\n Alberta's average diabetes percentage is lower than the national average");
  }
  
  if ((brtotal/brcount) < (ctotal/ccount))
  {
    printf("\n British Columbia's average diabetes percentage is lower than the national average");
  }
  
  //Question 4
  printf("\n\nQuestion 4");
  printf("\n Highest: %s %d %.2lf", hprovince, hyear, highest);
  printf("\n Lowest: %s %d %.2lf", lprovince, lyear, lowest);  
 
  
  //Question 5

  //the output for this question is a graph with 5 plots on it. the graph, created through gnuplot is attached in the report
  FILE *ontario;
  ontario = fopen("ontario.data", "w");
  fprintf(ontario, "2015\t\t %lf", (ototal2015/ocount2015));
  fprintf(ontario, "\n2016\t\t %lf", (ototal2016/ocount2016));
  fprintf(ontario, "\n2017\t\t %lf", (ototal2017/ocount2017));
  fprintf(ontario, "\n2018\t\t %lf", (ototal2018/ocount2018));
  fprintf(ontario, "\n2019\t\t %lf", (ototal2019/ocount2019));
  fprintf(ontario, "\n2020\t\t %lf", (ototal2020/ocount2020));
  fprintf(ontario, "\n2021\t\t %lf", (ototal2021/ocount2021));
  
  fclose(ontario);
  
  FILE *quebec;
  quebec = fopen("quebec.data", "w");
  fprintf(quebec, "2015\t\t %lf", (qtotal2015/qcount2015));
  fprintf(quebec, "\n2016\t\t %lf", (qtotal2016/qcount2016));
  fprintf(quebec, "\n2017\t\t %lf", (qtotal2017/qcount2017));
  fprintf(quebec, "\n2018\t\t %lf", (qtotal2018/qcount2018));
  fprintf(quebec, "\n2019\t\t %lf", (qtotal2019/qcount2019));
  fprintf(quebec, "\n2020\t\t %lf", (qtotal2020/qcount2020));
  fprintf(quebec, "\n2021\t\t %lf", (qtotal2021/qcount2021));
  
  fclose(quebec);
  
  FILE *alberta;
  alberta = fopen("alberta.data", "w");
  fprintf(alberta, "2015\t\t %lf", (atotal2015/acount2015));
  fprintf(alberta, "\n2016\t\t %lf", (atotal2016/acount2016));
  fprintf(alberta, "\n2017\t\t %lf", (atotal2017/acount2017));
  fprintf(alberta, "\n2018\t\t %lf", (atotal2018/acount2018));
  fprintf(alberta, "\n2019\t\t %lf", (atotal2019/acount2019));
  fprintf(alberta, "\n2020\t\t %lf", (atotal2020/acount2020));
  fprintf(alberta, "\n2021\t\t %lf", (atotal2021/acount2021));
  
  fclose(alberta);
  
  FILE *british_columbia;
  british_columbia = fopen("british_columbia.data", "w");
  fprintf(british_columbia, "2015\t\t %lf", (brtotal2015/brcount2015));
  fprintf(british_columbia, "\n2016\t\t %lf", (brtotal2016/brcount2016));
  fprintf(british_columbia, "\n2017\t\t %lf", (brtotal2017/brcount2017));
  fprintf(british_columbia, "\n2018\t\t %lf", (brtotal2018/brcount2018));
  fprintf(british_columbia, "\n2019\t\t %lf", (brtotal2019/brcount2019));
  fprintf(british_columbia, "\n2020\t\t %lf", (brtotal2020/brcount2020));
  fprintf(british_columbia, "\n2021\t\t %lf", (brtotal2021/brcount2021));
  
  fclose(british_columbia);
  
  FILE *canada;
  canada = fopen("canada.data", "w");
  fprintf(canada, "2015\t\t %lf", (ctotal2015/ccount2015));
  fprintf(canada, "\n2016\t\t %lf", (ctotal2016/ccount2016));
  fprintf(canada, "\n2017\t\t %lf", (ctotal2017/ccount2017));
  fprintf(canada, "\n2018\t\t %lf", (ctotal2018/ccount2018));
  fprintf(canada, "\n2019\t\t %lf", (ctotal2019/ccount2019));
  fprintf(canada, "\n2020\t\t %lf", (ctotal2020/ccount2020));
  fprintf(canada, "\n2021\t\t %lf", (ctotal2021/ccount2021));
  
  fclose(canada);

  //Question 6
  //this is also a graphing question. the graph, created through gnuplot is attached in the report
  FILE *canada_age_groups;
  canada_age_groups = fopen("canada_age_groups.txt", "w");

  fprintf(canada_age_groups, "35-49\t%lf", (ctotal35to49/ccount35to49));
  fprintf(canada_age_groups, "\n50-64\t%lf", (ctotal50to64/ccount50to64));
  fprintf(canada_age_groups, "\n65+\t%lf", (ctotal65/ccount65));
  
  fclose(data);


	return 0;
}

