#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include <time.h>

// DEKLARIM I FUNKSIONEVE
void  MenuKryesore();
void regjistroprofesor();
void regjistroStudent();
void modifikoprofesor();
void modifikoStudent();
void afishoProfesoret();
void afishoStudentet();
void rregjistropyetjet();
void afishopiket();
void raporte();
void shikopiket();
void profesor();
void filloprovimin();
void ndryshimfjalkalimi();
void numeropyetjet();



struct profesor              //struktura me te dhenat e profesoreve
{
    int ID;
    char EmerPerdorues[20];
   int fjalkalimi;
    char Statusi[20];
    char lenda[20];
}p;
long pi = sizeof(p);
struct student                  //struktura me te dhenat e studenteve
{
    int IDP;
    char emerPerdorues[20];
    int fjalekalimi;
    char statusi[20];
    int piket;
    char moment[20];

}s;
long si = sizeof(s);

struct admin       // struktura me te dhenat e adminit
{
	char e[10];
	char p[10];
	char moment[20];
  char lend[20];
}a;
struct gabim{     // ruhen pyetjat e gabuara
  char pyetja[100];
  int id;
  char lenda[20];
}h;
long hi = sizeof(h);

struct pyetje{    // Ruhen te gjitha pyetjet dhe pergjigjet e profesorit.

	char pyetja[1000];
     char pergj[100];
char pergj1[100];
char pergj2[100];
    char pergj3[100];
    char profesor[20];
    char sakt;
     int piket;
     char lenda[20];
     int shuma;
     char moment[100];
     char sakt2;
}d;

struct nota{        // Ruhen piket e studentit
	char lenda[10];
	char emri[20];
	int piket;
	char pw[20];
	char prof[20];
	int id;

}n;
FILE *fp;

void administrator(){        // Menu e administratorit
	struct admin e={"GlenLohja","glen1234"};
    char emri[10];
    char pw[10];
    char zgjedhja;
    int nrId=1;
    int c;
    system("CLS");
    printf("\n\n\n\t\t\tShkruani emrin e Administratorit : ");
    scanf("%s",emri);
    printf("\n\t\t\tShkruani fjalekalimin : ");
    scanf("%s",pw);

      if((strcmp(emri,e.e)==0)&&(strcmp(pw,e.p)==0))
    {
    	back:
    	 system("CLS");
	    printf("\n\n\t\t\tPershendetje %s , Miresevini ne menune e administratorit.\n\n",e.e);
                      printf("\n\t\t\t1-Shto profesore\n");
                      printf("\n\t\t\t2-Shto studente\n");
                      printf("\n\t\t\t3-Ndrysho statusin e  profesorit\n");
                      printf("\n\t\t\t4-Ndrysho statusin e  studentit\n");
                      printf("\n\t\t\t5-Afisho te dhenat e profesoreve\n");
                     printf("\n\t\t\t6-Afisho te dhenat e studenteve\n");
                     printf("\n\t\t\t7-Ndrysho fjalekalimet.");
                     printf("\n\n\t\t\tA-Dil");
                     printf("\n\t\t\tZgjedhja : ");
                          char c;
						  c=getch();
						 do{

						  if(c=='1')   {      // rregjistrojme profesore
                        regjistroprofesor();
                         goto back;
					   }
                          else if(c=='2'){      // rregjistrojme student
                        regjistroStudent();
					 goto back;; }
                       else if(c=='3'){      // modifikojme statusin e profesorit
                       modifikoprofesor();
					      goto back;
					   }
					   else if(c=='4'){     // modifikojme statusin e studentit
					   	modifikoStudent();
					   	 goto back;
					   }
					   else if(c=='5'){
					   	afishoProfesoret();             // RAPORT EXTRA
					   	 goto back;
					   }
					   else if(c=='6'){
					   	afishoStudentet();              // RAPORT EXTRA
					   	 goto back;
					   }
					   else if(c=='7'){           // ndryshim fjalekalimi
					   ndryshimfjalkalimi();
					   goto back;
					   }
               }
                 while ((c!='a') && (c!='A'));
                system("CLS");
                  return ;
									  }         
                    printf("\n\t\t\tFjalekalimi ose emermbiemri eshte gabim .");
                    printf("\n\n\t\t\tShtyp nje task per te dalur nga menuja .... ");
                    getch();
                    return ;

            fclose(fp);



	}

void profesor(){
	char emri[20];
    int fjalekalim;
    system("CLS");
     printf("\n\t\t\tShkruani emrin e profesorit : ");
   fflush(stdin);
   gets(emri);
   printf("\n\n\t\t\tShkruani fjalekalimin: ");
   fflush(stdin);
   scanf("%d",&fjalekalim);
   fp=fopen("profesore.txt","rb+");
   while(fread(&p,pi,1,fp)==1){
  if((strcmp(emri,p.EmerPerdorues)==0)&&
  fjalekalim==p.fjalkalimi){
  	strcpy(a.moment,emri);
    strcpy(a.lend,p.lenda);
   repeat:
   	system("CLS");
   	fflush(stdin);
	          printf("\n\n\t\t\tPershendetje %s , Miresevini ne menune e profesorit.\n\n",emri);
                      printf("\n\t\t\t1-Harto provimin\n");
                      printf("\n\t\t\t2-Shiko rezultatet e provimit.\n");
                      printf("\n\t\t\t3-Raporte\n");
                     printf("\n\t\t\tA-Dil");
                     printf("\n\t\t\tZgjedhja : ");
	                     char c;
						  c=getch();

						  if(c=='1')   {
                       rregjistropyetjet();
                         goto repeat;
					   }
                          else if(c=='2'){
                        shikopiket();
					 goto repeat; }
                       else if(c=='3'){
                       raporte();
					      goto repeat;}
  	                 else if((c=='a')||(c=='A'))
                         	return ;
                         	  else if((c!='1')||(c!='2')||(c!='3'));
                       return;
  }
}

	  printf("\n\t\t\tEmri i perdoruesit ose fjalekalimi i shkruar eshte gabim ....");
             printf("\n\n\t\t\tShtyp nje tast per t'u larguar..");
             getch();
             return;
}

void student(){             // MENU E STUDENTIT
char em[20];
    int fj;
    char c;
    system("CLS");
     printf("\n\t\t\tShkruani emrin e studentit : ");
   fflush(stdin);
   gets(em);
   printf("\n\n\t\t\tShkruani fjalekalimin: ");
   fflush(stdin);
   scanf("%d",&fj);
   fp=fopen("student.txt","rb+");
   while(fread(&s,si,1,fp)==1){
  if((strcmp(em,s.emerPerdorues)==0)&&
  (fj==s.fjalekalimi)){
    strcpy(s.moment,em);
  rep: 
  	system("CLS");
	       printf("\n\n\t\t\tPershendetje %s , Miresevini ne menune e studentit.\n\n",em);
	              printf("\n\t\t\t1-Merr provimin\n");
                printf("\n\t\t\t2-Shiko rezultatet e provimit.\n");
                     printf("\n\t\t\tA-Dil");
					 c=getch();
                         if(c=='1')   {
                       filloprovimin();
                         goto rep;
					   }
                          else if(c=='2'){
                        afishopiket();
					 goto rep; }
  	                 else if((c=='a')||(c=='A'))
                         	return ;
                       else if((c!='1')||(c!='2'));
                       return;

}
}
printf("\n\t\t\tPasswordi ose emri i dhene eshte gabim..");
printf("\n\t\t\tShtyp nje tast per te dal...");
getch();
return;
}



void regjistroprofesor()                     //funksioni qe regjistron te dhenat per profesorin
{

    char zgjedhja;
    int nrId=1;
    int c;
    int len=0;
 	char emerPerdorues[20];
	int y,i,sum=0;
	int pw;
    system("CLS");
     a:
		fp=fopen("profesore.txt","rb");
		while(fread(&p,sizeof(p),1,fp)==1){
			if(nrId==p.ID){
    		nrId++;
    	}
		}
	fclose(fp);

    system("CLS");
    printf("                                Regjistrimi i Profesorit\n                                       ");
    	fp=fopen("profesore.txt","ab");
    printf("\n\t\t\tEmri i perdoruesit(emermbiemer): ");
    fflush(stdin);
    p.ID=nrId;                       
    gets(p.EmerPerdorues);
                strcpy(emerPerdorues,p.EmerPerdorues);
                len = strlen(emerPerdorues);
                for(y=0;y<len;y++)
                {
                	sum=sum+emerPerdorues[y];                  
				}
				     pw=p.ID*sum;
                printf("\n\t\t\tFjalkalimi gjeneruar : %d \n",pw);
          p.fjalkalimi=pw;
          printf("\n\t\t\tShkruani emrin e lendes qe jep profesori : ");
          fflush(stdin);
          gets(p.lenda);
    printf("\n\t\t\tStatusi i profesorit: ");
     fflush(stdin);
    gets(p.Statusi);
    printf("\n\n\t\t\t**Regjistrimi u krye me sukses!\n\n");
     fwrite(&p,sizeof(p),1,fp);
    printf("\t\t\tShtyp nje task per te vazhduar ...\n");
  getch();

            fclose(fp);

}


void regjistroStudent()          // funksioni qe regjistron te dhenat per cdo student
{

    char zgjedhja;
    int nrIdStudent=1;
    int len;
 	char emerPerdorues[20];
    char w;
    int y,i,sum=0;
	int pw;
    system("CLS");
      loops:
			fp=fopen("student.txt","rb");
		while(fread(&s,sizeof(s),1,fp)==1){
			if(nrIdStudent==s.IDP){
    		nrIdStudent++;
    	}
		}
	fclose(fp);
    system("CLS");
    printf("                           Regjistrimi i Studentit\n                           ");
    fp=fopen("student.txt","ab");
      printf("\n\t\t\tEmri i perdoruesit(emermbiemer): ");
    fflush(stdin);
    s.IDP=nrIdStudent;
    gets(s.emerPerdorues);
       strcpy(emerPerdorues,s.emerPerdorues);
                len = strlen(emerPerdorues);
                for(y=0;y<len;y++)
                {
                	sum=sum+emerPerdorues[y];
				}
				     pw=s.IDP*sum;
				     printf("\n\t\t\tFjalkalimi gjeneruar : %d \n",pw);
          s.fjalekalimi=pw;
    printf("\n\t\t\tStatusi i studentit: ");
    scanf("%s",s.statusi);
    printf("\n\n\t\t\t**Regjistrimi u krye me sukses!\n\n");
     fwrite(&s,sizeof(s),1,fp);
   printf("\t\t\tShtyp nje task per te vazhduar ...\n");
  getch();



    fclose(fp);

}

void ndryshimfjalkalimi(){    // ne kete funksion behet reset fjalekalimi
	system("cls"); 
	char c;
  int len;
    char w;
    int y,i,sum=0;
	int pw;
	printf("\n\n\t\t\t1.Ndrysho fjalkalimin per Profesor.\n");
	printf("\n\t\t\t2.Ndrysho fjalkalimin per student.");
	  printf("\n\n\t\t\tA-Dil");
    printf("\n\t\t\tZgjedhja : ");
	c=getch();
	if(c=='1'){
		 char emer[20];
   int f=0;
   system("CLS");
   printf("\n\t\t\tShkruani emrin e profesorit : ");
   scanf("%s",emer);
      fp=fopen("profesore.txt","rb+");
  srand(time(NULL));   
int r = rand() % 20;
   while(fread(&p,sizeof(p),1,fp)==1){
   if(strcmpi(emer,p.EmerPerdorues)==0){
                len = strlen(emer);
                for(y=0;y<len;y++)
                {
                	sum=sum+emer[y];
				}
         pw=r*sum;
         printf("\n\t\t\tFjalkalimi i ri  : %d \n",pw);
          p.fjalkalimi=pw;
   f=1;
   fflush(stdin);
   fseek(fp,-pi,1);
   fwrite(&p,sizeof(p),1,fp);
   fclose(fp);

   break;
	}
}
if(f==0)
printf("\n\t\t\tProfesori qe ju kerkoni nuk eshte i rregjisturar");
else
printf("\n\t\t\tFjalekalimi u ndryshua me sukses");
printf("\n\n\t\t\tShtyp nje task per te vazhduar ...\n");
  getch();
}
if(c=='2'){
	char emri[20];
  int id=1;
   int f=0;
   system("CLS");
   printf("\n\t\t\tShkruani emrin e nxenesit : ");
   scanf("%s",emri);
   fp=fopen("student.txt","rb+");
   srand(time(NULL));   
int r = rand() % 20;
   while(fread(&s,sizeof(s),1,fp)==1){
   if(strcmpi(emri,s.emerPerdorues)==0){
     len = strlen(emri);
                for(y=0;y<len;y++)
                {
                	sum=sum+emri[y];
				}
				     pw=id*sum;
				     printf("\n\t\t\tFjalkalimi i ri  : %d \n",pw);
          s.fjalekalimi=pw;
   f=1;
   fseek(fp,-si,1);
   fwrite(&s,sizeof(s),1,fp);
   fclose(fp);

}
}
if(f==0){

printf("\n\t\t\tStudenti qe ju kerkoni nuk eshte i rregjisturar");}

else
printf("\n\t\t\tStatusi u ndryshua me sukses");
printf("\n\t\t\tShtyp nje task per te vazhduar ...\n");
  getch();
}

if((c=='a')||(c='A'))
return;
}


void afishoProfesoret()                      // funksioni qe afishon te dhenat per profesoret (EXTRA)
{
    system("CLS");
    printf("\t\t\tProfesoret e regjistruar\n");
        printf("\t\t\tID           Emri            Fjalekalimi            Statusi\n");
  FILE *fp;
  fp=fopen("profesore.txt","rb");
  while(fread(&p,sizeof(p),1,fp)==1){
  	    printf("\t\t\t%d           %s                %d            %s   \n",p.ID,p.EmerPerdorues,p.fjalkalimi,p.Statusi);
  }
  fclose(fp);
  printf("\n\t\t\tShtyp nje task per te vazhduar ...");
  getch();
}


void afishoStudentet()                   //funksioni qe afishon te dhenat per studenteve(EXTRA)
{
  system("CLS");
    printf("\n\n\t\t\tStudentet  e regjistruar\n");
        printf("\t\t\tID          Emri            Fjalekalimi            Statusi        \n");
  FILE *fp;
  fp=fopen("student.txt","rb");
  while(fread(&s,sizeof(s),1,fp)==1){
  	    printf("\t\t\t%d          %s                %d           %s        \n",s.IDP,s.emerPerdorues,s.fjalekalimi,s.statusi);
  }
  fclose(fp);
  printf("\t\t\tShtyp nje task per te vazhduar ...\n");
  getch();
}

void modifikoprofesor()           //funksioni qe modifikon statusin per cdo profesor te rregjistruar
{
   char emer[20];
   int f=0;
   system("CLS");
   printf("\n\t\t\tShkruani emrin e profesorit : ");
   scanf("%s",emer);
   fp=fopen("profesore.txt","rb+");
   while(fread(&p,sizeof(p),1,fp)==1){
   if(strcmpi(emer,p.EmerPerdorues)==0){
   f=1;
   printf("\n\t\t\tShkruani Statusin e ri(aktiv ose i larguar ) :");
   fflush(stdin);
   gets(p.Statusi);
   fseek(fp,-pi,1);
   fwrite(&p,sizeof(p),1,fp);
   fclose(fp);

   break;

}
}
if(f==0)
printf("\n\t\t\tProfesori qe ju kerkoni nuk eshte i rregjisturar");
else
printf("\n\t\t\tStatusi u ndryshua me sukses");
printf("\n\n\t\t\tShtyp nje task per te vazhduar ...\n");
  getch();
}
void modifikoStudent()                      //funksioni qe modifikon statusin per cdo student te rregjistruar.
{
   char emri[20];
   int f=0;
   system("CLS");
   printf("\n\t\t\tShkruani emrin e nxenesit : ");
   scanf("%s",emri);
   fp=fopen("student.txt","rb+");
   while(fread(&s,sizeof(s),1,fp)==1){
   if(strcmpi(emri,s.emerPerdorues)==0){
   f=1;
   printf("\n\t\t\tShkruani Statusin e ri(aktiv ose alumni) :");
   fflush(stdin);
   gets(s.statusi);
   fseek(fp,-si,1);
   fwrite(&s,sizeof(s),1,fp);
   fclose(fp);

}
}
if(f==0){

printf("\n\t\t\tStudenti qe ju kerkoni nuk eshte i rregjisturar");}

else
printf("\n\t\t\tStatusi u ndryshua me sukses");
printf("\n\t\t\tShtyp nje task per te vazhduar ...\n");
  getch();
}

void rregjistropyetjet(){                      //funksioni qe rregjistron pyetjet
    char pyetje[1000];
    char pergjigje[100];
    char zgjedhja;
    char w,q;
    int i=0;
    system("CLS");
    fclose(fp);
   	fp=fopen("pyetje.txt","ab");

    system("CLS");
    printf("\t\t                           Regjistrimi i pyetjeve\n                           ");
      printf("\n\t\t\t*************************************************** : ");
             strcpy(d.lenda,a.lend);
          printf("\n\n\t\t\tShkruani numrin e pyetjeve qe deshiron te rregjistrosh : ");
          scanf("%d",&q);
        strcpy(d.profesor,a.moment);          // ruajme emrin e profesorit te loguar ne strukture/file
          for( i=0;i<q;i++){
          	printf("\n\n\t\t\tShkruani pyetjen[%d] : ",i+1);
          	fflush(stdin);
          	 gets(d.pyetja);
          	 printf("\n\t\t\tShkruani pergjigjen 1 : ");
            fflush(stdin);
          	 gets(d.pergj);
          	  printf("\n\t\t\tShkruani pergjigjen 2 : ");
          	  fflush(stdin);
          	   gets(d.pergj1);
          	    printf("\n\t\t\tShkruani pergjigjen 3: ");
          	fflush(stdin);
          	gets(d.pergj2);
           printf("\n\t\t\tShkruani pergjigjen 4: ");
          fflush(stdin);
          	gets(d.pergj3);
        printf("\n\t\t\ta).%s\n\t\t\tb).%s\n\t\t\tc).%s\n\t\t\td).%s\n",d.pergj,d.pergj1,d.pergj2,d.pergj3);
        printf("\n\t\t\tNese ka 2 pergjigje te sakta shtyp 2 \n\t\t\tnese jo shtyp 1....\n\n");                  // DETYRA EXTRA ( PYETJE ME 2 pergjigje te sakta)
        char g; g=getch();
         if(g=='1'){  // Nese shtypet 1 kemi vetem nje pergjigje te sakte
        printf("\n\t\t\tZgjidhjni pergjigjen e sakte(a-d): ");
  	          d.sakt=getch();
  	          printf("%c",d.sakt);
  	      }
  	      else if(g=='2'){ // Nese shtypet 2 kemi 2 pergjigje te sakta.
        printf("\n\n\t\t\tZgjidhjni pergjigjen e sakte 1(a-d): ");
  	          d.sakt=getch();
  	          printf("%c",d.sakt);
  	    printf("\n\n\t\t\tZgjidhjni pergjigjen e sakte 2(a-d): ");
  	         d.sakt2=getch();
  	         printf("%c",d.sakt2);
  	      }
          	fwrite(&d,sizeof(d),1,fp); 

}
    fclose(fp);
}



void filloprovimin(){              // Permes ketij funks nxenesi fillon provimin .
   int l=0;
   int nr=0,o=0;
	char a;
	char nuk[20]={"Nuk e di"};
	int shuma;
  int idd=1;
  char emri[20];
  char pyet[2][14];
  int numri[100];
	system("CLS");
	printf("\n\t\t\t*********************************\n");
    printf("\n\t\t\tPyetjet  e regjistruara\n");
    int i=1;
    int b=1;
    int w=0;
  fp=fopen("profesore.txt","rb");  
    while(fread(&p,sizeof(p),1,fp)==1){                // lexojme nga file emrat e profesore .
    	printf("\n\t\t\t[%d].%s",b,p.EmerPerdorues);
    	b++;
		}                      
		fclose(fp);
  printf("\n\n\n\t\t\tShkruani emrin e profesorit te lendes  (emermbiemer):");
         scanf("%s",n.prof);                                                             // zgjidhet profesori 

strcpy(n.emri,s.moment);
     fp=fopen("pyetje.txt","rb+");
 while(fread(&d,sizeof(d),1,fp)==1){    // lexojme file ku jane ruajtur pyetjet dhe pergjigjet e sakta
  	if(strcmpi(n.prof,d.profesor)==0)
  	   {
                     strcpy(n.lenda,d.lenda);                                   
					     printf("\n\t\t\t**LENDA** \n\t\t\t**%s**",d.lenda);
		   printf("\n\n\t\t\tPyetja[%d] : %s\n",i,d.pyetja);
  	    printf("\n\t\t\tPergjigja[1] : %s\n\t\t\tPergjigja[2] : %s\n\t\t\tPergjigja[3] : %s\n\t\t\tPergjigja[4] : %s\n",d.pergj,d.pergj1,d.pergj2,d.pergj3);
  	    i++;

  	    printf("\n\t\t\tCila eshte pergjigja e sakte ? \n");
  	    fflush(stdin);
  	    printf("\n\t\t\ta).%s\n\t\t\tb).%s\n\t\t\tc).%s\n\t\t\td).%s\n\t\t\te).%s\n\t\t\tZgjedhja : ",d.pergj,d.pergj1,d.pergj2,d.pergj3,nuk);
  	    scanf("%c",&a);
  	        fflush(stdin);

			  if((a==d.sakt)||(a==d.sakt2)){          // ne rast se pergjigja eshte e sakte studenti merr 1 pike
  	                w++;
                    strcpy(pyet[l],d.pyetja);
                    numri[l]=1;
						  }
						 	  else if((a!='e')&&(a!=d.sakt)&&(a!=d.sakt2)) { w--;         // studenti merr -1 pike
                  strcpy(pyet[l],d.pyetja);
                    numri[l]=-1;
          strcpy(d.moment,d.pyetja);
					numeropyetjet();
  
						   }
						   else if(a=='e'){      // studenti merr 0 pike
                    strcpy(pyet[l],d.pyetja);
                    numri[l]=0;
               }
						   l++;
               o++;
						         // ruajme lenden ne strukturen e notave.
  	 
	}
	}	              
                         	if(l==0){      
		              		printf("\n\t\t\tProfesori qe kerkoni nuk ka hartuar ende nje provim...");
		              			printf("\n\n\t\t\tShtyp nje task per te vazhduar ...\n");
                                getch();
                             return;
						  }
  	    printf("\n\n\t\t\tPiket totale gjate ketij provimi jane : %d\n\n",w);         
printf("\n\t\t\tDeshiron te shikosh nje liste te detajuar te pikeve te marra(p/j) ? \n"); 
char q=getch();
printf("\n\t\t\tZgjedhja : ");
if((q=='p')||(q=='P')){       // Shikohen piket ne menyre te detajuar.
for(l=0;l<o;l++)
printf("\n\t\t\tTek pyetja[%s] ju morret %d pike!\n",pyet[l],numri[l]);
}
 
    n.piket = w;
    strcpy(emri,n.emri);
	 fp=fopen("notat.txt","ab");
    fwrite(&n,sizeof(n),1,fp);           // Ruajme notat emrin e studentit, lendes dhe profesorit.
    fclose(fp);                             
	printf("\n\n\t\t\tShtyp nje task per te vazhduar ...\n");
           getch();
           return;
}
void numeropyetjet(){  //Numerohen pyetjet e gabuara.
FILE *f;
int idd=1;
     int q=0;
                f=fopen("gabime.txt","rb+");                      
             while(fread(&h,sizeof(h),1,f)==1){          
                if(strcmpi(h.pyetja,d.moment)==0){
                  do
                    idd++;
                  while((idd==h.id)||(idd<h.id));
                  
                  h.id=idd;
                   fseek(f,-hi,1);
                 fwrite(&h,sizeof(h),1,f);
                 q++;
                  fclose(f);
                }
             }                                         
                  if(q==0){
                     f=fopen("gabime.txt","ab");
                  strcpy(h.pyetja,d.moment);
                  strcpy(h.lenda,n.lenda);
                   h.id=idd;
                    fwrite(&h,sizeof(h),1,f);
                       fclose(f);
                  }
                
return;
}
void afishopiket()            // Funksioni qe perdoret nga studentet per te pare notat sipas deshires
{      
	int nr=0;
	char name[20];
	char stud[20];
	char em[20];
	char emri[20];
	char c;
	int i=1;
	int q=0;
 system("CLS");
printf("\t\t\t*************************************\n\n");
  fp=fopen("profesore.txt","rb");
  printf("\n\t\t\t1.Shiko notat sipas lendes.");
   printf("\n\t\t\t2.Shiko te gjitha notat.");
   printf("\n\t\t\tZgjedhja : ");
   c=getch();
   if(c=='1')                     // Sipas lendes
   {
   		while(fread(&p,sizeof(p),1,fp)==1){
   	printf("\n\t\t\tLenda : %s ",p.lenda);
   }
   fclose(fp);
   fflush(stdin);
  printf("\n\t\t\tShkruani emrin  lendes : ");
  fflush(stdin);
  gets(name);

	strcpy(em,s.moment);
	 fp=fopen("notat.txt","rb+");
  while(fread(&n,sizeof(n),1,fp)==1){
  	if((strcmpi(name,n.lenda)==0)&&(strcmpi(em,n.emri)==0)){
  		q++;
  		printf("\n\n\t\t\t****LENDA****");
  		printf("\n\n\t\t\t****%s****",n.lenda);
  	    printf("\n\n\t\t\tEmri : %s Piket :  %d\n",n.emri,n.piket);
}
}
if(q==0){
	printf("\n\t\t\tNuk eshte hartuar ende nje provim per lenden qe ju zgjodhet.");
	printf("\n\n\n\t\t\tShtyp nje task per te vazhduar ...\n");
           getch();
           return;

}
   fclose(fp);
  	printf("\n\t\t\tShtyp nje task per te vazhduar ...\n");
           getch();
           return;
}

else if (c=='2')      // Te gjitha notat e studentit.
{

	 fp=fopen("notat.txt","rb");
strcpy(emri,s.moment);
	while(fread(&n,sizeof(n),1,fp)){
  	if(strcmp(emri,n.emri)==0){
  		printf("\n\n\t\t\t****LENDA****");
  		printf("\n\n\t\t\t    %s    ",n.lenda);
  	    printf("\n\n\t\t\tEmri : %s Piket :  %d\n",n.emri,n.piket);
  	}
}

  fclose(fp);
}
 	printf("\n\t\t\tShtyp nje task per te vazhduar ...\n");
     getch();
           return;

}

void shikopiket(){                                     // Permes ketij funksioni profesori shikon vetem notat dhe mesataren e lendes se tij.
	 int nr=0;
 	  char lenda[20];
      char emri[20];
      int sum=0,y;
      float mes=0;
       int o=0;
  strcpy(emri,a.moment);
  fp=fopen("pyetje.txt","rb");
   fp=fopen("notat.txt","rb");
   while(fread(&n,sizeof(n),1,fp)==1){
   if(strcmpi(emri,n.prof)==0){
printf("\n\n\t\t\t************************************\n");
   printf("\n\t\t\tstudenti : %s  Piket : %d",n.emri,n.piket);
   fflush(stdin);
   y=n.piket;
   sum=sum+y;
   o++;
}
}

 mes=(float)sum/o;
 printf("\n\n\t\t\tMesatarja e notave %f",mes);

 fclose(fp);
 	printf("\n\n\t\t\tShtyp nje task per te vazhduar ...\n");
 getch();
    return;
}
void raporte(){             // Raporte te ndryshme per profesor.
 system("CLS");
	          printf("\n\n\t\t\t*******************RAPORTE*****************\n\n");
                      printf("\n\t\t\t1-Listo studentin (studentet) me piket me te larta\n\n");
                      printf("\n\t\t\t2-Listo studentin/studentet me 0 pike.\n\n");
                      printf("\n\t\t\t3-Listo pyetjen/pyetjet ku eshte gabuar me shpesh.\n\n");
                      printf("\n\t\t\t4-Listo sipas pikeve ne rend zbrites: shfaq studentet dhe numrin e pikeve\n\n");
                      printf("\n\t\t\tA-Dil\n\n");
                     printf("\n\t\t\tZgjedhja : ");
	                     char c;
					        c=getch();
if(c=='1'){   //Shikojme piket me te larta te marra nga te gjithe provimet.
system("CLS");
		fp=fopen("notat.txt","rb");
    int i=0, max=0;
    int nr=0,y=1;
     int v[100];
      char emri[20];
   while(fread(&n,sizeof(n),1,fp)==1){
   	v[i]=n.piket;
   	i++;
   	nr++;
   }
   for(i=0;i<nr;i++)
   {
        if ( v[i] > max )
                max = v[i];
    }
     printf("\n\t\t\tPiket me te larta [%d] jan marre nga keto student\n",max);
     fclose(fp);
     fp=fopen("notat.txt","rb");
     while(fread(&n,sizeof(n),1,fp)==1){
     if ( n.piket == max )
        {
          printf("\n\t\t\t ~ [%d].%s ~ Lenda : %s ~\n\n",y,n.emri,n.lenda);  
         y++; 
       }
   }


   fclose(fp);
  	printf("\n\t\t\tShtyp nje task per te vazhduar ...\n");
 getch();
   return;
}
else if(c=='2'){ // te gjithe studentet qe kan marre 0 pike
   system("cls");
  char emri[20];
		fp=fopen("notat.txt","rb");
       int y=1;

printf("\n\t\t\tStudentet me 0 pike :");
   while(fread(&n,sizeof(n),1,fp)==1){
        if ( n.piket == 0 )
        {
            printf("\n\t\t\t[%d].%4s\t Lenda:%s\n\n",y, n.emri,n.lenda);
         y++;
        }
    }
   
    fclose(fp);
  	printf("\n\t\t\tShtyp nje task per te vazhduar ...\n");
 getch();
    return;
}

else if(c=='3'){      // Pyetjet qe jan gabuar me se shumti.
   system("cls");
FILE *f;
char emri[20];
  int i=0, max;
int nr=0;
 int y=1;
 int v[100];
 f=fopen("gabime.txt","rb");
   printf("\n\t\t\tPyetjet qe jane gabuar me se shumti : ");
     while(fread(&h,sizeof(h),1,f)==1){
     	v[i]=h.id;
   	i++;
   	nr++;
   }
   for(i=0;i<nr;i++){
     if ( h.id > max )
        {
          max = h.id;
    }
     }
     fclose(f);
     f=fopen("gabime.txt","rb");
 if ( h.id == max )
  {
         printf("\n\t\t\t -  Pyetja[%s] - %d here  -  LENDA : %s  -\n\n",h.pyetja,max,h.lenda);
         
    }
     
     
fclose(f);
  	printf("\n\t\t\tShtyp nje task per te vazhduar ...\n");
 getch();
   return;


}
	else if(c=='4'){  // listim nga piket me te madhe tek me te voglat.
    system("cls");
    struct nota s[100],tmp;
    int i=0,j,nr=0;
    FILE * fp;
    printf("\n\t\t\tPiket e pa listuara :");
    	fp=fopen("notat.txt","rb");
 while(fread(&n,sizeof(n),1,fp)==1){
   printf("\n\t\t\t[%d].%s Piket : %d  Lenda : %s",i+1,n.emri,n.piket,n.lenda);
   s[i].piket=n.piket;
   strcpy(s[i].emri,n.emri);
   strcpy(s[i].lenda,n.lenda);
  i++;
  nr++;
   }
 
 for(i=0;i<nr-1;i++)
{
for(j=0;j<nr-1;j++)
{
if(s[j].piket<s[j+1].piket)
{
 tmp=s[j];
s[j]=s[j+1];
s[j+1]=tmp;
}
}
}
printf("\n\n\n\t\t\t***********************************\n\n");
printf("\n\t\t\tPiket e listuara : \n");
  for(j=0;j<nr;j++){                                          // listohen piket.
   printf("\n\t\t\t[%d].[%s]    Piket : %d    Lenda : %s",j+1,s[j].emri,s[j].piket,s[j].lenda);
   }
   fclose(fp);      
  printf("\n\n\n\t\t\tShtyp nje task per te vazhduar ...\n");
   getch();
  return;

 }
}



void MenuKryesore()     // MENU
{


	 	       printf("\n\n\t\t\t\tMIRESEVINI NE MENUNE KRYESORE\n");
	 	       printf("\t\t\t\t*****************************\n");
	 	printf("\n\t\t\tZgjidh njerin nga 3 rolet e meposhtme.\n\n");
	 	printf("\t\t\t 1- Administrator \n\n");
	 	printf("\t\t\t 2- Profesor\n\n");
	 	printf("\t\t\t 3- Student\n\n");
     printf("\t\t\t a- Dil\n\n" );
	    printf("\t\t\t Zgjedhja :   ");


}

int main(void)    
{
	system("CLS");
    char zgjedhja;
     system("Color 30");
    do
    {
      
    		system("CLS");
   MenuKryesore();
        zgjedhja=getch();
        if (zgjedhja=='1')
            administrator();
           else if (zgjedhja=='2')
            profesor();
           else if (zgjedhja=='3')
           student();

        else
            system("CLS");
    }
    while ((zgjedhja!='a') && (zgjedhja!='A'));
    system("CLS");
  printf("\n\n\t\t\tPunoi : GLEN LOHJA\n\n\n\n");
      system("\tPause");
}

