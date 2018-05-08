#include<iostream>
#include<string.h>
using namespace std;
class address
{
    char street[30],city[30],state[30],country[30];
    public:
    void create();
    void display();
};
class sportachnts
{
    char event[30];
    address ad;
    int score,place;
    bool win;
public:
    void create(int);
    void display(int);
};
class sport
{
    char spname[30];
    int matches_played,matches_won;
    int num,no_achnts;
    sportachnts achnts[5];
  public:
    void create();
    float win_ratio();
    void display();
    char* sportname(){return spname;}
};
class sportdata
{
    char name[30];
    int sec,roll_no;
    sport mainsport;
    int no_osports;
    int othersports[5];
  public:
    void create();
    void display();
    char* studname(){return name;}
    char* sportname(){return mainsport.sportname();}

};
void address::create()
{
    cout<<"\nEnter the street,city,state,country of the event\n";
    char str[30];
    cin>>str;
    strcpy(street,str);
    cin>>str;
    strcpy(city,str);
    cin>>str;
    strcpy(state,str);
    cin>>str;
    strcpy(country,str);
}
void menu()
{
    cout<<"\nEnter\n1.Cricket\n2.Football\n3.Basketball\n4.Volleyball\n5.Badminton\n6.Chess\n7.Carroms\n8.TableTennis\n9.Running\n10.Tennis\n";
}
void sport::create()
{
    menu();
    cout<<"Enter the main sport of the student\n";
    cin>>num;
    if(num>10)
        throw "Invalid Input";
    switch(num)
    {
        case 1:strcpy(spname,"Cricket");
               break;
        case 2:strcpy(spname,"Football");
               break;
        case 3:strcpy(spname,"Basketball");
               break;
        case 4:strcpy(spname,"Volleyball");
               break;
        case 5:strcpy(spname,"Badminton");
               break;
        case 6:strcpy(spname,"Chess");
               break;
        case 7:strcpy(spname,"Carroms");
               break;
        case 8:strcpy(spname,"TableTennis");
               break;
        case 9:strcpy(spname,"Running");
               break;
        case 10:strcpy(spname,"Tennis");
               break;
        default:break;

    }
    spname[strlen(spname)]='\0';
    cout<<"Enter the total no of matches played if any else enter 0.\n";
    cin>>matches_played;
    if(matches_won!=0)
    {
        cout<<"Enter matches won\n";
        cin>>matches_won;
    }
    cout<<"Enter the number of events to be entered \n";
    cin>>no_achnts;
    if(no_achnts!=0)
    {
        cout<<"Enter the details of any events the student has participated in main sport\n";
        for(int i=0;i<no_achnts;i++)
            achnts[i].create(num);
    }
}
void sportachnts::create(int n)
{
    cout<<"\nEnter the event the student participated in \n";
    char str[30];
    cin>>str;
    strcpy(event,str);
    ad.create();
    switch(n)
    {
        case 1:cout<<"Enter the total runs scored by the student in the match\n";
               cin>>score;
               cout<<"Enter\n0.Loss the match\n1.Won the match\n";
               cin>>win;
               if(win)
               {
                  cout<<"Enter the place of student's team in the event\n";
                  cin>>place;
               }
               break;
        case 2:cout<<"Enter the goals scored by player\n";
               cin>>score;
               cout<<"Enter\n0.Loss the match\n1.Won the match\n";
               cin>>win;
               if(win)
               {
                  cout<<"Enter the place of student's team in the event\n";
                  cin>>place;
               }
               break;
        case 3:cout<<"Enter the number of hoops\n";
               cin>>score;
               cout<<"Enter\n0.Loss the match\n1.Won the match\n";
               cin>>win;
               if(win)
               {
                  cout<<"Enter the place of student's team in the event\n";
                  cin>>place;
               }
               break;
        case 4:cout<<"Enter the points scored by player team\n";
               cin>>score;
               cout<<"Enter\n0.Lost the match\n1.Won the match\n";
               cin>>win;
               if(win)
               {
                  cout<<"Enter the place of student's team in the event\n";
                  cin>>place;
               }
               break;
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:cout<<"Enter\n0.Lost the match\n1.Won the match\n";
                cin>>win;
                if(win)
                {
                  cout<<"Enter the place of student in the event\n";
                  cin>>place;
                }
                break;
        default:cout<<"Invalid Input";

    }
}
void sportdata::create()
{
    cout<<"Enter the name ,section and roll number of the student\n";
    cin>>name>>sec>>roll_no;
    mainsport.create();
    menu();
    cout<<"Enter the number of other interested sports of the student\n";
    cin>>no_osports;
    cout<<"give the input number from above\n ";
    for(int i=0;i<no_osports;i++)
         cin>>othersports[i];
}
void address::display()
{
    cout<<"Street:"<<street<<"\n";
    cout<<"City:"<<city<<"\n";
    cout<<"State:"<<state<<"\n";
    cout<<"Country:"<<country<<"\n";
}
float sport::win_ratio()
{
     if(matches_played!=0)
        return matches_won/matches_played;
    else
        return -1;
}
void sport::display()
{
        for(int i=0;i<strlen(spname);i++)
            cout<<spname[i];
        cout<<"\n";
        if(no_achnts==0)
            cout<<"No notable achievements\n";
        else
        {   int k;
            cout<<"Enter 1 to see information about any events the student participated  in interested sport or any number for not seeing the achievements.\n";
            cin>>k;
            if(k==1)
                for(int i=0;i<no_achnts;i++)
                    achnts[i].display(num);
            else
                cout<<"Achievements are not shown\n";
        }
}
void sportachnts::display(int n)
{
    cout<<"The event is :";
    cout<<event;
    cout<<"\n At the location of:\n";
    ad.display();
    switch(n)
    {
        case 1:cout<<"The runs scored by the student in the match is\n";
               cout<<score<<"\n";
               if(win)
                   cout<<"The student's team achieved "<<place<<" place in the event\n";
               else
                   cout<<"The student team lost the match\n";
               break;
        case 2:cout<<"The goals scored by the student in the match is\n";
               cout<<score<<"\n";
               if(win)
                   cout<<"The student's team achieved "<<place<<" place in the event\n";
               else
                   cout<<"The student team lost the match\n";
               break;
        case 3:cout<<"The hoops scored by the student in the match is\n";
               cout<<score<<"\n";
               if(win)
                   cout<<"The student's team achieved "<<place<<" place in the event\n";
               else
                   cout<<"The student team lost the match\n";
               break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:if(win)
                   cout<<"The student achieved "<<place<<" place in the event\n";
                else
                   cout<<"The student lost the match\n";
               break;
        default:break;
    }


}
void sportdata::display()
{
    cout<<"Name:"<<name<<"\n";
    cout<<"Section:C-"<<sec<<"\n";
    cout<<"Roll number:"<<roll_no<<"\n";
    cout<<"Interested sport is:";
    mainsport.display();
    cout<<"\nSome of the other sports played by the student are:\n";
    if(no_osports==0)
        cout<<"none\n";
    for(int i=0;i<no_osports;i++)
        switch(othersports[i])
        {

            case 1:cout<<"Cricket "<<"\n";
                   break;
            case 2:cout<<"Football"<<"\n";
                   break;
            case 3:cout<<"Basketball"<<"\n";
                    break;
            case 4:cout<<"Volleyball"<<"\n";
                    break;
            case 5:cout<<"Badminton"<<"\n";
                    break;
            case 6:cout<<"Chess"<<"\n";
                    break;
            case 7:cout<<"Carrom"<<"\n";
                     break;
            case 8:cout<<"TableTennnis"<<"\n";
                     break;
            case 9:cout<<"Running"<<"\n";
                     break;
            case 10:cout<<"Tennis"<<"\n";
                      break;


    }
}
